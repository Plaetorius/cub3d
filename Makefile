NAME			= cub3d
FTSRCS			= .c
DIRSRCS 		= srcs/program/
SRCS 			=	$(addsuffix .c,				\
					$(addprefix srcs/parsing/,	\
						parsing					\
						textures				\
						map_size				\
						map_correct				\
						map_creation			\
					)							\
					$(addprefix srcs/cleaning/,	\
						errors					\
					)							\
						srcs/cub3d				\
					)
BONUSOBJS		= ${BONUS:.c=.o}
PATH_INCLUDES	= includes
HEADER			= ${PATH_INCLUDES}
LIBFTDIR		= libft
LIBFTLIB		= -lft
CC				= cc
FLAGS			= -Wall -Wextra -Werror
OBJS			= ${SRCS:.c=.o}
RM				= rm -rf
RED				= \033[1;31m
NC				= \033[0m
LGREEN			= \033[1;32m
CYAN			= \033[1;36m

%.o: %.c
	@echo "\033[1A                                                          "
	@echo -n "\033[1A"
	@echo "${CYAN}Compiling $< ${NC}"
	@${CC} ${FLAGS} -o $@ -c $^ -I${HEADER}

all: ${NAME}
	@echo "${LGREEN}Successfully created${NC}${CYAN} ${NAME}${NC}${LGREEN}!${NC}"

${NAME}: ${OBJS} ${LIBFTDIR}/libft.a
	@${CC} ${FLAGS} ${OBJS} -I${HEADER} -L${LIBFTDIR} ${LIBFTLIB} -o $@ -g3

sanitize: ${OBJS} ${LIBFTDIR}/libft.a
	@${CC} ${FLAGS} ${OBJS} -I${HEADER} -L${LIBFTDIR} ${LIBFTLIB} -o cub3d -g3 -fsanitize=address

${LIBFTDIR}/libft.a:
	@make -C ${LIBFTDIR}

bonus: ${BONUSOBJS} ${LIBFTDIR}/libft.a
	@${CC} ${FLAGS} ${BONUSOBJS} ${HEADER} -L${LIBFTDIR} ${LIBFTLIB} -o cub3d -g3

#----------------------------PUSH_SWAP

clean:
	@echo "${CYAN}Cleaned ${NAME}${NC}"
	@${RM} ${OBJS}
fclean:		clean
	@echo "${CYAN}FCleaned ${NAME}${NC}"
	@${RM} ${NAME}

re: fclean all

bonus_clean:
	@${RM} ${BONUSOBJS}

bonus_fclean: bonus_clean
	@${RM} checker

bonus_re: bonus_fclean bonus

#----------------------------LIBFT

libft_all:
	@make -C ${LIBFTDIR} all

libft_clean:
	@make -C ${LIBFTDIR} clean

libft_fclean:
	@make -C ${LIBFTDIR} fclean


libft_re:
	@make -C ${LIBFTDIR} re

#----------------------------ALL

all_clean: clean libft_clean bonus_clean

all_fclean: fclean libft_fclean bonus_fclean

all_re: libft_re re
	@echo "${CYAN}Re-ed ${NAME}${NC}"


.PHONY: all clean fclean re libft_re libft_all libft_fclean libft_clean all_clean all_fclean bonus bonus_clean bonus_fclean bonus_re
