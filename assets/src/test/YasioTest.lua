local class     = require "xgame.class"
local UIScene   = require "xgame.ui.UIScene"
local YasioTest = class('YasioTest', UIScene)
local link      = require "control.linkServer".new()

function YasioTest:ctor()
    link:start()
end
    
return YasioTest
