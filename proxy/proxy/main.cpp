#include "libbitmap.cpp"
#include <iostream>

using namespace std;

int main()
{
	Bitmap bmp;
	bmp.load("123.bmp");
	cout << bmp.m_height;
	cout << bmp.m_width;



	cin.get();
}
