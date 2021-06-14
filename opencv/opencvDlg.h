
// opencvDlg.h: 头文件
//

#pragma once


// CopencvDlg 对话框
class CopencvDlg : public CDialogEx
{
// 构造
public:
	CopencvDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_OPENCV_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CMenu m_Menu;
	CString m_path;
	Mat src;
	Mat str,str_r, str1, str2, str3,str4;
	afx_msg void On32776();
	afx_msg void On32772();
	afx_msg void On32773();
	afx_msg void On32774();
	afx_msg void On32775();
	afx_msg void OnBnClickedButton1();
	void rotate_arbitrarily_angle(Mat& src, Mat& dst, float angle);
	Mat face2(Mat image);
	int h1;//四幅图的长宽
	int w1;
	int h2;
	int w2;
	int h3;
	int w3;
	int h4;
	int w4;
	afx_msg void OnBnClickedButton2();
	afx_msg void On32779();
	int mutex=0;
	int x1;//旋转度数
	int x2;
	int x3;
	afx_msg void OnBnClickedButton3();
	int zx1;//添加到第一幅图的坐标位置
	int zx2;
	int zx3;
	int zy1;
	int zy2;
	int zy3;
	afx_msg void OnBnClickedButton4();
	CString signal;
	int hh2;//后三幅图旋转后的长宽
	int ww2;
	int hh3;
	int ww3;
	int hh4;
	int ww4;
	afx_msg void On32781();
	afx_msg void On32782();
	afx_msg void On32777();
	afx_msg void On32778();
};
