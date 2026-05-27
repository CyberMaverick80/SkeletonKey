#ifndef KEYMGMT_H
#define KEYMGMT_H

#include <stdbool.h>

void keymgmt_init(void);
bool keymgmt_generate_session_key(void);

#endif
