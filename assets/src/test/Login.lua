local class         = require "xgame.class"
local UIScene       = require "xgame.ui.UIScene"
local LoginScene    = class('LoginScene', UIScene)
local login          = require "control.login".new()

function LoginScene:ctor()
    link:start()
end
    
return LoginScene
