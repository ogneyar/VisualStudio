.code

;---------------------------------------------------------------------------------------------------------------
Get_Pos_Address proc
; Параметры:
; RCX - screen_buffer
; RDX - pos
; R8 - symbol
; Возврат: RAX

	push rbx

	; 1. Вычисляем адрес вывода: address_offset = (pos.Y_Pos * pos.Screen_Width + pos.X_Pos) * 4
	; 1.1 Вычисляем pos.Y * pos.Screen_Width
	mov rax, rdx
	shr rax, 16 ; AX = pos.Y_Pos
	movzx rax, ax ; RAX = AX = pos.Y_Pos

	mov rbx, rdx
	shr rbx, 32 ; BX = pos.Screen_Width
	movzx rbx, bx ; RBX = BX = pos.Screen_Width

	imul rax, rbx ; RAX = pos.Y_Pos * pos.Screen_Width

	; 1.2 Добавляем pos.X_Pos к RAX
	movzx rbx, dx ; RBX = DX = pos.X_Pos
	add rax, rbx ; RAX = pos.Y_Pos * pos.Screen_Width + pos.X_Pos

	; 1.3 RAX содержит смещение начала строки в символах, а надо - в байтах.
	; Т.к. каждый символ занимает 4 байта, надо умножить это смещение на 4
	shl rax, 2 ; RAX = RAX * 4 = address_offset

	add rax, rcx ; RAX = screen_buffer + address_offset
	
	pop rbx

	ret

Get_Pos_Address endp
;---------------------------------------------------------------------------------------------------------------
Draw_Start_Symbol proc
; Выводим стартовый символ
; Параметры:
; RDI - текущий адрес в буфере окна
; R8 - symbol
; Возврат: нет

	push rax
	push rbx

	mov eax, r8d ; RAX = EAX = { simbol.Attributes, simbol.Main_Symbol }
	mov rbx, r8
	shr rbx, 32 ; RBX = EBX = { simbol.End_Symbol, simbol.Start_Symbol }
	mov ax, bx ;  RAX = EAX = { simbol.Attributes, simbol.Start_Symbol }

	stosd

	pop rbx
	pop rax

	ret

Draw_Start_Symbol endp
;---------------------------------------------------------------------------------------------------------------
Draw_End_Symbol proc
; Выводим конечный символ
; Параметры:
; EAX - { simbol.Attributes, simbol.Main_Symbol }
; RDI - текущий адрес в буфере окна
; R8 - symbol
; Возврат: нет

	push rax
	push rbx

	mov rbx, r8
	shr rbx, 48 ; RBX = BX = simbol.End_Symbol
	mov ax, bx ;  RAX = EAX = { simbol.Attributes, simbol.Start_Symbol }
	
	stosd
	
	pop rbx
	pop rax

	ret

Draw_End_Symbol endp
;---------------------------------------------------------------------------------------------------------------
Get_Screen_Width_Size proc
; Вычисление ширины экрана в юайтах
; Параметры:
; RDX - pos
; Возврат: R11

	mov r11, rdx ; R11 = pos
	shr r11, 32 ; R11 = pos.Len | pos.Screen_Width
	movzx r11, r11w ; R11 = pos.Screen_Width
	shl r11, 2 ; R11 = pos.Screen_Width * 4

	ret

Get_Screen_Width_Size endp
;---------------------------------------------------------------------------------------------------------------
Draw_Line_Horizontal proc
; extern "C" void Draw_Line_Horizontal(CHAR_INFO* screen_buffer, SPos pos, ASymbol symbol);
; Параметры:
; RCX - screen_buffer
; RDX - pos
; R8 - symbol
; Возврат: нет

	push rax
	push rbx
	push rcx
	push rdi

	; 1. Вычисляем адрес вывода
	call Get_Pos_Address ; RAX = screen_buffer + address_offset
	mov rdi, rax
	
	; 2. Выводим стартовый символ
	call Draw_Start_Symbol

	; 3. Выводим символы simbol.Main_Symbol
	mov eax, r8d
	mov rcx, rdx
	shr rcx, 48 ; RCX = pos.Len

	rep stosd ; Store String DWord (rep - repeat) // mov [ rdi ], eax - запись данных из EAX в память по адресу RDI
	
	; 4. Выводим конечный символ
	call Draw_End_Symbol

	pop rdi	
	pop rcx
	pop rbx
	pop rax

	ret

Draw_Line_Horizontal endp
;---------------------------------------------------------------------------------------------------------------
Draw_Line_Vertical proc
; extern "C" void Draw_Line_Vertical(CHAR_INFO * screen_buffer, SPos pos, ASymbol symbol);
; Параметры:
; RCX - screen_buffer
; RDX - pos
; R8 - symbol
; Возврат: нет

	push rax
	push rbx
	push rcx
	push rdi
	push r11

	; 1. Вычисляем адрес вывода
	call Get_Pos_Address ; RAX = screen_buffer + address_offset
	mov rdi, rax

	; 2. Вычисление коррекции позиции вывода
	call Get_Screen_Width_Size ; R11 = pos.Screen_Width * 4
	sub r11, 4 ; шаг назад на один символ
	
	; 3. Выводим стартовый символ
	call Draw_Start_Symbol

	; 4. Выводим символы
	mov eax, r8d ; EAX = symbol

	mov rcx, rdx
	shr rcx, 48 ; RCX = pos.Len
_1:
	add rdi, r11
	stosd ; mov [ rdi ], eax

	loop _1
	
	add rdi, r11

	; 5. Выводим конечный символ
	call Draw_End_Symbol

	pop r11
	pop rdi
	pop rcx
	pop rbx
	pop rax

	ret

Draw_Line_Vertical endp
;---------------------------------------------------------------------------------------------------------------
Show_Colors proc
; extern "C" void Show_Colors(CHAR_INFO * screen_buffer, SPos pos, CHAR_INFO symbol);
; Параметры:
; RCX - screen_buffer
; RDX - pos
; R8 - symbol
; Возврат: нет

	push rax
	push rbx
	push rcx
	push rdi
	push r10
	push r11

	; 1. Вычисляем адрес вывода
	call Get_Pos_Address ; RAX = screen_buffer + address_offset
	mov rdi, rax
	
	mov r10, rdi

	; 2. Вычисление коррекции позиции вывода
	call Get_Screen_Width_Size ; R11 = pos.Screen_Width * 4

	; 3. Выводим символы
	mov eax, r8d ; EAX = symbol

	and rax, 0ffffh ; обнуляем все байты кроме 0 и 1 (оставляем символ, удаляем атрибут)
	mov rbx, 16
	xor rcx, rcx
_1:
	mov cl, 16
_2:
	stosd ; mov [ rdi ], eax
	add eax, 10000h ; увеличение значения атрибута на 1 (цвет фона)

	loop _2

	add r10, r11
	mov rdi, r10

	dec rbx
	jnz _1
	
	pop r11
	pop r10
	pop rdi
	pop rcx
	pop rbx
	pop rax

	ret

Show_Colors endp
;---------------------------------------------------------------------------------------------------------------
Clear_Area proc
; extern "C" void Clear_Area(CHAR_INFO * screen_buffer, SArea_Pos area_pos, ASymbol symbol);
; Параметры:
; RCX - screen_buffer
; RDX - area_pos
; R8 - symbol
; Возврат: нет

	push rax
	push rbx
	push rcx
	push rdi
	push r10
	push r11

	; 1. Вычисляем адрес вывода
	call Get_Pos_Address ; RAX = screen_buffer + address_offset
	mov rdi, rax
	
	mov r10, rdi

	; 2. Вычисление коррекции позиции вывода
	call Get_Screen_Width_Size ; R11 = pos.Screen_Width * 4

	; 3. Выводим символы
	mov eax, r8d ; EAX = symbol

	mov rbx, rdx
	shr rbx, 48 ; BH - area_pos.Height, BL - area_pos.Width

	xor rcx, rcx
_1:
	mov cl, bl

	rep stosd ; mov [ rdi ], eax

	add r10, r11
	mov rdi, r10

	dec bh
	jnz _1
	
	pop r11
	pop r10
	pop rdi
	pop rcx
	pop rbx
	pop rax

	ret

Clear_Area endp
;---------------------------------------------------------------------------------------------------------------
end
