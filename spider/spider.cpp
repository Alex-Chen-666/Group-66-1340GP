//Code Requirement: Data structures for storing game status :9,10,11
//                  Dynamic memory management:9, 92
#include "spider.h"
int spider(){//the main function for game process of spider solitaire
    full_screen();
    int flag = 0, total_file_index = get_total_file_index();
    while(true){
        int column_number, reserved_chances, decks_of_card, suit_num, step;
        int * hidden_position = new int[1]; //Data structures for storing game status, Dynamic memory management 
        std::vector<std::vector<std::string>> card;//already dealt cards  // Data structures for storing game status 
        std::vector<std::string> savedcard;//the cards to be dealt //  Data structures for storing game status 
        int state;
        state = choose_mode(flag);
        flag = 0;//flag is used to determine whether we need to print the hint; flag==0:no need; flag==1: print'open failure';flag==2:print'no history record'
        if (state == 0){//enter the 'instruction'
            instruction();
        }
        else if (state == 1){//resume the previous game
            std::cout << "\033[?25h";
            ifstream fin("historyRecord.txt");
            if (fin.fail()){
                flag = 1;         
            }
            
            else{
                if (total_file_index == 0)
                    flag = 2;
                else{
                    std::string record_name = "", label = "";
                    int state=choose_history(total_file_index, 20, record_name);
                    if (state != 1)
                        label = get_info_through_input_record(record_name, 2);
                    while (state != 1 && !(label == "Unfinished" || label == "Probably Stalemate")){
                        state = choose_history(total_file_index, 20, record_name);
                        if (state != 1)
                            label = get_info_through_input_record(record_name, 2);
                    }
                    if (label == "Unfinished" || label == "Probably Stalemate"){
                        std::string fileIndex = get_info_through_input_record(record_name, 1); 
                        loading(fileIndex, flag, column_number, reserved_chances, decks_of_card
                            , suit_num, step, hidden_position, card, savedcard);
                        if (flag == 0)
                            game_process(column_number,reserved_chances,decks_of_card
                            , suit_num, step, hidden_position, card, savedcard, total_file_index);
                    } 
                }
                
                
                
            }
        }
        else if(state==2){//start a new game
            state=new_game(column_number,reserved_chances,decks_of_card,
                suit_num,hidden_position,card,savedcard,step);
            if (state!=1)
                game_process(column_number,reserved_chances,decks_of_card
                ,suit_num,step,hidden_position,card,savedcard,total_file_index);
        }
        else if(state==3){//check the history records
            std::string record_name;
            if(total_file_index==0){
                flag=2;
            }
            else{
                while (state!=1){
                    state=choose_history(total_file_index,20,record_name);
                    if(state!=1){
                        std::string fileIndex=get_info_through_input_record(record_name,1);
                        print_history( fileIndex,flag); 
                    }
                    
                }
                
            }
            
        }
        else if (state == 4){
            system("rm -rf Records");
            system("rm historyRecord.txt index.txt");
            system("touch historyRecord.txt");
            system("mkdir Records");
            std::ofstream fout("index.txt");
            fout << 1 << std::endl;
            fout.close();
            total_file_index = 0;
            //clear all the history record
        }
        else if(state==5){
            std::cout<<"\033[?25h";
            return 1;//exit
        }
        delete[] hidden_position; //Dynamic memory management
    }
    
}
