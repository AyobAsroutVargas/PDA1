#ifndef PDA_STACK_
#define PDA_STACK_

#include <iostream>
#include <string>
#include <set>
#include <vector>

class Pda_stack {
 public:
  Pda_stack(std::vector<std::string> symbols);
  ~Pda_stack(){};

  void push(std::string symbol);
  void push(std::vector<std::string> symbols);

  std::string pop();
  std::string getTop();

  int getSize();
  std::string getInitialSymbol();
  std::vector<std::string> getAcceptedSymbols();

 private:
  std::set<std::string> stackSymbols_;
  int size_;
  std::vector<std::string> content_;
  std::string initialSymbol_;
};



#endif