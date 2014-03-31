/*
** mbf for my_basic_fct in /home/bourge_v/rendu/PSU_2013_minitalk/src
** 
** Made by bourge_v
** Login   <bourge_v@epitech.net>
** 
** Started on  Fri Mar 21 23:23:59 2014 bourge_v
** Last update Sun Mar 23 23:38:49 2014 bourge_v
*/

#include "include/my.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  while (*str != 0)
    {
      my_putchar(*str);
      str++;
    }
}

int	my_putnbr(int nb)
{
  my_putchar(nb < 0 && (nb *= -1) ? '-' : '\0');
  my_putchar(nb - (nb >= 10 ? my_putnbr(nb / 10) : 0) + 48);
  return (nb * 10);
}
