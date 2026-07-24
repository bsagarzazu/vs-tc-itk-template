#include "Handlers.h"
#include "ItkHelpers.hxx"

#include <string>

#include <epm/epm.h>

#define ACTION_ENTRY(function) {#function, nullptr, (EPM_action_handler_t) (function)}
#define RULE_ENTRY(function) {#function, nullptr, (EPM_rule_handler_t) (function)}

struct ActionHandlerDefinition
{
    const char* name;
    const char* description;
    EPM_action_handler_t function;
};

struct RuleHandlerDefinition
{
    const char* name;
    const char* description;
    EPM_rule_handler_t function;
};

static ActionHandlerDefinition action_handler_registry[] = {ACTION_ENTRY(action_handler_name)};

static RuleHandlerDefinition rule_handler_registry[] = {RULE_ENTRY(rule_handler_name)};

void RegisterHandlers()
{
    std::string prefix = STRINGIFY(CLIENT_PREFIX);

    for (const auto& action : action_handler_registry)
    {
        std::string fullName = prefix + action.name;
        TC_CALL(EPM_register_action_handler(fullName.c_str(), action.description, action.function))
    }

    for (const auto& rule : rule_handler_registry)
    {
        std::string fullName = prefix + rule.name;
        TC_CALL(EPM_register_rule_handler(fullName.c_str(), rule.description, rule.function))
    }
}

int action_handler_name(EPM_action_message_t message)
{
    try
    {
        TC_write_syslog("%s Running %s...\n", LOG_PREFIX, __FUNCTION__);

        // Business logic here...

        return ITK_ok;
    }
    TC_CATCH(ITK_ok);
}

EPM_decision_t rule_handler_name(EPM_rule_message_t message)
{
    try
    {
        TC_write_syslog("%s Running %s...\n", LOG_PREFIX, __FUNCTION__);

        // Business logic here...

        return EPM_go;
    }
    catch (...)
    {
        return EPM_nogo;
    }
}
