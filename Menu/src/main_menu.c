#define MAIN_MENU_LOCAL

#include "main_menu.h"

#define MAX_ARGS            30
typedef bool;
#define true                1
#define false               0

RCC_ClocksTypeDef  rcc_clocks;
uint8_t ch;

void System_Information()
{
    printf("SYSCLK_Frequency = %d\r\n",rcc_clocks.SYSCLK_Frequency );
    printf("HCLK_Frequency = %d\r\n",rcc_clocks.HCLK_Frequency );
    printf("PCLK1_Frequency = %d\r\n",rcc_clocks.PCLK1_Frequency );
    printf("PCLK2_Frequency = %d\r\n",rcc_clocks.PCLK2_Frequency );
    printf("ADCCLK_Frequency = %d\r\n",rcc_clocks.ADCCLK_Frequency );
}

void USB_Test_Start (void)
{
    USB_Interrupts_Config();
    Set_USBClock();
    USB_Init();
}

void default_menu()
{
    while(1){
        printf("\r\n---------------------\r\n");
#ifdef BOARD_DEF_MANGO_M32
        printf("Mango M32 test start...\n");
#elif  BOARD_DEF_MANGO_Z1
        printf("Mango Z1 test start...\n");
#endif
        printf("Press menu key\r\n");
        printf("---------------------\r\n");
        printf("0> System Information\r\n");
        printf("---------------------\r\n");
        printf("1> LED Test\r\n");
        printf("2> KEY Test\r\n");
#ifdef BOARD_DEF_MANGO_M32
        printf("3> 7-Segment Test\r\n");
#elif  BOARD_DEF_MANGO_Z1
        printf("3> ZigBee Test\r\n");
#endif
        printf("4> USB HID Test\r\n");
        printf("5> \r\n");
        printf("---------------------\r\n");
        printf("x> quit\r\n\r\n");

        ch = USART_GetCharacter(USART1);
        printf(" is selected\r\n\r\n");

        switch((char)ch)
        {
        case '0':
            System_Information();
            break;

        case '1':
            LED_Test();
            break;

        case '2':
            KEY_Test();
            break;

        case '3':
#ifdef BOARD_DEF_MANGO_M32
            Seven_Segment_Test();
#elif  BOARD_DEF_MANGO_Z1
            ZigBee_Test();
#endif
            break;

        case '4':
            g_TestProcessState = TRUE;

            /* USB initialization */
            USB_Test_Start();
            Delay(500);
            USB_Cable_Config(ENABLE);
            break;

        case '5':
            break;

        }

        if('x' == (char)ch)
        {
            break;
        }    
    }
}

typedef enum
{
    VAR_LONG = 32,
    VAR_SHORT = 16,
    VAR_CHAR = 8
} VAR_TYPE;

#define NULL ((void *)0)

char cmd[128]; //one word
int cmd_size;
// 구조체 선언
struct _CMD_TBL{
    // 예약된 명령어
    char *cmd;
    // 함수 포인터, 이중포인터는 포인터 배열을 가리킨다.
    bool (*run)(struct _CMD_TBL *cptr, int argc, char **argv);
    // 해당되는 명령어의 사용법
    char *usage;
    // 해당되는 명령어의 도움말, 더 자세한 사용법
    char *help;
    char *help_more;
};

//초기화
#define CMD_TBL_TEST                  {"test",      do_test, 0, 0, 0}
#define CMD_TBL_END                   {0,           0,       0, 0, 0}


//함수 프로토 타입 선언
void display_prompt(char *prompt);
bool do_print_help(int argc, char **argv);
int get_command(char *cmd, int len, int timeout);
int get_args(char *s, char **argv);

bool do_test(struct _CMD_TBL *cptr, int argc, char **argv);

//구조체를 배열로 할당(구조체 배열)
struct _CMD_TBL cmd_tbl[] =
{
    CMD_TBL_TEST,
    //추가 시작
    
    //end는 0으로 되어있고 command에서 cptr이 0이면, for문은 빠져나오게 되어 있다.
    //end 밑에 추가하면 동작이 안된다.
    //추가 끝
    CMD_TBL_END
};

//함수 프로토 타입 선언
void display_prompt(char *prompt);
bool do_print_help(int argc, char **argv);
int get_command(char *cmd, int len, int timeout);
int get_args(char *s, char **argv);

MAIN_MENU_DEF void Sys_Info(void);

RCC_ClocksTypeDef rcc_clocks;

MAIN_MENU_DEF void Sys_Info(void)
{
    printf("SYSCLK_Frequency = %d\r\n",rcc_clocks.SYSCLK_Frequency );
    printf("HCLK_Frequency = %d\r\n",rcc_clocks.HCLK_Frequency );
    printf("PCLK1_Frequency = %d\r\n",rcc_clocks.PCLK1_Frequency );
    printf("PCLK2_Frequency = %d\r\n",rcc_clocks.PCLK2_Frequency );
    printf("ADCCLK_Frequency = %d\r\n",rcc_clocks.ADCCLK_Frequency );
}



void display_prompt(char *prompt)
{
    if(prompt == NULL)
    {
        printf(">>> ");
    }
    else
    {
        printf("%s\r\n", prompt);
    }
}
int get_command(char *cmd, int len, int timeout)
{
    char key;
    int i, rd_cnt, rd_max;
    rd_max = len - 1;
    for(rd_cnt = 0, i = 0; rd_cnt < rd_max; )
    {
        key = USART_GetCharacter(USART1);
        if((key == '\n') || (key == '\r'))
        {
            cmd[i++] = '\0';
            printf("\r\n");
            return rd_cnt;
        }
        else if(key == '\b')
        {
            if(i > 0)
            {
                i--;
                rd_cnt--;
                printf("\b \b");
            }
            
        }
        else if(key == '\0')
        {
            cmd[cmd_size] = '\0';
            printf("\r\n");
            return cmd_size;
        }
        else
        {
            cmd[i++] = key;
            rd_cnt++;
            printf("%c", key);
        }

    }
}

int get_args(char *s, char **argv)
{
    int args = 0;
    if(!s || *s == '\0')
    {
        return 0;
    }
    while(args < MAX_ARGS)
    {
        while((*s == ' ') || (*s == '\t'))
        {
            s++;
        }

        if(*s == '\0')
        {
            argv[args] = 0;
            return args;
        }
        argv[args++] = s;
        while(*s && (*s != ' ') && (*s != '\t'))
        {
            s++;
        }
        if(*s == '\0')
        {
            argv[args] = 0;
            return args;
        }
        *s++ ='\0';
    }
    return args;
}


bool do_print_help(int argc, char **argv)
{
    struct _CMD_TBL *cptr;

    if(argc == 1)
    {
        printf("\nThe following command are supported : \n");
        printf("Help : Help for commands. \n");

        for(cptr = cmd_tbl; cptr->cmd; cptr++)
        {
            if(cptr->help_more)
            {
                printf(cptr->help_more);
            }
        }
        printf("\n\n");
    }
    else
    {
        printf("\n\t Unknow command : %s\n", argv[0]);
    }

    return true;
}

bool do_test(struct _CMD_TBL *cptr, int argc, char **argv)
{
    printf("\nThis is test\n");
    return true;
}

