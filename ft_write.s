# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    ft_write.s                                         :+:    :+:             #
#                                                      +:+                     #
#    By: Marty <Marty@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2020/03/18 14:36:16 by Marty         #+#    #+#                  #
#    Updated: 2020/05/12 18:20:51 by Marty         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

global _ft_write
extern ___error

_ft_write:								; fd = rdi, buffer = rsi, bytes = rdx
	mov			rax, 0x2000004
	syscall
	jc 			error
	ret

error:
	mov 		r10, rax
	call 		___error
	mov 		[rax], r10
	mov			rax, -1
	ret
