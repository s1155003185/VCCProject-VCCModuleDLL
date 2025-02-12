#pragma once

#include <assert.h>
#include <memory>

#include "i_manager.hpp"
#include "base_object.hpp"
#include "class_macro.hpp"
#include "log_config.hpp"

namespace vcc
{
    class BaseManager : public IManager, public BaseObject
    {
        GETSET_SPTR_NULL(LogConfig, LogConfig);
    
    private:
        BaseManager() = default;

    protected:
        BaseManager(std::shared_ptr<LogConfig> logConfig) : _LogConfig(logConfig) {}
        virtual ~BaseManager() {}
        
        // No Clone for Manager
        virtual std::shared_ptr<IObject> Clone() const override { assert(false);  return nullptr; }
    };
}
