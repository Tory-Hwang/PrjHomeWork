// CImageView.cpp: 구현 파일
//

#include "pch.h"
#include "PrjHomeWork.h"
#include "CImageView.h"
#include "afxdialogex.h"
#include "UserDef.h"

// CImageView 대화 상자

IMPLEMENT_DYNAMIC(CImageView, CDialogEx)

CImageView::CImageView(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DLG_VIEW, pParent)
{

}

CImageView::~CImageView()
{
}

void CImageView::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CImageView, CDialogEx)
	ON_WM_PAINT()
	ON_WM_CREATE()
END_MESSAGE_MAP()


int CImageView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialogEx::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.	

	return 0;
}

void CImageView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 여기에 메시지 처리기 코드를 추가합니다.
					   // 그리기 메시지에 대해서는 CDialogEx::OnPaint()을(를) 호출하지 마십시오.
}

/*======================================
Dialog 사이즈 변경 
======================================*/
void CImageView::MoveDlgWindow()
{
	CRect rect;
	GetDlgItem(IDC_GROUP)->GetWindowRect(&rect);
	m_nImagePosY = rect.Height();
	MoveWindow(0, 0, IMG_WIDTH+ DLG_BLANK, IMG_HEIGHT + m_nImagePosY*2);
}

/*======================================
이미지 로드 
======================================*/
void CImageView::ImageLoad()
{
	CString strMsg;
	if (m_image != NULL)
	{
		m_image.Destroy();
	}
	strMsg.Format(_T("File Path: %s"), m_strFileImage);
	m_image.Load(m_strFileImage);
	GetDlgItem(IDC_FILE_NAME)->SetWindowText(strMsg);
}

/*======================================
Cimage Draw
======================================*/
void CImageView::UpdateDisplay()
{
	CClientDC dc(this);
	m_image.Draw(dc, 1, m_nImagePosY);
}

/*======================================
Image Save & Display
======================================*/
void CImageView::SaveDisplayFile(CImage * pImage)
{
	if (pImage != NULL)
		pImage->Save(m_strFileImage);

	MoveDlgWindow();
	ImageLoad();
	UpdateDisplay();	
}


