//Code Requirement: Data structures for storing game status :16
#include "printcard.h"
int max(std::vector<std::vector<std::string>> c) {//find the column with the most cards and return the number of cards in that column.
    int max_len=0;
    for(int i=0;i<c.size();i++) {
        if (c[i].size()>max_len) {
            max_len=c[i].size();
        }
    }
    return max_len;
}
int number_length(int num) {//input is an int. return the number of digit.
    std::string str = std::to_string(num);
    return str.length();
}
void printcard(std::vector<std::vector<std::string>> card,int column,int * hidden_position,bool clear_line) {//input are the important arguments of the table, print the table
    //Data structures for storing game status 
    std::cout<<"\033[?25l";
    std::string head,tail; 
    int max_card_number=max(card),row=1;//row records which column is being printed now.
    int max_card_number_len=2;
    column_center_print(6+8*column+6,0,clear_line);
    std::cout<<"     ";
    for(int i=1;i<=column-1;i++) {
        std::cout<<i<<"       ";
    }
    std::cout<<column<<std::endl;
    column_center_print(6+8*column+6,0,clear_line);
    for(int level=0;level<=2*max_card_number+2;level++){
        if (level%2==0){//even layer
            for(int i=0;i<column;i++) {
                //check the head and tail
                if (i==0){
                    std::string make_up;//Used to bridge the gap between two-digit and one-digit numbers.
                    if(max_card_number_len==1)
                        make_up="";
                    else if(max_card_number_len==2)
                        make_up=" ";
                    head=" "+make_up;
                    tail="  ";
                }
                else if(i==column-1){
                    head="";
                    tail="\n";
                }
                else{
                    head="";
                    tail="  ";
                }


                if(card[i].size()-1>=level/2 && card[i].size()!=0 ) {//not arrive at the tail yet
                    
                    if(card[i][level/2]!=""){//ensure that it is not an empty card
                        std::cout <<head<<top<<tail;//╔════╗
                    }
                    else if((level>2 &&card[i][level/2-1]=="" &&card[i][level/2-2]=="")||(level<2 )||(level==2 &&card[i][level/2-1]=="")){//this one is an empty card, the two beyond it are also empty cards
                        std::cout<<head<<"      "<<tail; 
                    }
                    else if((level>2 &&card[i][level/2-1]!="" &&card[i][level/2-2]!="")||(level==2 &&card[i][level/2-1]!="")){//this one is an empty card, the two beyond it are not empty cards
                        std::cout<<head<<side<<"    "<<side<<tail;
                    }
                    else if(level>2 &&card[i][level/2-1]=="" &&card[i][level/2-2]!=""){//current one and is an empty card, the one beyond it is also an empty card, the one beyond that is not empty.╚════╝
                        std::cout<<head<<bottom<<tail; 
                    }
                    
                    
                }
                else if (card[i].size()==level/2 && card[i].size()!=0 ) {
                    std::cout<<head<<side<<"    "<<side<<tail;//║    ║
                }
                else if (card[i].size()==level/2-1 && card[i].size()!=0 ) {
                    std::cout<<head<<bottom<<tail;  //╚════╝
                }
                else {
                    std::cout<<head<<"      "<<tail;
                }
                if(tail=="\n")
                    column_center_print(6+8*column+6,0,clear_line);
            }
        }
        else {//odd layer//layers with suits are all here
            for(int i=0;i<column;i++) {
                //check the head and tail
                if(i==0){
                    if (row<= max_card_number){//print the column number after the first column
                        std::string make_up;
                        if(max_card_number_len==number_length(row))
                            make_up="";
                        else if(max_card_number_len-number_length(row)==1)
                            make_up=" ";
                        head=make_up+std::to_string(row);
                        
                    }
                    else{//have printed the column number of all columns
                        std::string make_up;
                        if(max_card_number_len==1)
                            make_up="";
                        else if(max_card_number_len==2)
                            make_up=" ";
                        head=" "+make_up;
                    }
                    tail="  "; 
                }
                else if(i==column-1){
                    head="";
                    if (row<= max_card_number){
                        tail=std::to_string(row)+"\n";
                        row++;
                    }
                    else
                        tail="\n";
                    
                }
                else{
                    head="";
                    tail="  ";
                }


                if(card[i].size()-1>=(level-1)/2 && card[i].size()!=0 ) {//not arrive at the tail yet
                    if (card[i][(level-1)/2]!="") {//current card is not empty
                        if((level-1)/2<hidden_position[i]-1){//the suit is hidden    ║??  ║                       
                            std::cout<<head<<side<<"??"<<"  "<<side<<tail;
                        }
                        else{
                            if (card[i][(level-1)/2].length()==14){
                                std::cout<<head<<side<<card[i][(level-1)/2]<<" "<<side<<tail;
                            }
                            else{
                                std::cout<<head<<side<<card[i][(level-1)/2]<<"  "<<side<<tail;
                                
                            }
                        }
                                
                    }
                    else if((level>=3 &&card[i][(level-1)/2-1]=="")||(level<3 )){//current card and last card are empty, use == to determine whether problems exist
                        std::cout<<head<<"      "<<tail;
                    }
                    else if(level>=3 &&card[i][(level-1)/2-1]!=""){//current card is empty, the card above it is not.
                        if((level-1)/2-1<hidden_position[i]-1){                       
                            std::cout<<head<<side<<"  "<<"??"<<side<<tail;
                        }
                        else{
                            if(card[i][(level-1)/2-1].length()==14){
                                std::cout<<head<<side<<" "<<card[i][(level-1)/2-1]<<side<<tail;
                            }
                            else{
                                std::cout<<head<<side<<"  "<<card[i][(level-1)/2-1]<<side<<tail;
                            }
                        }
                    }                          
                }
                else if (card[i].size()==(level-1)/2 && card[i].size()!=0 ) {//the one card after the tail
                    if((level-1)/2-1<hidden_position[i]-1){                   
                            std::cout<<head<<side<<"  "<<"??"<<side<<tail;
                        }
                    else{
                        if (card[i][(level-1)/2-1].length()==14){
                            std::cout<<head<<side<<" "<<card[i][(level-1)/2-1]<<side<<tail;
                        }
                        else{
                            std::cout<<head<<side<<"  "<<card[i][(level-1)/2-1]<<side<<tail;
                        }
                    }
                            
                }
                else {//empty
                    std::cout<<head<<"      "<<tail;
                }
                if(tail.substr(tail.length()-1)=="\n")
                    column_center_print(6+8*column+6,0,clear_line);
            }            
        }
    }
}
void printreservedcard(std::vector<std::vector<std::string>> card
                       ,int reserved_chances, int column
                       ,int original_max_card_num) {//input are the important arguments of the table;print the dealing card
    int max_card_number=max(card);
    std::cout<<"\033[2C";
    for(int i=0;i<column;i++){
        std::cout<<"\033[8C";
    }
    std::cout<<"\033[2C";//move the cursor to the right
    if(reserved_chances>0)
        std::cout<<"\033[4A";
    if(max_card_number>original_max_card_num){
        for(int i=0;i<max_card_number-original_max_card_num;i++){
            std::cout<<"\033[2A";//Exclude the impact of card movement upward.
        }
    }
    for(int i=0;i<reserved_chances;i++){//arrive at the top
            std::cout<<"\033[1A";
    }
    for(int i=0;i<reserved_chances;i++){
        std::cout<<top;
        std::cout<<"\033[1B"<<"\033[6D";
    }
    if(reserved_chances>0){
        std::cout<<side<<"??"<<"  "<<side<<"\033[1B"<<"\033[6D";
        std::cout<<side<<"    "<<side<<"\033[1B"<<"\033[6D";
        std::cout<<side<<"  "<<"??"<<side<<"\033[1B"<<"\033[6D";
        std::cout<<bottom;
    }
    if(max_card_number>original_max_card_num){
        for(int i=0;i<max_card_number-original_max_card_num;i++){
            std::cout<<"\033[2B";//Exclude the impact of card movement downward.
        }
    }
    std::cout<<std::endl;
    std::cout<<"\033[?25h";
} 
