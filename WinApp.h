#pragma once
class WinApp
{
public://�ÓI�����o�֐�
	static LRESULT WindoeProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);


public://�����o�֐�
	//������
	void Initialize();
	//�X�V
	void Update();
};

