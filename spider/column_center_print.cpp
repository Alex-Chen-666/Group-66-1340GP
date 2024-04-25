//Code Requirement: Data structures for storing game status: line9
#include "column_center_print.h"
void column_center_print(int column_num, int row_num){
    /*Center the image on the screen (if no row number is passed in, only the columns are centered).
      Every time a line is printed, the columns are centered once (when there is a carriage return)。
      The rows are centered only once at the beginning.*/
    //input: column number; row number
    //output: centered image on the screen
    struct winsize w;   //use struct to store player's window size
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    int row_size = w.ws_row; 
    int col_size = w.ws_col;
    std::string blank(col_size, ' ');
    if (row_num != 0 && row_num <= row_size){
        for (int i = 0; i < (row_size - row_num) / 2; i++){
            std::cout << blank;
            std::cout << std::endl;
        }
    }
    std::cout << blank << "\n" << "\033[1A";    //clear current line
    for (int i = 0; i < (col_size - column_num) / 2; i++)
        std::cout << "\033[1C";
}

void de_column_center_print(int row_num){
    //The cursor returns to the beginning of the page
    //input: row number
    //output: place the cursor at the beginning of the page
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    int row_size = w.ws_row; 
    int col_size = w.ws_col;
    for (int i = 0; i < (row_size - row_num) / 2 + row_num + 1; i++)
        std::cout << "\033[1A";
}

