//Coding Requirement: Generation of random game sets or events: line17
//Coding Requirement: Data structures for storing game status:  line25

#include "quick_game.h"
using namespace std;

int SETSTEP, SETMARK; // global variable to determined the level of the game
extern int steps, marks, GRID_SIZE;
extern vector<vector< block > > grid;// global variable defined in "print_grid.cpp"

void refresh(bool endless){
    system("clear");
    printGrid(endless);
    system("sleep 1");
}

map<int, array<int, 3> > Levels = {//using map to decide the level of the game
        {0, {8, 10, 25}},
        {1, {6, 10, 25}},
        {2, {6, 10, 30}},
        {3, {9, 0,   0}}
    };
//the second game "poker_crush" starts here
//input: int level,bool endless to determine the game difficulty
//output：return whether the game is successfully completed or not
int quick_game(int level,bool endless) {
    system("clear");
    srand(static_cast<unsigned int>(time(0))); // set the seed for rand()
    steps = 0; marks = 0; GRID_SIZE = 0;                       
    array<int, 3> levelArr = Levels[level]; 
    GRID_SIZE = levelArr[0];
    SETSTEP = levelArr[1];
    SETMARK = levelArr[2];
    initGrid();

    while (check()){       
        eliminate(); sink(); fall();
        }
    printGrid(endless);  //to ensure there is no match in the the original map 

    int invalid=0;               
    while (true){
        int x1, y1, x2, y2;
        int y1_state, x1_state, dir_state;
        
        system("stty -icanon");         //buffer off
        system("stty -echo");          //echo off
        
        if(invalid==1)              
            printInvalid('y');   
        else if(invalid==2)         
            printInvalid('x');
        else if(invalid ==3)        
            printInvalid('d');
        else if(invalid==4)         
            printInvalid('u');              //print the error information
        invalid=0;

                                       
        y1_state = inputy1(y1);             //start reading the y coordinate            
        if (y1_state == -1) 
            return -1;                      //if the player presses 'q', then quit
        else if (y1_state == 0){            //if an invalid y value is pressed, then skip
            refresh(endless); 
            invalid=1;
            continue; 
        }
        x1_state = inputx1(x1, y1);         //start reading the y coordinate
        if (x1_state == -1) 
            return -1;                      //if the player presses 'q', then quit
        else if (x1_state ==  0){           //if an invalid x value is pressed, then skip 
            refresh(endless); 
            invalid=2;
            continue;
        }
        ++steps;
        input_direction(x1, y1, x2, y2);    //Select the direction of the exchange
        if (x2 == 0 || x2 > GRID_SIZE+1 ||
            y2 == 0 || y2 > GRID_SIZE+1){
            refresh(endless); 
            invalid=3;                      ////if an invalid direction is pressed, then skip 
            continue;
        }
        swap(y1,x1,y2,x2);  //swap two blocks selected


        if (check()){   
            marks += check();               //if the exchange is valid, blocks begin to eliminate, fall, fill
            while (true){
                marks += eliminate();       //add the marks 
                refresh(endless);
                sink(); refresh(endless);
                fall(); refresh(endless);
                if (check() == 0) break;       
            }
        }                               
        else{refresh(endless);              //if the exchange is invalid, blocks will shift back to the original pattern
            swap(y1,x1,y2,x2); 
            refresh(endless);
            invalid=4;
        }
        if(!endless){
            if ((steps  < SETSTEP) && ( marks > SETMARK)) return 2;
            if ((steps  > SETSTEP) && ( marks < SETMARK)) return -1;
        }
        


    }
    system("stty echo");           
    system("stty icanon");          
    system("clear");
    return 2;
}
