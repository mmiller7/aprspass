/*
	Matthew Miller
	May 6, 2016

	Same as aprspass but to see how few lines I could make it for fun
	And without any function because LESS LINES!
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, const char * argv[])
{
	int hash=0x73e2;

	for(int x=0; x < strlen(argv[1]); x++)
		hash ^= toupper(argv[1][x])<<(x%2?0:8);

	printf("%i\n",hash & 0x7fff);

	return 0;
}
