#define SEG_MENU_LOCAL

#include "seg_menu.h"

static unsigned short flag;

SEG_DEF int Command_Seg_Main(int argc, char argv);
SEG_DEF int Command_Seg_Main_Menu(void);


SEG_DEF int Command_Seg_Main(int argc, char argv)
{
    int key;
    return 0;
}
SEG_DEF int Command_Seg_Main_Menu(void)
{
    int key;
    printf("\r\n\r\n");
    printf("-------------------------------------------------\r\n");
    printf("                 SEG MAIN MENU\r\n");
    printf("-------------------------------------------------\r\n");
    printf(" 1. SEG On                                         \r\n");
    printf(" 2. SEG Off                                         \r\n");
    printf(" 3. Yellow On                                         \r\n");
    printf(" 4. Yellow Off                                         \r\n");
    printf(" 5. Blue On                                         \r\n");
    printf(" 6. Blue Off                                         \r\n");
    printf(" 7. Led Test                                         \r\n");
    printf(" 8. System_Information                                         \r\n");
    printf(" 9. Test                                         \r\n");
    printf(" 0. Test                                         \r\n");
    printf("-------------------------------------------------\r\n");
    printf(" q. LED Menu QUIT\r\n");
    printf("-------------------------------------------------\r\n");
    printf("\r\n\r\n");

    printf("SELECT THE COMMAND NUMBER : ");
    key=USART_GetCharacter(USART1);
    
    return key;        
}