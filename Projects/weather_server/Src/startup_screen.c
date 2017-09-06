/*********************************************************************
*                                                                    *
*                SEGGER Microcontroller GmbH & Co. KG                *
*        Solutions for real time microcontroller applications        *
*                                                                    *
**********************************************************************
*                                                                    *
* C-file generated by:                                               *
*                                                                    *
*        GUI_Builder for emWin version 5.32                          *
*        Compiled Oct  8 2015, 11:59:02                              *
*        (c) 2015 Segger Microcontroller GmbH & Co. KG               *
*                                                                    *
**********************************************************************
*                                                                    *
*        Internet: www.segger.com  Support: support@segger.com       *
*                                                                    *
**********************************************************************
*/


#include "DIALOG.h"
#include <stdint.h>
#include "startup_screen.h"
#include "WindowDLG.h"
#include "main.h"


/*********************************************************************
*
*       Defines
*
**********************************************************************
*/
#define ID_WINDOW_0    (GUI_ID_USER + 0x00)
#define ID_TEXT_0    (GUI_ID_USER + 0x01)
#define ID_BUTTON_0    (GUI_ID_USER + 0x02)
#define ID_BUTTON_1    (GUI_ID_USER + 0x03)
#define ID_BUTTON_2    (GUI_ID_USER + 0x04)



/*********************************************************************
*
*       Static data
*
**********************************************************************
*/

 WM_HWIN startup_screen;
 uint8_t user_select;


/*********************************************************************
*
*       _aDialogCreate
*/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate_start[] = {
  { WINDOW_CreateIndirect, "Window", ID_WINDOW_0, 0, 0, 480, 272, 1, 0x0, 0 },
  { TEXT_CreateIndirect, "Text", ID_TEXT_0, 112, 47, 260, 73, 0, 0x64, 0 },
  { BUTTON_CreateIndirect, "USER 1", ID_BUTTON_0, 70, 138, 80, 80, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "USER 2", ID_BUTTON_1, 200, 138, 80, 80, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "USER 3", ID_BUTTON_2, 330, 138, 80, 80, 0, 0x0, 0 },
  // USER START (Optionally insert additional widgets)
  // USER END
};

/*********************************************************************
*
*       Static code
*
**********************************************************************
*/

/*********************************************************************
*
*       _cbDialog
*/
static void _cbDialog_start(WM_MESSAGE * pMsg) {
  WM_HWIN hItem;
  int     NCode;
  int     Id;
  // USER START (Optionally insert additional variables)
  // USER END

  switch (pMsg->MsgId) {
  case WM_INIT_DIALOG:
    //
    // Initialization of 'Window'
    //
    hItem = pMsg->hWin;
    WINDOW_SetBkColor(hItem, GUI_MAKE_COLOR(0x00F0000F));
    //
    // Initialization of 'Text'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_0);
    TEXT_SetText(hItem, "HomeControl");
    TEXT_SetFont(hItem, GUI_FONT_32_1);
    TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00FFFFFF));
    TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
    // USER START (Optionally insert additional code for further widget initialization)
    // USER END
    break;
  case WM_NOTIFY_PARENT:
    Id    = WM_GetId(pMsg->hWinSrc);
    NCode = pMsg->Data.v;
    switch(Id) {
    case ID_BUTTON_0: // Notifications sent by 'USER 1'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
    	  //check user permissions in database:
    	  //open txt file on SD card
    	  //search for user number
    	  //check accesses: set user_select based on granted accesses
    	  user_select = 1;

        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_BUTTON_1: // Notifications sent by 'USER 2'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
    	  user_select = 2;
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_BUTTON_2: // Notifications sent by 'USER 3'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
    	  user_select = 3;
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    // USER START (Optionally insert additional code for further Ids)
    // USER END
    }
    break;
  // USER START (Optionally insert additional message handling)
  // USER END
  default:
    WM_DefaultProc(pMsg);
    break;
  }
}

/*********************************************************************
*
*       Public code
*
**********************************************************************
*/
/*********************************************************************
*
*       CreateWindow
*/
WM_HWIN CreateWindow_start(void) {
  startup_screen = GUI_CreateDialogBox(_aDialogCreate_start, GUI_COUNTOF(_aDialogCreate_start), _cbDialog_start, WM_HBKWIN, 0, 0);
  return startup_screen;
}


/*************************** End of file ****************************/
