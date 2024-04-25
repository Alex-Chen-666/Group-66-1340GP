#ifndef RULE_H
#define RULE_H
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <sstream>
void printAndClearLine(const std::string& line);
bool validinput(std::string input);
bool validdrag(std::vector<std::vector<std::string>> v,int * flip,int col_from,int col_to,int size,int start_row,int state);
int valid(std::string input,std::vector<std::vector<std::string>> v,int * flip,int size,int deal_times);
#endif
