#include "functionality.h"

double time() 
{
    return (clock() / (double)(CLOCKS_PER_SEC));
}
