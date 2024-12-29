#pragma once
#include "afxdialogex.h"


// CDigImage 대화 상자

class CDigImage : public CDialogEx
{
	DECLARE_DYNAMIC(CDigImage)

public:
	CDigImage(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CDigImage();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CDigImage };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};
