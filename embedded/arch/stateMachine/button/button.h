// https://kienltb.wordpress.com/2015/05/22/state-machine-va-ung-dung-trong-lap-trinh-nhung/

/********************************************************************************
Product: MSP430 FrameWork
Module: Button
Author: 5/18/2015, by KIENLTB
Description: Framework for button
********************************************************************************/
#ifndef __BUTTON__
#define __BUTTON__
/*-----------------------------------------------------------------------------*/
/* Header inclusions */
/*-----------------------------------------------------------------------------*/
#include "io.h"
/*-----------------------------------------------------------------------------*/
/* Data type definitions */
/*-----------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------
Lưu ý, do ngôn ngữ C không hỗ trợ hướng đối tượng nên các
phương thức sẽ được khai báo bằng các con trỏ hàm. Như ở ví dụ trên,
SYSTEMCALLBACK là một macro định nghĩa con trỏ hàm sau:
-------------------------------------------------------------------------------*/
#define SYSTEMCALLBACK VOID (*fnCallback) (*void);

/*-----------------------------------------------------------------------------
Bước đầu tiên là định nghĩa các trạng thái của hệ thống. Dựa vào hình trên,
ta định nghĩa ra các trạng thái tương ứng như sau:
-----------------------------------------------------------------------------*/
typedef enum tagSTATE
{
    IDLE,
    WAIT_BUTTON_UP,
    WAIT_PRESS_TIMEOUT,
    WAIT_CLICK_TIMEOUT,
    WAIT_DCLICK_TIMEOUT
}state;
/*-----------------------------------------------------------------------------
Đối với Button, ta tiếp cận theo hướng hướng đối tượng.
Nếu coi Button như một đối tượng thì nó bao gồm các 
thuộc tính và phương thức như sau:
-----------------------------------------------------------------------------*/
typedef struct tagButton
{
    WORD 	nTick;			// Current tick of button.
    WORD 	gpioPin;		// GPIO PIN connect witch button.
    BOOL 	enable;			//
    BYTE	state;			//
    SYSTEMCALLBACK  fnCallbackIDLE;
    SYSTEMCALLBACK  fnCallbackClick;
    SYSTEMCALLBACK  fnCallbackDoubleClick;
    SYSTEMCALLBACK  fnCallbackHold;
} BUTTON, *PBUTTON;

/*-----------------------------------------------------------------------------*/
/* Constant definitions  */
/*-----------------------------------------------------------------------------*/
#define MAX_BUTTON_COUNT    10      // can handle max 10 button, can adjust to meet requirement
#define CLICK_TICK          200	    // 200ms
#define DOUBLE_CLICK_TICK   200	    // 200ms
#define HOLD_TICK           500     // 500ms
/*-----------------------------------------------------------------------------*/
/* Macro definitions  */
/*-----------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------*/
/* Global variables  */
/*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
Để xử lý được nhiều button, ta sẽ định nghĩa ra một mảng chứa các con trỏ hàm,
mỗi phần tử trong hàm này sẽ trỏ đến một đối tượng Button.
-----------------------------------------------------------------------------*/
// Array store pointer to button
INTERNAL PBUTTON g_pButtons[MAX_BUTTON_COUNT] = {{NULL}};

/*-----------------------------------------------------------------------------
Khi muốn sử dụng button, ta chỉ việc định nghĩa Button và
gán vào một vị trí trong mảng trên. Mỗi vòng lặp,
hệ thống sẽ thực hiện quét các phần tử trong mảng và lần lượt xác định
trạng thái các button và gọi hàm callback tương ứng.
-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------*/
/* Function prototypes  */
/*-----------------------------------------------------------------------------*/

/*
    initialization Button and regist callback function to handle event
*/
VOID ButtonInit(PBUTTON button, WORD GPIO_PIN, SYSTEMCALLBACK onIDLE, SYSTEMCALLBACK onClick, SYSTEMCALLBACK onDoubleClick, SYSTEMCALLBACK onHold);

/*
    Enable Button, regist to array g_pButtons[]and start listion event, recall while button cancel;
*/
BOOL ButtonStart(PBUTTON pBtnRegister);

/*
    Detroy Button, delete from g_pButtons[].
*/
VOID ButtonCancel(BUTTON btnCancel);

/*
Quet mang g_pButtons[] va check cac button da dang ky. Xu ly button .
*/
VOID ButtonProcessEvent(VOID);

#endif // __BUTTON__
