ENGG1340 Group 66 presents
"Poker Carnival"

Team Members:
    Chen Zhendong
    Cheng Lefan
    Cheng Xiuheng
    Gong Jianxiang
    Li Shibiao


Description & Introduction:
Description:
    Our Poker-themed group project "Poker Carnival" is a comprehensive game combination.
    It contains 2 games: Spider Solitaire and Poker Crush (which is a match-3 game).
    The player needs to:
        1. plan the strategies carefully to arrange cards
        2. have good insightful observation to match colored patterns
    In this way, you can gradually manage to succeed in our games.
    We believe the fusion of Spider Solitaire and Poker Crush creates an intriguing and relaxing game experience.
    Though some scenarios may be a bit challenging, we sincerely hope you to relax and have fun in our games! 

Game rules:
    1. Spider Solitaire:
    ***For more details about game operation, please refer to instruction_spider.txt 
    or select "Instruction" in Spider Solitaire's main interface***
        *Spider Solitaire is a card game:
            1) At the beginning, n columns of cards (n is determined by the user) are randomly dealt.
                Only the bottom card in each column is face-up.
            2) To the right of these n columns is the stock pile, which can be used to deal one card 
                to each column when you want a new set of cards. 
            3) The newly dealt cards are all face-up.When all the face-up cards in a column are 
                removed, the bottom card of that column automatically flips face-up. 
            4) Your objective is to form a sequence of cards of the same suit, from King to Ace (in 
                descending order from top to bottom), which will then be removed from the table. 
            5) Your ultimate goal is to remove all the cards from the table.

        *To move cards, you are supposed to input the starting column, starting row, and 
            destination column to drag the cards onto another pile. 

        *The rules for moving cards are as follows:
            1) You can move the bottom card of any pile to an empty pile.
            2) You can move the bottom card of a pile onto another card whose face value is one 
                higher than the card you drag.(regardless of suit).
            3) A group of cards of the same suit and in sequential order can be moved as a unit 
                (the starting column and starting row should imply the position of the top card 
                of the group you want to move).
            4) When a complete sequence from King to Ace, with the same suit, is formed, that 
                sequence is removed from the table.
            5) If there are no more moves available or no more meaningful moves to be made, you 
                can press 'r' to deal a new set of cards. Additionally, before dealing a new set 
                of cards, there should be no empty piles.
        
    2. Poker Crush:
    ***Welcome to Poker Crush! Get ready for an exciting and addictive match-3 puzzle game that
    will put your skills to the test. Just like Spider Solitaire, Poker Crush offers a unique 
    gameplay experience that combines elements of strategy, matching, and card games.***

        1) At the start, you can choose mode to decide the difficulty of the game
            each level of game has different set-steps and set-marks
        2) Then, you'll be presented with a grid filled with various cards. 
            Your objective is to create matches of three or more cards of the same type to eliminate 
            them and earn points.
        3) Keep an eye out for special cards that can help you achieve bigger matches or trigger powerful combos. 
            Strategically plan your moves to maximize your score and clear the grid.
        4) As you eliminate cards, new ones will appear, creating opportunities for chain reactions and 
            cascading matches. Aim to create the highest-scoring combinations and set new records.
        5) Your ultimate goal in Poker Crush is to reach the marks set within the steps set

      *To choose mode, please press w (up) and s(down) to select the wanted option and 
      press "enter" to ensure your choice.

      *To play Poker Crush, simply select two adjacent cards to swap their positions. 
        1) Press the key 1~9 to choose the coordinates of the first block
        2) Press the key w a s d to choose the direction to be swapped

Features:
    instruction.cpp: 
        We enable Spider Solitaire's instruction to flip page by page via the player's control.
        Corresponding code requirement:
            Data structures for storing game status (use vector)
            Dynamic memory management (use vector)
    loading_save.cpp: file I/O
        We add archive functions so that the player can save/resume his history games.
        Besides, the player can browse through his history records and clear his history by clicking "
    updownchoice.cpp: 
        create the choice mainface that can be controlled instantly without enter
    choose_history.cpp: 
        can see the history with rolling up and down
    stalemate3.cpp: 
        line61-82: recursion
    print_grid.cpp:
        Corresponding code requirement:
            Data structures for storing game status (use vector)
            Dynamic memory management (use vector)
            Generation of random game sets or events: line49



    quick_game.cpp:
        Corresponding code requirement:
            Generation of random game sets or events: line17
            Dynamic memory management (use map)





Non-standard C/C++ library:
In column_center_print.cpp and full_screen.cpp:
    1. <sys/ioctl.h>
    2. <unistd.h>
These libraries are used to get the player's row size and column size of the screen.
We can then access the player's screen size to prompt him to resize to full screen.


Compilation and execution instructions:
    $ make p
    $ make clean(clean all the Compilation file)
    $ ./p
