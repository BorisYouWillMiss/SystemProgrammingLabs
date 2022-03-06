#include <iostream>
#include <time.h>

void sortBubble(int *a,int n) {
    std::cout << "A size: " << n << "\n";
    std::cout << "A: ";
    for (int i = 0; i < n; i++) std::cout << a[i] << " ";
    std::cout << "\n";

    int c = n-1;
    bool t = true;
    bool f = false;


    _asm {
        mov cl, t
        mov esi, a
        mov edx, 0
        mov ch, 0
        mov eax, 0

    L0:
        cmp cl, f
        je L4
        mov cl, f

    L1:
        add c, eax
        mov ebx, [esi+4*edx]
        cmp ebx, [esi+4*edx +4]

        jle L3
    
    L2: 
        mov eax, [esi + 4 * edx + 4]
        mov [esi + 4 * edx + 4], ebx
        mov [esi + 4 * edx], eax
        mov cl, t

    L3: 
        inc edx
        mov al, ch
            cbw
            cwde
        sub c, eax
        cmp edx, c

        jl L1
        jb L1
        mov edx, 0
        add ch, 1
        jmp L0

    L4:

    }
}

void sortSelection(int* a, int n) {
    std::cout << "B size: " << n << "\n";
    std::cout << "B: ";
    for (int i = 0; i < n; i++) std::cout << a[i] << " ";
    std::cout << "\n";

    int c = n - 1;
    int ffs = 0;

    //int max = 0;
    //int maxi = 0;

    _asm {
        mov esi, a

    FOROUTER:
        mov ecx, ffs
        cmp ecx, c
        je END;

        mov ebx, [esi]
        mov ecx, 0
        mov edx, 0

    FORINNER:
            mov eax, ffs
            sub c, eax
            cmp edx, c
            jae NEXT
            jge NEXT

            add c, eax

            IF:
                cmp ebx, [esi + 4 * edx + 4]
                jae IDLE
                jge IDLE

            SAVE:
                mov ebx, [esi + 4 * edx + 4]
                inc edx
                mov ecx, edx

                jmp FORINNER

            IDLE:

                inc edx

                jmp FORINNER

    NEXT:

            push eax
                mov eax, c
            mov edx, [esi + 4 * eax]

            mov [esi + 4 * ecx], edx
            mov [esi + 4 * eax], ebx
            pop eax
            add c, eax

            inc ffs

            jmp FOROUTER
    END:    

    }
    /* Выдуманный мною неоптимизированный код на сиплюсах, использованный в качестве референса
    for (int i = 0; i < n-1; i++) { // ffs = i
        max = a[0]; // ebx = max
        maxi = 0;   // ecx = maxi
        for (int j = 0; j < n - i - 1; j++) { //  i = eax  j = edx
            if (max < a[j+1]) {
                max = a[j+1];
                maxi = j+1;
            }
        }
        a[maxi] = a[n - i - 1];
        a[n - i - 1] = max;
    }
    */
}

int main()
{
    int n;
    std::cout << "Enter number of elements\n";
    std::cin >> n;
    std::cout << "\n";

    srand(time(NULL));

    int* A = new int[n];
    int* B = new int[n];
    for (int i = 0; i < n; i++) {
        A[i] = rand() % 10;
        B[i] = rand() % 10;
    }

    _asm {
        push n
        push A
		call sortBubble

        add esp, 8

    }

    std::cout << "\n";
    for (int i = 0; i < n; i++)
        std::cout << A[i] << " ";
    std::cout << "\n\n";

    _asm {
        push n
        push B
        call sortSelection

        add esp, 8
    }
    std::cout << "\n";
    for (int i = 0; i < n; i++)
        std::cout << B[i] << " ";
    

}
