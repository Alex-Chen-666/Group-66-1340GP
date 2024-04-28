//feature  file I/O in line 7
//This part serves to print the introduction of the second game "poker_crush"
#include "instruction2.h"
void instruction2() {
    std::ifstream file("instruction2.txt");

    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::cout << line << std::endl;
        }
        file.close();
    } else {
        std::cout << "Failed to open the file." << std::endl;
    }

    column_center_print(90);
    std::cout << "\033[34mQuit, press 'q'.\033[0m" <<std:: endl;

    char input;
    std::cin.clear();
    system("stty -icanon"); 
    system("stty -echo");
    input = getchar();

    while (true){
        if (input == 'q'){
            std::cout << "\033[?25h";
            return;
            }
        else{
            std::cout << "\033[40D" << "                                                       " << "\033[55D";
            column_center_print(90);
            std::cout << "\033[31mInvalid input,please try again.\033[0m" << std::flush;
            std::cout << "\033[1A" << std::endl;
            input = getchar();
            system("clear");
        }
    }
    std::cout << "\033[?25h";
}


   
