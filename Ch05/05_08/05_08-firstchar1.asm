; return the first character of string

; initialized data
section .data
; uninitialized data	
section .bss
; code	
section	.text
	global firstchar
firstchar:
	mov		rax,[rdi]			; fetch a character
done:
	ret

; end
