/*
** raycasting.c for wolf3d in /home/le-gof_j/wolf3d
** 
** Made by jean-charles le-goff
** Login   <le-gof_j@epitech.net>
** 
** Started on  Fri Dec 12 12:16:49 2008 jean-charles le-goff
** Last update Sun Jan 18 15:13:48 2009 jean-charles le-goff
*/

#include "wolf3d.h"

void	raycasting_rotate(t_data *data)
{
  float	nx_pos_one;
  float	ny_pos_one;
  
  nx_pos_one =
    data->x_pos_one * cos(data->alpha) - data->y_pos_one * sin(data->alpha);
  ny_pos_one = 
    data->x_pos_one * sin(data->alpha) + data->y_pos_one * cos(data->alpha);
  data->x_pos_one = nx_pos_one;
  data->y_pos_one = ny_pos_one;
}

void	raycasting_translation(t_data *data)
{
  float	nx_pos_one;
  float	ny_pos_one;

  nx_pos_one = data->x_pos_one + data->x_pos_zero;
  ny_pos_one = data->y_pos_one + data->y_pos_zero;
  data->x_pos_one = nx_pos_one;
  data->y_pos_one = ny_pos_one;
}

float	raycasting_intersection_in_y(t_data *data, int map[SIZE_MAP][SIZE_MAP])
{
  float	x_inter;
  float	y_inter;
  float	k_temp;
  float	k_y;
  float	vx;
  float	vy;

  vx = data->x_pos_one - data->x_pos_zero;
  vy = data->y_pos_one - data->y_pos_zero;
  k_y = 500;
  y_inter = 0;
  while (y_inter < SIZE_MAP)
    {
      k_temp = (y_inter - data->y_pos_zero) / vy;
      x_inter = data->x_pos_zero + k_temp * vx;
      if ((int)y_inter >= 0 &&(int)y_inter <= SIZE_MAP && (int)x_inter >= 0 &&
	  (int)x_inter <= SIZE_MAP)
	if (map[(int)y_inter][(int)x_inter] == 1 && k_temp < k_y && k_temp > 0 &&
	    map[(int)y_inter][(int)x_inter + 1] == 1 && k_temp < k_y && k_temp > 0)
	 k_y = k_temp;
     y_inter++;
    }
  return (k_y);
}

float	raycasting_intersection_in_x(t_data *data, int map[SIZE_MAP][SIZE_MAP])
{
  float	x_inter;
  float	y_inter;
  float	k_temp;
  float	k_x;
  float	vx;
  float	vy;

  vx = data->x_pos_one - data->x_pos_zero;
  vy = data->y_pos_one - data->y_pos_zero;
  k_x = 500;
  x_inter = 0;
  while (x_inter < SIZE_MAP)
    {
      k_temp = (x_inter - data->x_pos_zero) / vx;
      y_inter = data->y_pos_zero + k_temp * vy;
      if ((int)y_inter >= 0 &&(int)y_inter <= SIZE_MAP && (int)x_inter >= 0 &&
	  (int)x_inter <= SIZE_MAP)
	if (map[(int)y_inter][(int)x_inter] == 1 && k_temp < k_x && k_temp > 0 &&
	    map[(int)y_inter + 1][(int)x_inter] == 1 && k_temp < k_x && k_temp > 0)
	  k_x = k_temp;
      x_inter++;
    }
  return (k_x);
}

void	raycasting(t_data *data)
{
  float	p;
  float	d;
  float	k;
  float	k_y;
  float	k_x;

  p = 1;
  d = p / 2;
  data->x_pos_one = d;
  data->y_pos_one = (p * (WIN_X / 2 - data->x) / WIN_X);
  raycasting_rotate(data);
  raycasting_translation(data);
  k_y = raycasting_intersection_in_y(data, data->map);
  k_x = raycasting_intersection_in_x(data, data->map);
  if (k_x < k_y && k_x > 0)
    k = k_x;
  else
    k = k_y;
  draw(data, k);
}
