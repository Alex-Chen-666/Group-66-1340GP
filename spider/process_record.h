#ifndef PROCESS_RECORD
#define PROCESS_RECORD
#include <string>   
#include <sstream>
#include <fstream>
int get_total_file_index();
std::string get_record_through_input_num(int fileIndex);
std::string get_info_through_input_record(std::string str,int position);
#endif
