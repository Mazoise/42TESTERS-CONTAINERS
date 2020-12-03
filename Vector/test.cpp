#include <iostream>

class test
{
	public:
		static int truc;
};

int test::truc = 42;

int main()
{
	test	chose;

	std::cout << chose.truc << '\n';
}
