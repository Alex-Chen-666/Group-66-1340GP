#ifndef PRINTCARD_H
#define PRINTCARD_H
#include <string>
#include <vector>
#include <iostream>
#include "column_center_print.h"
#include "global.h"
int max(std::vector<std::vector<std::string>> c);
int number_length(int num);
void printcard(std::vector<std::vector<std::string>> card,int column,int * hidden_position,bool clear_line=true);
void printreservedcard(std::vector<std::vector<std::string>> card
                       ,int reserved_chances, int column
                       ,int original_max_card_num);
#endif
