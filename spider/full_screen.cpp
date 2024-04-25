//Code Requirement: File Input/Output: line15
#include "full_screen.h"
void full_screen(){
    //check whether this is full screen
    //no input
    //output: prompt message
    struct winsize w;
    int time = 10, odd_and_even = 0;   //time represents the remaining time, wait for 10 seconds to start directly, every second time-=1, 
                                        //odd_and_even represents whether it is 0.5 seconds or 1 second
    std::chrono::milliseconds duration(500);
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    int row_size = w.ws_row; 
    int col_size = w.ws_col;
    system("stty -echo");
    std::ifstream nullInput("/dev/null");       //open "/dev/null" (write only)
    std::streambuf* originalInputBuffer = std::cin.rdbuf();
    std::cin.rdbuf(nullInput.rdbuf());      //redirect input to /dev/null
    if (row_size < 35 || col_size <= 120){
        std::cout << "\033[?25l";
        system("clear");
        column_center_print(77,1);
        std::cout << "Not enough screen space. Please adjust to FULL screen mode to start this game." << std::endl;
        column_center_print(1);
        std::cout << time << std::endl;
    }
    while ((row_size < 35 || col_size <= 120) && (time != 0)){
        if (odd_and_even == 0){
            odd_and_even++;
        } 
        else{
            odd_and_even = 0;
            time--;
        }
        std::this_thread::sleep_for(duration);
        ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
        if (row_size != w.ws_row || col_size != w.ws_col){
            row_size = w.ws_row;
            col_size = w.ws_col;
            if (row_size < 35 || col_size <= 120){
                std::cout << "\033[?25l";
                system("clear");
                column_center_print(77, 1);
                std::cout << "Not enough screen space. Please adjust to FULL screen mode to start this game." << std::endl;
                column_center_print(1);
                std::cout << time << std::endl;
            }
        }
        std::cout << "\033[1A";
        column_center_print(1); 
        std::cout << "                                                       " << "\033[55D";
        std::cout << time << std::endl;
        
    }
    std::cin.rdbuf(originalInputBuffer);    //restore the original input stream buffer
}

