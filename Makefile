##
## EPITECH PROJECT, 2019
## 42sh
## File description:
## Makefile
##

NAME		=	42sh

LD		=	@ld
CC		=	@gcc
DIROBJ		=	objects
EXTENSION	=	.c

SRC			=	$(wildcard $(addprefix lib/, *)$(EXTENSION))
SRC			+=	$(wildcard $(addprefix src/, *)$(EXTENSION))
NOM			=	$(basename $(notdir $(SRC)))
OBJ			=	$(addprefix $(DIROBJ)/, $(addsuffix .o, $(NOM)))
SRC-CRIT	=	$(wildcard $(addprefix tests/, *)$(EXTENSION))
OBJ-CRIT	=	$(SRC-CRIT:$(EXTENSION)=.o)


NCURSFLAGS	+=	-lncurses
CPPFLAGS	+=	-W -Wall -Wextra #-fPIC
LDFLAGS		+=	-g3
CFLAGS		+=	-Iinclude -fno-builtin -g3
CXXFLAGS	+=	-IInclude -fno-builtin

END		=	\033[0m
BOLD		=	\033[1m
GREY		=	\033[30m
RED		=	\033[31m
GREEN		=	\033[32m
YELLOW		=	\033[33m
BLUE		=	\033[34m
PURPLE		=	\033[35m
CYAN		=	\033[36m
WHITE		=	\033[37m

all:	$(NAME)

$(NAME):	$(OBJ)
	@$(CC) $(LDFLAGS) -o $(NAME) $(OBJ) $(CGRAPHICS)
	@echo -e "$(GREEN)=========( COMPLETED )=========$(END)"

test_run:	$(OBJ-CRIT)
	@$(CC) $(CFLAGS) $(CRITFLAGS) $(OBJ-CRIT)
	@echo -e "$(GREEN)=========( COMPLETED )=========$(END)"
	./a.out

clean:
	@find . -type f \( -iname "*~" \) -delete
	@$(RM) $(OBJ)
	@$(RM) $(OBJ-CRIT)
	@echo -e "$(RED)=========( CLEANED )=========$(END)"

fclean:	clean
	@$(RM) -r $(DIROBJ)
	@$(RM) $(NAME)
	@$(RM) a.out

re:	fclean all

$(DIROBJ):
	@mkdir -p $@ \
	&& echo -e "$(GREEN)[OK]\t$(CYAN)Creating:$(WHITE)$(BOLD)" $(DIROBJ) "$(END)" \
	|| echo -e "$(RED)[KO]\tCan't create:$(BOLD)" $(DIROBJ) "$(END)"

# $(DIROBJ)/%.o: lib/%$(EXTENSION) | $(DIROBJ)
# 	@$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $< \
# 	&& echo -e "$(GREEN)[OK]\t$(BLUE)Compiling:$(WHITE)$(BOLD)" $< "$(END)" \
# 	|| echo -e "$(RED)[KO]\tCan't compile:$(BOLD)" $< "$(END)"

$(DIROBJ)/%.o:	src/%$(EXTENSION) | $(DIROBJ)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $< \
	&& echo -e "$(GREEN)[OK]\t$(CYAN)Compiling:$(WHITE)$(BOLD)" $< "$(END)" \
	|| echo -e "$(RED)[KO]\tCan't compile:$(BOLD)" $< "$(END)"

.PHONY: all test_run clean fclean re

