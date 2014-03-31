/*
** main.c for client in /home/bourge_v/rendu/PSU_2013_minitalk/src/client
** 
** Made by bourge_v
** Login   <bourge_v@epitech.net>
** 
** Started on  Fri Mar 21 18:31:21 2014 bourge_v
** Last update Sat Mar 22 04:12:44 2014 bourge_v
*/

#include "../include/my.h"

void		my_decompose(register int pid, register char msg)
{
  register int	i;

  i = -1;
  while (++i != 8)
    {
      usleep(70);
      if (((msg >> i) & 1))
	{
	  if (kill(pid, SIGUSR1) == -1)
	    my_error(2);
	}
      else
	if (kill(pid, SIGUSR2) == -1)
	  my_error(2);
    }
}

void		my_client(register int pid, register char *msg)
{
  while (*msg)
    {
      my_decompose(pid, *msg);
      msg++;
    }
  my_decompose(pid, *msg);
}

void		test_av_one(register char av[1])
{
  while (*av)
    {
      if (*av >= '0' && *av <= '9')
	*av++;
      else 
	my_error(1);
    }
}

void		main(int ac, char **av)
{
  if (ac == 3)
    {
      test_av_one(av[1]);
      my_client(atoi(av[1]), av[2]);
    }
  else
    my_error(0);
}
