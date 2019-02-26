# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile.new                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gfielder <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/19 14:34:55 by gfielder          #+#    #+#              #
#    Updated: 2019/02/22 01:46:31 by gfielder         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a
CC=clang
CFLAGS=-Wall -Wextra -Werror -I includes/

SRC=ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_itoa_base.c ft_lstadd.c ft_lstcpy_elem.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_lstnew_byref.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c ft_print_hex.c ft_print_hex_padded.c ft_print_memory.c ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c ft_strnew.c ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnstr.c ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c ft_toupper.c ft_tolower.c ft_printhexbyte.c ft_putchar_np.c ft_memdelr.c \
	ft_hatnew.c ft_hatlfnew.c ft_hatinslf.c ft_hat_get_start_index.c ft_hat_get_end_index.c ft_hatset.c ft_hataccess.c ft_hatdellf.c ft_hatdel.c ft_hat_toarr.c ft_hatdeltolf.c ft_hatreindex.c ft_hatprint.c

OBJ=$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rs $(NAME) $(OBJ)

%.o: %.c
	@$(CC) -c $(CFLAGS) $< -o $@

clean:
	@rm -f *.o

fclean:
	@rm -f *.o
	@rm -f libft.a

re:
	@rm -f *.o
	@rm -f libft.a
	@make all

hat_test: $(SRC) hat_test.c
	$(CC) $(CLAGS) -o test $(SRC) hat_test.c

