//Code Requirement: Data structures for storing game status: line11-12
#include "deal.h"
void deal(std::vector<std::vector<std::string>> &card, std::vector<std::string> &savedcard,
            int column_number, int *hidden_position, int reserved_chances){
    //deal cards in game
    /*input: current cards; dealing card pile; column number; 
            a dynamic array with the number of rows of the first turned card in each column; remaining chances*/
    //output: deal cards
    std::chrono::milliseconds duration(100);    //create a time interval of 0.1 seconds
    system("clear");
    for (int i = 0; i < column_number; i++){
        std::string added_card = savedcard[i];      //use vector to store dealing card pile
        card[i].push_back(added_card);          //use vector to store current cards
        //add a card to the end of each column
        std::this_thread::sleep_for(duration);
        printcard(card, column_number, hidden_position);
        std::cout << "\n" << "\033[5A";
        for (int i = 0; i < max(card); i++)
            std::cout << "\033[2A";
    }
    savedcard.erase(savedcard.begin(), savedcard.begin() + column_number);
    //delete the cards dealt from the dealing pile
}

