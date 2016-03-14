/*
** draw.c for wolf3d in /home/le-gof_j/wolf3d
** 
** Made by jean-charles le-goff
** Login   <le-gof_j@epitech.net>
** 
** Started on  Thu Jan  8 14:11:46 2009 jean-charles le-goff
** Last update Sun Jan 18 14:48:20 2009 jean-charles le-goff
*/

#include "wolf3d.h"

void		put_pixel_to_image(SDL_Surface * surface, Uint16 x, Uint16 y, Uint32 color)
{
  Uint8 bpp	= surface->format->BytesPerPixel;
  Uint8 * p	= ((Uint8 *)surface->pixels) + y * surface->pitch + x * bpp;
  switch(bpp)
    {
    case 1:
      *p = (Uint8) color;
      break;
    case 2:
      *(Uint16 *)p = (Uint16) color;
      break;
    case 3:
      if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
        {
          *(Uint16 *)p = ((color >> 8) & 0xff00) | ((color >> 8) & 0xff);
          *(p + 2) = color & 0xff;
        }
      else
        {
          *(Uint16 *)p = color & 0xffff;
          *(p + 2) = ((color >> 16) & 0xff) ;
        }
      break;
    case 4:
      *(Uint32 *)p = color;
      break;
    }
}

Uint32	get_pixel_from_surface(SDL_Surface *surf, int x, int y)
{
  int bpp = surf->format->BytesPerPixel;
  Uint8 *p = (Uint8 *)surf->pixels + y * surf->pitch + x * bpp;
  
  switch (bpp)
    {
    case 1:
      return *p;

    case 2:
      return *(Uint16 *)p;

    case 3:
      if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
	return p[0] << 16 | p[1] << 8 | p[2];
      else
	return p[0] | p[1] << 8 | p[2] << 16;
      
    case 4:
      return *(Uint32 *)p;
      
    default:
      return 0;
    }
}




void	draw_sky(t_data *data, int top)
{
  int	y;

  y = 0;
  while (y <= top)
    {
      put_pixel_to_image(data->img, data->x, y, BLUE);
      y++;
    }
}

void	draw_wall(t_data *data, int top, int bottom)
{
  while (top <= bottom)
    {
     put_pixel_to_image(data->img, data->x, top, DARK_GREY);
     top++;
    }
}

void	draw_floor(t_data *data, int bottom)
{
  while (bottom < WIN_Y)
    {
      put_pixel_to_image(data->img, data->x, bottom, GREY);
      bottom++;
    }
}

void	draw(t_data *data, float k)
{
  int	middle;
  int	wall_middle_height;
  int	top;
  int	bottom;

  if (k < 1)
    data->key_up = 0;
  else
    {
      data->key_up = 1;
      middle = WIN_Y / 2;
      wall_middle_height = WIN_Y / (2 * k);
      top = middle - wall_middle_height;
      bottom = middle + wall_middle_height;
      draw_sky(data, top);
      draw_wall(data, top, bottom); 
      draw_floor(data, bottom);
    }
}
