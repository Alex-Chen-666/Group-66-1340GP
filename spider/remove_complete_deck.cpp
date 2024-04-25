//Code Requirement: Data structures for storing game status :9,35
#include "remove_complete_deck.h"
int check_deck(std::vector<std::vector<std::string>> card,int *hidden_position,int column_number){
    //check if a complete sequence of cards(same suit) is formed in the column
    //input:input are the important arguments of the table,and the column to be checked
    //output: return true if a complete sequence exists;false if no complete sequence

    //Data structures for storing game status 
    std::vector<std::string> deck,standered_deck={"K","Q","J","10"
                            ,"9","8","7","6","5","4","3","2","A"};
    std::string color;
    if(hidden_position[column_number]>0 &&card[column_number].size()-hidden_position[column_number]+1>=13){//check the number of visible cards
        deck.assign(card[column_number].end()-13,card[column_number].end());
    }
    else if(hidden_position[column_number]==0 &&card[column_number].size()>=13){
        deck.assign(card[column_number].end()-13,card[column_number].end());
    }
    else
        return false;
    color=deck[0].substr(5,3);
    for(int i=0;i<13;i++){
        if (deck[i].substr(5,3)!=color)//check the suit
            return false;
        if(deck[i].substr(8,deck[i].length()-12)!=standered_deck[i])//check the number
            return false;
    }
    return true;  
}
void remove_complete_deck(std::vector<std::vector<std::string>> &card
        ,int *hidden_position,int column_number,int column,int reserved_chances ){
    //remove the complete sequence
    //'column' is the total number of columns.'column_number' is the column to be checked.others are the arguments of the table.
    
    //Data structures (std::chrono::milliseconds) for storing game status 
    std::chrono::milliseconds duration(100);
    std::string wipe((8*column),' ');
    if(check_deck(card,hidden_position,column_number)){
        
        for(int i=0;i<13;i++){
            card[column_number].pop_back();//delete a card from the tail
            std::this_thread::sleep_for (duration);
            printcard(card,column, hidden_position);
            std::cout<<std::endl;
            column_center_print(8*column);
            std::cout<<std::endl;
            column_center_print(8*column);
            std::cout<<std::endl;//remove the line printed before the following two layers
            std::cout<<"\033[7A";
            for(int i=0;i<max(card);i++){
                std::cout<<"\033[2A";
            }
        }
        if(card[column_number].size()+1==hidden_position[column_number])
            hidden_position[column_number]--;
        system("clear");
        
    }
}
