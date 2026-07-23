#include "Extensions.h"
#include "Handlers.h"
#include "ItkHelpers.hxx"

#include <tccore/custom.h>
#include <ict/ict_userservice.h>

int InitModule(int* decision, va_list args)
{
    *decision = ALL_CUSTOMIZATIONS;
    try
    {
        TC_write_syslog("\n%s Initializing Custom Module: $projectname$ \n", LOG_PREFIX);

        RegisterHandlers();
        RegisterExtensions();

        return ITK_ok;
    }
    TC_CATCH(ITK_ok)
}

extern "C" DLLAPI int $projectname$_register_callbacks()
{
    try
    {
        TC_CALL(CUSTOM_register_exit("$projectname$", "USER_init_module", (CUSTOM_EXIT_ftn_t) InitModule));

        return ITK_ok;
    }
    TC_CATCH(ITK_ok)
}
