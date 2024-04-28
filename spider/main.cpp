#include "spider.h"
#include "choose_game.h"
#include "poker_crush.h"
#include "animation.h"
#include "full_screen.h"
int main(){
    full_screen();
    animation();
    int state;      //flag用于判断是否需要打印提示，0不用，1打印打开失败，2打印没有历史记录
    while (true){
        state = choose_game(0);
        if (state == 0)
            spider();

        else if (state == 1)
            poker_crush();

        
        else if (state == 2){
            return 0;
        }
    }
    
}
