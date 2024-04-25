#ifndef GAME_PROCESS_H
#define GAME_PROCESS_H
#include <vector>   
#include <string>   
#include <sstream>
#include <iomanip> 
#include <fstream>                                                                                     
#include "rule.h"
#include "printcard.h"
#include "column_center_print.h"
#include "move.h"
#include "deal.h"
#include "remove_complete_deck.h"
#include "stalemate3.h"
#include "finish.h"
#include "loading_save.h"
int game_process(int column_number, int reserved_chances, int decks_of_card, int suit_num, int step, 
                int * hidden_position, std::vector<std::vector<std::string>> card,
                std::vector<std::string> savedcard, int &total_file_index);
#endif
