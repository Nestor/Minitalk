##
## Makefile for Makefile in /home/bourge_v/rendu/PSU_2013_minitalk
## 
## Made by bourge_v
## Login   <bourge_v@epitech.net>
## 
## Started on  Tue Mar 18 15:26:27 2014 bourge_v
## Last update Wed Mar 26 18:25:29 2014 bourge_v
##

SRCC	= ./src/client/main.c \
	  ./src/my_error.c \
	  ./src/my_basic_fct.c

SRCS	= ./src/server/main.c \
	  ./src/my_error.c \
	  ./src/my_basic_fct.c

OBJC	= $(SRCC:.c=.o)

OBJS	= $(SRCS:.c=.o)

NAMEC	= ./bin/client/client

NAMES	= ./bin/server/server

RED	= \033[1;31m

GREEN	= \033[1;32m

WHITE	= \033[0m

all: $(NAMEC) $(NAMES)

$(NAMEC): $(OBJC)
	@cc -o $(NAMEC) $(OBJC)
	@echo -e "$(GREEN)\n > COMPILING CLIENT : Done.\n$(WHITE)"

$(NAMES): $(OBJS)
	@cc -o $(NAMES) $(OBJS)
	@echo -e "$(GREEN)\n > COMPILING SERVER : Done.\n$(WHITE)"

clean:
	@rm -rf $(OBJC)
	@echo -e "$(RED)\n > REMOVING CLIENT OBJECTS : Done.$(WHITE)"
	@rm -rf $(OBJS)
	@echo -e "$(RED)\n > REMOVING SERVER OBJECTS : Done.$(WHITE)"

fclean: clean
	@rm -rf $(NAMEC)
	@echo -e "$(RED)\n > REMOVING CLIENT BIN : Done.$(WHITE)"
	@rm -rf $(NAMES)
	@echo -e "$(RED)\n > REMOVING SERVER BIN : Done.\n$(WHITE)"

re: fclean all

.PHONY: all clean fclean re
