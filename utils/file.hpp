#ifndef __UTILS_FILE_HPP__
#define __UTILS_FILE_HPP__

#include <fstream>
#include <string>


namespace utils
{
namespace file
{

// ydm TODO: Handle encodings?
std::string read(const std::string& filename)
{
    std::ifstream s(filename);
    if (s)
    {
        return std::string(std::istreambuf_iterator<char>(s),
                           std::istreambuf_iterator<char>());
    }
    else
    {
        return "";
    }
}

} // namespace file
} // namespace utils

#endif // __UTILS_FILE_HPP__
