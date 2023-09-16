#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Liste_simple.h"

int main()
{
// void show_grid(T_grid grid, int size)
// {
//     for (int col = 0; col < size; col++)
//     {
//         for (int n = 0; n < (2 * size + 1); n++)
//             printf("-");
//         printf("\n|");
//         for (int lin = 0; lin < size; lin++)
//         {
//             if (get_size(grid[col][lin]) == 1)
//                 printf("%d|", grid[col][lin]->pdata);
//             else
//                 printf(" |");
//         }
//         printf("\n");
//     }
//     for (int n = 0; n < (2 * size + 1); n++)
//             printf("-");
// }

    T_box box;
    initListe(&box);
    box = fillList(box, 9);
    showList(box);
    
    return 0;
}