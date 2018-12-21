#ifndef __LED_MENU_H__
#define __LED_MENU_H__

#include "menu.h"

#ifdef LED_MENU_LOCAL
#define LED_MENU_DEF
#else
#define LED_MENU_DEF       extern
#endif

LED_MENU_DEF int Command_Led_Main(int argc, char **argv);
LED_MENU_DEF int Command_Led_Main_Menu(void);


#endif