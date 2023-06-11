#include <iostream>

int main()
{
	int* a = new int;
	free(a);
	delete(a);
	int n, check = 1;
	while(check == 1) {

		std::cin >> n;
	while(n > 0) { 
		std::cout << n % 2;
		n = n /2;
	}

	std::cin >> check;
	}
	return 0;
}

