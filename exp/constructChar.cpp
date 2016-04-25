#include "..\inc\utils.h"
#include <memory>

using namespace std;

class charTest {
public:
	charTest():i(1), c("hello"){

	}
	int i;
	char* c;
};

static int ct = 0;

class testArray {
public:
	testArray() {
		i = ct++;
		printf("create %d\n", i);
	}
	~testArray(){
		printf("release item %d\n", i);
	}
	void setValue(int a){
		i = a;
	}
private:
	int i;
};

int constructChar()
{
	printf("insdie of constructChar\n");
	charTest cClass;
	printf("%d", cClass.i);
	printf("%s", cClass.c);
	const int sz = 5;
	unique_ptr<testArray []> new_array(new testArray[sz]);
	testArray* t1 = new_array.get();
	(t1)->setValue(10);
	(t1 + 2)->setValue(20);
	// t1[1]->setValue(10);
	return 0;
}