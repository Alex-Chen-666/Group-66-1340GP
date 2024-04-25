//Code Requirement: File input/output: line153
//                  Data structures for storing game status: line155
#include "rule.h"
#include <iostream>
#include <thread>
#include <chrono>
using namespace std;
void printAndClearLine(const string& line) {
    //print the reason of error and remove the invalid input on the screen.
    //input: the string to be printed.
    //output: print the reason of error and remove the invalid input on the screen.
    std::cout<<"\033[?25l";
    std::cout<<"\033[1A"<<"                                        ";
    std::cout<<"\033[1B"<<"\033[40D"<<"                                                       "<<"\033[55D";
    std::cout << line << flush;
    std::cout<<"\033[2A"<<std::endl;
    std::cout<<"\033[?25h";//use ANSI code here to move the cursor and clear the specific line on the screen.

}
bool validinput(std::string input){
    //determine whether the input is valid
    //input:user's input
    //output: return true if input is valid. return false if input is invalid
    int counter=0;
    std::string ans="";
    for(char i:input){
        if(!isblank(i)){
            counter+=1;
            if(counter==1){
                ans=i;
            }
        }
    }
    if(counter==1&&(ans=="y"||ans=="n")){
        return true;
    }
    return false;
}
//判断相邻两张牌能否连起来
bool validconnect(string lower,string upper){
    //determine whether a card can connect with the card on top of it.
    //input: the strings representing the two cards
    //output: return true if the two adjacent cards can connect with each other. Otherwise return false.
    int length_l=lower.length();
    int length_u=upper.length();
    if (lower.substr(5,3)==upper.substr(5,3)){
        string upper_num=upper.substr(8,length_u-12);
        string lower_num=lower.substr(8,length_l-12);
        string reference[13]={"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
        for (int i=0;i<12;i++){
            if (reference[i+1]==upper_num &&reference[i]==lower_num){
                return 1;
            }
        }
    }
    return 0;
}

bool validdrag(vector<vector<string>> v,int * flip,int col_from,int col_to,int size,int start_row,int state){
    //determine whether the drag is valid or not and print the reason why it is invalid
    //input: a vector storing the card layout; a pointer pointing to an array storing the first card flipped in each column; 
    //       three ints representing the start point and destination of the drag; an int representing the number of columns; 
    //       an int representing whether this function should print the invalid reason or not
    //output: true: the drag is valid; false: the drag is invalid and print the invalid reason is 'state==0'
    int col= size;
    start_row-=1;
    col_from-=1;
    col_to-=1;
    if (col_from>=col||col_from<0||col_to>=col||col_to<0){
        if(state==0){
            printAndClearLine("Column out of range.");
        }
        return 0;
    }
    int num_of_card_in_col_from=v[col_from].size();
    int flipped = flip[col_from]-1;
    if (start_row<flipped||start_row>=num_of_card_in_col_from){
        if(state==0){
            printAndClearLine("Row out of range");
        }
        return 0;
    }
    if (v[col_from].size()==0){
        if(state==0){
            printAndClearLine("No card to move.");
        }
        return 0;
    }
    string current_card=v[col_from][start_row];
    int target_row=v[col_to].size()-1;
    if (target_row!=-1){
        string target_card=v[col_to][target_row];
        int length_l=current_card.length();
        int length_u=target_card.length();
        string upper_num=target_card.substr(8,length_u-12);
        string lower_num=current_card.substr(8,length_l-12);
        string reference[13]={"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
        for (int i=0;i<12;i++){
            if (reference[i+1]==upper_num &&reference[i]==lower_num){
                break;
            }
            else if(i==11){
                if(state==0){
                    printAndClearLine("Can not connect with target card.");
                }
                return 0;
            }
        }
    }
   
    for(int i=start_row;i<v[col_from].size()-1;i++){
        if(!validconnect(v[col_from][i+1],v[col_from][i])){
            if(state==0){
                printAndClearLine("invalid drag");
            }
            return 0;
        }
    }
    return 1;
}

bool validdeal(vector<vector<string>> v,int size,int deal_times){
    //determine whether the user can deal cards
    //input: a vector storing the card layout; an int representing the number of columns; an int representing the number of dealing opportunities;
    //output: return false: empty deck exists or the dealing opportunities run out
    //        return true: the user can deal cards
    for (int i=0;i<size;i++){
        if (v[i].empty()){
            printAndClearLine("Empty deck exists. Unable to deal.");
            return 0;
        }
    }
    if (deal_times==0){ 
        printAndClearLine("The dealing opportunity has run out.");
        return 0;
    }
    return 1;
}


int valid(string input,vector<vector<string>> v,int * flip,int size,int deal_times){
    //the main function to determine whether user's input is valid and can be executed. 
    //If the input is valid, return the int representing the type of input for further execution.
    //input: a string which is user's input; a vector storing the card layout;
    //       a pointer pointing to an array storing the first card flipped in each column;
    //       an int representing the number of columns; an int representing the number of dealing opportunities;
    //output: return 0 if the input is invalid and print the invalid reason
    //        return 1 if the input is valid and the user want to deal cards
    //        return 2 if the input is valid and the user want to quit the game
    //        return 3 if the input is valid and the user want to drag card(s)

    //use string input here to read the data divided by space in user's input
    istringstream line(input);
    int counter=0;
    string word,arr[3];//use an array here to store data
    while(line>>word){
        arr[counter]=word;
        counter+=1;
        if (counter>3){
            printAndClearLine("Invalid input, please try again with correct format.");
            return 0;
        }
    }
    if (counter==0){
        printAndClearLine("Invalid input, please try again with correct format.");
        return 0;
    }
    else if (counter==2){
        for (int i=0;i<2;i++){   
            for (char ii:arr[i]){
                if(!isdigit(ii)){
                    printAndClearLine("Invalid input, please try again with correct format.");
                    return 0;
                }
            }
        }
        int col_from=stoi(arr[0]),start_row=v[col_from-1].size(),col_to=stoi(arr[1]);
        if(validdrag(v,flip,col_from, col_to, size,start_row,0)){
            return 3;
        }
        return 0;
    }
    else if (counter==1){
        if (arr[0]=="r"){
            if(validdeal(v,size,deal_times)){
                return 1;
            }
            return 0;
        }
        else if(arr[0]=="q"){
            return 2;
        }
        printAndClearLine("Invalid input, please try again with correct format.");
        return 0;
    }
    else if(counter==3){
        for (int i=0;i<3;i++){  
            for (char ii:arr[i]){
                if(!isdigit(ii)){
                    printAndClearLine("Invalid input, please try again with correct format.");
                    return 0;
                }
            }
        }
        int start_row=stoi(arr[1]),col_from=stoi(arr[0]),col_to=stoi(arr[2]);
        if(validdrag(v,flip,col_from, col_to, size,start_row,0)){
            return 3;
        }
        return 0;
    }
    return 0;
}
