#ifndef PDA_
#define PDA_

#include <iomanip>

#include "pda_stack.hpp"
#include "in_tape.hpp"
#include "helpers.hpp"
#include <sstream>
#include <fstream>
#include <exception>

typedef std::pair<std::string, std::string> transition_t;

class Pda {
 public:
  Pda(std::string automataFile, std::string inputFile);
  ~Pda();

  void loadInput(std::string inputFile);
  void loadAutomata(std::string automataFile);

  bool checkInput();
  void nextStep(std::string actualState, In_tape input, Pda_stack stack, int readCount);
  std::vector<transition_t> getTransitionsForState(std::string state, In_tape input, Pda_stack stack);
  bool isFinalState(std::string state);
 private:
  void readStates(std::string states);
	void readInputSymbols(std::string symbols);
	void readStackSymbols(std::string symbols);
	void readInitialState(std::string state);
	void readInitialStackSymbol(std::string symbol);
	void readFinalStates(std::string states);
	void saveTransition(std::string transition);

  std::vector<std::string> states_;
  std::vector<std::string> inputSymbols_;
	std::vector<std::string> finalStates_;
	std::vector<transition_t> transitions_;
	std::string initialState_;


	Pda_stack* stack_;
	In_tape* inputTape_;
	std::string actualState_;
	bool acceptedInput_;
};

#endif