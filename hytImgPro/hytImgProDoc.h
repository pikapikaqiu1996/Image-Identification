// hytImgProDoc.h : interface of the CHytImgProDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_HYTIMGPRODOC_H__992AE78D_D593_4056_9E36_BAC9F4F88EE3__INCLUDED_)
#define AFX_HYTIMGPRODOC_H__992AE78D_D593_4056_9E36_BAC9F4F88EE3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "dibapi.h"

class CHytImgProDoc : public CDocument
{
protected: // create from serialization only
	CHytImgProDoc();
	DECLARE_DYNCREATE(CHytImgProDoc)

// Attributes
public:
	HDIB m_hDIB;
	HDIB m_hProDIB;
	HDIB m_hSrcDIB;
	CPalette* GetDocPalette() const
	{ return m_palDIB; }
	CSize GetDocSize() const
	{ return m_sizeDoc; }

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHytImgProDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	virtual BOOL OnSaveDocument(LPCTSTR lpszPathName);
	//}}AFX_VIRTUAL

// Implementation
public:
	DWORD m_FileSize;
	void InitDIBData();
	virtual ~CHytImgProDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	CPalette* m_palDIB;
	CSize m_sizeDoc;
	//{{AFX_MSG(CHytImgProDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HYTIMGPRODOC_H__992AE78D_D593_4056_9E36_BAC9F4F88EE3__INCLUDED_)
