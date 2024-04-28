////Coding Requirement: Data structures for storing game status: line16
//feature: can see the history with rolling up and down
#include "choose_history.h"
#include "process_record.h"
int choose_history(int total_file_index, int max_record_num, std::string &record_name){
    //let the player select the history record he wants
    //input: the number of total file indexes; maximum record number, a string representing the name of the record
    //output: return 0 if the player confirms his selection; return 1 if the player chooses to quit
    int record_num, record_position = 1, flag = 0;      //record_position shows the current history record index, starting from 1
    if (total_file_index > max_record_num)
        record_num = max_record_num;        //set maximum value
    else
        record_num = total_file_index;

    int size = 1;
    std::vector<updownchoice> history(size);    //use vector for storing history record interface
    history[0] = {record_num, 1, 45, 45, "History Record", {}, {}};
    for (int i = 0; i < record_num; i++){
        history[0].g.push_back(get_record_through_input_num(i + 1));
        history[0].c.push_back("white");
    } 
    for (int i = 0; i < size; i++){     //initialization
        history[i].mainface = {};
        history[i].resizemainface();
        history[i].initialize();
    }
    focus_title(history);
    char i = 'e';
    system("clear");
            
    printscreen(history, size);
    system("stty -icanon");
    system("stty -echo");
    while (i != 'q'){
        i = getchar();
        if (i == 'w'){
            if (record_position > 1)
                record_position--;
            if (history[0].position == 0 && std::stoi(get_info_through_input_record(history[0].g[0], 1)) != 1){
                history[0].g.pop_back();
                history[0].g.insert(history[0].g.begin(), get_record_through_input_num(record_position));   //insert corresponding history record for record_position
                history[0].mainface={};
                history[0].resizemainface();
                history[0].initialize();
            }
            else
                history[0].shiftud("up");
        }
        else if (i == 's'){
            if (record_position < total_file_index)
                record_position++;
            if (history[0].position == record_num - 1 && std::stoi(get_info_through_input_record(history[0].g[record_num-1], 1)) != total_file_index){
                history[0].g.erase(history[0].g.begin());
                history[0].g.push_back(get_record_through_input_num(record_position));      //insert corresponding history record for record_position
                history[0].mainface = {};
                history[0].resizemainface();
                history[0].initialize();
                for (int i = 0; i < record_num; i++){
                    history[0].shiftud("down");
                }
            }
            else
                history[0].shiftud("down");
        }
        else if (i == '\n') {
            system("stty echo");
            system("stty icanon");
            record_name = history[0].g[history[0].position];
            system("clear");
            return 0;
            system("stty -icanon");
            system("stty -echo");
        }
        else
            flag = 3;
        std::cout << std::endl;
        printscreen(history, size, flag); 
        flag = 0;   //initialize flag
    }
    system("stty echo");
    system("stty icanon");
    return 1;
}
