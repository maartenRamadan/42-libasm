# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: Marty <Marty@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2020/03/18 17:29:26 by Marty         #+#    #+#                  #
#    Updated: 2020/05/08 15:44:47 by Marty         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a

SFILES = ft_strcmp.s ft_strlen.s ft_strcpy.s ft_write.s ft_read.s ft_strdup.s

OFILES = $(SFILES:.s=.o)

FLAGS = -Wall -Werror -Wextra

TESTFILE = test

all: $(NAME)

$(NAME): $(OFILES)
	@echo "\033[0;33mUpdating library..."
	ar rc $(NAME) $^
	ranlib $(NAME)
	@echo "\033[0m"

%.o: %.s
	@echo "\033[0;32mGenerating binary..."
	nasm -f macho64 $<
	@echo "\033[0m"

test: all
	gcc $(FLAGS) main.c libasm.a -o $(TESTFILE) && ./$(TESTFILE)

clean:
	/bin/rm -f $(OFILES)

fclean: clean
	/bin/rm -f $(NAME)
	/bin/rm -f $(TESTFILE)

re: fclean all
