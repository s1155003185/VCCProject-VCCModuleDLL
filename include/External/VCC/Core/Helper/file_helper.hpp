#pragma once
#include <filesystem>
#include <fstream>
#include <string>

#include "exception.hpp"
#include "exception_macro.hpp"
#include "exception_type.hpp"
#include "file_constant.hpp"

using namespace std;

namespace vcc
{
	inline bool AppendFileSingleLline(PATH filePath, std::wstring line, bool isForce) 
	{
		// 1. Check directory exists
		// 2. Check file exists
		// 3. Check file can read write
		// 4. Write file
		
		PATH dir = filePath.parent_path();
		if (!std::filesystem::is_directory(dir))
		{
			if (!isForce)
				THROW_EXCEPTION(ExceptionType::DIRECTORY_NOT_FOUND, L"Directory " + dir.wstring() + L" not found.");
			else if (!std::filesystem::create_directories(dir))
				THROW_EXCEPTION(ExceptionType::DIRECTORY_CANNOT_CREATE, L"Directory " + dir.wstring()  + L" not found.");
		}
		if (!std::filesystem::exists(filePath))
		{
			if (!isForce)
				THROW_EXCEPTION(ExceptionType::FILE_NOT_FOUND, L"File " + filePath.wstring() + L" not found.");
		}
		std::wofstream fileStream(filePath, ios_base::app);
		fileStream << line << NL;
		fileStream.close();
		return true;
	}

	inline wstring ReadFileSingleLline(PATH filePath, int index) 
	{
		// 1. Check directory exists
		// 2. Check file exists
		// 3. Check file can read
		// 4. Read file
		
		PATH dir = filePath.parent_path();
		if (!std::filesystem::is_directory(dir))
			THROW_EXCEPTION(ExceptionType::DIRECTORY_NOT_FOUND, L"Directory " + dir.wstring() + L" not found.");
		if (!std::filesystem::exists(filePath))
			THROW_EXCEPTION(ExceptionType::FILE_NOT_FOUND, L"File " + filePath.wstring() + L" not found.");
		
		std::wifstream fileStream(filePath, ios_base::in);
		std::wstring line, result;
		int cnt = 0;
		while (std::getline(fileStream, line))
		{
			if (cnt == index) {
				result = line;
				break;
			}
			cnt++;
		}
		fileStream.close();
		return result;
	}
}
