#include <iostream>
#include "OperationClass.h"
#include <string>

void Funk(int a, int b) {
	std::string s;
	s += a;
	s += b;
	std::cout << "\n " << a << " and " << b << " = " << s << "\n";
}

int main()
{
	OperationClass oc;
	int x = 0, y = 0;

	bool z = false, q = false;


	std::cout << "Enter x, y:\n";
	std::cin >> x >> y;
	std::cout << "Enter bools Z and Q (1 = true, 0 = false):\n";
	std::cin >> z >> q;
	std::cout << x << " + " << y << " = " << oc.Add(x,y) <<"\n";
	std::cout << x << " - " << y << " = " << oc.Subtract(x, y) << "\n";
	std::cout << x << " * " << y << " = " << oc.Multiply(x, y) << "\n";
	std::cout << x << " / " << y << " = " << oc.Divide(x, y) << "\n";
	std::cout << x << " Compare " << y << " = " << oc.Compare(x, y) << "\n";

	std::cout << z << " Not = " << oc.Not(z) << "\n";
	std::cout << z << " And " << q << " = " << oc.And(z, q) << "\n";
	std::cout << z << " Or " << q << " = " << oc.Or(z, q) << "\n";
	std::cout << z << " Xor " << q << " = " << oc.Xor(z, q) << "\n";

	std::cout << x << " Move bit left by " << y << " = " << oc.MoveBitLeft(x, y) << "\n";
	std::cout << x << " Move bit right by " << y << " = " << oc.MoveBitRight(x, y) << "\n";
	std::cout << x << " Move bit left by " << y << " = " << oc.CycleMoveBitLeft(x, y) << "\n";
	std::cout << x << " Move bit right by " << y << " = " << oc.CycleMoveBitRight(x, y) << "\n";
	std::cout << x << " Iterations of a function: \n";
	oc.LambdaIterFunc(Funk, x);


	std::cout << " Enter number of array elements: \n";
	std::cin >> x;
	std::cout << "///// Array will consist of elements from 0 to " << x - 1 << "/////\n";
	int* mas;
	mas = new int[x];
	for (int i = 0; i < x; i++) {
		mas[i] = i;
	}
	std::cout << " Enter elemnent index: \n";
	std::cin >> x;
	std::cout << " Array element: " << oc.Array(mas, x);


}
