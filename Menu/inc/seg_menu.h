#ifndef __SEG_MENU_H__
#define __SEG_MENU_H__

#include "menu.h"

#ifdef SEG_MENU_LOCAL
#define SEG_DEF
#else
#define SEG_DEF            extern
#endif

SEG_DEF int Command_Seg_Main(int argc, char argv);
SEG_DEF int Command_Seg_Main_Menu(void);

#endif