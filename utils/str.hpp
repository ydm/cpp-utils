#ifndef __UTILS_STR_HPP__
#define __UTILS_STR_HPP__

#include <cctype>
#include <functional>
#include <string>

namespace utils
{
  namespace str
  {
    std::string lstrip(const std::string& s)
    {
      static const std::function<int (int)> spacep = std::ptr_fun<int, int>(std::isspace);
      const std::string::const_iterator it = std::find_if_not(s.begin(), s.end(), spacep);
      return std::string(it, s.end());
    }

    std::string rstrip(const std::string& s)
    {
      static const std::function<int (int)> spacep = std::ptr_fun<int, int>(std::isspace);
      const std::string::const_reverse_iterator it = std::find_if_not(s.rbegin(), s.rend(), spacep);
      return std::string(s.begin(), it.base());
    }

    std::string strip(const std::string& s)
    {
      return lstrip(rstrip(s));
    }
  }
}

#endif // __UTILS_STR_HPP__
