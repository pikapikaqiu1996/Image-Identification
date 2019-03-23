// hytImgPro.h : main header file for the HYTIMGPRO application
//

#if !defined(AFX_HYTIMGPRO_H__B17E97A7_8690_4BEC_AE88_6051BE795EA9__INCLUDED_)
#define AFX_HYTIMGPRO_H__B17E97A7_8690_4BEC_AE88_6051BE795EA9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CHytImgProApp:
// See hytImgPro.cpp for the implementation of this class
//

class CHytImgProApp : public CWinApp
{
public:
	CHytImgProApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHytImgProApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CHytImgProApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HYTIMGPRO_H__B17E97A7_8690_4BEC_AE88_6051BE795EA9__INCLUDED_)
