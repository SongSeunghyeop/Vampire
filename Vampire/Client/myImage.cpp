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
		mBitmap = (HBITMAP)LoadImageW(nullptr  // 받은 이미지 비트맵에 저장
			, path.c_str(), IMAGE_BITMAP
			, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

		if (mBitmap == nullptr) // 비트맵에 받은 이지지가 없으면 
			return E_FAIL; // false 리턴 

		BITMAP bitInfo = {};
		GetObject(mBitmap, sizeof(BITMAP), &bitInfo);

		mWidth = bitInfo.bmWidth; // 받은 리소스를 저장한 비트맵의 가로
		mHeight = bitInfo.bmHeight; // 받은 리소스를 저장한 비트맵의 세로

		HDC mainDC = myapplication.GetHdc();
		mHdc = CreateCompatibleDC(mainDC); // 원본의 DC와 호환가능한 값으로 초기화

		HBITMAP oldBitmap = (HBITMAP)SelectObject(mHdc, mBitmap); // 방금 만든 캐릭터의 dc와 bmp를 받고 기존 bmp 
		DeleteObject(oldBitmap); // 삭제

		return S_OK;
	}
}
