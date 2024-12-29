
// Glim_SWDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "Glim_SW.h"
#include "Glim_SWDlg.h"
#include "afxdialogex.h"

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


// CGlimSWDlg 대화 상자



CGlimSWDlg::CGlimSWDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_GLIM_SW_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGlimSWDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CGlimSWDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_Draw, &CGlimSWDlg::OnBnClickedBtnDraw)
	ON_BN_CLICKED(IDC_BTN_Action, &CGlimSWDlg::OnBnClickedBtnAction)
	ON_BN_CLICKED(IDC_BTN_OPEN, &CGlimSWDlg::OnBnClickedBtnOpen)
END_MESSAGE_MAP()


// CGlimSWDlg 메시지 처리기

BOOL CGlimSWDlg::OnInitDialog()
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

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	srand((unsigned int)time(NULL));

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CGlimSWDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CGlimSWDlg::OnPaint()
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
HCURSOR CGlimSWDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// Draw 버튼 클릭했을 시
void CGlimSWDlg::OnBnClickedBtnDraw()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	// 좌표 초기화
	CString strX1, strY1, strX2, strY2;

	GetDlgItemText(IDC_EDIT_START_X1, strX1);
	GetDlgItemText(IDC_EDIT_START_Y1, strY1);
	GetDlgItemText(IDC_EDIT_END_X2, strX2);
	GetDlgItemText(IDC_EDIT_END_Y2, strY2);

	SttX = _ttoi(strX1);
	SttY = _ttoi(strY1);
	EndX = _ttoi(strX2);
	EndY = _ttoi(strY2);

	int dX = EndX - SttX;
	int dY = EndY - SttY;
	Dist = dX * dX + dY * dY;

	int nWidth = 590;
	int nHeight = 280;
	int nBpp = 8;
	int nGray = 80;

	
	Radius = rand() % 50 + 1;

	if (!m_image.IsNull()) {
		m_image.Destroy();
	}

	// 배경 이미지 그리기
	m_image.Create(nWidth, -nHeight, nBpp);
	if (nBpp == 8) {
		static RGBQUAD rgb[256];
		for (int i = 0; i < 256; i++)
			rgb[i].rgbRed = rgb[i].rgbGreen = rgb[i].rgbBlue = i;
		m_image.SetColorTable(0, 256, rgb);
	}

	int nPitch = m_image.GetPitch();
	unsigned char* fm = (unsigned char*)m_image.GetBits();

	memset(fm, 0xff, nPitch * nHeight);

	drawCircle(fm, SttX, SttY, Radius, nGray);

	UpdateDisplay();

	// 이미지 저장
	//m_image.Save(_T("c:\\image\\save.bmp"));
}

void CGlimSWDlg::UpdateDisplay() {
	CClientDC dc(this);
	m_image.Draw(dc, 10, 100);
}

void CGlimSWDlg::moveCircle(int x, int y)
{
	int nGray = 80;                 
	int nWidth = m_image.GetWidth(); 
	int nHeight = m_image.GetHeight(); 
	int nPitch = m_image.GetPitch();
	unsigned char* fm = (unsigned char*)m_image.GetBits();

	memset(fm, 0xff, nPitch * nHeight);

	if (x < 0 || y < 0 || x >= nWidth || y >= nHeight) return;

	drawCircle(fm, x, y, Radius, nGray);

	UpdateDisplay();
}

void CGlimSWDlg::drawCircle(unsigned char* fm, int x, int y, int nRadius, int nGray)
{
	int nCenterX = x;               
	int nCenterY = y;              
	int nWidth = m_image.GetWidth();  
	int nHeight = m_image.GetHeight(); 
	int nPitch = m_image.GetPitch();  

	for (int j = nCenterY - nRadius; j <= nCenterY + nRadius; j++) {
		if (j < 0 || j >= nHeight) continue; 

		for (int i = nCenterX - nRadius; i <= nCenterX + nRadius; i++) {
			if (i < 0 || i >= nWidth) continue;

			
			if (isinCircle(i, j, nCenterX, nCenterY, nRadius)) {
				fm[j * nPitch + i] = nGray; 
			}
		}
	}

		/*for (int j = -y; j < y + nRadius * 2; j++) {
			for (int i = -x; i < x + nRadius * 2; i++) {
				if (isinCircle(i, j, nCenterX, nCenterY, nRadius))
					fm[j * nPitch + i] = nGray;
			}
		}*/
}

void CGlimSWDlg::OnBnClickedBtnAction()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int dx = EndX - SttX; 
	int dy = EndY - SttY; 

	int steps = max(abs(dx), abs(dy)); 
	if (steps == 0) return; 

	float stepX = (float)dx / steps; 
	float stepY = (float)dy / steps; 

	float currentX = SttX;
	float currentY = SttY;

	for (int i = 0; i <= steps; i++) {
		if (!validImgPos((int)currentX, (int)currentY)) break;

		moveCircle((int)currentX, (int)currentY);

		currentX += stepX;
		currentY += stepY;

		saveImage();
		Sleep(10);
	}
}

// 영역 밖으로 나가도 유지되도록 하는 함수
BOOL CGlimSWDlg::validImgPos(int x, int y) 
{
	int nWidth = m_image.GetWidth();
	int nHeight = m_image.GetHeight();

	// 영역 생성
	CRect rect(0, 0, nWidth, nHeight);

	// 포인트가 이 안에 들어가는지 안들어가지는 확인
	// CPoint 형태로 변환해야함
	return rect.PtInRect(CPoint(x, y));
}

bool CGlimSWDlg::isinCircle(int i, int j, int nCenterX, int nCenterY, int nRadius)
{
	bool bRet = false;

	double dX = i - nCenterX;
	double dY = j - nCenterY;
	double dDist = dX * dX + dY * dY;

	if (dDist < nRadius * nRadius) {
		bRet = true;
	}

	return bRet;
}

// 이미지 저장 함수
void CGlimSWDlg::saveImage() {
	SYSTEMTIME currentTime;
	GetLocalTime(&currentTime);

	CString filePath;
	filePath.Format(_T("c:\\image\\save_%04d%02d%02d_%02d%02d%02d_%03d.bmp"),
		currentTime.wYear, currentTime.wMonth, currentTime.wDay,
		currentTime.wHour, currentTime.wMinute, currentTime.wSecond,
		currentTime.wMilliseconds);

	m_image.Save(filePath);
}

void CGlimSWDlg::OnBnClickedBtnOpen()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	CFileDialog dlg(TRUE, _T("bmp"), NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		_T("Image Files (*.bmp;*.jpg;*.png)|*.bmp;*.jpg;*.png|All Files (*.*)|*.*||"));

	if (dlg.DoModal() == IDOK) {
		CString filePath = dlg.GetPathName();

		if (!m_image.IsNull()) {
			m_image.Destroy(); 
		}

		UpdateDisplay();

		CPoint center = findCircleCenter();

		int offsetX = 10; 
		int offsetY = 100; 
		center.x += offsetX;
		center.y += offsetY;

		HDC hdc = GetDC()->m_hDC;
		HPEN hPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		HGDIOBJ oldPen = SelectObject(hdc, hPen);

		MoveToEx(hdc, center.x - 5, center.y - 5, NULL);
		LineTo(hdc, center.x + 5, center.y + 5);
		MoveToEx(hdc, center.x + 5, center.y - 5, NULL);
		LineTo(hdc, center.x - 5, center.y + 5);

		CString coords;
		coords.Format(_T("(%d, %d)"), center.x - offsetX, center.y - offsetY);
		SetTextColor(hdc, RGB(255, 0, 0));
		TextOut(hdc, center.x + 10, center.y, coords, coords.GetLength());

		SelectObject(hdc, oldPen);
		DeleteObject(hPen);
	}
}

// 무게 중심 
CPoint CGlimSWDlg::findCircleCenter()
{
	int nWidth = m_image.GetWidth();   
	int nHeight = m_image.GetHeight(); 
	int nPitch = m_image.GetPitch();  
	unsigned char* fm = (unsigned char*)m_image.GetBits();

	int nGray = 80; 

	long long sumX = 0;
	long long sumY = 0; 
	int count = 0;     

	for (int y = 0; y < nHeight; y++) {
		for (int x = 0; x < nWidth; x++) {
			if (fm[y * nPitch + x] >= (nGray - 10) && fm[y * nPitch + x] <= (nGray + 10)) { 
				sumX += x;
				sumY += y;
				count++;  
			}
		}
	}

	int centerX = (int)(sumX / count);
	int centerY = (int)(sumY / count);

	return CPoint(centerX, centerY); 
}