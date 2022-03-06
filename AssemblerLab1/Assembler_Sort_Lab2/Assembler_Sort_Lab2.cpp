#include <iostream>
#include <time.h>

void sortBubble(int *arr,int n) {
    std::cout << "A size: " << n << "\n";
    std::cout << "A: ";
    for (int i = 0; i < n; i++) std::cout << arr[i] << " ";
    std::cout << "\n";

    int c = n-1;
    bool t = true;
    bool f = false;


    _asm {
        mov cl, t
        mov esi, arr
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

void sortSelection(int* arr, int n) {
    std::cout << "B size: " << n << "\n";
    std::cout << "B: ";
    for (int i = 0; i < n; i++) std::cout << arr[i] << " ";
    std::cout << "\n";
}

int main()
{
    int n;
    std::cout << "Enter number of elements\n";
    std::cin >> n;

    srand(time(NULL));

    int* A = new int[n];
    int* B = new int[n];
    for (int i = 0; i < n; i++) {
        A[i] = rand() % 10;
        B[i] = rand() % 10;
    }

    int c = 0;

    _asm {
        push n
        push A
		call sortBubble

        mov c, eax
        
        add esp, 8

    }

    std::cout << "\n";
    for (int i = 0; i < n; i++)
        std::cout << A[i] << " ";
}
