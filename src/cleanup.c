#include "so_long.h"



void  ft_free_matrix(char **matrix)
 {
int i;

  i = 0;
 while (matrix[i])
 free(matrix[i++]);
 free(matrix);
 }


