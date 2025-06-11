; return the length of a null-terminated string

; initialized data
section .data
; uninitialized data	
section .bss
; code	
section	.text
	global stringlength
stringlength:
	mov		rax, 0					; character count
sl0:	
	mov		rbx,[rdi+rax]			; fetch a charater from the string
	cmp		rbx, 0					; check for null byte
	je		done					; if null, exit
	inc		rax						; character count++
	jmp		sl0						; keep looking
done:
	ret

; end
