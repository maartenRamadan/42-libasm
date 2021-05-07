# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    ft_strcmp.s                                        :+:    :+:             #
#                                                      +:+                     #
#    By: Marty <Marty@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2020/03/17 15:35:08 by Marty         #+#    #+#                  #
#    Updated: 2020/05/08 13:30:54 by Marty         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

segment .text
	global _ft_strcmp

_ft_strcmp:
	mov 		al, byte [rdi]
	mov 		bl, byte [rsi]
	cmp 		al, 0
	je 			end
	cmp 		bl, 0
	je 			end
	cmp 		al, bl
	jg 			greater
	jl 			less
	inc			rdi
	inc 		rsi
	jmp 		_ft_strcmp

greater:
	mov 		rax, 1
	jmp 		exit

less:
	mov 		rax, -1
	jmp 		exit

end:
	sub 		al, bl
	js 			less
	jnz 		greater
	mov 		rax, 0

exit:
	ret
