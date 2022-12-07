#include "../lib/helpers.hpp"

std::vector<std::string> helpers::lineToStrings (std::string line, std::string delimiter) {
  std::vector<std::string> strings;
  char * pch = strtok ( (char*) line.c_str(),delimiter.c_str());
  while (pch != NULL) {
    strings.push_back(pch);
    pch = strtok (NULL, delimiter.c_str());
  }
  return strings;
}

std::string helpers::charToString (char c) {
  std::stringstream ss;
  std::string s;
  ss << c;
  ss >> s;
  return s;
}