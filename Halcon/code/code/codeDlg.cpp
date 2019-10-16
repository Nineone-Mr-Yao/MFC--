
// codeDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "code.h"
#include "codeDlg.h"
#include "afxdialogex.h"
#include "HalconCpp.h"
using namespace Halcon;
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


//����Ĳ���
 Hobject  Image1,Image2,Image3;
 HTuple  AcqHandle1,AcqHandle2,AcqHandle3;
 HTuple  hv_WindowHandle1,hv_WindowHandle2,hv_WindowHandle3;
 //�����Ƶ���Ƿ����رյĸ����ж�
 bool camera1ontime=FALSE,camera2ontime=FALSE,camera3ontime=FALSE;
 //halcon���ڴ򿪺͹رյ� ��ʶ
 bool HalconW1=FALSE,HalconW2=FALSE,HalconW3=FALSE;

// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CcodeDlg �Ի���




CcodeDlg::CcodeDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CcodeDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CcodeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CHECK1, m_check1);
	DDX_Control(pDX, IDC_CHECK2, m_check2);
	DDX_Control(pDX, IDC_CHECK3, m_check3);
}

BEGIN_MESSAGE_MAP(CcodeDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CcodeDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CcodeDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CcodeDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CcodeDlg::OnBnClickedButton4)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON5, &CcodeDlg::OnBnClickedButton5)
END_MESSAGE_MAP()


// CcodeDlg ��Ϣ�������

BOOL CcodeDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������



	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CcodeDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CcodeDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CcodeDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//����ĳ�ʼ��
void CcodeDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
    //��һ������Ƿ�ѡ��
	if (1==m_check1.GetCheck())
    {
		Icamera1();

    } 
    else
    {
		MessageBox("1��ûѡ��");
    }
	//��2������Ƿ�ѡ��
	if (1==m_check2.GetCheck())
	{
		Icamera2();
	} 
	else
	{
		MessageBox("2��ûѡ��");
	}
	//��3 ������Ƿ�ѡ��
	if (1==m_check3.GetCheck())
	{
		Icamera3();
	} 
	else
	{
		MessageBox("3��ûѡ��");
	}

}

//��Ƶ���ĳ�ʼ��
void CcodeDlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//��һ������Ƿ�ѡ��
	if (1==m_check1.GetCheck())
	{		
		//��ʼ��Ƶ��
		camera1ontime=TRUE;//���������Ƶ����
		SetTimer(1,50,NULL);
	} 
	else
	{
		
	}

	//��2������Ƿ�ѡ��
	if (1==m_check2.GetCheck())
	{
		//��ʼ��Ƶ��
		camera2ontime=TRUE;//���������Ƶ����
		SetTimer(2,50,NULL);
	} 
	else
	{
		
	}
	//��3 ������Ƿ�ѡ��
	if (1==m_check3.GetCheck())
	{
		camera3ontime=TRUE;
		SetTimer(3,50,NULL);
	} 
	else
	{
		
	}
}
//��ʼ�����1�ţ�����ͼƬ�ؼ���HALCON����������ķ���
void CcodeDlg::Icamera1()
{
	CRect m_rect1;                              //��������
	GetDlgItem(IDC_STATIC_1)->GetWindowRect(&m_rect1);  //��ͼƬ�ռ�Ĵ�С���棬�ѵ�1��ͼƬ�ؼ���ID����
	HWND hwnd1= GetDlgItem(IDC_STATIC_1)->m_hWnd;   //�ѵ�һ��ͼ��IDC_IMAGE_STATIC���ľ����ʽת��
	//�������ʹ�ؼ�������Ĳɼ���Сƥ��

	//���������haclon�����ֵ���
	open_framegrabber("GigEVision", 0, 0, 0, 0, 0, 0, "progressive", -1, "default", 
		-1, "false", "default", "0021490171f7_DahengImaging_MER50014GC", 0, -1, &AcqHandle1);
	//

	grab_image_start(AcqHandle1, -1);
    grab_image_async(&Image1, AcqHandle1, -1);	
	//���ô���
	HalconW1=TRUE;//��ʶ�򿪴���1
	open_window(0,0,m_rect1.Width(),m_rect1.Height(),(long)hwnd1,"visible","",&hv_WindowHandle1);//��5��λ�ã�����ת����ʽ(long)hwnd1
	HDevWindowStack::Push(hv_WindowHandle1);	
	if (HDevWindowStack::IsOpen())
		disp_obj(Image1, hv_WindowHandle1);//��ʾͼƬ
	    set_draw(hv_WindowHandle1,"margin");
	    set_color(hv_WindowHandle1,"red");

	
}
//��ʼ�����2�ţ�����ͼƬ�ؼ���HALCON����������ķ���
//�������ֻҪ����open_framegrabber,����Ĳ���������HALCON�������ֱ�ӵõ�
void CcodeDlg::Icamera2()
{
	CRect m_rect2;                              //��������
	GetDlgItem(IDC_STATIC_2)->GetWindowRect(&m_rect2);  //��ͼƬ�ռ�Ĵ�С���棬�ѵ�1��ͼƬ�ؼ���ID����
	HWND hwnd2= GetDlgItem(IDC_STATIC_2)->m_hWnd;   //�ѵ�һ��ͼ��IDC_IMAGE_STATIC���ľ����ʽת��
	//�������ʹ�ؼ�������Ĳɼ���Сƥ��

	//open_framegrabber��HALCON��ȡ����
	//
	open_framegrabber("GigEVision", 0, 0, 0, 0, 0, 0, "progressive", -1, "default", 
		-1, "false", "default", "0021490171f7_DahengImaging_MER50014GC", 0, -1, &AcqHandle2);
	//
	grab_image_start(AcqHandle2, -1);
	grab_image_async(&Image2, AcqHandle2, -1);	
	//���ô���
	HalconW2=TRUE;//��ʶ�򿪴���2
	open_window(0,0,m_rect2.Width(),m_rect2.Height(),(long)hwnd2,"visible","",&hv_WindowHandle2);//��5��λ�ã�����ת����ʽ(long)hwnd1
	HDevWindowStack::Push(hv_WindowHandle2);	
	if (HDevWindowStack::IsOpen())
		disp_obj(Image2, hv_WindowHandle2);//��ʾͼƬ
	set_draw(hv_WindowHandle2,"margin");
	set_color(hv_WindowHandle2,"red");
}//��ʼ�����3�ţ�����ͼƬ�ؼ���HALCON����������ķ���
void CcodeDlg::Icamera3()
{
	CRect m_rect3;                              //��������
	GetDlgItem(IDC_STATIC_3)->GetWindowRect(&m_rect3);  //��ͼƬ�ռ�Ĵ�С���棬�ѵ�1��ͼƬ�ؼ���ID����
	HWND hwnd3= GetDlgItem(IDC_STATIC_3)->m_hWnd;   //�ѵ�һ��ͼ��IDC_IMAGE_STATIC���ľ����ʽת��
	//�������ʹ�ؼ�������Ĳɼ���Сƥ��
	open_framegrabber("GigEVision", 0, 0, 0, 0, 0, 0, "progressive", -1, "default", 
		-1, "false", "default", "0021490171f7_DahengImaging_MER50014GC", 0, -1, &AcqHandle3);
	//
	grab_image_start(AcqHandle3, -1);
	grab_image_async(&Image3, AcqHandle3, -1);	
	//���ô���
	HalconW3=TRUE;//��ʶ�򿪴���3
	open_window(0,0,m_rect3.Width(),m_rect3.Height(),(long)hwnd3,"visible","",&hv_WindowHandle3);//��5��λ�ã�����ת����ʽ(long)hwnd1
	HDevWindowStack::Push(hv_WindowHandle3);	
	if (HDevWindowStack::IsOpen())
		disp_obj(Image3, hv_WindowHandle3);//��ʾͼƬ
	set_draw(hv_WindowHandle3,"margin");
	set_color(hv_WindowHandle3,"red");
}

//�ر�ȫ�����
void CcodeDlg::OnBnClickedButton3()
{
	// 1�����
	if (camera1ontime==TRUE)
	{
		KillTimer(1);
		camera1ontime=FALSE;
	}
	if (HalconW1==TRUE)
	{
		if (HDevWindowStack::IsOpen())
		clear_window(hv_WindowHandle1);
	    close_window(hv_WindowHandle1);
		HalconW1=FALSE;
	}
	
	//2�����
	if (camera2ontime==TRUE)
	{
		KillTimer(2);
		camera2ontime=FALSE;
	}
	if(HalconW2==TRUE)
	{
		if (HDevWindowStack::IsOpen())
			clear_window(hv_WindowHandle2);
			close_window(hv_WindowHandle2);
		HalconW2=FALSE;
	}
	
	//3�����
	if (camera3ontime==TRUE)
	{
		KillTimer(3);
		camera3ontime=FALSE;
	}
	if(HalconW3==TRUE)
	{
		if (HDevWindowStack::IsOpen())
			clear_window(hv_WindowHandle3);
			close_window(hv_WindowHandle3);
		HalconW3=FALSE;
	}

    close_all_framegrabbers();//�ر�ȫ�����


}
//

void CcodeDlg::OnBnClickedButton4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	


}

//1,2,3������Ƶ����ʹ��
void CcodeDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	switch (nIDEvent)      
	{      
	case 1: 
		// һ�������Ƶ���Ĳɼ����ɼ�Ԥ����     
		grab_image_async(&Image1,AcqHandle1,-1);
		clear_window(hv_WindowHandle1);
		disp_obj(Image1,hv_WindowHandle1);
		break;      
	case 2:      
		// ����յ�IDΪ2�Ķ�ʱ������Ϣ����ú���      
		grab_image_async(&Image2,AcqHandle2,-1);
		clear_window(hv_WindowHandle2);
		disp_obj(Image2,hv_WindowHandle2);   
		break;     
	case 3:
		grab_image_async(&Image3,AcqHandle3,-1);
		clear_window(hv_WindowHandle3);
		disp_obj(Image3,hv_WindowHandle3);  
		break;
	default:      
		break;      
	}      
	CDialogEx::OnTimer(nIDEvent);
}

//����������գ��ɷ��ڴ�����
void CcodeDlg::OnBnClickedButton5()
{
	// 1�����
	if (1==m_check1.GetCheck())
	{
	    if (camera1ontime==TRUE)
	  {
		KillTimer(1);
		camera1ontime=FALSE;
	  }
	  grab_image(&Image1,AcqHandle1);
	  scale_image(Image1,&Image1,-1,255);
	  clear_window(hv_WindowHandle1);
	  disp_obj(Image1,hv_WindowHandle1);
	}
	//2�����
	if (1==m_check2.GetCheck())
	{
		if (camera2ontime==TRUE)
		{
			KillTimer(2);
			camera2ontime=FALSE;
		}
		grab_image(&Image2,AcqHandle2);
		scale_image(Image2,&Image2,-1,255);
		clear_window(hv_WindowHandle2);
		disp_obj(Image2,hv_WindowHandle2);
	}
	//3�����
	if (1==m_check3.GetCheck())
	{
		if (camera3ontime==TRUE)
		{
			KillTimer(3);
			camera3ontime=FALSE;
		}
		grab_image(&Image3,AcqHandle3);
		scale_image(Image3,&Image3,-1,255);
		clear_window(hv_WindowHandle3);
		disp_obj(Image3,hv_WindowHandle3);
	}
}
