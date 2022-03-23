local class         = require "xgame.class"
local login         = class("login")
local yasio         = require("yasio"):singleton()

function login:ctor()
    yasio:addStatusCallBack(function(...)
        self:onStatusCallBack(...)
    end)
    yasio:addProtoCallBack(function(...)
        self:onProtoCallBack(...)
    end)
end

function login:start()
    yasio:linkServer()
end

function login:onStatusCallBack(ev)

end

function linkServer:onProtoCallBack(rpc, proto, ...)
    local ctrl_name = string.format("control.%s", proto)
    local ctrl = require (ctrl_name)
    ctrl[rpc](table.pack(...))
end

return linkServer
