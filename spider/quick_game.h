#ifndef QUICKGAME
#define QUICKGAME
#include "headfiles.h"
#include <iostream>
#include <map>
#include <array>
#include "main_logic.h"
#include "print_grid.h"
#include "input_position.h"
#include "full_screen.h"
#include "poker_crush.h"

using namespace std;
void refresh(bool endless=false);
int quick_game(int level,bool endless=false);
#endif
