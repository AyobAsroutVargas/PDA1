#ifndef IN_TAPE_
#define IN_TAPE_

#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include <fstream>

class In_tape {
 public:
  In_tape(){};
  In_tape(std::string fileName);
  ~In_tape();

  void loadFromFile(std::string fileName);
  std::string read();
  std::string getActualChar();
  bool hasNext();
  bool isEmpty();
 private:
  int index_;
  std::string fileName_;
  std::vector<std::string> characters_;
};

#endif