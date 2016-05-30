#include "libbitmap.cpp"
#include <string>


using namespace std;

class Proxy
{
public:
	
	static string get_size(string const &n_file)
	{
		unsigned int weidth(0), height(0);
		if(!parser(n_file, weidth, height))
		{
			if (!get_size_from_file(n_file, weidth, height))
			{
				throw "Error format file";

			}
		}
		return to_string(weidth) + "x" + to_string(height);
	}
	static string get_size(string const &n_file, string const &form) //получение размера по формату
	{
		if(form.length()!=2) //если длинна формата не равна 2 - ошибка в формате
		{
			throw "Incorrect out format";
		}
		else if((form[0]!='w'||form[1]!='h')&&(form[0]!='h'||form[1]!='w')) //если фортмат не овечает "wh" || "hw" - ошибка формата
		{
			throw "Incorrect out format";
		}
		else
		{
			unsigned int weidth(0), height(0); 
			string result;
			if (!parser(n_file, weidth, height)) //если не удалось получить размер из имени файла 
			{
				if (!get_size_from_file(n_file, weidth, height))//попытка получить из файла, если не удалось выбрас исключени€
				{
					throw "Error format file";
				}
			}

			if(form[0]=='w')//возврат результата в соответствии с заданным форматом
			{
				return to_string(weidth) + 'x' + to_string(height); //перва€ ширина
			}
			else
			{
				return to_string(height) + 'x' + to_string(weidth); //перва€ высота
			}
		}
	}
	static unsigned int get_w(string const &n_file) //получение ширины
	{
		unsigned int weidth(0), height(0);
		string result;
		if (!parser(n_file, weidth, height))
		{
			if (!get_size_from_file(n_file, weidth, height))
			{
				throw "Error format file";

			}
		}
		return weidth;
	}
	static unsigned int get_h(string const &n_file) //получение высоты
	{
		unsigned int weidth(0), height(0);
		string result;
		if (!parser(n_file, weidth, height))
		{
			if (!get_size_from_file(n_file, weidth, height))
			{
				throw "Error format file";
			}
		}
		return height;
	}


protected:
	static bool get_size_from_file(string const &n_file, unsigned int &weidth, unsigned int &height) //получение размера из файла.
	{
		Bitmap bmp;
		bmp.load(n_file);
		weidth = bmp.m_width;
		height = bmp.m_height;
		if (weidth == 0 || height == 0)
		{
			return false;
		}
		return true;
	}
	static bool parser(string const &n_file, unsigned int &weidth, unsigned int &height) //получение размера их имени файла
	{

		string tmp;
		unsigned int b(0),e(0);
		b = n_file.find_first_of("_",0) + 1;
		e = n_file.find_first_not_of("012345678", b);
		if(e==4294967295) //≈сли "e" получило максимальное значение значит ошибка в формате возврат фолс
		{
			return false;
		}

		///*
		if (n_file.substr(e ,  1) != "X" && n_file.substr(e, 1) != "x") // ≈сли следующий символ не разделительный "х" - ошибка, возврат фосл
		{
			return false;
		}
		//*/
		weidth = atoi(n_file.substr(b, e).c_str()); // получение ширены
		b = n_file.find_first_of("0123456789", e+1); 
		e = n_file.find_first_not_of("0123456789", b);
		if(b==e) // если "b" и "e" значит высота не присутствует в имени файла - ошибка, возврат фолс
		{
			cout << "false" << endl;
			return false;
		}
		height = atoi(n_file.substr(b, e).c_str()); //получение разера высоты
		return true;
	}
};
