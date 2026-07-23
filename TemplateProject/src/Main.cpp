#include "Handlers.h"
#include "Extensions.h"

extern "C" DLLAPI int $projectname$_register_callbacks()
{
	RegisterHandlers();
	RegisterExtensions();
	return ITK_ok;
}