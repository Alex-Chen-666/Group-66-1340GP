#ifndef SPIDER_H
#define SPIDER_H
#include <cstdio>         //std::getchar     
#include <vector>   
#include <string>   
#include <sstream>
#include <fstream>      //file I/O 读档存档
#include <ctime>        //time
#include <chrono>       //time conversion to string
#include <cstdlib>
#include <iomanip>                                                                                      
#include "rule.h"
#include "printcard.h"
#include "updownchoice.h"
#include "column_center_print.h"
#include "move.h"
#include "new_game.h"
#include "choose_mode.h"
#include "deal.h"
#include "remove_complete_deck.h"
#include "stalemate3.h"
#include "game_process.h"
#include "choose_history.h"
#include "process_record.h"
#include "print_history.h"
#include "loading_save.h"
#include "instruction.h"
#include "full_screen.h"
int spider();
#endif
