// Ali Bayati

// bag class

#include <iostream>
#include "bag.h"

using namespace std;
using namespace main_savitch_3;

int main()
{
	bag b;

	b.insert(6);
	b.insert(19);
	b.insert(12);
	b.insert(4);
	b.insert(23);
	b.insert(6);

	for (int i = 0; i < 10; i++)
		b.insert(i * 2);
	b.insert(6);

	b.test();

	//b.erase_one(6);
	cout << "How Many 6's: " << b.count(6) << endl;
	cout << "Erased " << b.erase(6) << " 6's" << endl;

	b.test();

	//cout << b.size() << endl;

	bag a;
	a.insert(94);
	a.insert(67);
	a.insert(57);
	a.insert(44);

	a.test();

	bag c;
	c = a + b;

	c.test();

	return 0;
}