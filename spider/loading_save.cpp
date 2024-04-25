//Code Requirement: File Input/Output: line24-48, line54-91
//                  Data structures for storing game status: line5-6
//                  Dynamic memory management: line29-30
#include "loading_save.h"
void loading(std::string fileIndex, int &flag, int &column_number, int &reserved_chances, int &decks_of_card, int &suit_num, \
            int &step, int * &hidden_position, std::vector<std::vector<std::string>> &card, std::vector<std::string> &savedcard){
    //file input history data
    /*input: selected file index; flag; column number; remaining chances; decks of card; suit number; steps; 
             a dynamic array with the number of rows of the first turned card in each column; current cards; dealing card pile */
    //output: import history data
    std::string line, value, filename;
    bool is_num = true;
    for(char c : fileIndex){
        if (!isdigit(c)){
            is_num = false;
            break;
        }    
    }
    if (is_num)
        filename = "./Records/" + fileIndex + ".txt";
    else
        filename = fileIndex;

    std::ifstream fin1(filename);
    if (fin1.fail())
        flag = 1;
    fin1 >> column_number >> reserved_chances >> decks_of_card >> suit_num >> step;

    delete[] hidden_position;       //Dynamic memory management
    hidden_position = new int[column_number];       //Dynamic memory management
    for (int i = 0; i < column_number; i++)     //file input hidden_position (array)
        fin1 >> hidden_position[i];
    int count = 1;
    fin1.ignore(std::numeric_limits<std::streamsize>::max(), '\n');      //clear residual characters in the input buffer

    while (count <= column_number){     //file input current cards (2-D vector)
        std::getline(fin1, line);
        std::vector<std::string> row;
        std::stringstream ss(line);
        while (ss >> value)
            row.push_back(value);
        card.push_back(row);
        count++;
    }

    while (fin1 >> value)       //read in dealing card pile (vector)
        savedcard.push_back(value);
    fin1.close();
}

int save(int column_number, int reserved_chances, int decks_of_card, int suit_num, int step, 
                int * hidden_position, std::vector<std::vector<std::string>> card,
                std::vector<std::string> savedcard, std::string outcome){
    //file output history data
    /*input: column number; remaining chances; decks of card; suit number; steps; 
             a dynamic array with the number of rows of the first turned card in each column; current cards; dealing card pile; game outcome */
    //output: export history data

    std::ofstream fout("historyRecord.txt", std::ios::app);     //each historical record is displayed with index + outcome + time
    if (fout.fail()){
        column_center_print(6+8*column_number+6);
        std::cout << "Error in file opening!" << std::endl;
        return 1;
    }
    
    std::string fileIndex, line;    //get the index used for storage
    std::ifstream fin("index.txt");
    while (std::getline(fin, line))
        fileIndex = line;
    fin.close();
    std::ofstream foutIndex("index.txt", std::ios::app);
    foutIndex << std::stoi(fileIndex) + 1 << std::endl;
    foutIndex.close();

    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
    std::time_t currentTime = std::chrono::system_clock::to_time_t(now);
    char* timeString = std::ctime(&currentTime);
    fout << fileIndex << ' ' << outcome << ' ' << timeString;     //distinguish different histories through outcome and time
    fout.close();

    std::string filename = "./Records/" + fileIndex + ".txt";      //create index.txt, storing specific information for each history record
    std::ofstream fout1(filename);
    fout1 << column_number << ' ' << reserved_chances << ' ' << decks_of_card << ' ' << suit_num << ' ' << \
    step << std::endl;     //file output every integer parameter
    for (int i = 0; i < column_number; i++)   //file output hidden_position (array)
        fout1 << hidden_position[i] << std::endl;
                    
    for (const auto& row : card){  //file output current cards (2-D vector)
        for (const auto& element : row)
            fout1 << element << ' ';
        fout1 << std::endl;
    }

    for (const auto& element : savedcard)   //file output dealing card pile (vector)
        fout1 << element << std::endl;
    fout1.close();

    return 0;
}

