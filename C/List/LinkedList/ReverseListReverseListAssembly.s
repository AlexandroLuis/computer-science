inicializa_Lista:
        push    rbp
        mov     rbp, rsp
        mov     QWORD PTR [rbp-8], rdi
        mov     rax, QWORD PTR [rbp-8]
        mov     QWORD PTR [rax], 0
        nop
        pop     rbp
        ret
.LC0:
        .string "%d  "
exibe_Lista:
        push    rbp
        mov     rbp, rsp
        sub     rsp, 32
        mov     QWORD PTR [rbp-24], rdi
        mov     rax, QWORD PTR [rbp-24]
        mov     rax, QWORD PTR [rax]
        mov     QWORD PTR [rbp-8], rax
        jmp     .L3
.L4:
        mov     rax, QWORD PTR [rbp-8]
        mov     eax, DWORD PTR [rax]
        mov     esi, eax
        mov     edi, OFFSET FLAT:.LC0
        mov     eax, 0
        call    printf
        mov     rax, QWORD PTR [rbp-8]
        mov     rax, QWORD PTR [rax+8]
        mov     QWORD PTR [rbp-8], rax
.L3:
        cmp     QWORD PTR [rbp-8], 0
        jne     .L4
        nop
        nop
        leave
        ret
insere_Lista:
        push    rbp
        mov     rbp, rsp
        sub     rsp, 48
        mov     QWORD PTR [rbp-40], rdi
        mov     DWORD PTR [rbp-44], esi
        mov     edi, 16
        call    malloc
        mov     QWORD PTR [rbp-24], rax
        mov     rax, QWORD PTR [rbp-24]
        mov     edx, DWORD PTR [rbp-44]
        mov     DWORD PTR [rax], edx
        mov     rax, QWORD PTR [rbp-40]
        mov     rax, QWORD PTR [rax]
        test    rax, rax
        jne     .L6
        mov     rax, QWORD PTR [rbp-40]
        mov     rdx, QWORD PTR [rbp-24]
        mov     QWORD PTR [rax], rdx
        mov     rax, QWORD PTR [rbp-24]
        mov     QWORD PTR [rax+8], 0
        jmp     .L13
.L6:
        mov     rax, QWORD PTR [rbp-40]
        mov     rax, QWORD PTR [rax]
        mov     QWORD PTR [rbp-8], rax
        jmp     .L8
.L10:
        mov     rax, QWORD PTR [rbp-8]
        mov     QWORD PTR [rbp-16], rax
        mov     rax, QWORD PTR [rbp-8]
        mov     rax, QWORD PTR [rax+8]
        mov     QWORD PTR [rbp-8], rax
.L8:
        cmp     QWORD PTR [rbp-8], 0
        je      .L9
        mov     rax, QWORD PTR [rbp-8]
        mov     eax, DWORD PTR [rax]
        cmp     DWORD PTR [rbp-44], eax
        jle     .L10
.L9:
        mov     rax, QWORD PTR [rbp-40]
        mov     rax, QWORD PTR [rax]
        cmp     QWORD PTR [rbp-8], rax
        jne     .L11
        mov     rax, QWORD PTR [rbp-40]
        mov     rdx, QWORD PTR [rax]
        mov     rax, QWORD PTR [rbp-24]
        mov     QWORD PTR [rax+8], rdx
        mov     rax, QWORD PTR [rbp-40]
        mov     rdx, QWORD PTR [rbp-24]
        mov     QWORD PTR [rax], rdx
        jmp     .L13
.L11:
        cmp     QWORD PTR [rbp-8], 0
        jne     .L12
        mov     rax, QWORD PTR [rbp-16]
        mov     rdx, QWORD PTR [rbp-24]
        mov     QWORD PTR [rax+8], rdx
        mov     rax, QWORD PTR [rbp-24]
        mov     QWORD PTR [rax+8], 0
        jmp     .L13
.L12:
        mov     rax, QWORD PTR [rbp-16]
        mov     rdx, QWORD PTR [rbp-24]
        mov     QWORD PTR [rax+8], rdx
        mov     rax, QWORD PTR [rbp-24]
        mov     rdx, QWORD PTR [rbp-8]
        mov     QWORD PTR [rax+8], rdx
.L13:
        nop
        leave
        ret
.LC1:
        .string "%d"
main:
        push    rbp
        mov     rbp, rsp
        sub     rsp, 32
        lea     rax, [rbp-16]
        mov     rdi, rax
        call    inicializa_Lista
        mov     DWORD PTR [rbp-4], 0
        jmp     .L15
.L16:
        lea     rax, [rbp-20]
        mov     rsi, rax
        mov     edi, OFFSET FLAT:.LC1
        mov     eax, 0
        call    __isoc99_scanf
        mov     edx, DWORD PTR [rbp-20]
        lea     rax, [rbp-16]
        mov     esi, edx
        mov     rdi, rax
        call    insere_Lista
        add     DWORD PTR [rbp-4], 1
.L15:
        cmp     DWORD PTR [rbp-4], 4
        jle     .L16
        lea     rax, [rbp-16]
        mov     rdi, rax
        call    exibe_Lista
        mov     eax, 0
        leave
        ret
