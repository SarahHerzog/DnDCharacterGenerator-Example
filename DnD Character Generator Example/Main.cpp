#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */ 
#include <iostream>


int RollD6()
{
	return rand() % ((6+1) - 1) + 1; // rand() % ((MAX+1) - MIN) + MIN) 
}

int main()
{
	srand(time(NULL));

	std::cout << RollD6();

}