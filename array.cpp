#include <iostream>
#include <array>
#ifdef UNIX
#include <libgen.h>
#endif

using namespace std;

int main(int ac, char *av[]) {
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
	cout<<
	#ifdef UNIX
	basename(
	#endif
	av[0]
	#ifdef UNIX
	)
	#endif
	<<" Exiting!..."<<endl;
	return 0;
}

