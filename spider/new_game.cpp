//Code Requirement: Generation of random game sets or events: line169-183
//                  Data structures for storing game status: line167-214
#include "new_game.h"
void choice_limit(std::vector<updownchoice> &start, int column_position, std::string direction){
    //limit the choices
    //input: choice interface, current column position, moving direction
    //output: the choices are limited
    std::vector<updownchoice> origin_start = start;
    if (start[2].g[start[2].position] == "4"){
        start[0].g = {"10"};
        start[0].row = 1;
        start[0].position = 0;
    }
    if (start[1].g[start[1].position] == "1"){
        if (start[2].g[start[2].position] != "4"){
            start[0].g = {"5", "6", "7"};
            start[0].row = 3;
        }
        
        if (start[0].g[start[0].position] == "5" || start[0].g[start[0].position] == "4" ){
            start[3].g = {"4","5","6"};
            start[3].row = 3;
        }
        else if (start[0].g[start[0].position] == "6" || start[0].g[start[0].position] == "7" ){
            start[3].g = {"2","3","4"};
            start[3].row = 3;
        }
        else if (start[0].g[start[0].position] == "10" ){
            start[3].g = {"2","3"};
            start[3].row = 2;
        }
    }
    else if (start[1].g[start[1].position] == "2"){
        if (start[2].g[start[2].position] != "4"){
            start[0].g = {"6","7","8","9"};
            start[0].row = 4;
        }
        if (start[0].g[start[0].position] == "6" || start[0].g[start[0].position] == "7" ){
            start[3].g = {"6","7","8","9"};
            start[3].row = 4;
        }
        else if (start[0].g[start[0].position] == "8" || start[0].g[start[0].position] == "9" ){
            start[3].g = {"4","5","6","7"};
            start[3].row = 4;
        }
        else if (start[0].g[start[0].position] == "10" ){
            start[3].g = {"4","5"};
            start[3].row = 2;
        }
    }
    else if (start[1].g[start[1].position] == "3"){
        if (start[2].g[start[2].position] != "4"){
            start[0].g = {"8","9","10"};
            start[0].row = 3;
            start[3].g = {"8","9","10"};
            start[3].row = 3; 
        }  
    }
    else if (start[1].g[start[1].position] == "4"){
        if (start[2].g[start[2].position] != "4"){
            start[0].g = {"10"};
            start[0].row = 1;
            start[3].g = {"10"};
            start[3].row = 1;   
        }
    }
    if (column_position == 1){
        start[0].mainface = {};
        start[0].resizemainface();
        start[0].initialize();
        start[3].mainface = {};
        start[3].resizemainface();
        start[3].initialize();
    }
    else if (column_position == 0 && origin_start[3].g != start[3].g){
        start[3].mainface = {};
        start[3].resizemainface();
        start[3].initialize();
    }
    else if (column_position == 2 && ((start[2].g[start[2].position] == "3"&& direction == "up")||(start[2].g[start[2].position] == "4"&& direction == "down"))){
        start[0].mainface = {};
        start[0].resizemainface();
        start[0].initialize();
        start[3].mainface = {};
        start[3].resizemainface();
        start[3].initialize();
    }
}

int Initial_configuration(int &column_num, int &decks_of_card, int &suit_num, int &reserved_chances){
    //initialize game elements
    //input: column number; decks of card; suit number; remaining chances
    //output: update these inputs
    int size = 4,column_position = 0;
    std::vector<updownchoice> start(size);
    start[0] = {3, 3, 18, 18, "Number of columns", 
    {"5", "6", "7"}, {"red", "green", "yellow", "blue", "cyan", "green", "red"}};
    start[1] = {4, 3, 18, 18, "Number of decks", {"1", "2", "3", "4"}, {"red", "green", "yellow", "blue"}};
    start[2] = {4, 3, 18, 18, "Number of suits", {"1", "2", "3", "4"}, {"red", "green", "yellow", "blue"}};
    start[3] = {3, 3, 20, 20, "Number of card dealt", {"4", "5", "6"}, {"red", "green", "yellow", "blue", "cyan", "green"}};
    for (int i = 0; i < size; i++){     //initialization
        start[i].mainface = {};  
        start[i].resizemainface();
        start[i].initialize();
    }
    focus_title(start);
    char i = 'q';
    system("clear");
    
    printscreen(start, size);
    system("stty -icanon");
    system("stty -echo");
    while (i != 'e'){
        i = getchar();
        if (i == 'w'){
            start[column_position].shiftud("up");
            choice_limit(start, column_position,"up");
        }
        else if (i == 's'){
            start[column_position].shiftud("down");
            choice_limit(start, column_position, "down");
        }
        else if (i == 'a')
            shiftlr(start, column_position, "left");
        else if (i == 'd')
            shiftlr(start, column_position, "right");
        else if (i == '\n'){
            system("stty echo");
            system("stty icanon");
            column_num = std::stoi(start[0].g[start[0].position]);
            decks_of_card = std::stoi(start[1].g[start[1].position]);
            suit_num = std::stoi(start[2].g[start[2].position]);
            reserved_chances = std::stoi(start[3].g[start[3].position]);
            system("clear");
            return 0;
            system("stty -icanon");
            system("stty -echo");
        }
        std::cout << std::endl;
        printscreen(start, size); 
    }
    system("stty echo");
    system("stty icanon");
    return 1;
}

void addcolor(std::vector<std::string> &card){
    //color the current cards
    //input: current cards
    //output: colored current cards
    for (int i = 0; i < card.size(); i++) {
        if (card[i].substr(0,3) == "♥" || card[i].substr(0, 3) == "♦" )
            card[i] = "\033[31m" + card[i] + "\033[0m";
        
        else if (card[i].substr(0, 3) == "♠" || card[i].substr(0, 3) == "♣" )
            card[i] = "\033[38m" + card[i] + "\033[0m";
    }
}

void random_dealing_cards(std::vector<std::vector<std::string>> &card, std::vector<std::string> &reserved_card, 
                            int color_num, int decks_of_card, int column, int reserved_chances, int *hidden_position){
    //randomly deal the cards
    /*input: current cards; dealing card pile; color number; decks of card; column number; remaining chances; 
            a dynamic array with the number of rows of the first turned card in each column */
    //output: deal the cards at random
    //use different vectors to store different elements
    std::vector<std::string> color = {"♥", "♦", "♠", "♣"};
    std::string number[] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "K", "Q"};
    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle(color.begin(), color.end(), gen);
    std::vector<std::string> card_box, total_card;
    std::chrono::milliseconds duration(50);
    for (int i = 0; i < column; i++)
        hidden_position[i] = 1;
    for (int i = 0; i < color_num; i++){    //generate all possible cards
        for (int ii = 0; ii < 13; ii++)
            card_box.push_back(color[i] + number[ii]);
    }
    for (int i = 0; i < decks_of_card * 52 / card_box.size(); i++){
        std::shuffle(card_box.begin(), card_box.end(), gen);        //Generation of random game sets or events
        total_card.insert(total_card.end(),card_box.begin(),card_box.end());
    }
    addcolor(total_card);
    reserved_card.assign(total_card.begin(), total_card.begin() + column * reserved_chances);     //deal cards from dealing card pile
    total_card.erase(total_card.begin(), total_card.begin() + column * reserved_chances);
    int card_num_per_column = total_card.size() / column;
    int difference = total_card.size() % column;
    for (int ii = 0; ii < card_num_per_column; ii++){
        for (int i = 0; i < column; i++){
            if (!(i >= difference && ii == card_num_per_column - 1))
                hidden_position[i] += 1;
        card[i].insert(card[i].end(), total_card.begin(), total_card.begin() + 1);
        std::this_thread::sleep_for (duration);
        printcard(card, column, hidden_position);
        std::cout << "\n" << "\033[7A";
        for (int i = 0; i < card[i].size(); i++)
            std::cout << "\033[2A";

        total_card.erase(total_card.begin(), total_card.begin() + 1);
        }
    }
    
    for (int i = 0; i < difference; i++){
        card[i].insert(card[i].end(), total_card.begin(), total_card.begin() + 1);
        std::this_thread::sleep_for (duration);
        printcard(card, column, hidden_position);
        std::cout << "\n" << "\033[7A";
        for (int i = 0; i < card[i].size(); i++)
            std::cout << "\033[2A";

        total_card.erase(total_card.begin(), total_card.begin() + 1);
    }
}

int new_game(int & column_number, int &reserved_chances, int &decks_of_card, int &suit_num, int * &hidden_position, 
                std::vector<std::vector<std::string>> &card, std::vector<std::string> &savedcard, int &step){
    //update the elements and randomly assign values
    /*input: column number; remaining chances; decks of card; suit number;
        a dynamic array with the number of rows of the first turned card in each column; current cards; dealing card pile; steps */
    //output: assign random values to the elements
    int state = Initial_configuration(column_number, decks_of_card, suit_num, reserved_chances);
    if (state == 1)
        return 1;
    step = 0;
    hidden_position = new int[column_number];
    card.resize(column_number);
    random_dealing_cards(card, savedcard, suit_num, decks_of_card, column_number, reserved_chances, hidden_position);
    system("clear");
    return 0;
}

