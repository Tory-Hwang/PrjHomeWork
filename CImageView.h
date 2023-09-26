#pragma once


// CImageView 대화 상자

class CImageView : public CDialogEx
{

	DECLARE_DYNAMIC(CImageView)
/*======================================
User Function
======================================*/
	CImage m_image;
	int m_nImagePosY;
	CString m_strFileImage = _T(".\\save.bmp");

	void SaveDisplayFile(CImage* pImage);
	void UpdateDisplay();
	void ImageLoad();
	void MoveDlgWindow();


public:
	CImageView(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CImageView();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_VIEW };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};
