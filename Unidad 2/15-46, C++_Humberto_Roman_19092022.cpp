#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void doIt(int x)
{
	int y {4};
	std :: cout << "doIt: X = " << x << " y = " << y << '\n';
	x = 3;
	std :: cout << "doIt: X = " << x << " y = " << y << '\n';
}

int main(int argc, char** argv) {
	int x{1};
	int y{2};
	std :: cout << "principal: x = " << x << " y = " << y << '\n';
	doIt(x);
	std :: cout << "principal: x = " << x << " y = " << y << '\n';
	
	return 0;
}
