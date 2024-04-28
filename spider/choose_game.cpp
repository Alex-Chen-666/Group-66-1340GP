//Coding Requirement: Dynamic memory management: line9
#include "choose_game.h"
int choose_game(int flag){
    //let the player select the game he wants to play (or exit)
    //input: default flag = 0
    //output: return 0 to start "Spider Solitaire"; return 1 to start "Poker crush"; return 2 to exit
    
    int path_size = 1;
    std::vector<updownchoice> path(path_size);     //use vector to store main interface
    path[0] = {3, 3, 30, 40, "Poker Carnival", {"--Spider Solitaire--", "--Poker crush--",  "--Exit--"}, 
    {"cyan", "green", "red", "yellow", "green", "blue", "red"}};
    //Main interface: Spider Solitaire, match-3 , Exit

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
        if (i == 'w') {
            path[0].shiftud("up");
        }
        else if (i == 's') {
            path[0].shiftud("down");
        }
    
    else if (i == '\n') {
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
