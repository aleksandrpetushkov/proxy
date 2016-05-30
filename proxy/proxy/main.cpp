//#include "libbitmap.cpp"
#include <iostream>
#include "Proxy.h"
#include "gtest\gtest.h"

using namespace std;

TEST()
{
	ASSERT_EQ(Proxy::get_size("tst.bmp"), "500x333");
	ASSERT_EQ(Proxy::get_size("tst_200x200.bmp"), "200x200");
	ASSERT_THROW(Proxy::get_size("tst_200x.bmp"), char*);
	string form = "hw";
	ASSERT_EQ(Proxy::get_size("tst.bmp",form), "333x500");
	form = "wh";
	ASSERT_EQ(Proxy::get_size("tst.bmp", form), "500x333");
		form = "k";
	ASSERT_THROW(Proxy::get_size("tst_200x.bmp"), char*);
	ASSERT_EQ(Proxy::get_w("tst.bmp"), 500);
	ASSERT_EQ(Proxy::get_h("tst.bmp"), 333);
	ASSERT_THROW(Proxy::get_w("tst_200x.bmp"), char*);
	ASSERT_THROW(Proxy::get_h("tst_200x.bmp"), char*);
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();

	cin.get();
}
