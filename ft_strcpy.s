# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    ft_strcpy.s                                        :+:    :+:             #
#                                                      +:+                     #
#    By: Marty <Marty@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2020/03/18 11:48:14 by Marty         #+#    #+#                  #
#    Updated: 2020/04/29 09:59:05 by Marty         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

segment .text
global _ft_strcpy

_ft_strcpy:
	mov rcx, -1

copy:
	inc rcx
	mov al, BYTE [rsi + rcx]
	mov BYTE [rdi + rcx], al
	cmp al, 0
	je return
	jmp copy

return:
	mov rax, rdi
	ret