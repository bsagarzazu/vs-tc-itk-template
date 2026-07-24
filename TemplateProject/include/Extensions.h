#pragma once

#include <tccore/method.h>

void RegisterExtensions();

int pre_save_item_action(METHOD_message_t* msg, va_list args);
