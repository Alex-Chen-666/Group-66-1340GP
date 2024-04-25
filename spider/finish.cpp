#include "finish.h"
bool finish(std::vector<std::vector<std::string>> card, int column_number){
    //determine whether the game is finished or not
    //input: current cards; column number
    //output: return true if the game is finished; return false if the game is unfinished yet
    for (int i = 0; i < column_number; i++){
        if (!card[i].empty())
            return false;
    }
    return true;
}
