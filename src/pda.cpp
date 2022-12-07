#include "../lib/pda.hpp"

Pda::Pda(std::string automataFile, std::string inputFile){
  inputTape_ = new In_tape(inputFile);
  loadAutomata(automataFile);
}

Pda::~Pda(){
  
}

void Pda::loadInput(std::string inputFile){
  inputTape_->loadFromFile(inputFile);
}

void Pda::loadAutomata(std::string automataFile){
  std::ifstream file;
  file.open(automataFile.c_str());
  if (file.is_open()) {
      std::string temp;
      getline(file, temp);
      readStates(temp);
      getline(file, temp);
      readInputSymbols(temp);
      getline(file, temp);
      readStackSymbols(temp);
      getline(file, temp);
      readInitialState(temp);
      getline (file, temp);
      readInitialStackSymbol (temp);
      getline (file, temp);
      readFinalStates (temp);
      while (!file.eof()) {
        getline (file, temp);
        saveTransition (temp);
      }
      file.close();
  }
  else {
    std::cerr << "El fichero no existe" << std::endl;
  }
}

bool Pda::checkInput(){
  acceptedInput_ = false;
  nextStep(actualState_, *inputTape_, *stack_, 0);
  return acceptedInput_;
}

void Pda::nextStep(std::string actualState, In_tape input, Pda_stack stack, int readCount){
  if(!acceptedInput_) {
    if(!input.hasNext()) {
      if(isFinalState(actualState)) {
        acceptedInput_ = true;
      }
    }

    std::vector<transition_t> allowedTransitions = getTransitionsForState(actualState, input, stack);

    for(long unsigned int i = 0; i < allowedTransitions.size(); i++) {
      Pda_stack tempStack = stack;
      In_tape tempInput = input;
      std::string actual = allowedTransitions[i].first;
      std::string next = allowedTransitions[i].second;

      std::istringstream iss(actual);

      std::string readInput;
      iss >> readInput;
      iss >> readInput;
      if (readInput != ".") {
        readInput = tempInput.read();
      } else {
        readInput = ".";
      }

      std::istringstream iss2(next);
      std::string nextState;
      std::vector<std::string> nextStackSymbols;
      iss2 >> nextState;

      std::string symbols;
      iss2 >> symbols;

      tempStack.pop();
      for(long unsigned int i = symbols.size() - 1; i >= 0; i--) {
        std::string symbol = helpers::charToString(symbols[i]);
        if(symbol != ".") tempStack.push(symbol);
      }

      nextStep(nextState, tempInput, tempStack, readCount);
    }
  }
}

std::vector<transition_t> Pda::getTransitionsForState(std::string actualState, In_tape input, Pda_stack stack){
  std::string actual = actualState + " " + input.read() + " " + stack.getTop();
  std::string actualEmpty = actualState + " . " + stack.getTop(); // This transition is used to check e-transitions

  std::vector<transition_t> allowed;
  for (long unsigned int i = 0;i < transitions_.size(); i++) {
    if (transitions_[i].first == actual || transitions_[i].first == actualEmpty) {
      allowed.push_back(transitions_[i]);
    }
  }
  return allowed;
}

bool Pda::isFinalState(std::string state){
  return std::any_of(finalStates_.begin(), finalStates_.end(), [&state](std::string finalState) { return state == finalState;});
}
//Private methods for initialization **********************************************************************************
void Pda::readStates(std::string states){
  states_ = helpers::lineToStrings(states, " ");
}

void Pda::readInputSymbols(std::string symbols){
  inputSymbols_ = helpers::lineToStrings(symbols, " ");
}

void Pda::readStackSymbols(std::string symbols){
  stack_ = new Pda_stack (helpers::lineToStrings(symbols, " "));
}

void Pda::readInitialState(std::string state){
  initialState_ = state;
  actualState_ = initialState_;
}

void Pda::readInitialStackSymbol(std::string symbol){
  stack_->push(symbol);
}

void Pda::readFinalStates(std::string states){
  if (states != "")
    finalStates_ = helpers::lineToStrings(states, " ");
  else
    finalStates_.push_back("NO_FINAL");
}

void Pda::saveTransition(std::string transition){
  std::string actual = "";
  std::string next = "";
  std::istringstream iss(transition);

  std::string temp;
  iss >> temp;  // Actual state
  if (temp.size() > 1) {
    actual += temp;
    actual += " ";
    iss >> temp;  // actual input character
    actual += temp;
    actual += " ";
    iss >> temp;  // actual stack symbol
    actual += temp;

    iss >> temp;    // next state
    next += temp;
    next += " ";
    while (!iss.eof()) {
      iss >> temp;    // next symbol to push to stack
      next += temp ;
    }

    transition_t trans;
    trans.first = actual;
    trans.second = next;
    transitions_.push_back(trans);
  }
}
