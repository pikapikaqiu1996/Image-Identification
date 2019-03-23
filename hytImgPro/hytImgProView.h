// hytImgProView.h : interface of the CHytImgProView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_HYTIMGPROVIEW_H__DFAA2CF0_69C6_4DD9_81B0_202DC6DF7444__INCLUDED_)
#define AFX_HYTIMGPROVIEW_H__DFAA2CF0_69C6_4DD9_81B0_202DC6DF7444__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CHytImgProView : public CView
{
protected: // create from serialization only
	CHytImgProView();
	DECLARE_DYNCREATE(CHytImgProView)

// Attributes
public:
	CHytImgProDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHytImgProView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CHytImgProView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	void PixelSort(int a[]);
	LRESULT OnDoRealize(WPARAM wParam, LPARAM);
	//{{AFX_MSG(CHytImgProView)
	afx_msg void OnMenuConvertGray();
	afx_msg void OnButtonReset();
	afx_msg void OnMenuOpposite();
	afx_msg void OnMenuGrayStrecthing();
	afx_msg void OnMenuPowerTrans();
	afx_msg void OnMenuHistogramPro();
	afx_msg void OnMenuAverFilter();
	afx_msg void OnMenuMiddleFilter();
	afx_msg void OnMenuLaplace();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in hytImgProView.cpp
inline CHytImgProDoc* CHytImgProView::GetDocument()
   { return (CHytImgProDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HYTIMGPROVIEW_H__DFAA2CF0_69C6_4DD9_81B0_202DC6DF7444__INCLUDED_)
