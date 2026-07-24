#pragma once

#include <epm/epm.h>

void RegisterHandlers();

int action_handler_name(EPM_action_message_t message);
EPM_decision_t rule_handler_name(EPM_rule_message_t message);
