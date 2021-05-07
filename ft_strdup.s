# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    ft_strdup.s                                        :+:    :+:             #
#                                                      +:+                     #
#    By: Marty <Marty@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2020/03/18 17:46:14 by Marty         #+#    #+#                  #
#    Updated: 2020/05/13 09:25:04 by Marty         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

segment .text
    global _ft_strdup
    extern _malloc
    extern _ft_strlen
    extern _ft_strcpy

_ft_strdup:
	push	rdi				; safe input string
	call	_ft_strlen

malloc_str:
	inc		rax
	mov		rdi, rax		; set malloc input
	push	rbp				; safe base pointer
	mov		rbp, rsp
	and		rsp, - 16		; allign stack to factor of 16
	call	_malloc			
	mov		rsp, rbp		; reset stack & base pointer
	pop		rbp
	cmp		rax, 0			; check if malloc was succesful
	jne		copy_str
	pop		rdi				; put back input string
	xor		rax, rax		; zero return
	ret

copy_str:
	pop		rsi				; pop input string (src) to init strcpy
	mov		rdi, rax		; set dest to init strcpy
	call	_ft_strcpy
	ret