
// PrjHomeWorkDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "PrjHomeWork.h"
#include "PrjHomeWorkDlg.h"
#include "afxdialogex.h"

#include "UserDef.h"

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
	GetDlgItem(IDC_GROUP)->GetWindowRect(&rect);
	m_nImagePosY = rect.Height() + 10;

	MoveWindow(0, 0, IMG_WIDTH+ 20, IMG_HEIGHT + 150);
}

/*======================================
원형이 그려질 Rect인지 아닌지 판단. 
======================================*/
BOOL CPrjHomeWorkDlg::isValidRect(CRect& rect, int nImagePosY)
{
	BOOL bRet = FALSE;

	if (rect.bottom <= IMG_HEIGHT + nImagePosY &&
		rect.top >= nImagePosY &&
		rect.right <= IMG_WIDTH &&
		rect.left >= 0)

		bRet = TRUE;

	return bRet;
}

/*======================================
설정된 반지름, 개수에 맞게 원형을 그리는 함수 
======================================*/
void CPrjHomeWorkDlg::UpdateDisplay()
{
	CClientDC dc(this);
	int nRadius;
	int nDrawCnt=0;
	int k, nTempX, nTempY;
	int nMakeCnt = 0;	

	//if (m_image)
	//	m_image.Draw(dc, 0, m_nImagePosY);

	UpdateData(TRUE);

	nRadius = m_Ctl_nRadius;
	nMakeCnt = m_Ctl_nMakeCnt;
	
	CPen myYellowPen(PS_SOLID, 3, RGB(255, 255, 0)); // 노란색 펜 생성
	CPen* pOldYellowPen = dc.SelectObject(&myYellowPen);
	CPen myBlackYPen(PS_SOLID, 3, RGB(0, 0, 0)); // 블랙 펜 생성	
	CPen* pOldBlackPen = dc.SelectObject(&myBlackYPen);

	while (nDrawCnt < nMakeCnt)
	{
		nTempX = rand() % IMG_WIDTH;
		nTempY = rand() % IMG_HEIGHT;
		nTempY += m_nImagePosY;
		
		CRect ValidRect(nTempX - nRadius, nTempY - nRadius, nTempX + nRadius, nTempY + nRadius);

		if (isValidRect(ValidRect, m_nImagePosY) )
		{
			dc.SelectObject(pOldBlackPen);
			dc.Ellipse(nTempX - nRadius, nTempY - nRadius, nTempX + nRadius, nTempY + nRadius);

			/* 중심에 "+" 기호, 다시 검은색으로 */
			dc.SelectObject(pOldYellowPen);
			dc.MoveTo(nTempX - (MARK_LEN-1), nTempY);
			dc.LineTo(nTempX + MARK_LEN, nTempY);
			dc.MoveTo(nTempX, nTempY - (MARK_LEN-1));
			dc.LineTo(nTempX, nTempY + MARK_LEN);

			nDrawCnt++;
		}		
	}	
}

/*======================================
종료 시 동적 할당된 메모리가 존재 할 경우나,
종료 설정이 필요할 경우 호출 되는 함수
======================================*/
BOOL CPrjHomeWorkDlg::ReleaseDlg()
{
	BOOL bRet = FALSE;

	if (IDYES == AfxMessageBox(_T("프로그램을 종료 하시겠습니까?"), MB_YESNO))
		bRet = TRUE;

	//필요할 경우 동적 생성 변수를 제거한다
	
	return bRet;
}

/*======================================
생성 버튼 클릭 시 
======================================*/
void CPrjHomeWorkDlg::OnBnClickedBtnMake()
{
	int nPitch = 0;
	unsigned char* fm = NULL;

	if (m_image == NULL)
	{
		m_image.Create(IMG_WIDTH, -IMG_HEIGHT, IMG_BIT);
		nPitch = m_image.GetPitch();
		fm = (unsigned char*)m_image.GetBits();
	}

	if (fm != NULL)
		memset(fm, 0x00, IMG_WIDTH * IMG_HEIGHT);

	UpdateDisplay();
}

/*======================================
종료 버튼 클릭 시
======================================*/
void CPrjHomeWorkDlg::OnBnClickedBtnClose()
{
	if (ReleaseDlg())
		PostMessage(WM_CLOSE, 0, 0);
}

