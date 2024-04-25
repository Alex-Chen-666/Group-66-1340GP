//Code Requirement: Data structures for storing game status :6,18,32
#include "process_record.h"
int get_total_file_index(){         //get the total number of history records and return
    int total_file_index = 0;
    std::string num_record;
    std::ifstream fin("historyRecord.txt");//Data structures for storing game status 
    while (getline(fin, num_record)){
        if (!num_record.empty())
            total_file_index++;
    }
    fin.close();
    return total_file_index;
}

std::string get_record_through_input_num(int fileIndex){//input is an int representing the history record number.get the corresponding record and return.
        int count_num = 0;
        std::string num_record = "No record found";
        std::ifstream fin("historyRecord.txt");//Data structures for storing game status 
        while (getline(fin, num_record)){
            if (!num_record.empty())
                count_num++;
            if (count_num == fileIndex)
                break;
        }
        fin.close();
        return num_record;
}

std::string get_info_through_input_record(std::string str,int position){     
    //retrieve the record and return specific data
    //position=1 is the record number; position=2 is the condition of that record; position 3 is.....
    std::stringstream ss(str);//Data structures for storing game status 
    std::string num, lable, time;
    ss >> num >> lable;
    if (position == 1)      //retrieve the number
        return num;
    else if (position == 2)         //retrieve the lable
        return lable;
    else if (position == 3)  {       //retrieve the time
        time = str.erase(0, num.length() + lable.length() + 2);
        return time;
    }
    else
        return "Invalid position";
}
