#pragma once
#include <Windows.h>

class WinApp
{
public:	//メンバ関数
	//初期化
	void Initialize();
	//更新
	void Update();
	//getter
	HWND GetHend() const { return hwnd; }
	HINSTANCE GetHInstance() const { return w.hInstance; }

public:	//静的メンバ関数
	static LRESULT WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);

public:	//定数
	//ウィンドウ横幅
	static const int window_width = 1280;
	//ウィンドウ縦幅
	static const int window_height = 720;

private:
	//ウィンドウハンドル
	HWND hwnd = nullptr;
	//ウィンドウクラスの設定
	WNDCLASSEX w{};

};

