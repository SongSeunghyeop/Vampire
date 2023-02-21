#include "Myapplication.h"
#include "mySceneManager.h"
#include "Time.h"
#include "myInput.h"

namespace ya 
{
	myApplication::myApplication()
		: mhwnd(NULL), mhdc(NULL)
	{

	}
	myApplication::~myApplication()
	{
		mySceneManager::Release();
	}
	void myApplication::Initialize(HWND hwnd)
	{
		this->mhwnd = hwnd; // �ڵ�
		this->mhdc = GetDC(hwnd); // HDC : ��Ʈ�ʿ� �׷��ִ� ����

		RECT rect = { 0,0,1600,900 }; // ������ ��ü ũ���� �簢��
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false); // �ػ󵵸� �Է��ϸ�, �׿� �°� ����
		SetWindowPos(mhwnd, NULL, 100, 50, rect.right -  rect.left, rect.bottom -  rect.top, 0); // ������ ũ�� �� ��ġ ����
		ShowWindow(hwnd, true); // ������ �ػ� ������ ���� �Լ�(Ÿ��Ʋ��, �׵θ�,�޴��� ���� ������ �ػ��̹Ƿ�, ������ �ʿ�)
		//������ ��ü ���� ��� �簢��

		backBuffer = CreateCompatibleBitmap(mhdc, 1600, 900); // ������ hdc�� ȣȯ�Ǵ� ����� ��Ʈ���� ����(��Ʈ�� = ��ȭ��)
		backHdc = CreateCompatibleDC(mhdc); // ������ �ʴ� �޸𸮻��� HDC
		HBITMAP defaultBmp = (HBITMAP)SelectObject(backHdc, backBuffer); // ���� ���� �� HDC�� �� ���� ����
		DeleteObject(defaultBmp); // ������ ����Ʈ�� ���� // �غ� ��

		Time::Initialize();
		Input::Initialize();
		mySceneManager::Initialize();
	}
	void myApplication::Run()
	{
		Update(); 
		Render();
	}
	void myApplication::Update()
	{
		Time::Update();
		Input::Update();
		mySceneManager::Update();
	}
	void myApplication::Render()
	{
		Rectangle(backHdc, -1, -1, 1605, 905);
		Time::Render(backHdc);
		Input::Render(backHdc);
		mySceneManager::Render(backHdc); // ���δ� ����ۿ� ������

		//������� �׸� ����(������)�� ����
		BitBlt(mhdc, 0, 0, 1600, 900, backHdc, 0, 0, SRCCOPY); // ������ hdc�� �״�� ����
	}
}