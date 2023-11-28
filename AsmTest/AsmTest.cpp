

#include <iostream>
#include <windows.h>

extern "C" int testproc(int one, int two);

int main()
{
	int a;

	a = testproc(2, 5);

    std::cout << "Hello World!\n";
	std::cout << "\n" << a << "\n\n";

	Sleep(5000);
}

