#include "Utils.h"

std::string ext(std::string& path)
{
    return path.substr(path.find('.') + 1);
}