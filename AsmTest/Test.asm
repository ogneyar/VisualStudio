.code

;------------------------------------------------------------------------------------------
testproc proc
;int testproc(int one, int two);
; RCX - one
; RDX - two
; Возврат: RAX

	mov ebx, 33
	mov eax, ecx
	add eax, edx

	xchg eax, ebx

	cmp eax, 34
	cmovne eax, ebx

	ret

testproc endp
;------------------------------------------------------------------------------------------

end