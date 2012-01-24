/*
** wolf3d.h for wolf3d in /home/le-gof_j/wolf3d
** 
** Made by jean-charles le-goff
** Login   <le-gof_j@epitech.net>
** 
** Started on  Fri Dec 12 12:36:40 2008 jean-charles le-goff
** Last update Sun Jan 18 14:53:07 2009 jean-charles le-goff
*/

#define KEY_ECHAP 65307
#define KEY_LEFT 65361
#define KEY_RIGHT 65363
#define KEY_UP 65362
#define KEY_DOWN 65364
#define KEY_SPACE 32

#define GREEN 0x0000FF00
#define YELLOW 0x00FAEB30
#define DARK_YELLOW 0x00CDCD00
#define BLUE 0x002060FF
#define RED 0x00FF0000
#define GREY 0x00999999
#define BLACK 0x00000000
#define SKIN 0x00ffd39b
#define GREY_MARRON 0x008b7765
#define DARK_GREY 0x001A1A1A

/*
#define WIN_X 640
#define WIN_Y 480
*/

#define WIN_X 1024
#define WIN_Y 768

#define SIZE_MAP 20
#define MOVE_SPEED 0.4



#include "get_next_line.h"
#include <math.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>


typedef struct	s_data
{
  SDL_Surface   *img;
  SDL_Surface   *img_terre;
  int	x;
  int	map[SIZE_MAP][SIZE_MAP];
  char	*mapname;
  int	key_up;
  float	x_pos_zero;
  float	y_pos_zero;
  float	alpha;
  float	x_pos_one;
  float	y_pos_one;
}	t_data;


/*
** key.c
*/
void	key_left(t_data *data);
void	key_right(t_data *data);
void	key_up(t_data *data);
void	key_down(t_data *data);
/*
** raycasting.c
*/
void	raycasting_rotate(t_data *data);
void	raycasting_translation(t_data *data);
float	raycasting_intersection_in_y(t_data *data, int map[SIZE_MAP][SIZE_MAP]);
float	raycasting_intersection_in_x(t_data *data, int map[SIZE_MAP][SIZE_MAP]);
void	raycasting(t_data *data);
/*
** draw.c
*/
void    put_pixel_to_image(SDL_Surface * surface, Uint16 x, Uint16 y, Uint32 color);
void	draw_sky(t_data *data, int top);
void	draw_wall(t_data *data, int top, int bottom);
void	draw_floor(t_data *data, int bottom);
void	draw(t_data *data, float k);
/*
** get_map.c
*/
int	init(t_data *data);
int	get_map(t_data *data, int fd, int x, int y);
