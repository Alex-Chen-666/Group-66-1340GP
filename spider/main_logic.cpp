#include "main_logic.h"
using namespace std;
extern int GRID_SIZE;
extern vector<vector<block>> grid;


void swap(int y1, int x1, int y2, int x2){
    block temp = grid[y1][x1];
    grid[y1][x1].type = grid[y2][x2].type;
    grid[y2][x2].type = temp.type; 
}
int check(){
    int count = 0;
    for (int i = 1; i <= GRID_SIZE; i++) {
        for (int j = 1; j <= GRID_SIZE; j++) {
            if (grid[i][j].type == grid[i-1][j].type&&
                grid[i][j].type == grid[i+1][j].type){
                grid[i-1][j].match++;
                grid[i][j].match++;
                grid[i+1][j].match++;
                count++;}
            if (grid[i][j].type == grid[i][j+1].type&&
                grid[i][j].type == grid[i][j-1].type){
                grid[i][j-1].match++;
                grid[i][j].match++;
                grid[i][j+1].match++;
                count++;}
        }
    }      
    return count;
}
 
void eliminate(){
    for (int i = 1; i <= GRID_SIZE; i++) {
        for (int j = 1; j <= GRID_SIZE; j++) {
            if (grid[i][j].match > 0) {
                grid[i][j].type = -1;
                grid[i][j].match = 0; }
    }}}

void sink(){
    for (int i = GRID_SIZE; i > 0; i--) {
        for (int j = 1; j <= GRID_SIZE; j++) {
            if (grid[i][j].type == -1){
                for (int k = i-1; k > 0; k--){
                    if (grid[k][j].type != -1){
                        swap (k,j,i,j); break;}
    }}}}}

void fall(){
    for (int i = GRID_SIZE; i > 0; i--) {
        for (int j = 1; j <= GRID_SIZE; j++) {
            if (grid[i][j].type == -1){
                grid[i][j].type = rand() % SUIT_COUNT;
    }}}}
