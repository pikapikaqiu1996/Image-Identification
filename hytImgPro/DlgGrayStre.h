#if !defined(AFX_DLGGRAYSTRE_H__06309509_07B9_4F88_8CB0_645D4A1E3D49__INCLUDED_)
#define AFX_DLGGRAYSTRE_H__06309509_07B9_4F88_8CB0_645D4A1E3D49__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgGrayStre.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgGrayStre dialog

class CDlgGrayStre : public CDialog
{
// Construction
public:
	CDlgGrayStre(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgGrayStre)
	enum { IDD = IDD_DIALOG_GRAY_STRE };
	int		m_GrayStreR1;
	int		m_GrayStreS2;
	int		m_GrayStreS1;
	int		m_GrayStreR2;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgGrayStre)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgGrayStre)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGGRAYSTRE_H__06309509_07B9_4F88_8CB0_645D4A1E3D49__INCLUDED_)
