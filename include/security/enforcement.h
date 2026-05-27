#ifndef ENFORCEMENT_H
#define ENFORCEMENT_H

#include <stdbool.h>

typedef enum {
    SEC_ALLOW = 0,
    SEC_DENY  = 1
} sec_result_t;

/* Core lifecycle */
void enforcement_init(void);

/* Security gates */
sec_result_t enforcement_check_usb(void);
sec_result_t enforcement_check_keygen(void);
sec_result_t enforcement_check_firmware_update(void);

/* State helper */
bool enforcement_is_locked(void);

#endif
