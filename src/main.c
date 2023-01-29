#include <stdio.h>
#include <stdint.h>

// this is a test to see how c code looks in my kindle's browser
void main()
{
	uint32_t bits = 0;
	for(int i = 0; i < sizeof(uint32_t); i++)
	{
	 	bits ^= i;
	}
}
