#include "end_animation.h"
//when the player loses or quits the game "poker_crush";
//input:current level, steps and marks determined in quick_game()
//output:null, but print an ending image and statistics
void print_not_end(int level, int steps, int marks){
    system("clear");
    column_center_print(45,10);
    column_center_print(45);
    cout<<"Your level now: "<<level<<endl;
    column_center_print(45);
    cout<<"Steps taken: "<<steps<<endl;
    column_center_print(45);
    cout<<"Your marks: "<<marks<<endl;
    column_center_print(45);
    cout<<" __                                 _ "<<endl;
    column_center_print(45);
    cout<<"/ _\\ ___  ___   _   _  ___  _   _  / \\"<<endl;
    column_center_print(45);
    cout<<"\\ \\ / _ \\/ _ \\ | | | |/ _ \\| | | |/  /"<<endl;
    column_center_print(45);
    cout<<"_\\ \\  __/  __/ | |_| | (_) | |_| /\\_/ "<<endl;
    column_center_print(45);
    cout<<"\\__/\\___|\\___|  \\__, |\\___/ \\__,_\\/   "<<endl;
    column_center_print(45);
    cout<<"                |___/                 "<<endl;
    column_center_print(45);
    cout<<"Press any key to quit this game."<<endl;
    column_center_print(45);
    getchar();
    return;
}
//when the player wins the game "poker_crush";
//input:current level, steps and marks determined in quick_game()
//output:null, but print an ending image and statistics
void print_end(int level,int steps,int marks ){
    system("clear");
    column_center_print(45,10);
    column_center_print(45);
    cout<<"Your level now: "<<level<<endl;
    column_center_print(45);
    cout<<"Steps taken: "<<steps <<endl;
    column_center_print(45);
    cout<<"Your marks: "<<marks<<endl;
    column_center_print(45);
    cout<<"                           _           _ "<<endl;
    column_center_print(45);
    cout<<"/\\_/\\___  _   _  __      _(_)_ __     / \\"<<endl;
    column_center_print(45);
    cout<<"\\_ _/ _ \\| | | | \\ \\ /\\ / / | '_ \\   /  /"<<endl;
    column_center_print(45);
    cout<<" / \\ (_) | |_| |  \\ V  V /| | | | | /\\_/ "<<endl;
    column_center_print(45);
    cout<<" \\_/\\___/ \\__,_|   \\_/\\_/ |_|_| |_| \\/   "<<endl;
    column_center_print(45);
    cout<<"Press any key to quit this game."<<endl;
    getchar();
    return;
}

