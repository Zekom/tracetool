// Watches.cpp : implementation file
//

#include "stdafx.h"
#include "VS8_PPC2003Mfc_demo.h"
#include "Watches.h"


// Watches dialog

IMPLEMENT_DYNAMIC(Watches, CPropertyPage)

Watches::Watches()
	: CPropertyPage(Watches::IDD)
{

}

Watches::~Watches()
{
}

void Watches::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Watches, CPropertyPage)
    ON_BN_CLICKED(IDC_butWatch, &Watches::OnBnClickedbutwatch)
    ON_BN_CLICKED(IDC_butClearWatchWindow, &Watches::OnBnClickedbutclearwatchwindow)
    ON_BN_CLICKED(IDC_butDisplayWatchWindow, &Watches::OnBnClickedbutdisplaywatchwindow)
    ON_BN_CLICKED(IDC_butCreateWinWatch, &Watches::OnBnClickedbutcreatewinwatch)
    ON_BN_CLICKED(IDC_butWinWatchSend, &Watches::OnBnClickedbutwinwatchsend)
    ON_BN_CLICKED(IDC_butWinWatchClear, &Watches::OnBnClickedbutwinwatchclear)
    ON_BN_CLICKED(IDC_butWinWatchDisplay, &Watches::OnBnClickedbutwinwatchdisplay)
END_MESSAGE_MAP()


// Watches message handlers

//----------------------------------------------------------------------

// send watch to main watch window
void Watches::OnBnClickedbutwatch()
{
   TTrace::Watches()->Send ("test2" , TTrace::CreateTraceID()) ;
}

//----------------------------------------------------------------------

// clear main watch window
void Watches::OnBnClickedbutclearwatchwindow()
{
   TTrace::Watches()->ClearAll() ;         
}

//----------------------------------------------------------------------

// display main watch window
void Watches::OnBnClickedbutdisplaywatchwindow()
{
   TTrace::Watches()->DisplayWin() ;         
}

//----------------------------------------------------------------------

// create a new watch window
WinWatch * MyWinWatch  = NULL ;

void Watches::OnBnClickedbutcreatewinwatch()
{
   if (MyWinWatch == NULL)
      MyWinWatch = new WinWatch ("MyWinWatchID" , "My watches") ;
}

//----------------------------------------------------------------------

// send watch to the new wiwatch window
void Watches::OnBnClickedbutwinwatchsend()
{
   if (MyWinWatch == NULL)
      return ;

   SYSTEMTIME Time;
   char buffer [MAX_PATH] ;

   GetLocalTime(&Time);
   sprintf(buffer, "%02d:%02d:%02d:%03d", Time.wHour, Time.wMinute, Time.wSecond, Time.wMilliseconds); 

   MyWinWatch->Send ("Now" , buffer) ;
}

//----------------------------------------------------------------------

// clear the new watch window
void Watches::OnBnClickedbutwinwatchclear()
{
   if (MyWinWatch != NULL)
      MyWinWatch->ClearAll() ;         
}

//----------------------------------------------------------------------

// display the new watch window
void Watches::OnBnClickedbutwinwatchdisplay()
{
   if (MyWinWatch != NULL)
      MyWinWatch->DisplayWin() ;         
}