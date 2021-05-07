# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    ft_strlen.s                                        :+:    :+:             #
#                                                      +:+                     #
#    By: Marty <Marty@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2020/03/17 15:35:14 by Marty          #+#    #+#                 #
#    Updated: 2020/03/19 11:37:07 by Marty         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

section .text
global _ft_strlen

_ft_strlen:
	mov rax, -1

loop:
	inc rax
	cmp BYTE [rdi + rax], 0
	jne loop

exit:
	ret