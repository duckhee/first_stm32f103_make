#ifndef __MAIN_MENU_H__
#define __MAIN_MENU_H__

#include "menu.h"


#ifdef MAIN_MENU_LOCAL
#define MAIN_MENU_DEF
#else
#define MAIN_MENU_DEF           extern
#endif

MAIN_MENU_DEF void default_menu();
MAIN_MENU_DEF void USB_Test_Start (void);
MAIN_MENU_DEF void Sys_Info(void);
MAIN_MENU_DEF int Command_Main(int argc, char **argv);
MAIN_MENU_DEF int Command_Main_Menu(void);

#endif