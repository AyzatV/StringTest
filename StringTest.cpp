#include "StringTest.h"

namespace avst
{
	bool StringTest::IsKPeriodic(std::string structure, size_t filler_size)
	{
		bool result = false;
		size_t size = structure.length();
		if (filler_size <= size && size % filler_size == 0)	// проверка соответствия размеров части и всей строки
		{
			result = true;
			if (filler_size < size)							// случай совпадения размеров части и всей строки сразу засчитывается
			{
				std::string pattern = structure.substr(0, filler_size);
				for (size_t i = filler_size; i < size; i += filler_size)
				{
					if (pattern != structure.substr(i, filler_size))
					{
						result = false;
						break;
					}
				}
			}
		}
		return result;
	}
	
	void StringTest::KPeriodicTest()
	{
		// подключение кодовых страниц для ввода-вывода кириллицей
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);

		std::string test_string{};
		size_t part_size = 0;

		while (true)
		{
			std::cout << std::endl << "Введите строку для проверки (для прекращения работы - \"Enter\"): ";
			std::getline(std::cin, test_string);
			Trim(test_string);
			if (test_string.empty()) break;

			while (true)
			{
				std::cout << std::endl << "Введите размер кратной части строки (для ввода новой строки введите 0): ";
				std::string input;
				std::getline(std::cin, input);
				Trim(input);
				if (!input.empty())
				{
					std::stringstream ss;
					ss << input;
					ss >> part_size;
				}
				else part_size = 0;
				if (part_size == 0) break;

				if (IsKPeriodic(test_string, part_size))
				{
					std::cout << std::endl << "Часть введенного размера является кратной для данной строки:" << std::endl;
					size_t n = test_string.length() / part_size;
					std::string s = test_string.substr(0, part_size);
					for (size_t i = 0; i < n; i++) { std::cout << s << " "; }
					std::cout << std::endl;
				}
				else std::cout << std::endl << "Часть введенного размера не является кратной для данной строки" << std::endl;
			}
		}

		std::cout << std::endl << "Вы не ввели строку, работа будет прекращена";
		std::cin.get();
	}
	
	void StringTest::Trim(std::string& s)
	{
		int last = s.length() - 1;
		if (last < 0) return;

		bool is_empty = true;
		for (; last >= 0; last--)
		{
			if (s[last] != ' ')
			{
				is_empty = false;
				break;
			}
		}
		if (is_empty) s.clear();
		else
		{
			int first = 0;
			for (; first < last; first++)
			{
				if (s[first] != ' ') break;
			}
			s = s.substr(first, last - first + 1);
		}
	}
}