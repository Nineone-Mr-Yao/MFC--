
// codeDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CcodeDlg �Ի���
class CcodeDlg : public CDialogEx
{
// ����
public:
	CcodeDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_CODE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	// һ�������ѡ��ı���
	CButton m_check1;
	// ��2������ĸ�ѡ�����
	CButton m_check2;
	// ��3������ĸ�ѡ�����
	CButton m_check3;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	void Icamera1();//��ʼ�����1,
	void Icamera2();//��ʼ�����2��
	void Icamera3();//��ʼ�����3��
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnClickedButton5();
};
