#pragma once
#include "myResource.h"

namespace my
{
	class myImage : public Resource // 이미지리소스
	{
	public:
		myImage();
		~myImage();

		virtual HRESULT Load(const std::wstring& path) override; // 리소스 Load 함수 상속

		HDC GetHdc() { return mHdc; }
		HBITMAP GetBitmap() { return mBitmap; }
		UINT GetWidth() { return mWidth; }
		UINT GetHeight() { return mHeight; }

	private:
		HBITMAP mBitmap;
		HDC mHdc;
		UINT mWidth;
		UINT mHeight;
	};
}