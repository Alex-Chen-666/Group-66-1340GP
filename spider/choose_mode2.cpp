
//Coolaboration: This part is similar to "choose_mode.cpp" ,
// here we reuse the headfile "choose_mode.h"
#include "choose_mode.h"
//input: flag in pocker_crush() is always 0
//output: state in pocker_crush():
//  0 if the user choose "--Instruction--"
//  1 if the user choose "--Quick Start--"
//  2 if the user choose "--Exit--"
//used in the first mainface of poker crush
int choose_mode2(int flag){
    int path_size1 = 1;
    std::vector<updownchoice> path1(path_size1);      //use vector to store secondary selection interface
    path1[0]={3, 3, 30, 40, "Poker Crush", {"--Instruction--", "--Quick Start--",  "--Exit--"},{ "yellow", "green", "red"}};
    
    for (int i = 0; i <path_size1; i++){    //initialization
        path1[i].mainface = {};
        path1[i].resizemainface();
        path1[i].initialize();
    }
    focus_title(path1);
    char i = 'q';
    system("clear"); 
    printscreen(path1, path_size1, flag);
    
    system("stty -icanon");
    system("stty -echo");
    while (true){
        i = getchar();
        if (i == 'w') {
            path1[0].shiftud("up");
        }
        else if (i == 's') {
            path1[0].shiftud("down");
        }
    
    else if (i == '\n') {
            system("stty echo");
            system("stty icanon");
            system("clear");
            return path1[0].position;
            system("stty -icanon");
            system("stty -echo");
        }
        std::cout << std::endl;
        printscreen(path1, path_size1); 
    }
    system("stty echo");
    system("stty icanon");
    return 1;
}

int choose_level(int flag){
    
    //input: default flag = 0
    //no output
    //used after the first mainface of poker crush
    int path_size2 = 1;
    std::vector<updownchoice> path2(path_size2);      //use vector to store secondary selection interface
    //Secondary selection interface: Instruction, Resume previous game, Start a new game, History record, Clear all history, Exit
    path2[0]={5, 3, 30, 40, "Choose levels: ", {"--Easy--", "--Intermidiate--",  "--Difficult--","--Infinite mode--", "--Exit--"}, {"cyan", "green", "yellow", "red","blue"}};
    
    for (int i = 0; i < path_size2; i++){    //initialization
        path2[i].mainface = {};
        path2[i].resizemainface();
        path2[i].initialize();
    }
    focus_title(path2);
    char i = 'q';
    system("clear"); 
    printscreen(path2, path_size2, flag);

    system("stty -icanon");
    system("stty -echo");
    while (true){
        i = getchar();
        if (i == 'w') {
            path2[0].shiftud("up");
        }
        else if (i == 's') {
            path2[0].shiftud("down");
        }
    
    else if (i == '\n') {
            system("stty echo");
            system("stty icanon");
            system("clear");
            return path2[0].position;
            system("stty -icanon");
            system("stty -echo");
        }
        std::cout << std::endl;
        printscreen(path2, path_size2); 
    }
    system("stty echo");
    system("stty icanon");
    return 1;
}

