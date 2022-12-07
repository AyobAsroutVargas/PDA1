#include "../lib/pda_stack.hpp"

Pda_stack::Pda_stack(std::vector<std::string> symbols) {
  stackSymbols_ = std::set<std::string>(symbols.begin(), symbols.end());
  size_ = 0;
}

void Pda_stack::push(std::string symbol) {
  if(stackSymbols_.contains(symbol)) {
    if(size_ == 0) initialSymbol_ = symbol;
    content_.push_back(symbol);
    size_++;
  }
}

void Pda_stack::push(std::vector<std::string> symbols) {
  for(long unsigned int i = 0; i < symbols.size(); i++) {
    push(symbols[symbols.size() - 1 - i]);
  }
}

std::string Pda_stack::pop() {
  if(size_ > 0) {
    std::string top = getTop();
    content_.pop_back();
    size_--;
    return top;
  }
  return "";
}

std::string Pda_stack::getTop() {
  return content_.back();
}

int Pda_stack::getSize(){
  return size_;
}

std::string Pda_stack::getInitialSymbol(){
  return initialSymbol_;
}

std::vector<std::string> Pda_stack::getAcceptedSymbols(){
  return std::vector<std::string>(stackSymbols_.begin(), stackSymbols_.end());
}