# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mobrycki <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/20 11:43:39 by mobrycki          #+#    #+#              #
#    Updated: 2021/02/20 11:43:54 by mobrycki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB_DIR		=		libft

SRC_MAIN	=		main.c

SRC_PRINT	= 		ft_convertion.c					ft_printf_utils.c			ft_printf.c					ft_switch.c					\
					ft_integers.c					ft_char.c     				ft_strings.c 				ft_pointers.c

SRC_LIBFT	= 		$(LIB_DIR)/ft_isprint.c			$(LIB_DIR)/ft_memcmp.c		$(LIB_DIR)/ft_putchar_fd.c								\
					$(LIB_DIR)/ft_split.c			$(LIB_DIR)/ft_strlcat.c		$(LIB_DIR)/ft_strncmp.c		$(LIB_DIR)/ft_substr.c		\
					$(LIB_DIR)/ft_atoi.c			$(LIB_DIR)/ft_isalpha.c		$(LIB_DIR)/ft_itoa.c		$(LIB_DIR)/ft_memcpy.c		\
					$(LIB_DIR)/ft_putendl_fd.c		$(LIB_DIR)/ft_strchr.c		$(LIB_DIR)/ft_strlcpy.c		$(LIB_DIR)/ft_strnstr.c		\
					$(LIB_DIR)/ft_tolower.c			$(LIB_DIR)/ft_bzero.c   	$(LIB_DIR)/ft_isascii.c		$(LIB_DIR)/ft_memccpy.c		\
					$(LIB_DIR)/ft_memmove.c			$(LIB_DIR)/ft_putnbr_fd.c 	$(LIB_DIR)/ft_strdup.c 		$(LIB_DIR)/ft_strlen.c		\
					$(LIB_DIR)/ft_strrchr.c			$(LIB_DIR)/ft_toupper.c		$(LIB_DIR)/ft_calloc.c		$(LIB_DIR)/ft_isdigit.c		\
					$(LIB_DIR)/ft_memchr.c			$(LIB_DIR)/ft_memset.c		$(LIB_DIR)/ft_putstr_fd.c	$(LIB_DIR)/ft_strjoin.c		\
					$(LIB_DIR)/ft_strmapi.c			$(LIB_DIR)/ft_strtrim.c 
					
					


OBJS 		= 		$(SRC_LIBFT:.c=.o)	$(SRC_PRINT:.c=.o)		

OBJS_MAIN	=		$(SRC_MAIN:.c=.o)

CFLAGS		=		-Wall -Wextra -Werror 

CC 		= 		gcc

NAME 		= 		libftprintf.a



$(NAME) :	$(OBJS)
			ar rcs $(NAME) $(OBJS)

all:		$(NAME)

clean:
			@ rm -f  $(OBJS) $(OBJS_MAIN)

fclean:		clean
			@ rm -f $(NAME)

re:			fclean all

run:		$(OBJS) $(OBJS_MAIN)
			clear
			clear
			@ $(CC) $(CFLAGS) $(SRC_LIBFT) $(SRC_MAIN) $(SRC_PRINT)
			./a.out

debug:		$(OBJS) $(OBJS_MAIN)
			clear
			clear
			@ $(CC) $(CFLAGS) -g  $(SRC_LIBFT) $(SRC_MAIN) $(SRC_PRINT)
			lldb ./a.out

norme:		
			clear
			@ echo "\n#------|norme libft|------#" 
			norminette ./$(LIB_DIR)/*.c
			norminette ./$(LIB_DIR)/*.h
			@ echo "\n#------|norme printf|------#"
			norminette ./*.c
			norminette ./*.h

.PHONY: 	all clean fclean re run norme debug
