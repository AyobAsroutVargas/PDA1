#include "../lib/in_tape.hpp"

In_tape::In_tape(std::string fileName){
  loadFromFile(fileName);
}

In_tape::~In_tape(){
  characters_.clear();
}

void In_tape::loadFromFile(std::string fileName){
  index_ = 0;

  std::fstream file;
  std::string symbol;
  fileName_ = fileName;
  file.open(fileName.c_str(), std::ios::in);

  if(file.is_open()) {
    characters_.clear();
    while(file >> symbol) {
      characters_.push_back(symbol);
    }
    file.close();
    return;
  }
  std::cerr << "El fichero no exite\n";
}

void In_tape::loadFromKeyboard() {
  characters_.clear();
  index_ = 0;
  std::string input;
  std::cout << "Put string as input(without spaces between symbols): ";
  std::cin >> input;
  // Divide the whole string into substrings of size 1 and put them into the input tape.
  for_each(input.begin(), input.end(), [&](char c){characters_.push_back(helpers::charToString(c)); });
}

std::string In_tape::read(){
  if(index_ < (int) characters_.size()) {
    return characters_[index_++];
  }
  return "";
}

std::string In_tape::getActualChar(){
  return characters_[index_];
}

bool In_tape::hasNext(){
  return index_ < (int) characters_.size();
}

bool In_tape::isEmpty(){
  return characters_.size() == 0;
}
