local io_service    = require "yasio.io_service"
local config        = require "config"
local timer         = require "cclua.timer"
local sproto        = require "sproto"
local proto         = require "proto"
local proto_text    = proto.s2c
local host          = sproto.parse(proto_text):host("package")
local crypt         = require "crypt"

local class     = require "xgame.class"
local yasio     = class("yasio")
local singleton = nil

function yasio:singleton()
    if singleton == nil then 
        singleton = yasio.new()
    end
    return singleton
end

function yasio:ctor()
    self.statusCB = default_Status_CB
    self.protoCB = default_Proto_CB
end

function yasio:linkServer()
    local service = io_service.new({host_= config.host, port_= config.port})
    service:set_unpack_frame_option(0, 65535, 0, 2, 2)
    timer.schedule(0, function()
        service:dispatch(128)
    end)
    service:open(0)
    service:start(function(ev)
        print("kind =",     ev:kind())
        print("status =",   ev:status())
        print("timestamp =",   ev:timestamp())
        if ev:kind() == 3 then 
            local package = ev:packet()
            package = package:sub(3)
            print("hex =", crypt.hexencode(package))
            local args = table.pack(host:dispatch(package, len))
            print("packet =", table.unpack(args))
            self.protoCB(table.unpack(args))
        else
            self.statusCB(ev:status())
        end
    end)
end

function yasio:sendProto()

end

function yasio:addStatusCallBack(cb)
    self.statusCB = cb
end

function yasio:addProtoCallBack(cb)
    self.protoCB = cb
end

return yasio