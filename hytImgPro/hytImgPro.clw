; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMainFrame
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "hytImgPro.h"
LastPage=0

ClassCount=8
Class1=CHytImgProApp
Class2=CHytImgProDoc
Class3=CHytImgProView
Class4=CMainFrame

ResourceCount=4
Resource1=IDD_ABOUTBOX
Class5=CAboutDlg
Class6=CSrcImageView
Resource2=IDD_DIALOG_GRAY_STRE
Class7=CDlgGrayStre
Resource3=IDR_MAINFRAME
Class8=CDlgPowerTrans
Resource4=IDD_DIALOG_POWER_TRANS

[CLS:CHytImgProApp]
Type=0
HeaderFile=hytImgPro.h
ImplementationFile=hytImgPro.cpp
Filter=N
LastObject=CHytImgProApp

[CLS:CHytImgProDoc]
Type=0
HeaderFile=hytImgProDoc.h
ImplementationFile=hytImgProDoc.cpp
Filter=N
LastObject=CHytImgProDoc
BaseClass=CDocument
VirtualFilter=DC

[CLS:CHytImgProView]
Type=0
HeaderFile=hytImgProView.h
ImplementationFile=hytImgProView.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC
LastObject=CHytImgProView


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
BaseClass=CFrameWnd
VirtualFilter=fWC
LastObject=ID_MENU_AVER_FILTER




[CLS:CAboutDlg]
Type=0
HeaderFile=hytImgPro.cpp
ImplementationFile=hytImgPro.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_CUT
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_VIEW_TOOLBAR
Command15=ID_VIEW_STATUS_BAR
Command16=ID_APP_ABOUT
Command17=ID_MENU_CONVERT_GRAY
Command18=ID_MENU_OPPOSITE
Command19=ID_MENU_GRAY_STRECTHING
Command20=ID_MENU_POWER_TRANS
Command21=ID_MENU_HISTOGRAM_PRO
Command22=ID_MENU_AVER_FILTER
Command23=ID_MENU_MIDDLE_FILTER
Command24=ID_MENU_LAPLACE
CommandCount=24

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[TB:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_BUTTON_RESET
Command9=ID_APP_ABOUT
CommandCount=9

[CLS:CSrcImageView]
Type=0
HeaderFile=SrcImageView.h
ImplementationFile=SrcImageView.cpp
BaseClass=CView
Filter=C
LastObject=CSrcImageView

[DLG:IDD_DIALOG_GRAY_STRE]
Type=1
Class=CDlgGrayStre
ControlCount=12
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342177294
Control4=IDC_STATIC,button,1342177287
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_EDIT_GRAY_STRE_R1,edit,1350631552
Control10=IDC_EDIT_GRAY_STRE_S1,edit,1350631552
Control11=IDC_EDIT_GRAY_STRE_R2,edit,1350631552
Control12=IDC_EDIT_GRAY_STRE_S2,edit,1350631552

[CLS:CDlgGrayStre]
Type=0
HeaderFile=DlgGrayStre.h
ImplementationFile=DlgGrayStre.cpp
BaseClass=CDialog
Filter=D
LastObject=IDOK
VirtualFilter=dWC

[DLG:IDD_DIALOG_POWER_TRANS]
Type=1
Class=CDlgPowerTrans
ControlCount=9
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342177294
Control5=IDC_STATIC,button,1342177287
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_EDIT_C,edit,1350631552
Control9=IDC_EDIT_R,edit,1350631552

[CLS:CDlgPowerTrans]
Type=0
HeaderFile=DlgPowerTrans.h
ImplementationFile=DlgPowerTrans.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CDlgPowerTrans

