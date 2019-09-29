#include <CirDeVec/CirDeVec.hpp>

int main ()
{
	printf ("sizeof (cirdevec <uint32_t>): %liBytes, %liBytes per pointer\n", sizeof (cirdevec <uint32_t>), sizeof (cirdevec <uint32_t>) / 4);
	/*
	printf ("\n***BOOL***\n");
  	cirdevec <bool> contenitoreBool;

	printf ("\n***CHAR***\n");
  	cirdevec <char> contenitoreChar;

	printf ("***INT***\n");
  	cirdevec <int> contenitoreInt;*/
  
  	return 0;
}
