//Code Requirement: Data structures for storing game status :7,8,9
#include "print_history.h"
#include "loading_save.h"
void print_history(std::string fileIndex,int &flag){
        //input is the history record number, check if the input is valid. If valid, print the corresponding history record.
        int column_number,reserved_chances,decks_of_card,suit_num,step;
        int * hidden_position=new int[1];//Data structures for storing game status 
        std::vector<std::vector<std::string>> card;//already dealt cards
        std::vector<std::string> savedcard;
        std::string order;
        loading(fileIndex,flag,column_number,reserved_chances,decks_of_card
                ,suit_num,step,hidden_position,card,savedcard);
        printcard(card,column_number, hidden_position);
        printreservedcard(card,reserved_chances,column_number,max(card));
        std::cout<<"\033[?25l";
        column_center_print(6+8*column_number+6);
        std::cout<<"decks of card: "<<decks_of_card<<"  suit number: "<<suit_num<<"  Step: "<<step<<std::endl;
        column_center_print(6+8*column_number+6);
        std::cout<<"press enter to back\n";
        system("stty -icanon"); //close the buffer
        system("stty -echo");//Disable echo
        while(order!="\n"){
                order=getchar();
                if(order!="\n"){
                    std::cout<<"\033[?25l";
                    std::cout<<"\033[40D"<<"                                                       "<<"\033[55D";
                    column_center_print(6+8*column_number+6);
                    std::cout << "Invalid input,please try again." << std::flush;
                    std::cout<<"\033[1A"<<std::endl;
                }
                
        }
        system("stty echo");//open echo
        system("stty icanon"); //open buffer
        std::cout<<"\033[?25h";            
}
