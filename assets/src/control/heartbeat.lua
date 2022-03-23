local class         = require "xgame.class"
local heartbeat     = class("heartbeat")
local REQUEST       = {}

function REQUEST:heartbeat()
    print("on heartbeat")
end

heartbeat.REQUEST = REQUEST
return heartbeat