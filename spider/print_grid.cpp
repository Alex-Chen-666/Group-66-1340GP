#include "print_grid.h"

using namespace std;
int GRID_SIZE = 8, steps = 10, marks = 10;
string createcolor(const string& foreground, const string& background ) {
    string sequence = "";
    int foregroundIndex = -1;
    int backgroundIndex = -1;
    // 查找前景色和背景色的索引
    for (int i = 0; i < 8; ++i) {
        if (foreground == color[i]) {
            foregroundIndex = i;
        }
        if (background == color[i]) {
            backgroundIndex = i;
        }
    }
    // 生成 ANSI 转义序列
    if (foregroundIndex >= 0 && backgroundIndex >= 0) {
        sequence = "\x1b[" + to_string(30 + foregroundIndex) + ";" + to_string(40 + backgroundIndex) + "m";
    } else if (foregroundIndex >= 0) {
        sequence = "\x1b[" + to_string(30 + foregroundIndex) + "m";
    } else {
        sequence = "\x1b[0m";  // 默认为重置颜色(default is to reset color)
    }

    return sequence;
}
vector<vector<block>> grid;
void initGrid() {
    grid.resize(GRID_SIZE+2,vector<block>(GRID_SIZE+2));
    for (int i = 0; i <= GRID_SIZE; i++) {
        for (int j = 0; j <= GRID_SIZE; j++) {
            if ((i == 0) || (j == 0)){
                grid[i][j].type = -2;}

            else{
            grid[i][j].type = rand() % SUIT_COUNT;
            grid[i][j].match = 0;}
            }
        }
    }


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


void printGrid() {
    column_center_print(GRID_SIZE,GRID_SIZE);
    for (int i = 0; i <= GRID_SIZE; i++) {
        column_center_print(GRID_SIZE);
        for (int j = 0; j <= GRID_SIZE; j++) {
            printunit(i,j);}  
        cout << endl;}
    column_center_print(GRID_SIZE);
    cout<<"Steps taken: "<<steps<<endl;
    column_center_print(GRID_SIZE);
    cout<<"Current marks: "<<marks<<endl;
    }


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
