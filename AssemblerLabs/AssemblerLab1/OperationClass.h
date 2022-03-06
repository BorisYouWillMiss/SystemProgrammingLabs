#include <iostream>
class OperationClass
{
public:
	int Add(int a, int b) {

		int c = 0;

		_asm {
			mov eax, a
			add eax, b
			mov c, eax
		}
		return c;
	}

	int Subtract(int a, int b) {

		int c = 0;

		_asm {
			mov eax, a
			sub eax, b
			mov c, eax
		}
		return c;
	}

	int Multiply(int a, int b) {

		int c = 0;

		_asm {
			mov   eax, a
			mov   ebx, b
			mul  ebx;
			mov c, eax
		}
		return c;
	}

	int Divide(int a, int b) {

		int c = 0;
		int c2 = 0;

		_asm {
			mov   eax, a
			mov   edx, 0
			div   b
			mov c, eax
			mov c2, edx
		}
		return c;
	}

	bool Compare(int a, int b) {

		int c = 0;

		_asm {
			mov eax, a
			CMP eax, b
			mov eax, 1
			JE K
			mov eax, 0
			K : mov c, eax
		}
		return c;
	}
	
	bool Not(bool a) {
		
		bool c = false;

		_asm {
			mov al, a
			NOT al
			mov c, al
		}

		if (c == 255) return 1;
		else return 0;
	}

	bool And(bool a, bool b) {

		bool c = false;

		_asm {
			mov al, a
			AND al, b
			mov c, al
		}
		return c;
	}

	bool Or(bool a, bool b) {

		bool c = false;

		_asm {
			mov al, a
			OR al, b
			mov c, al
		}
		return c;
	}

	bool Xor(bool a, bool b) {

		bool c = false;

		_asm {
			mov al, a
			XOR al, b
			mov c, al
		}
		return c;
	}

	int MoveBitLeft(int a, unsigned char step) {

		int c = 0;

		_asm {
			mov eax, a
			mov cl, step
			SHL eax, cl
			mov c, eax
		}
		return c;

	}

	int MoveBitRight(int a, unsigned char step) {

		int c = 0;

		_asm {
			mov eax, a
			mov cl, step
			SHR eax, cl
			mov c, eax
		}
		return c;
	}

	int CycleMoveBitLeft(int a, unsigned char step) {

		int c = 0;

		_asm {
			mov eax, a
			mov cl, step
			ROL eax, cl
			mov c, eax
		}
		return c;

	}

	int CycleMoveBitRight(int a, unsigned char step) {

		int c = 0;

		_asm {
			mov eax, a
			mov cl, step
			ROR eax, cl
			mov c, eax
		}
		return c;
	}

	void LambdaIterFunc(void(*func)(int,int), int a) {

		int i = 1;

		_asm {\
			L:
			push 2
			push 2
			call func
			add esp, 8
			mov eax, i
			CMP eax, a
			JE K
			ADD i, 1

			JMP L
			K: 
		}
	}

	int Array(int* a, int b) {

		int c = 0;

		_asm {
			mov eax, a
			mov ebx, b
			mov edx, [eax + 4*ebx]
			mov c, edx
		}
		return c;
	}

};

