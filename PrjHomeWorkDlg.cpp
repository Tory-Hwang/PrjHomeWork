
// PrjHomeWorkDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "PrjHomeWork.h"
#include "PrjHomeWorkDlg.h"
#include "afxdialogex.h"

#include "UserDef.h"

#include<iostream>
#include <math.h>    // for sqrt

using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CPrjHomeWorkDlg 대화 상자



CPrjHomeWorkDlg::CPrjHomeWorkDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PRJHOMEWORK_DIALOG, pParent)
	, m_Ctl_nRadius(0)
	, m_Ctl_nMakeCnt(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPrjHomeWorkDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_E_RADIUS, m_Ctl_nRadius);
	DDX_Text(pDX, IDC_E_MAKECNT, m_Ctl_nMakeCnt);
}

BEGIN_MESSAGE_MAP(CPrjHomeWorkDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_CLOSE, &CPrjHomeWorkDlg::OnBnClickedBtnClose)
	ON_BN_CLICKED(IDC_BTN_MAKE, &CPrjHomeWorkDlg::OnBnClickedBtnMake)
	ON_BN_CLICKED(IDC_BTN_SAVE, &CPrjHomeWorkDlg::OnBnClickedBtnSave)
END_MESSAGE_MAP()


// CPrjHomeWorkDlg 메시지 처리기

BOOL CPrjHomeWorkDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	/*======================================
	Dlg 초기화 함수 호출 
	======================================*/
	InitDlg();

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CPrjHomeWorkDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CPrjHomeWorkDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CPrjHomeWorkDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
/*======================================
프로그램 시작 시 초기화 시켜주는 함수 
======================================*/
void CPrjHomeWorkDlg::InitDlg()
{
	CRect rect;

	m_ImageViewer = NULL;

	/* Cimage Top 위치 */
	GetDlgItem(IDC_GROUP)->GetWindowRect(&rect);
	m_nImagePosY = rect.Height() ;

	/* 생성 결과 초기는 0*/
	GetDlgItem(IDC_STATIC_CNT)->SetWindowText(_T("0"));

	/* Dlg 사이즈 변경 */
	MoveWindow(0, 0, IMG_WIDTH+ DLG_BLANK, IMG_HEIGHT + (m_nImagePosY *2));

	/*Cimage초기화*/
	InitImageCls();
}
/*======================================
생성된 원의 개수를 표시한다.
======================================*/
void CPrjHomeWorkDlg::CountDisplay(int Cnt)
{
	CString strMsg;
	strMsg.Format(_T("%d"), Cnt);
	GetDlgItem(IDC_STATIC_CNT)->SetWindowText(strMsg);
}
/*======================================
원형이 그려질 Rect인지 아닌지 판단. 
======================================*/
BOOL CPrjHomeWorkDlg::isValidRect(CRect& rect)
{
	BOOL bRet = FALSE;

	if (rect.bottom <= IMG_HEIGHT  &&
		rect.top >= 0 &&
		rect.right <= IMG_WIDTH &&
		rect.left >= 0)

		bRet = TRUE;

	return bRet;
}
/*=====================================
m_image  버퍼를 이용한 원 그리기
======================================*/
void CPrjHomeWorkDlg::drawCircle(int x, int y, int nRadius)
{
	int width = m_image.GetWidth();
	int height = m_image.GetHeight();
	
	/* m_image 전체 영역을 제외한 원에 대해서만 처리 */
	for (int i = max(0, y - nRadius); i < min(height, y + nRadius); ++i)
	{
		for (int j = max(0, x - nRadius); j < min(width, x + nRadius); ++j)
		{
			int dx = x - j;
			int dy = y - i;

			/*유클리안 거리 */
			double distance = sqrt(dx * dx + dy * dy);

			/* 반지름보다 작을때 */
			if (distance < nRadius)
			{
				/* RGB 영역 찾기*/
				BYTE* pPixel = (BYTE*)m_image.GetPixelAddress(j, i);

				/*반지름에서 테두리를 뺀값이 유클리안보다 작을 때  */
				if (distance > (nRadius - int(BORDER_LEN)) ) // 테두리 영역 ( 노란색 )
				{
					/*  B                   G               R           */
					pPixel[0] = 0x00; pPixel[1] = 0xFF; pPixel[2] = 0xFF; 
				}
				else // 채우기 영역 ( 흰색 )
				{
					/*  B                   G               R           */
					pPixel[0] = 0xFF; pPixel[1] = 0xFF; pPixel[2] = 0xFF;
				}
			}

			// 가운데 "+"마크 처리 
			if ((i == y && abs(j - x) < MARK_LEN) || (j == x && abs(i - y) < MARK_LEN))
			{
				/* RGB 영역 찾기*/
				BYTE* pPixel = (BYTE*)m_image.GetPixelAddress(j, i);
				/*  B                   G               R           */
				pPixel[0] = 0x00; pPixel[1] = 0x00; pPixel[2] = 0x00;				
			}
		}
	}
}

/*=====================================
m_image  원을 생성한다.
======================================*/
void CPrjHomeWorkDlg::MakeCircle()
{	
	int nRadius;
	int nDrawCnt = 0;
	int nTempX, nTempY;
	int nMakeCnt = 0;

	UpdateData(TRUE);

	nRadius = m_Ctl_nRadius;
	nMakeCnt = m_Ctl_nMakeCnt;
	
	/* 생성 개수만큼 만들어 질때까지 랜덤하게 반복*/
	while (nDrawCnt < nMakeCnt)
	{
		nTempX = rand() % IMG_WIDTH;
		nTempY = rand() % IMG_HEIGHT;

		                /*==    L                  T                 R                 B */
		CRect ValidRect(nTempX - nRadius, nTempY - nRadius, nTempX + nRadius, nTempY + nRadius);

		/* Cimage 테두리 영역에는 그리지 않는다.*/
		if (isValidRect(ValidRect))
		{
			drawCircle(nTempX, nTempY, nRadius);
			nDrawCnt++;
		}
	}
	CountDisplay(nDrawCnt);
	UpdateDisplay();
}
/*======================================
m_Image 생성
======================================*/
BOOL CPrjHomeWorkDlg::InitImageCls()
{
	BOOL bRet = TRUE;
	int nPitch = 0;
	unsigned char* fm = NULL;
	int nBit = BIT_24;

	/* 기존에 존재하면 Destroy*/
	if (m_image != NULL)
		m_image.Destroy();

	/* 테두리 노란색 처리를 위해 24bit로 처리한다. */
	m_image.Create(IMG_WIDTH, -IMG_HEIGHT, nBit);

	if (nBit == BIT_8)
	{
		static RGBQUAD rgb[256];
		for (int i = 0; i < 256; i++)
			rgb[i].rgbRed = rgb[i].rgbGreen = rgb[i].rgbBlue = (BYTE)i;
		m_image.SetColorTable(0, 256, rgb);

		nPitch = m_image.GetPitch();
	}

	fm = (unsigned char*)m_image.GetBits();

	if (fm != NULL)
		memset(fm, 0x00, IMG_WIDTH * IMG_HEIGHT);
	else
		bRet = FALSE;
	
	UpdateDisplay();
	
	return bRet;
}
/*======================================
m_Image 갱신
======================================*/
void CPrjHomeWorkDlg::UpdateDisplay()
{
	CClientDC dc(this);	

	if (m_image)
		m_image.Draw(dc, 0, m_nImagePosY);
}
/*======================================
종료 시 동적 할당된 메모리가 존재 할 경우나,
종료 설정이 필요할 경우 호출 되는 함수
======================================*/
BOOL CPrjHomeWorkDlg::ReleaseDlg()
{
	BOOL bRet = FALSE;
	CString strMsg;

	strMsg.LoadStringW(IDS_STR_CLOSE);
	if (IDYES == AfxMessageBox(strMsg), MB_YESNO)
	{
		bRet = TRUE;
		/*필요할 경우 동적 생성 변수를 제거하는 로직  */
		if (m_ImageViewer != NULL)
		{
			delete m_ImageViewer;
			m_ImageViewer = NULL;
		}
	}

	return bRet;
}
/*======================================
생성 버튼 클릭 시 
======================================*/
void CPrjHomeWorkDlg::OnBnClickedBtnMake()
{
	CString strMsg;
	UpdateData(TRUE);

	int nRadius = m_Ctl_nRadius;
	int nMakeCnt = m_Ctl_nMakeCnt;

	if (nRadius < 1 || nMakeCnt < 1 ) {
		strMsg.LoadStringW(IDS_STR_MIN_NUM);
		AfxMessageBox(strMsg);
		return;
	}

	if (nRadius > MAX_RADIUS) {
		strMsg.LoadStringW(IDS_STR_MAX_RADIUS);
		AfxMessageBox(strMsg);
		return;
	}

	if (nMakeCnt > MAX_MAKE_CNT) {
		strMsg.LoadStringW(IDS_STR_MAX_NUM);
		AfxMessageBox(strMsg);
		return;
	}
	
	if (InitImageCls())
	{		
		MakeCircle();
	}	
}
/*======================================
종료 버튼 클릭 시
======================================*/
void CPrjHomeWorkDlg::OnBnClickedBtnClose()
{
	if (ReleaseDlg())
		PostMessage(WM_CLOSE, 0, 0);
}
/*======================================
Cimage 저장 및 표출
======================================*/
void CPrjHomeWorkDlg::OnBnClickedBtnSave()
{
	if (m_ImageViewer == NULL)	{
		m_ImageViewer = new CImageView;	
		m_ImageViewer->Create(IDD_DLG_VIEW);
	}

	if (m_ImageViewer != NULL  )
	{
		m_ImageViewer->ShowWindow(SW_SHOW);
		m_ImageViewer->SaveDisplayFile(&m_image);
	}	
}
