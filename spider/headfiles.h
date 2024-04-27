#ifndef HEADFILES
#define HEADFILES
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "column_center_print.h"
#include <string>
#include "global.h"
#include <iostream>
#include <vector>


using namespace std;
/**
 * @brief Represents a block with its coordinates, type, and match status.
 */
struct block
{
    int y; /**< The y-coordinate of the block. */
    int x; /**< The x-coordinate of the block. */
    int type; /**< The type of the block (be referenced when being printed). */
    int match; /**< The match status of the block(be referenced in main_logic) */
};



const string SUIT_SYMBOLS[] = {"♠", "♣", "♦", "♥"};
const int  SUIT_COUNT = 4;

#endif
