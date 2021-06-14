
// opencvDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "opencv.h"
#include "opencvDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CopencvDlg 对话框



CopencvDlg::CopencvDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_OPENCV_DIALOG, pParent)
	, h1(0)
	, w1(0)
	, h2(0)
	, w2(0)
	, h3(0)
	, w3(0)
	, h4(0)
	, w4(0)
	, x1(-10)
	, x2(-15)
	, x3(-10)
	, zx1(350)
	, zx2(450)
	, zx3(550)
	, zy1(256)
	, zy2(148)
	, zy3(237)
	, signal(_T(""))
	, hh2(0)
	, ww2(0)
	, hh3(0)
	, ww3(0)
	, hh4(0)
	, ww4(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CopencvDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, ID_WINDOW_ARRANGE, h1);
	DDX_Text(pDX, IDCLOSE, w1);
	DDX_Text(pDX, IDC_EDIT2, h2);
	DDX_Text(pDX, IDC_EDIT3, w2);
	DDX_Text(pDX, IDC_EDIT4, h3);
	DDX_Text(pDX, IDC_EDIT5, w3);
	DDX_Text(pDX, IDC_EDIT6, h4);
	DDX_Text(pDX, IDC_EDIT7, w4);
	DDX_Text(pDX, IDC_EDIT8, x1);
	DDX_Text(pDX, IDC_EDIT9, x2);
	DDX_Text(pDX, IDC_EDIT10, x3);
	DDX_Text(pDX, IDC_EDIT12, zx1);
	DDX_Text(pDX, IDC_EDIT14, zx2);
	DDX_Text(pDX, IDC_EDIT16, zx3);
	DDX_Text(pDX, IDC_EDIT13, zy1);
	DDX_Text(pDX, IDC_EDIT15, zy2);
	DDX_Text(pDX, IDC_EDIT17, zy3);
	DDX_Text(pDX, IDC_EDIT18, signal);
	DDX_Text(pDX, IDC_EDIT11, hh2);
	DDX_Text(pDX, IDC_EDIT19, ww2);
	DDX_Text(pDX, IDC_EDIT20, hh3);
	DDX_Text(pDX, IDC_EDIT21, ww3);
	DDX_Text(pDX, IDC_EDIT22, hh4);
	DDX_Text(pDX, IDC_EDIT23, ww4);
}

BEGIN_MESSAGE_MAP(CopencvDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_32776, &CopencvDlg::On32776)
	ON_COMMAND(ID_32772, &CopencvDlg::On32772)
	ON_COMMAND(ID_32773, &CopencvDlg::On32773)
	ON_COMMAND(ID_32774, &CopencvDlg::On32774)
	ON_COMMAND(ID_32775, &CopencvDlg::On32775)
	ON_COMMAND(ID_32779, &CopencvDlg::On32779)
	ON_BN_CLICKED(IDC_BUTTON1, &CopencvDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CopencvDlg::OnBnClickedButton2)
	
	ON_BN_CLICKED(IDC_BUTTON3, &CopencvDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CopencvDlg::OnBnClickedButton4)
	ON_COMMAND(ID_32781, &CopencvDlg::On32781)
	ON_COMMAND(ID_32782, &CopencvDlg::On32782)
	ON_COMMAND(ID_32777, &CopencvDlg::On32777)
	ON_COMMAND(ID_32778, &CopencvDlg::On32778)
END_MESSAGE_MAP()


// CopencvDlg 消息处理程序

BOOL CopencvDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。
	m_Menu.LoadMenu(IDR_MENU1);
	SetMenu(&m_Menu);
	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	namedWindow("view", WINDOW_AUTOSIZE);
	HWND hWnd = (HWND)cvGetWindowHandle("view");
	HWND hparent = ::GetParent(hWnd);
	::SetParent(hWnd, GetDlgItem(IDC_STATIC)->m_hWnd);
	::ShowWindow(hparent, SW_HIDE);

	namedWindow("view1", WINDOW_AUTOSIZE);
	HWND hWnd1 = (HWND)cvGetWindowHandle("view1");
	HWND hparent1 = ::GetParent(hWnd1);
	::SetParent(hWnd1, GetDlgItem(ID_WIZNEXT)->m_hWnd);
	::ShowWindow(hparent1, SW_HIDE);
	
	namedWindow("view2", WINDOW_AUTOSIZE);
	HWND hWnd2 = (HWND)cvGetWindowHandle("view2");
	HWND hparent2 = ::GetParent(hWnd2);
	::SetParent(hWnd2, GetDlgItem(ID_WIZFINISH)->m_hWnd);
	::ShowWindow(hparent2, SW_HIDE);

	namedWindow("view3", WINDOW_AUTOSIZE);
	HWND hWnd3 = (HWND)cvGetWindowHandle("view3");
	HWND hparent3 = ::GetParent(hWnd3);
	::SetParent(hWnd3, GetDlgItem(ID_WIZBACK)->m_hWnd);
	::ShowWindow(hparent3, SW_HIDE);

	namedWindow("view4", WINDOW_AUTOSIZE);
	HWND hWnd4 = (HWND)cvGetWindowHandle("view4");
	HWND hparent4 = ::GetParent(hWnd4);
	::SetParent(hWnd4, GetDlgItem(ID_WINDOW_TILE_VERT)->m_hWnd);
	::ShowWindow(hparent4, SW_HIDE);

	
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CopencvDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CopencvDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CopencvDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}




void CopencvDlg::On32776()//退出
{
	// TODO: 在此添加命令处理程序代码
	exit(0);
}


void CopencvDlg::On32772()//打开图片1
{
	// TODO: 在此添加命令处理程序代码
	//设置打开图片路径的窗口
	if (mutex == 0)
	{
		CFileDialog dlg(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, NULL);
		dlg.m_ofn.lpstrTitle = _T("打开图像文件");
		dlg.m_ofn.lpstrInitialDir = "C:\\";
		dlg.m_ofn.lpstrFilter = "All Files (*.*) \0*.*\0jpg (*.jpg)\0*.jpg\0bmp (*.bmp)\0*.bmp\0png (*.png)\0*.png\0\0";
		//判断是否获得图片
		if (dlg.DoModal() != IDOK)
			return;
		m_path = dlg.GetPathName();//获取图片绝对路径
		//多字节字符集下的CString转char*
		src = imread((LPSTR)(LPCSTR)m_path);
		str_r = imread((LPSTR)(LPCSTR)m_path);
	}
	else {
		src = imread("1.1.png");
		str_r = imread("1.1.png");
	}
	h1 = src.cols;
	w1 = src.rows;
	UpdateData(FALSE);

	//显示图片
	Mat img;//保存缩放后的图片
	CRect rect;

	GetDlgItem(IDC_STATIC)->GetClientRect(&rect);//获取图像显示区
	double a, b, s;
	/*a =  src.cols/rect.Width();
	b = src.rows/rect.Height();*/
	a = (double)rect.Width() / (double)src.cols;
	b = (double)rect.Height() / (double)src.rows;
	if (a >= b)s = b;
	else s = a;
	//resize(src, img, Size(rect.Width(), rect.Height()), 0, 0);
	//resize(src, img, Size(rect.Width(), rect.Height()), s, s);

	resize(src, img, Size(), s, s, INTER_LINEAR);
	imshow("view", img);
	
}


void CopencvDlg::On32773()//打开图片二
{
	// TODO: 在此添加命令处理程序代码
	if (mutex == 0)
	{
		CFileDialog dlg(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, NULL);
		dlg.m_ofn.lpstrTitle = _T("打开图像文件");
		dlg.m_ofn.lpstrInitialDir = "C:\\";
		dlg.m_ofn.lpstrFilter = "png (*.png)\0*.png\0\0";
		//判断是否获得图片
		if (dlg.DoModal() != IDOK)
			return;
		m_path = dlg.GetPathName();//获取图片绝对路径
		//多字节字符集下的CString转char*
		src = imread((LPSTR)(LPCSTR)m_path);
	}

	else src = imread("1.2.png");
	h2 = src.cols;
	w2 = src.rows;
	UpdateData(FALSE);
	str1 = src;
	//显示图片
	Mat img;//保存缩放后的图片
	CRect rect;

	GetDlgItem(ID_WIZNEXT)->GetClientRect(&rect);//获取图像显示区
	double a, b, s;
	/*a =  src.cols/rect.Width();
	b = src.rows/rect.Height();*/
	a = (double)rect.Width() / (double)src.cols;
	b = (double)rect.Height() / (double)src.rows;
	if (a >= b)s = b;
	else s = a;
	//resize(src, img, Size(rect.Width(), rect.Height()), 0, 0);
	//resize(src, img, Size(rect.Width(), rect.Height()), s, s);

	resize(src, img, Size(), s, s, INTER_LINEAR);
	imshow("view1", img);
	
}


void CopencvDlg::On32774()//打开图片三
{
	// TODO: 在此添加命令处理程序代码
	if (mutex == 0)
	{
		CFileDialog dlg(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, NULL);
		dlg.m_ofn.lpstrTitle = _T("打开图像文件");
		dlg.m_ofn.lpstrInitialDir = "C:\\";
		dlg.m_ofn.lpstrFilter = "png (*.png)\0*.png\0\0";
		//判断是否获得图片
		if (dlg.DoModal() != IDOK)
			return;
		m_path = dlg.GetPathName();//获取图片绝对路径
		//多字节字符集下的CString转char*
		src = imread((LPSTR)(LPCSTR)m_path);
	}

	else src = imread("1.3.png");
	h3 = src.cols;
	w3 = src.rows;
	UpdateData(FALSE);
	str2 = src;
	//显示图片
	Mat img;//保存缩放后的图片
	CRect rect;

	GetDlgItem(ID_WIZFINISH)->GetClientRect(&rect);//获取图像显示区
	double a, b, s;
	/*a =  src.cols/rect.Width();
	b = src.rows/rect.Height();*/
	a = (double)rect.Width() / (double)src.cols;
	b = (double)rect.Height() / (double)src.rows;
	if (a >= b)s = b;
	else s = a;
	//resize(src, img, Size(rect.Width(), rect.Height()), 0, 0);
	//resize(src, img, Size(rect.Width(), rect.Height()), s, s);

	resize(src, img, Size(), s, s, INTER_LINEAR);
	imshow("view2", img);
	
}


void CopencvDlg::On32775()//打开图片4
{
	// TODO: 在此添加命令处理程序代码
	if (mutex == 0)
	{
		CFileDialog dlg(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, NULL);
		dlg.m_ofn.lpstrTitle = _T("打开图像文件");
		dlg.m_ofn.lpstrInitialDir = "C:\\";
		dlg.m_ofn.lpstrFilter = "png (*.png)\0*.png\0\0";
		//判断是否获得图片
		if (dlg.DoModal() != IDOK)
			return;
		m_path = dlg.GetPathName();//获取图片绝对路径
		//多字节字符集下的CString转char*
		src = imread((LPSTR)(LPCSTR)m_path);
	}

	else src = imread("1.4.png");
	h4 = src.cols;
	w4 = src.rows;
	UpdateData(FALSE);
	//显示图片
	Mat img;//保存缩放后的图片
	CRect rect;

	GetDlgItem(ID_WIZBACK)->GetClientRect(&rect);//获取图像显示区
	double a, b, s;
	/*a =  src.cols/rect.Width();
	b = src.rows/rect.Height();*/
	a = (double)rect.Width() / (double)src.cols;
	b = (double)rect.Height() / (double)src.rows;
	if (a >= b)s = b;
	else s = a;
	//resize(src, img, Size(rect.Width(), rect.Height()), 0, 0);
	//resize(src, img, Size(rect.Width(), rect.Height()), s, s);

	resize(src, img, Size(), s, s, INTER_LINEAR);
	imshow("view3", img);
	str3 = src;
}


void CopencvDlg::OnBnClickedButton1()//合成
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(FALSE);
	if (!str_r.data|| !str1.data|| !str2.data|| !str3.data)
	{
		MessageBox("必须四幅图像，请读入图像再来！","警告");
		return;
	}
	Mat dst1, dst2, dst3, dst1_1, dst2_2, dst3_3;
	str = str_r.clone();;
	UpdateData(TRUE);
	rotate_arbitrarily_angle(str1, dst1, x1);
	rotate_arbitrarily_angle(str2, dst2, x2);
	rotate_arbitrarily_angle(str3, dst3, x3);

	cvtColor(dst1, dst1_1, COLOR_BGR2GRAY);
	cvtColor(dst2, dst2_2, COLOR_BGR2GRAY);
	cvtColor(dst3, dst3_3, COLOR_BGR2GRAY);

	if (str.cols - dst1.cols >= zx1 && str.rows - dst1.rows >= zy1 && str.cols - dst2.cols >= zx2 && str.rows - dst2.rows >= zy2 && str.cols - dst3.cols >= zx3 && str.rows - dst3.rows >= zy3)
	{ 
	Mat imageROI;
	imageROI = str(Rect(zx1, zy1, dst1.cols, dst1.rows));
	dst1.copyTo(imageROI, dst1_1);
	imageROI = str(Rect(zx2, zy2, dst2.cols, dst2.rows));
	dst2.copyTo(imageROI, dst2_2);
	imageROI = str(Rect(zx3, zy3, dst3.cols, dst3.rows));
	dst3.copyTo(imageROI, dst3_3);
	str4 = str;
	//显示图片
	Mat img;//保存缩放后的图片
	CRect rect;

	GetDlgItem(ID_WINDOW_TILE_VERT)->GetClientRect(&rect);//获取图像显示区
	double a, b, s;
	/*a =  src.cols/rect.Width();
	b = src.rows/rect.Height();*/
	a = (double)rect.Width() / (double)str.cols;
	b = (double)rect.Height() / (double)str.rows;
	if (a >= b)s = b;
	else s = a;
	//resize(str, img, Size(rect.Width(), rect.Height()), 0, 0);
	resize(str, img, Size(), s, s, INTER_LINEAR);
	
	imshow("view4", img);}
	else MessageBox("请计算下是否可以和成再来", "警告");

}
void CopencvDlg::rotate_arbitrarily_angle(Mat& src, Mat& dst, float angle)
{
	float radian = (float)(angle / 180.0 * CV_PI);

	int maxBorder = (int)(max(src.cols, src.rows) * 1.414); //即为sqrt(2)*max
	int dx = (maxBorder - src.cols) / 2;
	int dy = (maxBorder - src.rows) / 2;
	copyMakeBorder(src, dst, dy, dy, dx, dx, BORDER_CONSTANT);

	//旋转
	Point2f center((float)(dst.cols / 2), (float)(dst.rows / 2));
	Mat affine_matrix = getRotationMatrix2D(center, angle, 1.0);//求得旋转矩阵
	warpAffine(dst, dst, affine_matrix, dst.size());

	//计算图像旋转之后包含图像的最大的矩形
	float sinVal = abs(sin(radian));
	float cosVal = abs(cos(radian));
	Size targetSize((int)(src.cols * cosVal + src.rows * sinVal),
		(int)(src.cols * sinVal + src.rows * cosVal));

	//剪掉多余边框
	int x = (dst.cols - targetSize.width) / 2;
	int y = (dst.rows - targetSize.height) / 2;
	Rect rect(x, y, targetSize.width, targetSize.height);
	dst = Mat(dst, rect);
}
Mat CopencvDlg::face2(Mat image) {
	Mat dst;
	int value1 = 3, value2 = 1;
	int dx = value1 * 5; // 双边滤波参数之一
	double fc = value1 * 12.5; // 双边滤波参数之一
	double p = 0.1f; // 透明度
	Mat temp1, temp2, temp3, temp4;

	bilateralFilter(image, temp1, dx, fc, fc);
	Mat temp22;
	subtract(temp1, image, temp22);

	add(temp22, Scalar(128, 128, 128, 128), temp2);
	GaussianBlur(temp2, temp3, Size(2 * value2 - 1, 2 * value2 - 1), 0, 0);
	Mat temp44;
	temp3.convertTo(temp44, temp3.type(), 2, -255);
	add(image, temp44, temp4);
	addWeighted(image, p, temp4, 1 - p, 0.0, dst);

	add(dst, Scalar(10, 10, 10), dst);
	return dst;

}

void CopencvDlg::OnBnClickedButton2()//美白
{
	// TODO: 在此添加控件通知处理程序代码
	//显示图片
	if (!str4.data)
	{
		MessageBox("还没合成，咋美白！", "警告");
		return;
	}
	Mat img;//保存缩放后的图片
	CRect rect;

	GetDlgItem(ID_WINDOW_TILE_VERT)->GetClientRect(&rect);//获取图像显示区
	double a, b, s;
	/*a =  src.cols/rect.Width();
	b = src.rows/rect.Height();*/
	a = (double)rect.Width() / (double)str.cols;
	b = (double)rect.Height() / (double)str.rows;
	if (a >= b)s = b;
	else s = a;
	//resize(face2(str4), img, Size(rect.Width(), rect.Height()), 0, 0);
	resize(face2(str4), img, Size(), s, s, INTER_LINEAR);
	imshow("view4", img);
}


void CopencvDlg::On32779()//读全部图像
{
	// TODO: 在此添加命令处理程序代码
	mutex = 1;
	On32772();
	On32773();
	On32774();
	On32775();
	mutex = 0;
}


void CopencvDlg::OnBnClickedButton3()//旋转后的长宽
{
	// TODO: 在此添加控件通知处理程序代码
	if (!str1.data || !str2.data || !str3.data)
	{
		MessageBox("二三四图像不全，请读入完图像再来！", "警告");
		return;
	}
	Mat dst1, dst2, dst3, dst1_1, dst2_2, dst3_3;
	str = str_r.clone();;
	UpdateData(TRUE);
	rotate_arbitrarily_angle(str1, dst1, x1);
	rotate_arbitrarily_angle(str2, dst2, x2);
	rotate_arbitrarily_angle(str3, dst3, x3);

	hh2 = dst1.cols; ww2 = dst1.rows;
	hh3 = dst2.cols; ww3 = dst2.rows;
	hh4 = dst3.cols; ww4 = dst3.rows;
	UpdateData(FALSE);
	
}


void CopencvDlg::OnBnClickedButton4()//计算是否可以合成
{
	// TODO: 在此添加控件通知处理程序代码
	if (!str1.data || !str2.data || !str3.data)
	{
		MessageBox("二三四图像不全，请读入完图像再来！", "警告");
		return;
	}
	Mat dst1, dst2, dst3, dst1_1, dst2_2, dst3_3;
	str = str_r.clone();;
	UpdateData(TRUE);
	rotate_arbitrarily_angle(str1, dst1, x1);
	rotate_arbitrarily_angle(str2, dst2, x2);
	rotate_arbitrarily_angle(str3, dst3, x3);
	if (str.cols - dst1.cols >= zx1 && str.rows - dst1.rows >= zy1 && str.cols - dst2.cols >= zx2 && str.rows - dst2.rows >= zy2 && str.cols - dst3.cols >= zx3 && str.rows - dst3.rows >= zy3)
		signal = "可以合成";
	else signal = "不能合成";
	UpdateData(FALSE);
}


void CopencvDlg::On32781()//合成保存
{
	// TODO: 在此添加命令处理程序代码
	if (!str4.data)
	{
		MessageBox("请合成图像后再来！", "警告");
		return;
	}
	TCHAR szFilter[] = _T("JPG图片(*.jpg)|*.jpg|BMP图片(*.bmp)|*.bmp|PNG图片(*.png)|*.png|JPEG图片(*.jpeg)|*.jpeg|DIB图片(*dib)|*.dib|PBM图片(*.pbm)|*.pbm||");
	// 构造保存文件对话框   
	CFileDialog fileDlg(FALSE, _T("jpg"), _T("New"), OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, szFilter, this);
	CString strFilePath;
	// 显示保存文件对话框   
	if (IDOK != fileDlg.DoModal())
	{
		return;
	}
	strFilePath = fileDlg.GetPathName();
	vector<int> compression_params;
	imwrite((LPSTR)(LPCSTR)strFilePath, str4);
}


void CopencvDlg::On32782()//美白保存
{
	// TODO: 在此添加命令处理程序代码
	if (!face2(str4).data)
	{
		MessageBox("请美白图像后再来！", "警告");
		return;
	}
	TCHAR szFilter[] = _T("JPG图片(*.jpg)|*.jpg|BMP图片(*.bmp)|*.bmp|PNG图片(*.png)|*.png|JPEG图片(*.jpeg)|*.jpeg|DIB图片(*dib)|*.dib|PBM图片(*.pbm)|*.pbm||");
	// 构造保存文件对话框   
	CFileDialog fileDlg(FALSE, _T("jpg"), _T("New"), OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, szFilter, this);
	CString strFilePath;
	// 显示保存文件对话框   
	if (IDOK != fileDlg.DoModal())
	{
		return;
		

	}
	strFilePath = fileDlg.GetPathName();
	vector<int> compression_params;
	imwrite((LPSTR)(LPCSTR)strFilePath, face2(str4), compression_params);

}


void CopencvDlg::On32777()//关于
{
	// TODO: 在此添加命令处理程序代码
	CAboutDlg td;
	td.DoModal();
}


void CopencvDlg::On32778()//介绍说明
{
	// TODO: 在此添加命令处理程序代码
	MessageBox("该软件是把后三幅图旋转叠加到第一幅图上，对图片的宽窄要求极高，第一幅图片的宽高必须比后三幅大，不然后三幅没法叠加到第一幅上边，其他的倒没啥说，点错了会有提示，其实选图选错了后边的按钮也用不了，容错都包含了。对了，最重要的一点就是图片是缩放显示的，实际大小看长宽。------最后一点，自定义旋转读书和叠加位置要先点击上边两个按钮，求出旋转位置和叠加位置是否合理。打开图像中的打开默认图像在.exe图像中无法使用，在项目中可以使用，如果测试默认，请用我上传的四幅图","注意事项");
}
