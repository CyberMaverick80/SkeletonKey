#include "security/enforcement.h"

void firmware_update_start(void)
{
    enforcement_check_firmware_update();
}
