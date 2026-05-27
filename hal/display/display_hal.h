#ifndef DISPLAY_HAL_H
#define DISPLAY_HAL_H

#include <stdbool.h>
#include <stdint.h>

void display_hal_init(void);

void display_hal_clear(void);

void display_hal_render_text(const char *text);

#endif /* DISPLAY_HAL_H */
