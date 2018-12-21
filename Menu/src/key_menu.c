#define KEY_MENU_LOCAL

#include "key_menu.h"

static unsigned short flag;

KEY_MENU_DEF int Command_Key_Main(int argc, char **argv);
KEY_MENU_DEF int Command_Key_Main_Menu(void);


KEY_MENU_DEF int Command_Key_Main(int argc, char **argv)
{
    int key;
    return 0;
}

KEY_MENU_DEF int Command_Key_Main_Menu(void)
{
    int key;
    
    printf("\r\n\r\n");
    printf("-------------------------------------------------\r\n");
    printf("                 KEY MAIN MENU\n");
    printf("-------------------------------------------------\r\n");
    printf(" 1. Key Test                                         \r\n");
    printf(" 2. Led Test                                         \r\n");
    printf(" 3. System_Information                                         \r\n");
    printf(" 4. Test                                         \r\n");
    printf(" 5. Test                                         \r\n");
    printf(" 6. Test                                         \r\n");
    printf(" 7. Test                                         \r\n");
    printf(" 8. Test                                         \r\n");
    printf(" 9. Test                                         \r\n");
    printf(" 0. Test                                         \r\n");
    printf("-------------------------------------------------\r\n");
    printf(" q. KEY Menu QUIT\r\n");
    printf("-------------------------------------------------\r\n");
    printf("\r\n\r\n");
    
    printf("SELECT THE COMMAND NUMBER : ");
    key=USART_GetCharacter(USART1);
        
    return key;    
}