#define LED_MENU_LOCAL

#include "led_menu.h"

static unsigned short flag;

LED_MENU_DEF int Command_Led_Main(int argc, char **argv);
LED_MENU_DEF int Command_Led_Main_Menu(void);


LED_MENU_DEF int Command_Led_Main(int argc, char **argv)
{
    int key;
    return 0;
}

LED_MENU_DEF int Command_Led_Main_Menu(void)
{
    int key;

    printf("\r\n\r\n");
    printf("-------------------------------------------------\r\n");
    printf("                 LED MAIN MENU\r\n");
    printf("-------------------------------------------------\r\n");
    printf(" 1. Red On                                         \r\n");
    printf(" 2. Red Off                                         \r\n");
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