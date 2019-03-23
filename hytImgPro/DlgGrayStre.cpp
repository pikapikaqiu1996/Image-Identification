// DlgGrayStre.cpp : implementation file
//

#include "stdafx.h"
#include "hytImgPro.h"
#include "DlgGrayStre.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgGrayStre dialog


CDlgGrayStre::CDlgGrayStre(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgGrayStre::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgGrayStre)
	m_GrayStreR1 = 0;
	m_GrayStreS2 = 0;
	m_GrayStreS1 = 0;
	m_GrayStreR2 = 0;
	//}}AFX_DATA_INIT
}


void CDlgGrayStre::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgGrayStre)
	DDX_Text(pDX, IDC_EDIT_GRAY_STRE_R1, m_GrayStreR1);
	DDV_MinMaxInt(pDX, m_GrayStreR1, 0, 255);
	DDX_Text(pDX, IDC_EDIT_GRAY_STRE_S2, m_GrayStreS2);
	DDV_MinMaxInt(pDX, m_GrayStreS2, 0, 255);
	DDX_Text(pDX, IDC_EDIT_GRAY_STRE_S1, m_GrayStreS1);
	DDV_MinMaxInt(pDX, m_GrayStreS1, 0, 255);
	DDX_Text(pDX, IDC_EDIT_GRAY_STRE_R2, m_GrayStreR2);
	DDV_MinMaxInt(pDX, m_GrayStreR2, 0, 255);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgGrayStre, CDialog)
	//{{AFX_MSG_MAP(CDlgGrayStre)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgGrayStre message handlers

BOOL CDlgGrayStre::OnInitDialog() 
{
	CDialog::OnInitDialog();
	m_GrayStreR1=80;
	m_GrayStreS1=30;
	m_GrayStreR2=160;
	m_GrayStreS2=200;
	
	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
