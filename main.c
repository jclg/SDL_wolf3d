/*
** wolf3d.c for wolf3d in /home/le-gof_j/wolf3d
** 
** Made by jean-charles le-goff
** Login   <le-gof_j@epitech.net>
** 
** Started on  Fri Dec 12 12:16:49 2008 jean-charles le-goff
** Last update Sat Jan 17 18:08:24 2009 jean-charles le-goff
*/

#include "wolf3d.h"

int		main(int argc, char **argv)
{
  t_data	data;
  SDL_Event	event;
  int		exit_flag = 1;

  if (argc != 2)
    {
      puts("No map specified...");
      return (1);
    }

  SDL_Init(SDL_INIT_VIDEO);
  SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY, 1);
  data.img = SDL_SetVideoMode(WIN_X, WIN_Y, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);

  if (data.img == NULL)
    {
      fprintf(stderr, "Impossible de charger le mode vidéo : %s\n", SDL_GetError());
      exit(EXIT_FAILURE);
    }


  data.img_terre = IMG_Load("terre.jpg");

  data.mapname = argv[1];
  init(&data);
  key_up(&data);
  SDL_Flip(data.img);


  while (exit_flag)
    {
      SDL_WaitEvent(&event);
      if (event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE)
        exit_flag = 0;
      else
        {
          if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_UP)
	      key_up(&data);
          else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_DOWN)
	      key_down(&data);
          else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_RIGHT)
	      key_right(&data);
          else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_LEFT)
	      key_left(&data);
	}
      SDL_Flip(data.img);
    }
  return (0);
}
