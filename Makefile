NAME	=	push_swap

SRCS	=	push_swap.c ft_atoi.c ft_lstnew.c ft_lstadd_front.c check_error.c sort3.c sort100.c sort500.c ft_strlcpy.c \
			push_s1.c push_s2.c sort5.c getlen.c getindex.c mrgsort.c ft_split.c sortmax.c \

BONUS	=	bonus/checker.c ft_lstnew.c ft_lstadd_front.c ft_split.c ft_strlcpy.c check_error.c ft_atoi.c \
			bonus/push_s1_bonus.c bonus/push_s2_bonus.c bonus/push_rr_rrr.c getlen.c bonus/get_next_line_utils.c bonus/get_next_line.c \

GCC		=	gcc -Werror -Wextra -Wall

RM	=	rm -f

all:	$(NAME)

$(NAME): $(SRCS)
	@$(GCC) $(SRCS) -o push_swap
	@echo " "
	@echo "\033[1;33m██████╗ ██╗   ██╗███████╗██╗  ██╗    ███████╗██╗    ██╗ █████╗ ██████╗ "
	@echo "\033[1;33m██╔══██╗██║   ██║██╔════╝██║  ██║    ██╔════╝██║    ██║██╔══██╗██╔══██╗"
	@echo "\033[1;33m██████╔╝██║   ██║███████╗███████║    ███████╗██║ █╗ ██║███████║██████╔╝"
	@echo "\033[1;33m██╔═══╝ ██║   ██║╚════██║██╔══██║    ╚════██║██║███╗██║██╔══██║██╔═══╝ "
	@echo "\033[1;33m██║     ╚██████╔╝███████║██║  ██║    ███████║╚███╔███╔╝██║  ██║██║     "
	@echo "\033[1;33m╚═╝      ╚═════╝ ╚══════╝╚═╝  ╚═╝    ╚══════╝ ╚══╝╚══╝ ╚═╝  ╚═╝╚═╝     "
	@echo " "
	@echo "\033[1;35m▐▌ DONE ▐▌"
	@echo " "

bonus: $(BONUS)
	@$(GCC) $(BONUS) -o checker
	@echo "\033[1;36m▐▌ DONE ▐▌"
	@echo " "

clean:
	@$(RM)

fclean:	clean
	@$(RM) $(NAME) checker

re:	fclean $(NAME) bonus