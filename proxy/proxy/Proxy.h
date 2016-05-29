#include "libbitmap.cpp"
#include <string>

using namespace std;

class Proxy
{
public:
	
	static char* get_w(char const &file_name)
	{
		
		
	}
	static unsigned int get_size(string const &n_file)
	{
		if(parser(n_file))
		{
			return 9999;
		}
		return weidth;
	}



protected:
	static bool parser(string const &n_file)
	{
		string tmp;
		unsigned int b(0),e(0);
		b = n_file.find_first_of("_",0) + 1;
		e = n_file.find_first_not_of("012345678", b);
		cout << n_file.substr(b, e - b);
		if(e==4294967295) //Если "e" получило максимальное значение значит ошибка в формате
		{
			return false;
		}

		///*
		if (n_file.substr(e ,  1) != "X" && n_file.substr(e, 1) != "x") // Если следующий символ не разделительный "х"
		{
			cout << n_file.substr(e+1, 1);
			return false;
		}
		//*/
		weidth = atoi(n_file.substr(b, e).c_str());
		b = n_file.find_first_of("0123456789", e+1);
		e = n_file.find_first_not_of("012345678", b);
		if(b==e)
		{
			return false;
		}
		//cout << weidth << endl;
		height = atoi(n_file.substr(b, e).c_str());

}
	static unsigned int weidth;
	static unsigned int height;


};
unsigned int Proxy::weidth = 0;
unsigned int Proxy::height = 0;