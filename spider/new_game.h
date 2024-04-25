#ifndef NEW_GAME_H
#define NEW_GAME_H
#include <iostream>
#include <string>
#include <vector>
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
#include <algorithm>      //std::shuffle
#include <random>         //std::random_device  std::mt19937
#include "printcard.h"
#include "updownchoice.h"
void choice_limit(std::vector<updownchoice> &start,int column_position);
int Initial_configuration(int &column_num
                          ,int &decks_of_card, int &suit_num, int &reserved_chances);
void addcolor(std::vector<std::string> &card);
void random_dealing_cards(std::vector<std::vector<std::string>> &card
                          , std::vector<std::string> &reserved_card,int color_num
                          ,int decks_of_card, int column, int reserved_chances,
                          int *hidden_position);
int new_game(int & column_number, int &reserved_chances,int &decks_of_card,
            int &suit_num,int * &hidden_position, 
            std::vector<std::vector<std::string>> &card, std::vector<std::string> &savedcard,
            int &step);
#endif
