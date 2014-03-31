/*
** main.c for main in /home/bourge_v/rendu/PSU_2013_minitalk/src/server
** 
** Made by bourge_v
** Login   <bourge_v@epitech.net>
** 
** Started on  Tue Mar 18 15:38:00 2014 bourge_v
** Last update Sat Mar 22 04:01:55 2014 bourge_v
*/

#include "../include/my.h"

t_client	g_client;

void		handler(register int signum)
{
  register int	bit;

  g_client.timeout = 0;
  g_client.client = IN_PROCESS;
  if (signum == SIGUSR1)
    bit = 1;
  else
    bit = 0;
  g_client.c = g_client.c + (bit << g_client.i++);
  if (g_client.i > 7)
    {
      if (g_client.c == '\0')
	{
	  my_putstr("\n");
	  g_client.client = NONE;
	}
      else
	my_putchar(g_client.c);
      g_client.c = 0;
      g_client.i = 0;
    }
}

int		initsig()
{
  usleep(50);
  if (signal(SIGUSR1, handler) == SIG_ERR)
    my_error(2);
  if (signal(SIGUSR2, handler) == SIG_ERR)
    my_error(2);
  return (0);
}

void		struct_init()
{
  g_client.client = NONE;
  g_client.timeout = 0;
  g_client.i = 0;
  g_client.c = 0;
}

void		timeout()
{
  my_putstr(RED);
  my_putstr("\n > CLIENT TIMED OUT!\n\n");
  my_putstr(WHITE);
  struct_init();
}

int		main(int ac, char **av)
{
  if (ac == 1)
    {
      if (initsig() != 0)
	my_error(2);
      struct_init();
      my_putstr(GREEN);
      my_putstr(" > My PID is : ");
      my_putnbr(getpid());
      my_putstr("\n");
      my_putstr(WHITE);
      while (JAIMELESCAROTTES)
	{
	  if (g_client.client == IN_PROCESS)
	    while (g_client.client == IN_PROCESS && g_client.timeout++)
	      if (g_client.client == IN_PROCESS && g_client.timeout > 10000000)
		timeout();
	}
    }
  else
    my_error(0);
}
