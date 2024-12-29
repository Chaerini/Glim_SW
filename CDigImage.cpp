// CDigImage.cpp: 구현 파일
//

#include "pch.h"
#include "Glim_SW.h"
#include "afxdialogex.h"
#include "CDigImage.h"


// CDigImage 대화 상자

IMPLEMENT_DYNAMIC(CDigImage, CDialogEx)

CDigImage::CDigImage(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CDigImage, pParent)
{

}

CDigImage::~CDigImage()
{
}

void CDigImage::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDigImage, CDialogEx)
END_MESSAGE_MAP()


// CDigImage 메시지 처리기
