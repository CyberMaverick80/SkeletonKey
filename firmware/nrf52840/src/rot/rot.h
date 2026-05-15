#ifndef ROT_H
#define ROT_H

#include <stdint.h>
#include <stdbool.h>

void rot_init(void);
bool rot_get_random(uint8_t *buf, size_t len);

#endif
