
#include "quick_game.h"
using namespace std;



//this fuction is to refresh the screen
void refresh(){
    system("clear");
    printGrid();
    system("sleep 1");
}
extern int steps, marks, GRID_SIZE;
extern vector<vector< block > > grid;

map<int, array<int, 3> > Levels = {
        {0, {8, 10, 10 }},
        {1, {6, 10, 15}},
        {2, {6, 10, 20}}
    };

int quick_game(int level) {
    system("clear");
    srand(static_cast<unsigned int>(time(0))); 
    int SETSTEP, SETMARK;

    steps = 0; marks = 0; GRID_SIZE = 0;                       
    array<int, 3> levelArr = Levels[level];
    GRID_SIZE = levelArr[0];
    SETSTEP = levelArr[1];
    SETMARK = levelArr[2];
    
    
    
    initGrid();

    while (check()){       
        eliminate(); sink(); fall();
        }
    printGrid();

    int invalid=0;               
    while (true){
        int x1, y1, x2, y2;
        int y1_state, x1_state, dir_state;
        
        system("stty -icanon");         //buffer off
        system("stty -echo");          //echo off
        
        if(invalid==1){
           printInvalid('y'); 
        }    
        else if(invalid==2)  
            printInvalid('x');
        else if(invalid ==3)
            printInvalid('d');
        else if(invalid==4)
            printInvalid('u');
        invalid=0;                                //get the coordinates to be changed
        y1_state = inputy1(y1);             //fisrt get the y coordinate  
        
        if (y1_state == -1) return -1;          //if 'q' is pressed, then quit the game
        else if (y1_state == 0){ 
            //printInvalid('y');         //if an invalid y value is pressed, then skip 
            refresh(); 
            invalid=1;
            continue;
            }

        x1_state = inputx1(x1, y1);         //then get the x coordinate
        if(invalid){
           refresh(); 
           invalid=false;
        }    
        if (x1_state == -1) return -1;          //if 'q' is pressed, then quit the game         
        else if (x1_state == 0){                                         //if an invalid x value is pressed, then skip 
            //printInvalid('x');
            refresh(); 
            invalid=2;
            continue;
            }

        input_direction(x1, y1, x2, y2);//Select the direction of the exchange 
        if(invalid){
           refresh(); 
           invalid=false;
        }    
        if (x2 == 0 || x2 > GRID_SIZE ||
            y2 == 0 || y2 > GRID_SIZE){
            //printInvalid('d');
            refresh(); 
            invalid=3;
            continue;
            }
        swap(y1,x1,y2,x2); //refresh();   //swap two blocks selected


        if (check()){   
            marks += check();               //if the exchange is valid, blocks begin to eliminate, fall, fill
            while (true){
                eliminate(); refresh();
                sink(); refresh();
                fall(); refresh();
                marks += check();
                if (check() == 0) break;       
            }
        }                               //if the exchange is invalid, blocks will shift back to the original pattern
        else{ swap(y1,x1,y2,x2); refresh();invalid=4;
        }
        steps ++;
        if ((steps  < SETSTEP) && ( marks > SETMARK)) return 2;
        if ((steps  > SETSTEP) && ( marks < SETMARK)) return -1;


    }
    system("stty echo");           
    system("stty icanon");          
    system("clear");
    return 2;
}
