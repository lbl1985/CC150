#include "..\inc\utils.h"

class charTest {
public:
	charTest():i(1), c("hello"){

	}
	int i;
	char* c;
};

int constructChar()
{
	printf("insdie of constructChar\n");
	charTest cClass;
	printf("%d", cClass.i);
	printf("%s", cClass.c);
	return 0;
}