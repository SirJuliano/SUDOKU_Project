#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Liste_simple.h"

int main()
{


    T_box box;
    initListe(&box);
    box = fillList(box, 9);
    showList(box);
    
    return 0;
}