//Coding Requirement: Data structures for storing game status: line8
#include "choose_mode.h"
int choose_mode(int flag){
    //let the player select game mode
    //input: prompt information (default flag = 0)
    //no output
    int path_size = 1;
    std::vector<updownchoice> path(path_size);      //use vector to store secondary selection interface
    path[0]={6, 3, 30, 40, "Spider Solitaire", {"--Instruction--", "--Resume previous game--", "--Start a new game--", "--History record--", "--Clear all history--", "--Exit--"}, 
    {"cyan", "green", "red", "yellow", "green", "blue", "red"}};
    //Secondary selection interface: Instruction, Resume previous game, Start a new game, History record, Clear all history, Exit
    for (int i = 0; i < path_size; i++){    //initialization
        path[i].mainface = {};
        path[i].resizemainface();
        path[i].initialize();
    }
    focus_title(path);
    char i = 'q';
    system("clear"); 
    printscreen(path, path_size, flag);
    
    system("stty -icanon");
    system("stty -echo");
    while (true){
        i = getchar();
        if (i == 'w')
            path[0].shiftud("up");
        else if (i == 's')
            path[0].shiftud("down");
    
    else if (i == '\n'){
            system("stty echo");
            system("stty icanon");
            system("clear");
            return path[0].position;
            system("stty -icanon");
            system("stty -echo");
        }
        std::cout << std::endl;
        printscreen(path, path_size); 
    }
    system("stty echo");
    system("stty icanon");
    return 1;
}
