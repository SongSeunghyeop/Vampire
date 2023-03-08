#include "myApplication.h"
#include "mySceneManager.h"
#include "myCollisionManager.h"
#include "Time.h"
#include "myInput.h"

namespace my 
{
	Application::Application()
		: mhwnd(NULL), mhdc(NULL)
	{

	}
	Application::~Application()
	{
		SceneManager::Release();
	}
	void Application::Initialize(HWND hwnd)
	{
		this->mhwnd = hwnd; // �ڵ�
		this->mhdc = GetDC(hwnd); // HDC : ��Ʈ�ʿ� �׷��ִ� ���� 
		                                              // getDC : ���� �����찡 �����ִ� ��Ʈ���� �Ҵ�޴� DC�� �������� ��� ��
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false); // �ػ󵵸� �Է��ϸ�, �׿� �°� ����
		GetClientRect(mhwnd, &rect);
		WindowPos.x = rect.right - rect.left;
		WindowPos.y = rect.bottom - rect.top;

		SetWindowPos(mhwnd, NULL, 0,0, (WindowPos.x), (WindowPos.y), 0); // ������ ó�� ���� �� ũ�� �� ��ġ ����
		ShowWindow(hwnd, true); // ������ �ػ� ������ ���� �Լ�(Ÿ��Ʋ��, �׵θ�,�޴��� ���� ������ �ػ��̹Ƿ�, ������ �ʿ�)
		//������ ��ü ���� ��� �簢��

		backBuffer = CreateCompatibleBitmap(mhdc, WindowPos.x, WindowPos.y); // ������ hdc�� ȣȯ�Ǵ� ����� ��Ʈ���� ����(��Ʈ�� = ��ȭ��)
		backHdc = CreateCompatibleDC(mhdc); // ���� hdc�� ȣȯ�Ǹ� ������ �ʴ� �޸𸮻��� HDC�� ����
		HBITMAP defaultBmp = (HBITMAP)SelectObject(backHdc, backBuffer); // ����ۿ� ��Ʈ�� ����, �� ���ۿ� hdc�� ���� ��Ʈ�ʰ� ��ü
		DeleteObject(defaultBmp); // ������ ��Ʈ�� ���� // �غ� ��

		Time::Initialize();
		Input::Initialize();
		SceneManager::Initialize();
	}
	void Application::Run()
	{
		Update(); 
		Render();
	}
	void Application::Update()
	{
		GetClientRect(mhwnd, &rect);
		WindowPos.x = rect.right - rect.left;
		WindowPos.y = rect.bottom - rect.top;

		Time::Update();
		Input::Update();
		SceneManager::Update();
		CollisionManager::Update();
	}
	void Application::Render()
	{
		Time::Render(backHdc);
		Input::Render(backHdc);
		SceneManager::Render(backHdc); // ���δ� ����ۿ� ����

		//������� �׸� ����(������)�� ���� ( ����� ȭ����� ��ü�� ��� ���ԵǾ ���簡 �Ǵ� ���̹Ƿ� �������� �ʴ´� 
		StretchBlt(mhdc, 0, 0, WindowPos.x, WindowPos.y, backHdc, 0, 0, 1500, 750, SRCCOPY); // ������ hdc�� �״�� ����
	}
}