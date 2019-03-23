#if !defined(AFX_SRCIMAGEVIEW_H__170E56DB_1FAD_4665_8E71_3C5999BB0029__INCLUDED_)
#define AFX_SRCIMAGEVIEW_H__170E56DB_1FAD_4665_8E71_3C5999BB0029__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SrcImageView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSrcImageView view

class CSrcImageView : public CView
{
protected:
	CSrcImageView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CSrcImageView)

// Attributes
public:
	CHytImgProDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSrcImageView)
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CSrcImageView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(CSrcImageView)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SRCIMAGEVIEW_H__170E56DB_1FAD_4665_8E71_3C5999BB0029__INCLUDED_)
