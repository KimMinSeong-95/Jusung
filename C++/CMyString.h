#pragma once

class CMyString
{
public:
	//���� �ɹ�
	 int m_nCount; // ��ü�� ������ ������
	//static void ResetCount();

	//////////////////////////////////
	//������ �����ε�
	CMyString();
	CMyString(CMyString& temp);//���� ������
	CMyString(const char *pszParam);
	~CMyString();
	
protected:
	// ���ڿ��� �����ϱ� ���� ���� �Ҵ��� �޸𸮸� ����Ű�� ������
	char* m_pszData;

	// ����� ���ڿ��� ����
	int m_nLength;

public:
	int SetString(const char* pszParam);

	// ��� �б⸸ �����ϹǷ� �޼��带 ���ȭ�Ѵ�.
	const char* GetString() const;

	void Release();
	
	/////////////////////////////////
	//������ �����ε�
	/*CMyString& operator=(const CMyString& rhs);
	CMyString& operator+(const CMyString& rhs);
	CMyString& operator-(const CMyString& rhs);*/
};