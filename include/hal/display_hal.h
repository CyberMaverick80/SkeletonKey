#ifndef DISPLAY_HAL_H
#define DISPLAY_HAL_H

#ifdef __cplusplus
extern "C" {
#endif

void display_hal_init(void);
void display_render_text(const char *text);

#endif
