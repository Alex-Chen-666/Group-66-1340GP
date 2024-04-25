#ifndef REMOVE_COMPLETE_DECK_H
#define REMOVE_COMPLETE_DECK_H
#include "printcard.h"
#include "move.h"
int check_deck(std::vector<std::vector<std::string>> card
            ,int *hidden_position,int column_number);
void remove_complete_deck(std::vector<std::vector<std::string>> &card
,int *hidden_position,int column_number,int column,int reserved_chances );
#endif
