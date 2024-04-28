#include "poker_crush.h"

extern int GRID_SIZE, steps, marks;// global variables defined in "print_grid.cpp" and "quick_game.cpp"
int state =0;
// main fuction of the game "poker_crush"
//no input, no output
void poker_crush(){
        int state2;
        while (true){
            state2 = choose_mode2(0);
            cout<<"";
            if (state2 == 0)
                instruction2();         // to get into the introduction
            else if(state2==1){         // to quickly start a new game
                int level;
                level = choose_level(0);
                if(level==4)            //quit the game
                    continue;
                else if(level==3)       //enter the infinite mode
                    state2 = quick_game(level,true);
                else                    //start a finite game(with three levels 0 1 2)
                    state2 = quick_game(level);

            if (state2 == -1){          // player loses or quits the game
                    print_not_end(level, steps, marks);
                    continue;
                }
            if (state2 == 2) {          // player wins the game
                    print_end(level, steps, marks);
                    continue;
                }
            }
            else if(state2==2){
                std::cout<<"\033[?25h";
                return ;                //go back to the previous page
            } 
            
        
        }
    
}
