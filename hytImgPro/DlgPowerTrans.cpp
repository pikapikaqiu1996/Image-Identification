// DlgPowerTrans.cpp : implementation file
//

#include "stdafx.h"
#include "hytImgPro.h"
#include "DlgPowerTrans.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgPowerTrans dialog


CDlgPowerTrans::CDlgPowerTrans(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgPowerTrans::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgPowerTrans)
	m_EditC = 0.0f;
	m_EditR = 0.0f;
	//}}AFX_DATA_INIT
}


void CDlgPowerTrans::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgPowerTrans)
	DDX_Text(pDX, IDC_EDIT_C, m_EditC);
	DDX_Text(pDX, IDC_EDIT_R, m_EditR);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgPowerTrans, CDialog)
	//{{AFX_MSG_MAP(CDlgPowerTrans)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgPowerTrans message handlers

BOOL CDlgPowerTrans::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	m_EditC=1;
	m_EditR=0.4;
	UpdateData(FALSE);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

