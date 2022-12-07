#ifndef UTILS_
#define UTILS_

#include <string>
#include <cstring>
#include <sstream>
#include <vector>

namespace helpers {
	std::vector<std::string> lineToStrings (std::string line, std::string delimiter);
	std::string charToString (char c);
}


#endif