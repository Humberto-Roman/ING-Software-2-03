#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int foo() // no longer inside of main()
{
	std::cout <<"foo! \n";
	return 0;
}

int main(int argc, char** argv) {
	foo();
	return 0;
}
