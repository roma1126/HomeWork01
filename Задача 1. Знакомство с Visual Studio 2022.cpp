#include <iostream>
#include <fstream>

int main()
{
	setlocale(LC_ALL, "Russian");

	int a, b;
	std::ifstream file("in.txt");
	std::ofstream fin("out.txt");
	if (file.is_open())
	{
		file >> a;

		int* mas = new int[a];

		for (int i = 0; i < a;i++)
		{
			file >> mas[i];
		}
		for (int i = 0;i < a - 1;i++)
		{
			std::swap(mas[i], mas[i + 1]);
		}

		file >> b;

		int* mas_2 = new int[b];

		for (int i = 0; i < b;i++)
		{
			file >> mas_2[i];
		}

		for (int i = b - 1;i > 0;i--)
		{
			std::swap(mas_2[i], mas_2[i - 1]);
		}

		fin << b << std::endl;

		for (int i = 0; i < b;i++)
		{
			fin << mas_2[i] << " ";
		}

		fin << std::endl;
		fin << a << std::endl;

		for (int i = 0; i < a;i++)
		{
			fin << mas[i] << " ";
		}

		delete[] mas;
		delete[] mas_2;

		file.close();
		fin.close();
	}
	else
	{
		std::cout << "Не удалось открыть файл!";
	}

}