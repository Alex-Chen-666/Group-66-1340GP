//
#include "input_position.h"
using namespace std;
extern int GRID_SIZE;// global variable defined in "print_grid.cpp"


//To handle the input of y coordinate of the chosen coordinate
//input: y1 is changed in a pass-by-reference way
//       will prompt the user to press the keyboard
//output: return integer to control quick_game():
//  -1 if the player press 'q'
//  0 if the player input a valid y coordinate
//  1 if the player input an invalid y coordinate
int inputy1(int& y1) {
    for (int p = 0; p < 1; p++){
        cout << endl;
    }
    column_center_print(10);
    string colortype = createcolor("green");
    cout <<colortype<< "y coordinate (vertical) "<< "\x1b[0m";
    column_center_print(10);
    cout <<colortype<< "press 'q' to quit "<< "\x1b[0m";
    char i = getchar();
    if (i == 'q') 
        {return -1;}
    else if (i - '0' > 0 && i - '0' <= GRID_SIZE){
        y1 = i - '0';
        system("clear");
        column_center_print(GRID_SIZE,GRID_SIZE);
        for (int i = 0; i <= GRID_SIZE; i++) {
            column_center_print(GRID_SIZE);
            
            if (y1 == i){
                for (int j = 0; j <= GRID_SIZE; j++) {
                    printunit(i,j,1);
                    }
                }             //highlight the row the player has chosen
            else {
                for (int j = 0; j <= GRID_SIZE; j++) {
                    printunit(i,j,0);
                    }
                }
        
            cout << endl; }return 1;
    }
    else {return 0;}  
}
//To handle the input of x coordinate of the chosen coordinate
//input: x1 is changed in a pass-by-reference way
//       will prompt the user to press the keyboard
//output: return integer to control quick_game():
//  -1 if the player press 'q'
//  0 if the player input a valid x coordinate
//  1 if the player input an invalid x coordinate
int inputx1( int&x1, int& y1) {
    for (int p=0; p<1; p++){
        cout << endl;
    }
    column_center_print(10);
    string colortype = createcolor("blue");
    cout << colortype << "x coordinate (horizontal) "<< "\x1b[0m";
    column_center_print(10);
    cout <<colortype<< "press 'q' to quit "<< "\x1b[0m";
    char i = getchar();
    if (i == 'q') 
        {return -1;}
    else if (i - '0' > 0 && i - '0' <= GRID_SIZE){
        x1 = i - '0';
        system("clear");
        column_center_print(GRID_SIZE,GRID_SIZE);
        for (int i = 0; i <= GRID_SIZE; i++) {
            column_center_print(GRID_SIZE);
                for (int j = 0; j <= GRID_SIZE; j++) {
                    if (x1 == j && y1 == i ){
                    printunit(i,j,1);
                    }          //highlight the block the player has chosen
                    else{
                    printunit(i,j,0);
                    }
                }
            cout << endl; } return 1;
        }
    else {return 0;}
}

//To handle the input of x,y coordinate of the chosen coordinate to be changed
//input: x2, y2 is changed in a pass-by-reference way
//       will prompt the user to press the keyboard
//judgment of the validity is left in quick_game()
void input_direction(const int& x1, const int& y1, int& x2, int& y2){
    cout << "\x1b[0m";
    column_center_print(12);
    cout << "direction (w a s d)";
    
    char choice = getchar();
    switch (choice) {
        case 'w': y2 = y1 - 1; x2 = x1;
            break;
        case 'a': x2 = x1 - 1; y2 = y1;
            break;
        case 's': y2 = y1 + 1; x2 = x1;
            break;
        case 'd': x2 = x1 + 1; y2 = y1;
            break;
        default:
            x2 = x1; y2 = y1;
            break;
    }}
    
