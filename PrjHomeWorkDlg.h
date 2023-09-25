
// PrjHomeWorkDlg.h: 헤더 파일
//

#pragma once


// CPrjHomeWorkDlg 대화 상자
class CPrjHomeWorkDlg : public CDialogEx
{

/*======================================
User Function
======================================*/
protected:

private:
	CImage m_image;
	int m_nImagePosY = 0;	

	void InitDlg();
	BOOL InitImageCls();
	void MakeCircle();	

	void UpdateDisplay();
	BOOL ReleaseDlg();
	BOOL isValidRect(CRect & rect);
	void drawCircle(int x, int y, int nRadius);
	void CountDisplay(int Cnt);

public:

// 생성입니다.
public:
	CPrjHomeWorkDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PRJHOMEWORK_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	int m_Ctl_nRadius;
	int m_Ctl_nMakeCnt;
	afx_msg void OnBnClickedBtnClose();
	afx_msg void OnBnClickedBtnMake();
	afx_msg void OnBnClickedBtnSave();
};
