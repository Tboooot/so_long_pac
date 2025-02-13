#include "so_long.h"


void get_map_attributes(t_map *map)
{
	int (i),(j);

	i = 0;
	while(map->grid[i])
	{
			j = 0;
		while(map->grid[i][j])
		{
					if(map->grid[i][j] == 'P')
						map->p++;
					if(map->grid[i][j] == 'E')
						map->e++;
					if(map->grid[i][j] == 'C')
					  map->c++;
			j++;
		}
		i++;
	}
}

void validate_allow_attribates(t_map *map) {
  int(i), (j);

  i = 0;
  while (map->grid[i]) {
    j = 0;
		while (map->grid[i][j]) {
		 if(!ft_strchr("10PCE",map->grid[i][j]))
			{
				ft_printf("Error \n Invalid map attribute"); 
				ft_free_grid(map->grid);
        exit(1);
			}
	j++;
    }
	i++;
	}
}
void validate_map_attributes(t_map * map) {
  map->e = 0;
  map->c = 0;
  map->p = 0;
  validate_allow_attribates(map);
	get_map_attributes(map);
		if(map->p == 1 && map->c > 0 && map->e == 1)
			return;
		ft_printf("Error \n Missing map attributes\n");
			ft_free_grid(map->grid);
	exit(1);
    }
