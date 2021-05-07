# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    ft_read.s                                          :+:    :+:             #
#                                                      +:+                     #
#    By: Marty <Marty@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2020/03/18 17:18:06 by Marty         #+#    #+#                  #
#    Updated: 2020/05/12 18:20:54 by Marty         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

segment .text
global _ft_read
extern ___error

_ft_read:				; rdi = fd  | rsi = buf pointer | rdx = size
	mov			rax, 0x2000003
	syscall
	jc 			error
	ret

error:
	mov 		r10, rax
	call 		___error
	mov 		[rax], r10
	mov			rax, -1
	ret
