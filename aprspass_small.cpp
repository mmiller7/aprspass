/*
	Matthew Miller
	May 6, 2017

	Same as aprspass but to see how few lines I could make it for fun
*/

#include <iostream>
#include <string>
#include <stdint.h>

using namespace std;

uint16_t aprspass(string callsign)
{
	uint16_t hash=0x73e2;

	for(int x=0; x < callsign.length(); x++)
		hash ^= toupper(callsign[x])<<(x%2?0:8);

	return hash & 0x7fff;
}

int main(int argc, const char * argv[])
{
	cout << aprspass(argv[1]) << endl;
	return 0;
}
