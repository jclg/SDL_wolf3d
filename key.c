/*
** key.c for wolf3d in /home/le-gof_j/wolf3d
** 
** Made by jean-charles le-goff
** Login   <le-gof_j@epitech.net>
** 
** Started on  Sat Jan 17 13:06:32 2009 jean-charles le-goff
** Last update Sun Jan 18 14:53:36 2009 jean-charles le-goff
*/

#include "wolf3d.h"

void	key_left(t_data *data)
{
  data->x = 0;
  if (data->alpha > (M_PI))
    data->alpha = - M_PI;
  else if (data->alpha < - M_PI)
    data->alpha = M_PI;
  (data->alpha) += 0.1;
  while (data->x < WIN_X)
    {
      raycasting(data);
      (data->x)++;
    }
}

void	key_right(t_data *data)
{
  data->x = 0;
  if (data->alpha > (M_PI))
    data->alpha = - M_PI;
  else if (data->alpha < - M_PI)
    data->alpha = M_PI;
  (data->alpha) -= 0.1;
  while (data->x < WIN_X)
    {
      raycasting(data);
      (data->x)++;
    }
}

void	key_up(t_data *data)
{
  if (data->key_up == 1)
    {
      data->x = 0;
      data->x_pos_zero = data->x_pos_zero + MOVE_SPEED * cos(data->alpha);
      data->y_pos_zero = data->y_pos_zero + MOVE_SPEED * sin(data->alpha);
      while (data->x < WIN_X)
	{
	  raycasting(data);
	  (data->x)++;
	}
    }
}

void	key_down(t_data *data)
{
  data->x = 0;
  data->x_pos_zero = data->x_pos_zero - MOVE_SPEED * cos(data->alpha);
  data->y_pos_zero = data->y_pos_zero - MOVE_SPEED * sin(data->alpha);
  while (data->x < WIN_X)
    {
      raycasting(data);
      (data->x)++;
    }
}
