#include "so_long.h"

void get_map_dimension(t_map *map)
{
	int (i),(j);

	i = 0;
	while(map->grid[i])
	{
		j = 0;
		while(map->grid[i][j++])
			map->n_col++;
		i++;
	}
	map->n_row = i;
	if(!map->n_row)
	{
		ft_printf("Error \n Empty map file\n");
		ft_free_grid(map->grid);
		exit(1);
	}
}
int check_fd(char *file_name , char *buffer)
{
	int fd;

	fd = open(file_name , O_RDONLY);
	if(fd < 0)
	{
		free(buffer);
		ft_printf("Error \n %s Doesnt exist \n",file_name);
		exit(1);
	}
	return(fd);
}
static int is_empty_line(char *row , char *buffer, int fd )
{
	if(ft_strncmp(row , "\n",2) == 0)
	{
		ft_printf("Error \n Invalid mpa. found empty line\n");
		free(row);
		free(buffer);
		close(fd);
		return(1);
	}
	return(0);
}
void read_map(char *file_name , char *buffer , t_game *game)
{
	int fd;
	char *row;
	char *pb;

	fd = check_fd(file_name , buffer);
	while(1)
	{
		row = get_next_line(fd);
		if(!row)
		{
			free(row);
			break;
		}
		if(is_empty_line(row, buffer,fd))
				exit(1);
		pb = buffer;
		buffer = ft_strjoin(buffer , row);
		free(row);
		free(pb);
	}
	game->map.grid = ft_split(buffer,'\n');
	free(buffer);
	close(fd);
}
void init_game(char *file_name , t_game *game)
{
	char *buffer;

	buffer = ft_strdup("");
	read_map(file_name , buffer , game);
	get_map_dimension(&game->map);

}
