#ifndef STALEMATE3_H
#define STALEMATE3_H
#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include "rule.h"
#include "move.h"
using namespace std;
int stalemate(vector<vector<string>>& tableau, vector<vector<vector<string>>>& visited,int * flip,int size,int times);
#endif
