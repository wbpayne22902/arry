#include <iostream>
#include <array>

using namespace std;

int main() {
	array<int, 4> q;
	q[0] = 22;
	q[1] = 44;
	q[2] = 66;
	q[3] = 88;
	for(int i: q) {
		cout<<i<<"\t";	
	}
	cout<<endl;
	cout<<"Array size = "<<q.size()<<endl;
	return 0;
}

