/*
** get_next_line.c for get_next_line in /home/le-gof_j/GetNextLine
** 
** Made by jean-charles le-goff
** Login   <le-gof_j@epitech.net>
** 
** Started on  Tue Nov 25 09:25:23 2008 jean-charles le-goff
** Last update Thu Dec  4 11:03:30 2008 jean-charles le-goff
*/

#include "get_next_line.h"
#include <string.h>

char	*get_buf(char *buffer, char *buffer_read, int *count, t_struct *ctr)
{
  buffer_read[ctr->ctr_read] = '\0';
  *count = 0;
  while (buffer_read[*count] != '\0' && ctr->ctr_read_total < SIZE_BUFFER)
    {
      buffer[ctr->ctr_read_total] = buffer_read[*count];
      if (buffer_read[*count] == '\n')
	{
	  (*count)++;
	  buffer[ctr->ctr_read_total] = '\0';
	  return (strdup(buffer));
	}
      (*count)++;
      (ctr->ctr_read_total)++;
    }
  buffer[ctr->ctr_read_total] = '\0';
  if (ctr->ctr_read_total == SIZE_BUFFER)
    return (strdup(buffer));
  return (0);
}

char			*get_next_line(const int fd)
{
  static char		buffer[SIZE_BUFFER + 1];
  static char		buffer_read[SIZE_READ + 1];
  static int		count = -1;
  t_struct		ctr;

  ctr.ctr_read_total = 0;
  if (count != -1)
    while (buffer_read[count] != '\0')
      {
	buffer[ctr.ctr_read_total] = buffer_read[count++];
	ctr.ctr_read_total++;
      }
  while ((ctr.ctr_read = read(fd, buffer_read, R_BIG_B)))
    {
      if (ctr.ctr_read == -1)
	return (0);
      else
	return (strdup(get_buf(buffer, buffer_read, &count, &ctr)));
    }
  if (ctr.ctr_read == 0 && count != -1)
    {
      count = -1;
      buffer[ctr.ctr_read_total] = '\0';
      return (strdup(buffer));
    }
  return (0);
}
