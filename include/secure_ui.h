#ifndef SECURE_UI_H
#define SECURE_UI_H

void secure_ui_init(void);

void secure_ui_show_locked(void);

void secure_ui_show_auth_required(void);

void secure_ui_show_unlocked(void);

void secure_ui_show_tamper_alert(void);

void secure_ui_show_auth(void);

void secure_ui_show_home(void);

#endif
