#ifndef PRINTGRID
#define PRINTGRID
#include "headfiles.h"
#include "column_center_print.h"
using namespace std;

string createcolor(const string& foreground, const string& background = "");
void initGrid();
void printunit(int i, int j, int selecting_mood = 0);
void printGrid(bool endless=false);
void printInvalid(char m);
#endif
