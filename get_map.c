/*
** get_map.c for wolf3d in /home/le-gof_j/wolf3d
** 
** Made by jean-charles le-goff
** Login   <le-gof_j@epitech.net>
** 
** Started on  Sat Jan 17 16:34:04 2009 jean-charles le-goff
** Last update Sun Jan 18 14:18:21 2009 jean-charles le-goff
*/

#include "wolf3d.h"

int	init(t_data *data)
{
  int	fd;

  data->key_up = 1;
  data->x = 0;
  data->x_pos_zero = 5;
  data->y_pos_zero = 5;
  data->alpha =  0;
  if ((fd = open(data->mapname, O_RDONLY)) == -1)
    {
      puts("Unable to open map...");
      return (1);
    }
  if (get_map(data, fd, 0, 0) == 1)
    {
      puts("Bad map format...");
      close(fd);
      return (1);
    }
  close(fd);
  return (0);
}

int	get_map(t_data *data, int fd, int x, int y)
{
  char	*s;

  while ((s = get_next_line(fd)))
    {
      if (s[0] == '0' || s[0] == '1')
	{ 
	  data->map[y][x] = s[0] - 48;
	  x++;
	  if (x > SIZE_MAP + 1)
	    return (1);
	}
      else if (s[0] == '\0')
	{
	  putchar(s[0]);
	  y++;
	  x = 0;
	  if (y > SIZE_MAP + 1)
            return (1);
	}
      else
	return (1);
    }
  return (0);
}
