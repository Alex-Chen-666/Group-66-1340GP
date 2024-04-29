//Code Requirement: Data structures for storing game status: line3-5
#include "game_process.h"
int game_process(int column_number, int reserved_chances, int decks_of_card, int suit_num, int step,
                int * hidden_position, std::vector<std::vector<std::string>> card, 
                std::vector<std::string> savedcard, int &total_file_index){
    //control the overall game process
    /*input: column number; remaining chances; decks of card; suit number; steps; a dynamic array with the number of rows of 
            the first turned card in each column; current cards; dealing card pile; the number of total file indexes */
    //output: game in progress
    //use different vectors to store game status
    printcard(card, column_number, hidden_position);
    printreservedcard(card, reserved_chances, column_number, max(card));
    column_center_print(6 + 8 * column_number + 6);
    std::cout << "Step: " << step << std::endl;

    std::string input;
    column_center_print(6 + 8 * column_number + 6);
    std::cout << "please input your command.\n";
    column_center_print(6 + 8 * column_number + 6);
    std::cout << "'q':quit;\n";
    column_center_print(6 + 8 * column_number + 6);
    std::cout << "'r':deal;\n";
    column_center_print(6 + 8 * column_number + 6);
    std::cout << "'a b c':move the card in column a, row b" << std::endl;
    column_center_print(6 + 8 * column_number + 6);
    std::cout << "and cards below it(if any) to column c." << std::endl;
    column_center_print(6 + 8 * column_number + 6);
    std::cout << "or 'a c': move the bottom card of column a to column c" << std::endl;
    column_center_print(6 + 8 * column_number + 6);
    if (std::cin.peek() == '\n')
        std::cin.ignore();
    getline(std::cin, input);
    std::string outcome = "Unfinished";
    while (true){
        column_center_print(6 + 8 * column_number + 6);
        int flag = valid(input,card,hidden_position,column_number,reserved_chances);
        if (flag){
            if (flag == 1){     //deal cards
                reserved_chances -= 1;
                deal(card, savedcard, column_number, hidden_position, reserved_chances);
                for (int i = 0; i < column_number; i++)
                    remove_complete_deck(card, hidden_position, i, column_number, reserved_chances);
                printcard(card, column_number, hidden_position);
                printreservedcard(card, reserved_chances, column_number, max(card));
                column_center_print(6 + 8 * column_number + 6);
                std::cout << "Step: " << step << std::endl;
            }
            else if (flag == 2){
                std::cout << "\033[2K\r";
                column_center_print(6 + 8 * column_number + 6);
                std::cout << "Back up or not?[y/n]" << std::endl;       //ask whether the player wants to save current game
                std::string answer, choice;
                column_center_print(6 + 8 * column_number + 6);
                getline(std::cin, answer);
                while (!validinput(answer)){
                    column_center_print(6 + 8 * column_number + 6);
                    printAndClearLine("Invalid input. Please try again.[y/n]");
                    column_center_print(6 + 8 * column_number + 6);
                    getline(std::cin, answer);
                }
                column_center_print(6 + 8 * column_number + 6);
                std::cout << "                                   " << std::endl;
                for (char i:answer){
                    if (isalpha(i))
                        choice = i;
                }

                if (choice == "y"){    //save current game
                    int tmp = save(column_number, reserved_chances, decks_of_card, suit_num, \
                        step, hidden_position, card, savedcard, outcome);
                    total_file_index++;
                }

                return 1;
            }

            else{   //drag cards
                std::cout << "\033[2K\r";
                std::istringstream line(input);
                int counter = 0;
                std::string word,arr[3];
                while (line >> word){
                    arr[counter] = word;
                    counter += 1;
                }
                int col_from, start_row, col_to;
                if (counter == 2){
                    col_from = stoi(arr[0]), start_row = card[col_from-1].size(), col_to = stoi(arr[1]);
                }
                else{
                    start_row = stoi(arr[1]),col_from = stoi(arr[0]),col_to = stoi(arr[2]);
                }
                step++;
                move(card, reserved_chances, column_number, col_from, col_to, start_row, hidden_position);

                for (int i = 0; i < column_number; i++){
                    remove_complete_deck(card, hidden_position, i, column_number, reserved_chances);
                }
                printcard(card, column_number, hidden_position);
                printreservedcard(card, reserved_chances, column_number, max(card));
                column_center_print(6 + 8 * column_number + 6);
                std::cout << "Step: " << step << std::endl;
            }

            //When the card dealing opportunities are exhausted, it will automatically detect whether a stalemate is reached.
            //If stalemate, it will prompt.
            if (reserved_chances == 0){
                std::vector<std::vector<std::vector<std::string>>> visited;
                int flag = stalemate(card, visited, hidden_position, column_number, 0);
                if (flag == 2){
                    column_center_print(6 + 8 * column_number + 6);
                    std::cout << "Hint: you will probably have no meaningful moves in less than 9 steps." << std::endl;
                    outcome = "Probably Stalemate";
                }
                else if (flag == 3){
                    column_center_print(6 + 8 * column_number + 6);
                    std::cout << "Hint: you are in a stalmate now." << std::endl;
                    outcome = "Stalemate";
                }
                visited.clear();
                if (finish(card, column_number)){   //finished
                    outcome = "Success";
                    column_center_print(6 + 8 * column_number + 6);
                    std::cout << "Congratulations!" << std::endl;
                    column_center_print(6 + 8 * column_number + 6);
                    std::cout << "Back up or not?[y/n]" << std::endl;       //ask whether the player wants to save current game
                    std::string answer, choice;
                    column_center_print(6 + 8 * column_number + 6);
                    getline(std::cin, answer);
                    while (!validinput(answer)){
                        column_center_print(6 + 8 * column_number + 6);
                        printAndClearLine("Invalid input. Please try again.[y/n]");
                        column_center_print(6 + 8 * column_number + 6);
                        getline(std::cin, answer);
                    }
                    column_center_print(6 + 8 * column_number + 6);
                    std::cout << "                                   " << std::endl;
                    for (char i:answer){
                        if (isalpha(i))
                            choice = i;
                    }

                    if (choice == "y"){    //save current game
                        int tmp = save(column_number, reserved_chances, decks_of_card, suit_num, \
                            step, hidden_position, card, savedcard, outcome);
                        total_file_index++;
                    }

                    return 1;
                }                
            }
        }
        
        else{
            column_center_print(6 + 8 * column_number + 6);
            getline(std::cin, input);
            continue;
        }
        
        column_center_print(6 + 8 * column_number + 6);
        std::cout << "Please input your command." << endl;
        column_center_print(6 + 8 * column_number + 6);
        getline(std::cin, input);
    }
}

