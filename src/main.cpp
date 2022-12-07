#include "../lib/pda.hpp"
#include <string>
#include <iostream>

int showMenu () {
	int option;

	std::cout << "1. Load input from file.\n";
	std::cout << "2. Load input from keyboard.\n";
	std::cout << "3. Exit\n\n";

	std::cout << "Insert option (1-3): ";
	std::cin >> option;

  return option;
}

void executeAutomata (Pda* automata) {
	if (automata->checkInput())
		std::cout << "\nInput is accepted\n\n";
	else
		std::cout << "\nInput is NOT accepted\n\n";
}

int main(int argc, char * argv[]) {
  std::string automataFile = "APf.txt";
  std::string inputFile = "input.txt";
  int option;

  if(argc == 3) {
    std::string optionString(argv[1]);
    if(optionString== "-i") {
      automataFile = argv[2];
    } else {
      automataFile = argv[1];
      inputFile = argv[2];

      Pda pda(automataFile, inputFile);
      if (pda.checkInput())
        std::cout << "\nInput is accepted\n\n";
      else
        std::cout << "\nInput is NOT accepted\n\n";
      return 0;
    }
  }

  Pda* automata = new Pda(automataFile);

  do {
    option = showMenu();
    switch (option)
    {
    case 1:
      std::cout << "Insert the input filename: ";
      std::cin >> inputFile;
      automata->loadInput(inputFile);
      break;
    case 2:
      automata->loadInputByKeyboard();
      executeAutomata(automata);
      break;
    case 3:
      std::cout << "Goodbye!\n";
      break;
    default:
      std::cout << "Option " << option << " doesn't exist..\n";
      break;
    }
  }while(option != 3);
  

  return 0;
}