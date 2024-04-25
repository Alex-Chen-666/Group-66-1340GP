//Code Requirement: Data structures for storing game status: line4-11
//                  Dynamic memory management: line19-20
#include "move.h"
void move(std::vector<std::vector<std::string>> &card, int reserved_chances, int column, 
            int from_column, int to_column, int row, int *hidden_position){
    //card movement
    //input: current cards; integers all equal to 1; 
    //output: move the cards
    //use vector to store game status
    std::chrono::milliseconds duration(500);
    int start_size = card[to_column - 1].size();    //store the initial length of the target position
    int blank_number = 3;
    int original_max_card_num = max(card);
    std::vector<std::string>::iterator first=card[from_column-1].begin() + row - 1;
    for (int i = 0; i < blank_number; i++){      //add empty cards to realize the effect of moving downward
        card[from_column - 1].insert(first, "");
        first = card[from_column - 1].begin() + row - 1;
    }
    if (hidden_position[from_column - 1] == row)
        hidden_position[from_column - 1]--;     //dynamic memory management

    std::this_thread::sleep_for (duration);
    system("clear");
    printcard(card, column, hidden_position);
    printreservedcard(card, reserved_chances, column, original_max_card_num);
    for(int i = 0; i < blank_number; i++)
        card[to_column - 1].insert(card[to_column - 1].end(), "");
        
    first = card[from_column - 1].begin() + row - 1;
    card[to_column - 1].insert(card[to_column - 1].end(),first + blank_number, card[from_column - 1].end());
    first = card[from_column - 1].begin() + row - 1;
    card[from_column - 1].erase(first,card[from_column - 1].end());
    std::this_thread::sleep_for (duration);
    system("clear");
    printcard(card, column, hidden_position);
    printreservedcard(card, reserved_chances, column, original_max_card_num);
    std::this_thread::sleep_for (duration);
    system("clear");
    std::vector<std::string>::iterator end_point_start_length = card[to_column - 1].begin() + start_size;
    card[to_column - 1].erase(end_point_start_length, end_point_start_length + blank_number);
}
