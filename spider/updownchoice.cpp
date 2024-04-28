//Code Requirement: 
//feature: create the choice mainface that can be controlled instantly without enter
#include "updownchoice.h"
std::string updownchoice::createcolor(std::string back_color, std::string string_color){
        //add colors to sequence
        //input: color; targeted sequence
        //output: colored sequence
        std::string target;
        for (int i = 0; i < 8; i++){
            if(color[i] == back_color)
                    target = ANSItitle+"3"+std::to_string(i) + ";";     //foreground color
        }
        for (int i = 0; i < 8; i++){
            if (color[i] == string_color)       //background color
                return target + "4" + std::to_string(i) + "m";
        }
        return target + "48m";
}

void updownchoice::initialize(){
    //initialize every column
    //no input
    //output: initialized column
    if (title.substr(0,2) != "\033[")     //prevent title from being recolored
        title = createcolor("white") + createCenterAligned(title) + normalize;
    position = 0;
    for (int i = 0; i < row; i++){
        for (int ii = 0; ii < column; ii++){
            if (i == 0){
                if (ii != column / 2)
                    mainface[i * column + ii] = createcolor("black", "white") + createCenterAligned(std::string(" ")) + normalize;
                else
                    mainface[i * column + ii] = createcolor("black", "white") + createCenterAligned(g[i]) + normalize;
            }
        
            else{
                if (ii != column / 2)
                    mainface[i * column + ii] = createcolor(c[i]) + createCenterAligned(std::string(" ")) + normalize;
                else
                    mainface[i * column + ii] = createcolor(c[i]) + createCenterAligned(g[i]) + normalize;
            }
        }  
    }
}

void updownchoice::shiftud(std::string direction){
    //let the player to PgUp/PgDn
    //input: moving direction
    //output: move upward/downward
    int cp = position * column;
    if (direction == "up" && position != 0){      //limit the upper boundary
        for (int i = 0; i < column; i++)
            mainface[cp + i] = createcolor(c[position]) + mainface[cp + i].substr(8);
        position -= 1;
        int cp = position * column;
        for (int i = 0; i < column; i++)
            mainface[cp + i] = createcolor("black", "white") + mainface[cp + i].substr(8);
    }
    else if (direction == "down" && position != row - 1){       //limit the lower boundary
        for (int i = 0; i < column; i++)
            mainface[cp + i] = createcolor(c[position]) + mainface[cp + i].substr(8);
        position += 1;
        int cp = position * column;
        for (int i = 0; i < column; i++){
            mainface[cp + i] = createcolor("black", "white") + mainface[cp + i].substr(8);
        }
    }
}

std::string center(std::string line, int length){
    //center the colored part within a given length
    //input: targeted line; given length
    //output: centered colored part
    if (line.substr(0, 2) == "\033[")
        length += 12;
    int padding = (length - line.length()) / 2;
    std::string paddingStr1(padding, ' ');
    std::string paddingStr2(length - line.length() - padding, ' ');
    return paddingStr1 + line + paddingStr2;
}

void shiftlr(std::vector<updownchoice> &choice, int &choice_position, std::string direction){
    //shift left and right
    //input: choice; position choice; direction (left/right)
    //output: perform left/right shift
    if (direction == "left" && choice_position != 0){       //limit the left boundary
        choice[choice_position].title = choice[choice_position].createcolor("white") + choice[choice_position].title.substr(8);
        choice_position -= 1;
        choice[choice_position].title = choice[choice_position].createcolor("magenta") + choice[choice_position].title.substr(8);
    }
    else if (direction == "right" && choice_position != choice.size() - 1) {        //limit the right boundary
        choice[choice_position].title = choice[choice_position].createcolor("white") + choice[choice_position].title.substr(8);
        choice_position += 1;
        choice[choice_position].title = choice[choice_position].createcolor("magenta") + choice[choice_position].title.substr(8);
    }
}

void focus_title(std::vector<updownchoice>& choice){
    //add color to the selection bar
    //input: a vector that contains selection bar
    //output: no output
    choice[0].title = choice[0].createcolor("magenta") + choice[0].title.substr(8);

void printscreen(std::vector<updownchoice> choice, int size, int flag){
    //print out the selection bar
    //input: a vector that contains selection bar
    //output: no output
    int col_len = 0, row_len;
    for (int i = 0; i < size; i++)
        col_len += choice[i].center_length;
    col_len += 4 * size;
    int max_row = choice[0].row;
    for (int i = 0; i < size; i++){
        if (choice[i].row > max_row)
            max_row = choice[i].row;
    }
    row_len=choice[0].column*max_row+1;
    std::cout << "\033[?25l";
    for (int ii = 0; ii < size; ++ii){
        if (ii == 0)
            column_center_print(col_len, row_len);
        std::cout << center(choice[ii].title, choice[ii].center_length) + "    " ;
    }
    std::cout << std::endl;
    
    for (int i = 0; i < (choice[0].column * max_row); i++){
        for (int ii = 0; ii < size; ii++){
            if (i < (choice[ii].column * choice[ii].row)){
                if (ii == 0)
                    column_center_print(col_len);
                std::cout << center(choice[ii].mainface[i],choice[ii].center_length) + "    " ;
            }
            else{
                if (ii == 0)
                    column_center_print(col_len);
                std::cout << center("  ", choice[ii].center_length) + "    " ;
            }
        }
        std::cout << std::endl;
    }
    if (flag == 1){
        column_center_print(col_len);
        std::cout << "Error in file opening!" << std::endl;
        std::cout << "\033[1A";
        
    }
    else if (flag == 2){
        column_center_print(col_len);
        std::cout << "No historyRecord" << std::endl;
        std::cout << "\033[1A";
    }
    else if (flag == 3){
        column_center_print(col_len);
        std::cout << "Press q to exit" << std::endl;
        std::cout << "\033[1A";
    }
    de_column_center_print(row_len);
}

