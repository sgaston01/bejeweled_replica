; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CBmpProView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "BmpPro.h"
LastPage=0

ClassCount=10
Class1=CBmpProApp
Class2=CBmpProDoc
Class3=CBmpProView
Class4=CMainFrame

ResourceCount=6
Resource1=IDD_DIALOG2
Class5=CAboutDlg
Resource2=IDD_ABOUTBOX
Class6=Mydebug
Class7=InvalidDialog
Class8=Dialog
Resource3=IDR_MAINFRAME
Class9=InvalidClick
Resource4=IDD_DIALOG4
Class10=DialogQuit
Resource5=IDD_DIALOG3
Resource6=IDR_TOOLBAR1

[CLS:CBmpProApp]
Type=0
HeaderFile=BmpPro.h
ImplementationFile=BmpPro.cpp
Filter=N

[CLS:CBmpProDoc]
Type=0
HeaderFile=BmpProDoc.h
ImplementationFile=BmpProDoc.cpp
Filter=N
BaseClass=CDocument
VirtualFilter=DC
LastObject=CBmpProDoc

[CLS:CBmpProView]
Type=0
HeaderFile=BmpProView.h
ImplementationFile=BmpProView.cpp
Filter=C
LastObject=CBmpProView
BaseClass=CView
VirtualFilter=VWC


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
BaseClass=CFrameWnd
VirtualFilter=fWC
LastObject=ID_SQUARES




[CLS:CAboutDlg]
Type=0
HeaderFile=BmpPro.cpp
ImplementationFile=BmpPro.cpp
Filter=D

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
Command2=ID_FILE_NEWGAME
Command3=ID_APP_EXIT
Command4=ID_FILE_OPEN
Command5=ID_FILE_SAVE
Command6=ID_FILE_SAVE_AS
Command7=ID_FILE_MRU_FILE1
Command8=ID_APP_EXIT
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_APP_ABOUT
Command14=ID_PLAYBEJEWELED
Command15=ID_PlayEditMode
Command16=ID_RED_RUBY_GEM
Command17=ID_WHITEPEARL
Command18=ID_GREENGEM
Command19=ID_PURPLEGEM
Command20=ID_ORANGEGEM
Command21=ID_YELLOWGEM
Command22=ID_BLUEDIAMOND
Command23=ID_SQUARES
CommandCount=23

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_UNDO
Command5=ID_EDIT_CUT
Command6=ID_EDIT_COPY
Command7=ID_EDIT_PASTE
Command8=ID_EDIT_UNDO
Command9=ID_EDIT_CUT
Command10=ID_EDIT_COPY
Command11=ID_EDIT_PASTE
Command12=ID_NEXT_PANE
Command13=ID_PREV_PANE
CommandCount=13

[CLS:Mydebug]
Type=0
HeaderFile=Mydebug.h
ImplementationFile=Mydebug.cpp
BaseClass=CDialog
Filter=D
LastObject=ID_APP_ABOUT

[DLG:IDD_DIALOG2]
Type=1
Class=Dialog
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDC_STATIC,static,1342308352

[CLS:InvalidDialog]
Type=0
HeaderFile=InvalidDialog.h
ImplementationFile=InvalidDialog.cpp
BaseClass=CDialog
Filter=D
LastObject=ID_APP_ABOUT

[CLS:Dialog]
Type=0
HeaderFile=Dialog.h
ImplementationFile=Dialog.cpp
BaseClass=CDialog
Filter=D
LastObject=Dialog

[DLG:IDD_DIALOG3]
Type=1
Class=InvalidClick
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDC_STATIC,static,1342308352

[CLS:InvalidClick]
Type=0
HeaderFile=InvalidClick.h
ImplementationFile=InvalidClick.cpp
BaseClass=CDialog
Filter=D
LastObject=ID_APP_ABOUT

[DLG:IDD_DIALOG4]
Type=1
Class=DialogQuit
ControlCount=1
Control1=IDC_BUTTON1,button,1342242816

[CLS:DialogQuit]
Type=0
HeaderFile=DialogQuit.h
ImplementationFile=DialogQuit.cpp
BaseClass=CDialog
Filter=D
LastObject=DialogQuit

[TB:IDR_TOOLBAR1]
Type=1
Class=?
Command1=ID_BUTTON32819
Command2=ID_SQUARES
CommandCount=2

