#include "animation.h"
void animation() {//show the begining animation
    bool num=true;
    int move_position=1;
    std::string sub_animation = "  [38m♠[0m  [38m♣[0m  [31m♦[0m  [31m♥[0m";
    bool stopAnimation = false;

    std::thread inputThread([&stopAnimation]() {
        std::cin.ignore();
        stopAnimation = true;
    });
    std::vector<std::string> card={"[31m♥[0m[31m6[0m", "[31m♦[0m[31m5[0m" ,"[31m♥[0m[31m3[0m","[38m♣[0m[38mJ[0m","[38m♠[0m[38mA[0m", "[38m♣[0m[38mQ[0m", "[31m♦[0m[31m6[0m", "[31m♥[0m[31mK[0m", "[31m♥[0m[31mJ[0m", "[31m♦[0m[31m6[0m","[38m♠[0m[38m6[0m","[38m♠[0m[38m4[0m", "[38m♣[0m[38m8[0m" ,"[38m♣[0m[38mJ[0m" ,"[38m♠[0m[38m7[0m" ,"[38m♠[0m[38m5[0m","[31m♥[0m[31m9[0m"  };
    std::string line[5],animation;
    for(int i=0;i<7;i++){
            animation+=sub_animation;
    }
    for(int i=0;i<16;i++){
        line[1]+=" ║"+card[i]+"  ║";
        line[3]+=" ║  "+card[i]+"║"; 
    }
        
    line[0]=" ╔════╗ ╔════╗ ╔════╗ ╔════╗ ╔════╗ ╔════╗ ╔════╗ ╔════╗ ╔════╗ ╔════╗ ╔════╗ ╔════╗ ╔════╗ ╔════╗ ╔════╗ ╔════╗";
    line[2]=" ║    ║ ║    ║ ║    ║ ║    ║ ║    ║ ║    ║ ║    ║ ║    ║ ║    ║ ║    ║ ║    ║ ║    ║ ║    ║ ║    ║ ║    ║ ║    ║";
    line[4]=" ╚════╝ ╚════╝ ╚════╝ ╚════╝ ╚════╝ ╚════╝ ╚════╝ ╚════╝ ╚════╝ ╚════╝ ╚════╝ ╚════╝ ╚════╝ ╚════╝ ╚════╝ ╚════╝";
    system("clear");
    system("stty -icanon");
    system("stty -echo");
    std::cout<<"\033[?25l";
    while (!stopAnimation) {
        if(!num){
            std::cout<<"\033[16A";
        }  
        for(int i=0;i<5;i++){
            if(num &&i==0)
                column_center_print(120,16);
            else
                column_center_print(120);
            std::cout<<line[i]<<std::endl; 
            
        }
        if(num){
            column_center_print(120);
            std::cout<<" _______  _______  _        _______  _______    _______  _______  _______  _       _________          _______  _       "<<std::endl;
            column_center_print(120);
            std::cout<<"(  ____ )(  ___  )| \\    /\\(  ____ \\(  ____ )  (  ____ \\(  ___  )(  ____ )( (    /|\\__   __/|\\     /|(  ___  )( \\      "<<std::endl;
            column_center_print(120);
            std::cout<<"| (    )|| (   ) ||  \\  / /| (    \\/| (    )|  | (    \\/| (   ) || (    )||  \\  ( |   ) (   | )   ( || (   ) || (      "<<std::endl;
            column_center_print(120);
            std::cout<<"| (____)|| |   | ||  (_/ / | (__    | (____)|  | |      | (___) || (____)||   \\ | |   | |   | |   | || (___) || |      "<<std::endl;
            column_center_print(120);
            std::cout<<"|  _____)| |   | ||   _ (  |  __)   |     __)  | |      |  ___  ||     __)| (\\ \\) |   | |   ( (   ) )|  ___  || |      "<<std::endl;
            column_center_print(120);
            std::cout<<"| (      | |   | ||  ( \\ \\ | (      | (\\ (     | |      | (   ) || (\\ (   | | \\   |   | |    \\ \\_/ / | (   ) || |      "<<std::endl;
            column_center_print(120);
            std::cout<<"| )      | (___) ||  /  \\ \\| (____/\\| ) \\ \\__  | (____/\\| )   ( || ) \\ \\__| )  \\  |___) (___  \\   /  | )   ( || (____/\\ "<<std::endl;
            column_center_print(120);
            std::cout<<"|/       (_______)|_/    \\/(_______/|/   \\__/  (_______/|/     \\||/   \\__/|/    )_)\\_______/   \\_/   |/     \\|(_______/"<<"\n"<<std::endl;
        }
        else
            std::cout<<"\033[9B";
        column_center_print(95);
        std::cout << animation<<std::endl;
        if(num){
            column_center_print(35);
            std::cout<<"Print any key to continue"<<std::endl;
        }  
        else
            std::cout<<"\033[1B";
        //std::cout.flush();

        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        if(move_position==1||move_position==3)
            animation = animation.substr(1) + animation.substr(0, 1);
        else if(move_position==6)
            animation = animation.substr(12) + animation.substr(0, 12);
        for(int i=0;i<5;i++){
            if(i==0||i==4){
                if(move_position==1){
                    line[i]=line[i].substr(1) + line[i].substr(0, 1);
                }
                else
                    line[i]=line[i].substr(3) + line[i].substr(0, 3);
            }
            else if(i==2){
                if(move_position==2||move_position==7)
                    line[i]=line[i].substr(3) + line[i].substr(0, 3);
                else
                    line[i]=line[i].substr(1) + line[i].substr(0, 1);
            }
            else if(i==1){
                if(move_position==2||move_position==7)
                    line[i]=line[i].substr(3) + line[i].substr(0, 3);
                if(move_position==3)
                    line[i]=line[i].substr(12) + line[i].substr(0, 12);
                if(move_position==4)
                    line[i]=line[i].substr(10) + line[i].substr(0, 10);
                if(move_position==6||move_position==5||move_position==1){
                    line[i]=line[i].substr(1) + line[i].substr(0, 1);
                }
            }
            else if(i==3){
                if(move_position==2||move_position==7)
                    line[i]=line[i].substr(3) + line[i].substr(0, 3);
                if(move_position==4||move_position==3||move_position==1)
                    line[i]=line[i].substr(1) + line[i].substr(0, 1);
                if(move_position==6){
                    line[i]=line[i].substr(10) + line[i].substr(0, 10);
                }
                if(move_position==5)
                    line[i]=line[i].substr(12) + line[i].substr(0, 12);
            }
            
                
        }
        if(move_position==7)
            move_position=1;
        else
            move_position++;
        num=false;

    }

    inputThread.join();
    system("stty icanon");
    system("stty echo");
    std::cout<<"\033[?25h";
    return ;
}

