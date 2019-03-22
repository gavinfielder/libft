# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gfielder <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/21 14:09:16 by gfielder          #+#    #+#              #
#    Updated: 2019/03/21 21:21:30 by gfielder         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
#
NAME=libft.a
CC=clang
CFLAGS=-Wall -g -Wextra -Werror -I includes/

SRC=ft_atoi.c \
ft_buffwriter.c \
ft_bzero.c \
ft_destroy_nullterm_ptrarray.c \
ft_fdwclear.c \
ft_fdwdel.c \
ft_fdwnew.c \
ft_fdwwrite.c \
ft_fdwwriten.c \
ft_fildeswriter.c \
ft_hat.c \
ft_hat_aux.c \
ft_hat_backend_1.c \
ft_hat_toarr.c \
ft_hatdellf.c \
ft_hatinslf.c \
ft_itoa.c \
ft_litoa.c \
ft_mem_1.c \
ft_mem_2.c \
ft_memalloc.c \
ft_memchr.c \
ft_memcpy.c \
ft_multistringer.c \
ft_multistringer_aux.c \
ft_print_hex.c \
ft_putchar.c \
ft_putnbr.c \
ft_putstr.c \
ft_sbtostr.c \
ft_str_aux.c \
ft_str_constructors.c \
ft_strcat.c \
ft_strclr.c \
ft_strcmp.c \
ft_strcpy.c \
ft_stringbuilder.c \
ft_stringwriter.c \
ft_strjoin.c \
ft_strjoin_inplace.c \
ft_strjoin_inplace_rev.c \
ft_strnew.c \
ft_strsplit.c \
ft_strstr.c \
ft_strsub.c \
ft_strtrim.c

OBJ=$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rs $(NAME) $(OBJ) #> /dev/null 2>&1
	@echo "Libft compiled."

%.o: %.c
	@clang -c $(CFLAGS) $< -o $@

clean:
	@rm -f *.o
	@rm -f test
	@echo "libft: Object files removed."

fclean:
	@rm -f *.o
	@rm -f test
	@rm -f libft.a
	@echo "libft: Object files and library removed."

re:
	@make fclean
	@make all

