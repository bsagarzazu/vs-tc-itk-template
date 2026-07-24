#pragma once

#include <map>
#include <string>

#include <epm/epm.h>

namespace itk
{
/* @brief Parses all handler arguments into a map. */
std::map<std::string, std::string> GetHandlerArguments(EPM_action_message_t msg);
} 
