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
		this->mhdc = GetDC(hwnd); // HDC : ��Ʈ�ʿ� �׷��ִ� ���� // getDC : ���� �����찡 �����ִ� ��Ʈ���� �Ҵ�޴� DC�� �������� ��� ��

		RECT rect = { 0,0,1600,900 }; // ������ ��ü ũ���� �簢��
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false); // �ػ󵵸� �Է��ϸ�, �׿� �°� ����
		SetWindowPos(mhwnd, NULL, 20, 20, (rect.right -  rect.left) - 200, (rect.bottom -  rect.top) - 200, 0); // ������ ũ�� �� ��ġ ����
		ShowWindow(hwnd, true); // ������ �ػ� ������ ���� �Լ�(Ÿ��Ʋ��, �׵θ�,�޴��� ���� ������ �ػ��̹Ƿ�, ������ �ʿ�)
		//������ ��ü ���� ��� �簢��

		backBuffer = CreateCompatibleBitmap(mhdc, 1600, 900); // ������ hdc�� ȣȯ�Ǵ� ����� ��Ʈ���� ����(��Ʈ�� = ��ȭ��)
		backHdc = CreateCompatibleDC(mhdc); // ���� hdc�� ȣȯ�Ǹ� ������ �ʴ� �޸𸮻��� HDC�� ����
		HBITMAP defaultBmp = (HBITMAP)SelectObject(backHdc, backBuffer); // ����ۿ� ��Ʈ�� ����, �� ���ۿ� hdc�� ���� ��Ʈ�ʰ� ��ü
		DeleteObject(defaultBmp); // ������ ��Ʈ�� ���� // �غ� ��

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
		Rectangle(backHdc, -1, -1, 1601, 901); // ��� ���
		Time::Render(backHdc);
		Input::Render(backHdc);
		mySceneManager::Render(backHdc); // ���δ� ����ۿ� ����

		//������� �׸� ����(������)�� ���� ( ����� ȭ����� ��ü�� ��� ���ԵǾ ���簡 �Ǵ� ���̹Ƿ� �������� �ʴ´� 
		BitBlt(mhdc, 0, 0, 1600, 900, backHdc, 0, 0, SRCCOPY); // ������ hdc�� �״�� ����
	}
}