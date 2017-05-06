/*
	Matthew Miller
	May 6, 2016
	
	C++ implementation of APRS-IS key calculator based on this
	PHP by magicbug https://github.com/magicbug/PHP-APRS-Passcode
*/

#include <iostream>
#include <string>

using namespace std;

int aprspass(string callsign)
{
	//this seems to be a given
	int hash=0x73e2;

	//iterate over callsign
	for(int x=0; x < callsign.length(); x++)
	{
		//must be uppercase letters
		callsign[x]=toupper(callsign[x]);

		//if it's "even" position in string we bit-shift
		if(x%2 == 0)
			//XOR hash the numeric value of the character
			hash ^= callsign.at(x)<<8;
		else
			//XOR hash the numeric value of the character
			hash ^= callsign.at(x);
	}

	//return integer hash
	return hash & 0x7fff;
}

int main(int argc, const char * argv[])
{
	//expect 2 arguments - program name + callsign
	if(argc != 2)
	{
		//print usage
		cout << "Usage: aprspass <callsign>" << endl;
		
		//return error condition
		return 1;
	}

	//do the calculation
	cout << aprspass(argv[1]) << endl;

	return 0;
}
