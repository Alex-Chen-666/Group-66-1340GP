//Code Requirement: Data structures for storing game status: line246-247
//                  Dynamic memory management: line246-247
#include "instruction.h"
using namespace std;
void wait_enter(int length){
    //wait for the player to press 'enter'
    //input: center length
    //output: prompt for invalid input; wait for player to press 'enter'
    char order;
    system("stty -icanon");
    system("stty -echo");
    while (order != '\n'){
        order = getchar();
        if (order != '\n'){
            std::cout << "                                                       " << "\033[55D";
            column_center_print(length);
            std::cout << "\033[31mInvalid input,please try again.\033[0m" << std::flush;
            std::cout << "\033[1A" << std::endl;
        }          
    }
}

void live(std::string instruction[], int instruction_line_num, std::string address, std::string command){
    //live demonstration for the example
    //input: instruction; line number of instruction; address of example; command
    //output: show live demonstration of the example
    std::cout<<"\033[?25l";
    int flag = 0;
    int column_number, reserved_chances, decks_of_card, suit_num, step;
    int * hidden_position = new int[1];
    std::vector<std::vector<std::string>> card;
    std::vector<std::string> savedcard;
    for (int i = 0; i < instruction_line_num; i++){
        if (i == 0)
            column_center_print(instruction[0].length(), 1);
        else
            column_center_print(instruction[0].length());
        if (i != instruction_line_num - 1)
            std::cout << instruction[i];
        else
            std::cout << instruction[i] << std::endl;
    }
    
    column_center_print(instruction[0].length());
    std::cout << "\033[36m    press enter to continue\033[0m\n";
    wait_enter(instruction[0].length());
    loading(address, flag, column_number, reserved_chances, decks_of_card, suit_num, step, hidden_position, card, savedcard);
    system("clear");
    if (flag == 1){     //fail to import
        column_center_print(22, 1);
        std::cout << "Error in file opening!" << std::endl;
        column_center_print(22);
        std::cout << "\033[36mpress enter to continue\033[0m\n";
        flag = 0;   //reset flag
    }
    else{
        printcard(card, column_number, hidden_position);
        printreservedcard(card, reserved_chances, column_number, max(card));
        std::cout << "\033[?25l";
        column_center_print(6 + 8 * column_number + 6);
        std::cout << "Step: " << step << std::endl;
        column_center_print(6 + 8 * column_number + 6);
        std::cout << "please input your command.\n";
        if (command != "stalemate" && command != "probably stalemate"){
            column_center_print(6 + 8 * column_number + 6);
            std::cout << command << std::endl;      //print specific command
        }        
        column_center_print(6 + 8 * column_number + 6);
        std::cout << "\033[36mpress enter to continue\033[0m\n";
        wait_enter(6 + 8 * column_number + 6);
        if (command == "stalemate"){
            column_center_print(6 + 8 * column_number + 6);
            std::cout << "\033[1A" << "                          " << "\033[26D";
            std::cout << "Hint: you are in a stalmate now." << std::endl;
            column_center_print(6 + 8 * column_number + 6);
            std::cout << "\033[36mpress enter to continue\033[0m\n";
        }
        else if (command == "probably stalemate"){
            column_center_print(6 + 8 * column_number + 6);
            std::cout << "\033[1A" << "                          " << "\033[26D";
            std::cout<<"Hint: you will probably have no meaningful move after several steps."<<std::endl;
            column_center_print(6 + 8 * column_number + 6);
            std::cout << "\033[36mpress enter to continue\033[0m\n\n";
        }
        else{
            column_center_print(6 + 8 * column_number + 6);
            int flag = valid(command, card, hidden_position, column_number, reserved_chances);
            std::cout << "\033[?25l";
            if (flag == 0){
                column_center_print(6 + 8 * column_number + 6);
                std::cout << "\033[36mpress enter to continue\033[0m\n";
            }
            
            if (flag == 2){
                column_center_print(6 + 8 * column_number + 6);
                std::cout << "\033[1A" << "                          " << "\033[26D";
                std::cout << "Back up or not?[y/n]" << std::endl;       //ask the player whether to save the game
                column_center_print(6 + 8 * column_number + 6);
                std::cout << "n\n";
                column_center_print(6 + 8 * column_number + 6);
                std::cout << "\033[36mpress enter to continue\033[0m\n";
            }
            if (flag == 3){
                std::cout << "\033[2K\r";
                std::istringstream line(command);
                int counter = 0;
                std::string word, arr[3];
                while (line >> word){
                    arr[counter] = word;
                    counter += 1;
                }
                int col_from, start_row, col_to;
                if (counter == 2)
                    col_from = stoi(arr[0]), start_row = card[col_from - 1].size(), col_to = stoi(arr[1]);
                else
                    start_row = stoi(arr[1]), col_from = stoi(arr[0]), col_to = stoi(arr[2]);
                step++;
                move(card, reserved_chances, column_number, col_from, col_to, start_row, hidden_position);
                //drag the cards

                for (int i = 0; i < column_number; i++)
                    remove_complete_deck(card, hidden_position, i, column_number, reserved_chances);

                printcard(card, column_number, hidden_position);
                printreservedcard(card, reserved_chances, column_number, max(card));
                std::cout << "\033[?25l";
                column_center_print(6 + 8 * column_number + 6);
                std::cout << "Step: " << step << std::endl;
                column_center_print(6 + 8 * column_number + 6);
                std::cout << "\033[36mpress enter to continue\033[0m\n";
            }
        }
    }
    wait_enter(6 + 8 * column_number + 6);
}

void read(int page, vector<int> pages_start, vector<int>pages_end){
    //print the specific page in the instruction.txt
    /*input: an int representing the page to be printed; a vector storing the line number of the first line of each page; 
             a vector storing the line number of the last line of each page */
    //output: print specific page and showcase animation examples
    ifstream fin;
    fin.open("instruction.txt");
    if (fin.fail())
        exit(1);
    string line;
    int currentLine = 1;
    bool line_num = true;
    while (getline(fin, line)){
        if (currentLine >= pages_start[page - 1] && currentLine <= pages_end[page - 1]){     
            if (currentLine == pages_start[1]){
                std::string instruction[1];
                instruction[0] = line;
                live(instruction, 1, "./example/1.txt", "2 1");
                return;
            }
            else if (currentLine == pages_start[2]){
                std::string instruction[2];
                instruction[0] = line;
                getline(fin, line);
                instruction[1] = line;
                currentLine++;
                live(instruction, 2, "./example/2.txt", "2 3");
                return;
            }
            else if (currentLine == pages_start[3]){
                std::string instruction[3];
                instruction[0] = line;
                getline(fin, line);
                instruction[1] = line;
                currentLine++;
                getline(fin, line);
                instruction[2] = line;
                currentLine++;
                live(instruction, 3, "./example/3.txt", "1 3 2");
                return;
            }
            else if (currentLine == pages_start[4]){
                std::string instruction[2];
                instruction[0] = line;
                getline(fin, line);
                instruction[1] = line;
                currentLine++;
                live(instruction, 2, "./example/4.txt", "2 1");
                return;
            }
            else if (currentLine == pages_start[5]){
                std::string instruction[3];
                instruction[0] = line;
                getline(fin, line);
                instruction[1] = line;
                currentLine++;
                getline(fin, line);
                instruction[2] = line;
                currentLine++;
                live(instruction, 3, "./example/5.txt", "r");
                return;
            }
            else if (currentLine == pages_start[9]){
                std::string instruction[1];
                instruction[0] = line;
                live(instruction, 1, "./example/1.txt", "q");
                return;
            }
            else if (currentLine == pages_start[11]){
                std::string instruction[1];
                instruction[0] = line;
                live(instruction, 1, "./example/6.txt", "stalemate");
                return;
            }
            else if (currentLine == pages_start[12]){
                std::string instruction[4];
                instruction[0] = line;
                getline(fin, line);
                instruction[1] = line;
                currentLine++;
                getline(fin, line);
                instruction[2] = line;
                currentLine++;
                getline(fin, line);
                instruction[3] = line;
                currentLine++;
                live(instruction, 4, "./example/7.txt", "probably stalemate");
                return;
            }
            else{
               if (line_num){
                    column_center_print(90, pages_end[page - 1] - pages_start[page - 1] + 1);
                    line_num = false;
                }
                else
                    column_center_print(90);
                cout << line << endl;  
            }
            
        }
        currentLine++;
    }
    fin.close();
}

void instruction(){
    //print the instruction.txt and showcase animation examples
    //no input
    //no output
    vector<int>pages_start = {1, 19, 20, 22, 25, 27, 30, 37, 68, 72, 73, 89, 90, 94};
    vector<int>pages_end = {18, 19, 21, 24, 26, 29, 36, 67, 71, 72, 88, 89, 93, 99};    //use vector here to store the beginning line and ending line of each page
    int page = 1;
    std::cout << "\033[?25l";
    while (true){
        system("clear");
        read(page, pages_start, pages_end);
        if (page != 1){
            cout << "\n\n";
            column_center_print(90);
            cout << "\033[36mIf you want to see the example again, press 't';\033[0m" << endl;
        }
        if (page != 1){
            column_center_print(90);
            cout << "\033[36mReturn to the previous page, press 'p';\033[0m" << endl;
        }
        if (page != 14){
            column_center_print(90);
            cout << "\033[36mContinue to next page, press 'c'\033[0m" << endl;
        }
        column_center_print(90);
        cout << "\033[36mQuit, press 'q'.\033[0m" << endl;
        char input;
        std::cin.clear();
        system("stty -icanon"); 
        system("stty -echo");
        input = getchar();
        while (true){
            if (input == 't')
                break;
            else if (input == 'p' && page > 1){
                page-=1;
                break;
            }
            else if (input == 'c' && page < 14){
                page += 1;
                break;
            }
            else if (input == 'q'){
                std::cout << "\033[?25h";
                return;
            }
            else{
                std::cout << "\033[40D" << "                                                       " << "\033[55D";
                column_center_print(90);
                std::cout << "\033[31mInvalid input,please try again.\033[0m" << std::flush;
                std::cout << "\033[1A" << std::endl;
                input = getchar();
            }
        }
        system("clear");
            
    }
    std::cout << "\033[?25h";
}
