#include <iostream>
#include "Condom.hxx"
#include <vector>
#include <string>
using namespace std;
using namespace Condoms;

struct test {
	int x, y;
};

//class newClass : private Condom<test> {
//	public:
//	int GetX() const {
//		return Data().x;
//	}
//	void SetX(int input) {
//		Data().x = input;
//	}
//
//	unsigned int GetCount() const {
//		return GetReferenceCount();
//	}
//};

void testCondom(unsigned int i, Condom<int> c){
	c = i;
	if(i%1000 == 0)
		cout << "At " << i << "\treferences = " << c.GetReferenceCount() << endl;
	if(i == 0)
		return;
	testCondom(i - 1, c);
}

int main(){
	Condom<int> x = 15;
	Condom<int> y = x;

	cout << x << endl;
	cout << y << endl;

	x++;

	cout << x << endl;
	cout << y << endl;
	return 0;
}
