#ifndef COLUMN_CENTER_PRINT_H
#define COLUMN_CENTER_PRINT_H
#include <string>
#include <vector>
#include <iostream>
#include <sys/ioctl.h>
#include <unistd.h>
void column_center_print(int column_num, int row_num = 0,bool clear_line=true);
void de_column_center_print(int row_num);
#endif
