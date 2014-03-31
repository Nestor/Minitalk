/*
** my.h for my.h in /home/bourge_v/rendu/PSU_2013_minitalk/src/server
** 
** Made by bourge_v
** Login   <bourge_v@epitech.net>
** 
** Started on  Sat Mar 22 01:17:35 2014 bourge_v
** Last update Sat Mar 22 22:59:32 2014 bourge_v
*/

#ifndef MY_H_
# define MY_H_

# define IN_PROCESS 1
# define NONE 0
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define WHITE "\033[0m"
# define JAIMELESCAROTTES -1

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <sys/types.h>

typedef struct	s_client
{
  int		client;
  int		timeout;
  int		c;
  int		i;
}		t_client;

/*
** SERVER/MAIN.C
*/
void	handler(register int signum);
int	initsig();
void	struct_init();
void	timeout();

/*
** CLIENT/MAIN.C
*/
void	my_decompose(register int pid, register char msg);
void	my_client(register int pid, register char *msg);
void	test_av_one(register char av[1]);

/*
** MY_BASIC_FCT.C
*/
void	my_putchar(char c);
void	my_putstr(char *str);

/*
** MY_ERROR.C
*/
void	my_arg_error();
void	my_av_error();
void	my_signal_error();
void	my_error(register int i);

#endif /* !MY_H */
