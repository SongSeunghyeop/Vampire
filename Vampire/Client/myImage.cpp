#include "myImage.h"
#include "myApplication.h"

extern my::myApplication myapplication;

namespace my
{
	myImage::myImage()
		: mBitmap(NULL)
		, mHdc(NULL)
		, mWidth(0)
		, mHeight(0)
	{

	}
	myImage::~myImage()
	{

	}
	HRESULT myImage::Load(const std::wstring& path)
	{
		mBitmap = (HBITMAP)LoadImageW(nullptr  // ���� �̹��� ��Ʈ�ʿ� ����
			, path.c_str(), IMAGE_BITMAP
			, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

		if (mBitmap == nullptr) // ��Ʈ�ʿ� ���� �������� ������ 
			return E_FAIL; // false ���� 

		BITMAP bitInfo = {};
		GetObject(mBitmap, sizeof(BITMAP), &bitInfo);

		mWidth = bitInfo.bmWidth; // ���� ���ҽ��� ������ ��Ʈ���� ����
		mHeight = bitInfo.bmHeight; // ���� ���ҽ��� ������ ��Ʈ���� ����

		HDC mainDC = myapplication.GetHdc();
		mHdc = CreateCompatibleDC(mainDC); // ������ DC�� ȣȯ������ ������ �ʱ�ȭ

		HBITMAP oldBitmap = (HBITMAP)SelectObject(mHdc, mBitmap); // ��� ���� ĳ������ dc�� bmp�� �ް� ���� bmp 
		DeleteObject(oldBitmap); // ����

		return S_OK;
	}
}
