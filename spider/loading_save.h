#ifndef LOADING_SAVE_H
#define LOADING_SAVE_H
#include <iostream>
#include <vector>   
#include <string>   
#include <sstream>
#include <iomanip> 
#include <fstream>                                                                                     
#include <ctime>
#include <chrono>
#include "column_center_print.h"
void loading(std::string fileIndex, int &flag, int &column_number, int &reserved_chances, int &decks_of_card, int &suit_num, \
            int &step, int * &hidden_position, std::vector<std::vector<std::string>> &card, std::vector<std::string> &savedcard);
int save(int column_number, int reserved_chances, int decks_of_card, int suit_num, int step,
                int * hidden_position, std::vector<std::vector<std::string>> card,
                std::vector<std::string> savedcard, std::string outcome);
#endif
