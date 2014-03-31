/*
** my_error.c for my_error in /home/bourge_v/rendu/PSU_2013_minitalk/src/client
** 
** Made by bourge_v
** Login   <bourge_v@epitech.net>
** 
** Started on  Fri Mar 21 20:38:11 2014 bourge_v
** Last update Sat Mar 22 22:58:46 2014 bourge_v
*/

#include "include/my.h"

void	my_arg_error()
{
  my_putstr("\n > NUMBER OF ARGUMENTS ERROR\n\n");
}

void	my_av_error()
{
  my_putstr("\n > WRONG PID FORMAT\n\n");
}

void	my_signal_error()
{
  my_putstr("\n > SIGNAL ERROR\n\n");
}

void	my_error(register int i)
{
  my_putstr(RED);
  if (i == 0)
    my_arg_error();
  else if (i == 1)
    my_av_error();
  else if (i == 2)
    my_signal_error();
  my_putstr(WHITE);
  exit(0);
}
