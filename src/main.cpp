#include "../lib/pda.hpp"
#include <string>
#include <iostream>

int main(int argc, char * argv[]) {
  std::string automataFile = "palin.automata";
  std::string inputFile = "palin.input";
  if (argc == 3) {
    automataFile = argv[1];
    inputFile = argv[2];
  }
  Pda pda(automataFile, inputFile);

  if (pda.checkInput())
		std::cout << "\nInput is accepted\n\nn";
	else
		std::cout << "\nInput is NOT accepted\n\nn";

  return 0;
}