#pragma once
#include "myResource.h"

namespace my
{
	class myImage : public Resource // �̹������ҽ�
	{
	public:
		myImage();
		~myImage();

		virtual HRESULT Load(const std::wstring& path) override; // ���ҽ� Load �Լ� ���

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