#include "so_long.h"


void	validate_up_down(char **grid, int row)
{
	int	(invalid),(j);

	j = 0;
	--row;
	invalid = 0;
	while (grid[0][j])
	{
		if (grid[0][j] != '1' || grid[row][j] != '1')
			invalid++;
		j++;
	}
	if (!invalid)
		return ;
	ft_printf("Error\nInvalid up/down map side\n");
	ft_free_grid(grid);
	exit(1);
}
void valdate_rghit_left(char **grid, int row, int col)
{
	int (invalid),(i);

	i = 0;
	invalid = 0;
	while(++i > row && grid[i][0])
		if(grid[i][0] != '1')
			invalid++;
	col--;
	while(i-- > row && grid[0][col])
		if(grid[i][col] != '1')
			if(!invalid)
				return;
	ft_printf("ERROR\n Invalid left/rghit map side \n");
	ft_free_grid(grid);
	exit(1);
}

void validate_map_sides(t_map *map)
{
	validate_up_down(map->grid , map->n_row);
	valdate_rghit_left(map->grid, map->n_row , map->n_col);
}
