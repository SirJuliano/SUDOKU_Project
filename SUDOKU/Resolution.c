bool validColumn(T_gridF grid, int posLargeur, int posHauteur)
{
    bool res = true ; 
    for(int column=0; column<9; column++)
    {
        for(int line=0; line<9; line++)
        {
            for(int box=0; box<9; box++)
            {
                if(grid[column][line]==grid[column][box])
                {
                    res:=false;
                }
            }
        }
    }
    return res;
}




// bool validGrid(T_gridF grid)
// {
//     for(int i=0; i)
// }