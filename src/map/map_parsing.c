#include "../../includes/map.h"

static char *join_line(char *map_str, char *line)
{
    char *tmp;

    tmp = ft_strjoin(map_str, line);
    free(map_str);
    return (tmp);
}

static int validate_newlines(char *map_str)
{
    int i;

    i = 0;
    while (map_str[i])
    {
        if (map_str[i] == '\n' && map_str[i + 1] == '\n')
            return (0);
        i++;
    }
    return (1);
}

char *read_map(int fd)
{
    char *line;
    char *map_str;

    map_str = ft_strdup("");
    if (!map_str)
        return (NULL);
    while ((line = get_next_line(fd)))
    {
        map_str = join_line(map_str, line);
        free(line);
        if (!map_str)
            break;
    }
    close(fd);
    if (map_str && *map_str)
        return (map_str);
    free(map_str);
    return (NULL);
}

int process_map(t_map *map, char *map_str)
{
    if (!validate_newlines(map_str))
    {
        print_error(ERR_NEWLINE);
        return (0);
    }
    map->grid = ft_split(map_str, '\n');
    if (!map->grid)
    {
        print_error(ERR_MALLOC);
        return (0);
    }
    map->height = ft_arrlen(map->grid);
    if (map->height < 3)
    {
        print_error(ERR_EMPTY);
        ft_free_grid(map->grid, map->height);
        return (0);
    }
    if (!is_rectangle(map) || !check_walls(map) || !check_characters(map))
    {
        ft_free_grid(map->grid, map->height);
        return (0);
    }
    return (1);
}

t_map *parse_map(char *file)
{
    t_map   *map;
    int     fd;
    char    *map_str;

    if (!file || ft_strlen(file) < 4 || 
        ft_strncmp(file + ft_strlen(file) - 4, ".ber", 4))
    {
        print_error(ERR_EXTENSION);
        return (NULL);
    }
    if ((fd = open(file, O_RDONLY)) < 0)
    {
        print_error(ERR_OPEN);
        return (NULL);
    }
    if (!(map_str = read_map(fd)))
    {
        print_error(ERR_EMPTY);
        return (NULL);
    }
    if (!(map = ft_calloc(1, sizeof(t_map))) || !process_map(map, map_str))
    {
        free(map_str);
        free(map);
        return (NULL);
    }
    free(map_str);
    return (map);
}
