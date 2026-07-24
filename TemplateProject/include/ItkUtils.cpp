#include "ItkUtils.h"
#include "ItkHelpers.hxx"

#include <epm/epm.h>
#include <tc/tc_arguments.h>
#include <tc/tc_startup.h>

namespace itk
{
std::map<std::string, std::string> GetHandlerArguments(EPM_action_message_t msg)
{
    std::map<std::string, std::string> argMap;

    if (msg.arguments == nullptr)
        return argMap;

    int count = TC_number_of_arguments(msg.arguments);
    if (count <= 0)
        return argMap;

    TC_init_argument_list(msg.arguments);

    for (int i = 0; i < count; ++i)
    {
        char* argString = TC_next_argument(msg.arguments);
        if (argString == nullptr)
            continue;

        itk::Ptr<char> argName;
        itk::Ptr<char> argValue;

        TC_CALL(ITK_ask_argument_named_value(argString, &argName, &argValue));

        if (argName != nullptr)
        {
            argMap[argName.getString()] = argValue.getString();
        }
    }

    return argMap;
}
} // namespace itk
