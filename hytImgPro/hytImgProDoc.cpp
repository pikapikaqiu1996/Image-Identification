// hytImgProDoc.cpp : implementation of the CHytImgProDoc class
//

#include "stdafx.h"
#include "hytImgPro.h"

#include "hytImgProDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHytImgProDoc

IMPLEMENT_DYNCREATE(CHytImgProDoc, CDocument)

BEGIN_MESSAGE_MAP(CHytImgProDoc, CDocument)
	//{{AFX_MSG_MAP(CHytImgProDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHytImgProDoc construction/destruction

CHytImgProDoc::CHytImgProDoc()
{
	m_hProDIB=NULL;
	m_hDIB = NULL;
	m_hSrcDIB=NULL;
	m_palDIB = NULL;
	m_sizeDoc = CSize(1,1);
}

CHytImgProDoc::~CHytImgProDoc()
{
	// 判断DIB对象是否存在
	if (m_hDIB != NULL)
	{
		// 清除DIB对象
		::GlobalFree((HGLOBAL) m_hDIB);
		m_hDIB=NULL;
	}

	if (m_hSrcDIB != NULL)
	{
		// 清除DIB对象
		::GlobalFree((HGLOBAL) m_hSrcDIB);
		m_hSrcDIB=NULL;
	}
	
	// 判断调色板是否存在
	if (m_palDIB != NULL)
	{
		// 清除调色板
		delete m_palDIB;
	}

	if (m_hProDIB != NULL)
	{
		// 清除DIB对象
		::GlobalFree((HGLOBAL) m_hProDIB);
		m_hProDIB=NULL;
	}
}

BOOL CHytImgProDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CHytImgProDoc serialization

void CHytImgProDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CHytImgProDoc diagnostics

#ifdef _DEBUG
void CHytImgProDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CHytImgProDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CHytImgProDoc commands

BOOL CHytImgProDoc::OnOpenDocument(LPCTSTR lpszPathName) 
{
	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;
	
	CFile file;
	CFileException fe;
	
	// 打开文件
	if (!file.Open(lpszPathName, CFile::modeRead | CFile::shareDenyWrite, &fe))
	{
		// 失败
		ReportSaveLoadException(lpszPathName, &fe,
			FALSE, AFX_IDP_FAILED_TO_OPEN_DOC);
		
		// 返回FALSE
		return FALSE;
	}
	
	DeleteContents();
	
	// 更改光标形状
	BeginWaitCursor();
	
	// 尝试调用ReadDIBFile()读取图像
	TRY
	{
		m_hDIB = ::ReadDIBFile(file);
	}
	CATCH (CFileException, eLoad)
	{
		// 读取失败
		file.Abort();
		
		// 恢复光标形状
		EndWaitCursor();
		
		// 报告失败
		ReportSaveLoadException(lpszPathName, eLoad,
			FALSE, AFX_IDP_FAILED_TO_OPEN_DOC);
		
		// 设置DIB为空
		m_hDIB = NULL;
		
		// 返回FALSE
		return FALSE;
	}
	END_CATCH

	// 初始化DIB
	InitDIBData();
	
	// 恢复光标形状
	EndWaitCursor();
	
	// 判断读取文件是否成功
	if (m_hDIB == NULL)
	{
		// 失败，可能非BMP格式
		CString strMsg;
		strMsg = "读取图像时出错！可能是不支持该类型的图像文件！";
		
		// 提示出错
		MessageBox(NULL, strMsg, "系统提示", MB_ICONINFORMATION | MB_OK);
		
		// 返回FALSE
		return FALSE;
	}
	
	// 设置文件名称
	SetPathName(lpszPathName);
	
	// 初始化文档是否被修改标记为FALSE
	SetModifiedFlag(FALSE);

	// 获取DIB（文件）长度（字节）
	m_FileSize= file.GetLength();
	
	//重新打开图像后释放指针内存
	if (m_hSrcDIB != NULL)
	{
		// 清除DIB对象
		::GlobalFree((HGLOBAL) m_hSrcDIB);
		m_hSrcDIB=NULL;
	}
	if (m_hProDIB != NULL)
	{
		// 清除DIB对象
		::GlobalFree((HGLOBAL) m_hProDIB);
		m_hProDIB=NULL;
	}

	if (m_hSrcDIB==NULL)
	{
		// 为DIB分配内存
		m_hSrcDIB = (HDIB) ::GlobalAlloc(GMEM_MOVEABLE | GMEM_ZEROINIT,m_FileSize);
		
		if (m_hSrcDIB == 0)
		{
			// 内存分配失败，返回NULL。
			MessageBox(NULL," CHytImgProDoc：内存分配失败！", "系统提示", MB_ICONINFORMATION | MB_OK);
		}
	}
	m_hSrcDIB=(HDIB)CopyHandle((HANDLE) m_hDIB);
	
	return TRUE;
}

void CHytImgProDoc::InitDIBData()
{
	// 初始化DIB对象
	
	// 判断调色板是否为空
	if (m_palDIB != NULL)
	{
		// 删除调色板对象
		delete m_palDIB;
		
		// 重置调色板为空
		m_palDIB = NULL;
	}
	
	// 如果DIB对象为空，直接返回
	if (m_hDIB == NULL)
	{
		// 返回
		return;
	}
	
	LPSTR lpDIB = (LPSTR) ::GlobalLock((HGLOBAL) m_hDIB);
	
	// 判断图像是否过大
	if (::DIBWidth(lpDIB) > INT_MAX ||::DIBHeight(lpDIB) > INT_MAX)
	{
		::GlobalUnlock((HGLOBAL) m_hDIB);
		
		// 释放DIB对象
		::GlobalFree((HGLOBAL) m_hDIB);
		
		// 设置DIB为空
		m_hDIB = NULL;
		
		CString strMsg;
		strMsg = "BMP图像太大！";
		
		// 提示用户
		MessageBox(NULL, strMsg, "系统提示", MB_ICONINFORMATION | MB_OK);
		
		// 返回
		return;
	}
	
	// 设置文档大小
	m_sizeDoc = CSize((int) ::DIBWidth(lpDIB), (int) ::DIBHeight(lpDIB));
	
	::GlobalUnlock((HGLOBAL) m_hDIB);
	
	// 创建新调色板
	m_palDIB = new CPalette;
	
	// 判断是否创建成功
	if (m_palDIB == NULL)
	{
		// 失败，可能是内存不足
		::GlobalFree((HGLOBAL) m_hDIB);
		
		// 设置DIB对象为空
		m_hDIB = NULL;
		
		// 返回
		return;
	}
	
	// 调用CreateDIBPalette来创建调色板
	if (::CreateDIBPalette(m_hDIB, m_palDIB) == NULL)
	{
		// 返回空，可能该DIB对象没有调色板
		
		// 删除
		delete m_palDIB;
		
		// 设置为空
		m_palDIB = NULL;
		
		// 返回
		return;
	}
}

BOOL CHytImgProDoc::OnSaveDocument(LPCTSTR lpszPathName) 
{
	CFile file;
	CFileException fe;
	
	// 打开文件
	if (!file.Open(lpszPathName, CFile::modeCreate |
		CFile::modeReadWrite | CFile::shareExclusive, &fe))
	{
		// 失败
		ReportSaveLoadException(lpszPathName, &fe,
			TRUE, AFX_IDP_INVALID_FILENAME);
		
		// 返回FALSE
		return FALSE;
	}
	
	// 尝试调用SaveDIB保存图像
	BOOL bSuccess = FALSE;
	TRY
	{
		
		// 更改光标形状
		BeginWaitCursor();
		
		// 尝试保存图像
		bSuccess = ::SaveDIB(m_hDIB, file);
		
		// 关闭文件
		file.Close();
	}
	CATCH (CException, eSave)
	{
		// 失败
		file.Abort();
		
		// 恢复光标形状
		EndWaitCursor();
		ReportSaveLoadException(lpszPathName, eSave,
			TRUE, AFX_IDP_FAILED_TO_SAVE_DOC);
		
		// 返回FALSE
		return FALSE;
	}
	END_CATCH
		
		// 恢复光标形状
		EndWaitCursor();
	
	// 重置胀标记为FALSE
	SetModifiedFlag(FALSE);
	
	if (!bSuccess)
	{
		// 保存失败，可能是其它格式的DIB，可以读取但是不能保存
		// 或者是SaveDIB函数有误
		
		CString strMsg;
		strMsg = "无法保存BMP图像！";
		
		// 提示出错
		MessageBox(NULL, strMsg, "系统提示", MB_ICONINFORMATION | MB_OK);
	}
	
	return bSuccess;
	
/*	return CDocument::OnSaveDocument(lpszPathName);*/
}




