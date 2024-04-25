//Data structures for storing game status :8-26
#ifndef UPDOWNCHOICE_H
#define UPDOWNCHOICE_H
#include <string>
#include <vector>
#include "column_center_print.h"
#include "global.h"
struct updownchoice {//一个代表一种上下选择
    int row,column,lineLength,center_length;//lineLength为有阴影的长度，center_length为一列整体长度,column为每个选项所占行数 lineLength<=center_length
    std::string title;//标题
    std::vector<std::string> g,c;//c为color顺序，g为选项内容
    std::vector<std::string> mainface;//不能直接在结构体内部使用成员变量的大小定义成员vector的大小
    int position=0;
    void resizemainface() {
        mainface.resize(row*column);
    }
    std::string createCenterAligned(std::string text){//给有颜色的部分居中
        int padding = (lineLength - text.length()) / 2;
        std::string paddingStr1(padding, ' ');
        std::string paddingStr2(lineLength-text.length()-padding,' ');
        return paddingStr1+text+paddingStr2;
    };
    std::string createcolor(std::string back_color,std::string string_color="no color");//没有传入颜色默认无颜色
    void initialize();
    void shiftud(std::string direction);
};
std::string center(std::string line,int  length);
void shiftlr(std::vector<updownchoice> &choice, int &choice_position, std::string direction);
void focus_title(std::vector<updownchoice>& choice);
void printscreen(std::vector<updownchoice> choice,int size,int flag=0);

#endif
