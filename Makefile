# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amitcul <amitculstudent.42porto.com>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/29 12:50:13 by amitcul           #+#    #+#              #
#    Updated: 2022/11/29 13:00:16 by amitcul          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= client
NAMESV		= server

NAMEBC		= client_bonus
NAMEBS		= server_bonus

LIBFT		= libft
INC			= inc
HEADER		= -I includes
SRC_DIR		= src/
OBJ_DIR		= obj/

CC			= cc
FLAGS		= -Wall -Werror -Wextra

RM			= rm -f

OBJF		=	.cache_exists

SRCCL_FILES	=	client
SRCSV_FILES	=	server
SRCBC_FILES	=	client_bonus
SRCBS_FILES	=	server_bonus

SRCCL 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRCCL_FILES)))
OBJCL 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRCCL_FILES)))

SRCSV 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRCSV_FILES)))
OBJSV 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRCSV_FILES)))

SRCBC 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRCBC_FILES)))
OBJBC 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRCBC_FILES)))

SRCBS 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRCBS_FILES)))
OBJBS 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRCBS_FILES)))

start:
			@make -C $(LIBFT)
			@cp $(LIBFT)/libft.a .

all:		start $(NAME) $(NAMESV)

$(NAME):	$(OBJCL) $(OBJF)
			$(CC) $(FLAGS) $(OBJCL) $(HEADER) libft.a -o $(NAME)

$(NAMESV):	$(OBJSV) $(OBJF)
			$(CC) $(FLAGS) $(OBJSV) $(HEADER) libft.a -o $(NAMESV)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(OBJF)
			$(CC) $(FLAGS) $(HEADER) -c $< -o $@

$(OBJF):
			mkdir -p $(OBJ_DIR)
			touch $(OBJF)

bonus:
			make -C $(LIBFT)
			cp $(LIBFT)/libft.a .
			make allbonus

allbonus:		$(NAMEBC) $(NAMEBS)

$(NAMEBC):	$(OBJBC) $(OBJF)
			$(CC) $(FLAGS) $(OBJBC) $(HEADER) libft.a -o $(NAMEBC)

$(NAMEBS):	$(OBJBS) $(OBJF)
			$(CC) $(FLAGS) $(OBJBS) $(HEADER) libft.a -o $(NAMEBS)

clean:
			$(RM) -r $(OBJ_DIR)
			$(RM) $(OBJF)
			make clean -C $(LIBFT)

fclean:		clean
			$(RM) $(NAME) $(NAMESV) $(NAMEBC) $(NAMEBS)
			$(RM) $(LIBFT)/libft.a
			$(RM) libft.a
			find . -name ".DS_Store" -delete

re:			fclean all

norm:
			clear
			norminette $(SRC) $(INC) $(LIBFT) | grep -v Norme -B1 || true

.PHONY:		start all clean fclean re bonus norm
