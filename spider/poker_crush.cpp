//Data structures for storing game status :9,10,11
//Dynamic memory management:10, 94
#include "poker_crush.h"

extern int GRID_SIZE, steps, marks;
int state =0;
void poker_crush(){//主函数

        /*int column_number, reserved_chances, decks_of_card, suit_num, step;//列数，中间发牌次数（中途要不断减一），几副牌（一副52张），花色数
        int * hidden_position = new int[1]; //Data structures for storing game status, Dynamic memory management 
        std::vector<std::vector<std::string>> card;//已经发的牌 Data structures for storing game status 
        std::vector<std::string> savedcard;//发牌堆的牌  Data structures for storing game status */
        int state2;//flag用于判断是否需要打印提示，0不用，1打印打开失败，2打印没有历史记录
        while (true){
            state2 = choose_mode2(0);
            cout<<"";
            if (state2 == 0){//教程,之后要继续选择
                instruction2();   }
            else if(state2==1){//新游戏
                int level;
                level = choose_level(0);
                if(level==3)
                    continue;
                state2 = quick_game(level);
                if (state2 == -1){
                    print_not_end(level, steps, marks);
                    continue;
                }
                if (state2 == 2) {
                    print_end(level, steps, marks);
                    continue;
                }
            }
            else if(state2==2){
                std::cout<<"\033[?25h";
                return ;             //直接退出
            } 
            
        
        }
    
}
