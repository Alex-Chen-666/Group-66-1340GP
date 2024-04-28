//Coding Requirement: Data structures for storing game status: line38
//Coding Requirement: Generation of random game sets or events: line49
#include "print_grid.h"
using namespace std;
//here are three global variables that will be wildly used afterwards
//int GRID_SIZE: to set the size of the grid
//int steps, marks: to record the steps the player has taken and the marks he gas got

int GRID_SIZE = 8, steps = 10, marks = 10;
extern int SETSTEP,SETMARK;// global variables defined in "quick_game.cpp"

////To generate ANSI sequence for character-background color pair
//input: two strings of the colors
//output: corresponding ANSI sequence
string createcolor(const string& foreground, const string& background ) {
    string sequence = "";
    int foregroundIndex = -1;
    int backgroundIndex = -1;
    // (search for character color and background color)
    for (int i = 0; i < 8; ++i) {
        if (foreground == color[i]) {
            foregroundIndex = i;
        }
        if (background == color[i]) {
            backgroundIndex = i;
        }
    }
    // (generate ANSI sequence)
    if (foregroundIndex >= 0 && backgroundIndex >= 0) {
        sequence = "\x1b[" + to_string(30 + foregroundIndex) + ";" + to_string(40 + backgroundIndex) + "m";
    } else if (foregroundIndex >= 0) {
        sequence = "\x1b[" + to_string(30 + foregroundIndex) + "m";
    } else {
        sequence = "\x1b[0m";  // (default is to reset color)
    }

    return sequence;
}
vector<vector<block>> grid;// a 2-D vector to store the board
//to initialize the grid defined above
void initGrid() {
    grid.resize(GRID_SIZE+2,vector<block>(GRID_SIZE+2));
    for (int i = 0; i <= GRID_SIZE; i++) {
        for (int j = 0; j <= GRID_SIZE; j++) {
            if ((i == 0) || (j == 0)){
                grid[i][j].type = -2;}

            else{
            grid[i][j].type = rand() % SUIT_COUNT;// randomly distributed
            grid[i][j].match = 0;}
            }
        }
    }




//to print the block according to the block type
//input: the coordinates of the block to be printed
//       for mood, 1 means it is highlighted, 0 means it is regular
void printunit(int i, int j, int selecting_mood) {
    int index = grid[i][j].type;
    string colortype;
    if (index == -2){
        if (i == 0 && j == 0) {
            cout << "  ";
            return;
        }
        else if  (i == 0){
            cout << to_string(j) << " ";
            return;
        }
        else if  (j == 0){
            cout << to_string(i) << " ";
            return;
        }
    return;}
        
    else if (selecting_mood == 1){
        switch(index){
            case 0:colortype=createcolor( "green", "magenta");
                break;
            case 1:colortype=createcolor( "yellow","magenta");
                break;
            case 2:colortype=createcolor( "red",   "magenta");
                break;
            case 3:colortype=createcolor( "blue",  "magenta");
                break;};
        cout << colortype << SUIT_SYMBOLS[grid[i][j].type];
        cout << " " << "\x1b[0m" ;
        return;}
         
    else if (index != -1 && index != -2 ){
        switch(index){
            case 0:colortype=createcolor("green");
                break;
            case 1:colortype=createcolor("yellow");
                break;
            case 2:colortype=createcolor("red");
                break;
            case 3:colortype=createcolor("blue");
                break;};
    
        cout << colortype << SUIT_SYMBOLS[grid[i][j].type];
        cout << " " << "\x1b[0m" ;
        return; }  
    else {
        cout << "\x1b[0m" <<"  ";} 
        return;
    }




//print out the whole board 
//input: 0 if the player wants to play finite mood
//       1 if the player wants to play infinite mood
void printGrid(bool endless) {
    column_center_print(GRID_SIZE,GRID_SIZE);
    for (int i = 0; i <= GRID_SIZE; i++) {
        column_center_print(GRID_SIZE);
        for (int j = 0; j <= GRID_SIZE; j++) {
            printunit(i,j);}  
        cout << endl;}
    column_center_print(GRID_SIZE);
    if(!endless)
        cout<<"Steps taken: "  <<steps<<"/"<<SETSTEP<<endl;
    else
        cout<<"Steps taken: "  <<steps<<endl;
    column_center_print(GRID_SIZE);
    if(!endless)
        cout<<"Current marks: "<<marks<<"/"<<SETMARK<<endl;
    else
        cout<<"Current marks: "<<marks<<endl;
}




//to print the warning if the player has input invalid information
//input: char m denotes the type of error
void printInvalid(char m) {
    column_center_print(GRID_SIZE);
    cout<<endl;
    column_center_print(GRID_SIZE);
    cout<<createcolor("red")<<"Invalid move!"<<"\x1b[0m"<<endl;
    if (m == 'y'){
        column_center_print(GRID_SIZE);
        cout<< createcolor("red")<<"Invalid y coordinate!"<<"\x1b[0m"<<endl;
    }
    else if (m == 'x'){
        column_center_print(GRID_SIZE);
        cout<< createcolor("red")<<"Invalid x coordinate!"<<"\x1b[0m"<<endl;
    }
    else if (m =='d'){
        column_center_print(GRID_SIZE);
        cout<< createcolor("red")<<"Invalid direction!"<<"\x1b[0m"<<endl;
    }
    else if (m=='u'){
        column_center_print(GRID_SIZE);
        cout<< createcolor("red")<<"A trivial move!"<<"\x1b[0m"<<endl;
    }
    return;
}
