#pragma once

// win only
// need to be sepearate as cannot use namespace std
#ifdef _WIN32
#include <string>
#include <tchar.h>

namespace vcc 
{
    std::wstring process_service_win(std::wstring command);
}
#endif