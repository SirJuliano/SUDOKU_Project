T_grid AlloueTab2D(int largeur, int hauteur)
{
    T_grid grid;
    grid = (T_box***)malloc(sizeof(T_box**)*largeur);
    for (int i=0; i<largeur; i++)
    {
        grid[i] = (T_box**)malloc(sizeof(T_box*)*hauteur);
    }
    return grid;  //tab2D contenant des pointeurs
}
