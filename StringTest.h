#pragma once
#include <string>
#include <iostream>
#include <sstream>
#include <Windows.h>

namespace avst
{
	class StringTest
	{
	public:
		static bool IsKPeriodic(std::string structure, size_t filler_size);
		static void KPeriodicTest();
		static void Trim(std::string&);
	};
}