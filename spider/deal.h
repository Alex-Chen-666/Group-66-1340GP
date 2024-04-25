#ifndef DEAL_H
#define DEAL_H
#include <string>
#include <vector>
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
#include "printcard.h"
void deal(std::vector<std::vector<std::string>> &card, std::vector<std::string> &savedcard,
            int column_number, int *hidden_position, int reserved_chances);
#endif
