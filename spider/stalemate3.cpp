//Code Requirement: Data structures for storing game status: line18
//                    Dynamic memory management: line18
//feature: line61-82: recursion
#include <iostream>
#include <vector>
#include <string>
#include "stalemate3.h"
#include "rule.h"
#include "move.h"
using namespace std;
int stalemate( vector<vector<string>>& tableau, vector<vector<vector<string>>>& visited,int * flip,int size,int times) {
    //determine whether the user reaches a stalmate;
    //input: a vector recording the card layout, a vector recording the visited card layout, a pointer pointing to an array storing the first card flipped in each column, an int representing the number of columns, an int recording the number of predicting steps;
    //return 2:there will be no meaingful moves after several steps(please see the instruction for details about meaningful moves)
    //return 1: no valid moves currently
    //return 0: there exist valid and meaningful moves. 
    times+=1;//times records the number of predicting steps: This function predicts at most five steps. If there are still possible moves, it is determined as a non-stalemate situation.
    for (int i=0;i<visited.size();i++){//use a vector visited to record the visited card layout.
        if(visited[i]==tableau){
            return 1;//if the card layout is already visited, return 1;
        }
    }
    visited.push_back(tableau);  // tag the current card layout visited
    // empty piles exist, not in stalemate, return 0;
    for (const auto& column : tableau) {
        if (column.empty()) {
            return 0;
        }
    }
    //no stalemate after 5 steps of predicting, return 0
    if(times==5){
        return 0;
    }
    // try all possible moves
    int flag=0;
    for (int i=0;i<size;i++){
        for(int j=0;j<tableau[i].size();j++){
            for(int k=0;k<size;k++){
                if(validdrag(tableau,flip,i+1,k+1,size,j+1,1)){
                    flag=1;//flag=1 implies that valid moves exist
                    break;
                }
            }
            if(flag==1){
                break;
            }
        }
        if(flag==1){
                break;
        }
    }
    if(flag==0){
        if (times==1){//no valid move currently
            return 3;
        }
        else{
            return 0;
        }
    }
    else{//flag!=0,valid move exists, use recursion to determine if it is duplicate and meaningless move.
        for (int i=0;i<size;i++){
            for(int j=0;j<tableau[i].size();j++){
                for(int k=0;k<size;k++){
                    if(validdrag(tableau,flip,i+1,k+1,size,j+1,1)){
                        int k_size=tableau[k].size();
                        vector<string>::iterator first=tableau[i].begin()+j;
                        tableau[k].insert(tableau[k].end(),first,tableau[i].end());
                        first=tableau[i].begin()+j;
                        tableau[i].erase(first,tableau[i].end());
                        if (!stalemate(tableau, visited,flip,size,times)) {//once one recursion returns false, the whole function returns false; The whole function returns true if and only if all the recursion returns true
                            tableau[i].insert(tableau[i].end(),tableau[k].begin()+k_size,tableau[k].end());
                            tableau[k].erase(tableau[k].begin()+k_size,tableau[k].end());
                            return 0;
                        }
               
                        tableau[i].insert(tableau[i].end(),tableau[k].begin()+k_size,tableau[k].end());
                        tableau[k].erase(tableau[k].begin()+k_size,tableau[k].end());
                    }
                }
            }
        }
        return 2;
    }
}
