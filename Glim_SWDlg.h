
// Glim_SWDlg.h: 헤더 파일
//

#pragma once


// CGlimSWDlg 대화 상자
class CGlimSWDlg : public CDialogEx
{
private:
	CImage m_image;
	BOOL validImgPos(int x, int y);
	int Radius, SttX, SttY, EndX, EndY, Dist;

// 생성입니다.
public:
	CGlimSWDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_GLIM_SW_DIALOG };
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
	afx_msg void OnBnClickedBtnDraw();
	void UpdateDisplay();
	void moveCircle(int x, int y);
	void drawCircle(unsigned char* fm, int i, int j, int nRadius, int nGray);
	bool isinCircle(int i, int j, int nCenterX, int nCenterY, int nRadius);
	void saveImage();
	CPoint findCircleCenter();
	afx_msg void OnBnClickedBtnAction();
	afx_msg void OnBnClickedBtnOpen();
};
