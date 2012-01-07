/*
** get_next_line.h for get_next_line in /home/le-gof_j/GetNextLine
** 
** Made by jean-charles le-goff
** Login   <le-gof_j@epitech.net>
** 
** Started on  Tue Nov 25 09:54:50 2008 jean-charles le-goff
** Last update Sat Jan 17 16:44:42 2009 jean-charles le-goff
*/

#define SIZE_READ 1
#define SIZE_BUFFER 1
#define R_BIG_B (SIZE_READ > SIZE_BUFFER ? SIZE_BUFFER : SIZE_READ)
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

char	*get_next_line(const int fd);
char	*my_strdup(char *src);

typedef struct	s_struct 
{
  int		ctr_read;
  int		ctr_read_total;
}		t_struct;
