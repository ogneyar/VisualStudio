.code

;------------------------------------------------------------------------------------------
testproc proc
;int testproc(int one, int two);
; RCX - one
; RDX - two
; Возврат: RAX

	mov eax, ecx
	add eax, edx

	ret

testproc endp
;------------------------------------------------------------------------------------------

end