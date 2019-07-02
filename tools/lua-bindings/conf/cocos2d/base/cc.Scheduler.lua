local cls = class()
cls.CPPCLS = "cocos2d::Scheduler"
cls.LUACLS = "cc.Scheduler"
cls.SUPERCLS = "cc.Ref"
cls.CHUNK = [[
template <typename T> bool doScheduleUpdate(lua_State *L, const char *cls)
{
    if (olua_is_cppobj(L, 2, cls)) {
        cocos2d::Scheduler *self = nullptr;
        lua_Integer arg2 = 0;
        bool arg3 = false;
        
        olua_to_cppobj(L, 1, (void **)&self, "cc.Scheduler");
        olua_check_int(L, 3, &arg2);
        olua_check_bool(L, 4, &arg3);
        
        T* arg1 = nullptr;
        olua_to_cppobj(L, 2, (void **)&arg1, cls);
        self->scheduleUpdate(arg1, (int)arg2, arg3);
        
        return true;
    }
    
    return false;
}]]
cls.enum('PRIORITY_SYSTEM', 'cocos2d::Scheduler::PRIORITY_SYSTEM')
cls.enum('PRIORITY_NON_SYSTEM_MIN', 'cocos2d::Scheduler::PRIORITY_NON_SYSTEM_MIN')
cls.func('new', new_ccobj(cls))
cls.callback(
    'void schedule(const std::function<void(float)>& callback, void *target, float interval, bool paused, const std::string& key)',
    'void schedule(const std::function<void(float)>& callback, void *target, float interval, unsigned int repeat, float delay, bool paused, const std::string& key)',
    {
        CALLBACK_MAKER = 'makeScheduleCallbackTag(#-1)',
        CALLBACK_STORE = 2, -- 2th void *target
        CALLBACK_REPLACE = true,
    }
)
cls.callback(
    'void unschedule(const std::string& key, void *target)',
    {
        CALLBACK_MAKER = 'makeScheduleCallbackTag(#1)',
        CALLBACK_STORE = 2, -- 2th void *target
        CALLBACK_MODE = 'OLUA_CALLBACK_TAG_ENDWITH',
        CALLBACK_REMOVE = true,
    }
)
cls.callback(
    'void unscheduleAllForTarget(void *target)',
    {
        CALLBACK_MAKER = 'makeScheduleCallbackTag("")',
        CALLBACK_MODE = 'OLUA_CALLBACK_TAG_WILDCARD',
        CALLBACK_STORE = 1, -- 1th void *target
        CALLBACK_REMOVE = true,
    }
)
cls.callback(
    'void unscheduleAll()',
    {
        CALLBACK_MAKER = 'makeScheduleCallbackTag("")',
        CALLBACK_MODE = 'OLUA_CALLBACK_TAG_WILDCARD',
        CALLBACK_REMOVE = true,
    }
)
cls.func('scheduleUpdate', [[
{
    lua_settop(L, 4);
    
    if (doScheduleUpdate<cocos2d::Scheduler>(L, "cc.Scheduler") ||
        doScheduleUpdate<cocos2d::ActionManager>(L, "cc.ActionManager") ||
        doScheduleUpdate<cocos2d::Node>(L, "cc.Node") ||
        doScheduleUpdate<cocos2d::Action>(L, "cc.Action") ||
        doScheduleUpdate<cocos2d::Component>(L, "cc.Component") ||
        doScheduleUpdate<cocos2d::ActionManager>(L, "cc.ActionManager")) {
        return 0;
    }
    
    luaL_error(L, "unsupport type: %s", olua_typename(L, 2));

    return 0;
}]])
cls.funcs([[
    float getTimeScale()
    void setTimeScale(float timeScale)
    void update(float dt)
    void unscheduleUpdate(void *target)
    void unscheduleAllWithMinPriority(int minPriority)
    bool isScheduled(const std::string& key, const void *target)
    void pauseTarget(void *target)
    void resumeTarget(void *target)
    bool isTargetPaused(void *target)
    std::set<void*> pauseAllTargets()
    std::set<void*> pauseAllTargetsWithMinPriority(int minPriority)
    void resumeTargets(const std::set<void*>& targetsToResume)
    void removeAllFunctionsToBePerformedInCocosThread()
]])
cls.props [[timeScale]]


return cls