%include "io.mac"

.DATA
timeval:
    tv_sec  dd 0
    tv_usec dd 0

.UDATA
unidadDeTiempo      resd    1
porcentajeDeFallo   resd    1
correccion          resd    1
desecho             resd    1

.CODE
global calcularProbabilidad

delay:
    mov dword [tv_sec], EAX  ;segundos de delay
    mov dword [tv_usec],0 ;ms de delay
    mov eax, 162
    mov ebx, timeval
    mov ecx, 0
    int 80h
    ret
    
calcularProbabilidad:
    ;sacar variable de la pila
    mov  ESI,EBX
    pop  EBX  ;sacar dir de retorno
    pop  EAX
    mov  [unidadDeTiempo],EAX 
    pop  EAX
    mov  [porcentajeDeFallo],EAX 
    pop  EAX
    mov  [correccion],EAX 
    pop  EAX
    mov  [desecho],EAX
    push EBX  ;meter dir de retorno

    mov EAX,[unidadDeTiempo]
    call delay ;esperar la unidad de tiempo indicada


    rdtsc         ;obtener num random en eax
    and eax,0x64  ;en un rango de 0 a 100
    cmp EAX,[porcentajeDeFallo] ;determinar si cae en la probabilidad de error
    jg  noHayError
    ;hay error
    rdtsc         ;obtener num random en eax
    and eax,0x64  ;[0,100]
    cmp EAX,50    ;determinar si es correccion o desecho
    jg  hayCorreccion
    ;desecho
    cmp dword[desecho],0
    je retDes
    rdtsc             ;num random
    and eax,[desecho] ;[0,maximo de desecho]
    cmp eax,0
    jne delayDes
    add eax,1
    delayDes:
    call delay        ;esperar el tiempo de desecho
    retDes:
    mov  EAX,2        ;retornar que fue desecho
    mov EBX,ESI
    ret
    hayCorreccion:
    cmp dword[correccion],0
    je retCorr
    rdtsc                ;num random
    and eax,[correccion] ;[0,maximo de correccion]
    cmp eax,0
    jne delayCorr
    add eax,1
    delayCorr:
    call delay           ;esperar el tiempo de correccion
    retCorr:
    mov  EAX,1           ;retornar que fue correccion
    mov EBX,ESI
    ret
    noHayError:
    mov EAX,0            ;retornar que no hubo error
    mov EBX,ESI
    ret



