#pragma once

#include <string>

/*
* Logging manager that should be used for all logging/tracing in the code.
*/

namespace logging {
struct Logger {
  static void log(std::string message, const char* file, const char* func, int line) {
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
    const char slash = '\\';
#else
    const char slash = '/';
#endif

    const char* shortFile = (strrchr(file, slash) ? strrchr(file, slash) + 1 : file);
    printf("%s {File: %s, Function: %s(), Line: %d} \n", message.c_str(), shortFile, func, line);
  }
};
} // namespace log


#define log(message) logging::Logger::log(message, __FILE__, __func__, __LINE__)
