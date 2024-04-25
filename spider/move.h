#ifndef MOVE_H
#define MOVE_H
#include <iostream>
#include <string>
#include <vector>
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
#include "printcard.h"
void move(std::vector<std::vector<std::string>> &card,int reserved_chances,int column, 
            int from_column, int to_column, int row,int *hidden_position);
#endif
