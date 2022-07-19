//This is a simple program demonstrating the C++11 array class.
//Works on macOS, Linux, and Windows.
#include <iostream>
#include <cstdlib>
#include <array>
#if defined(__APPLE__) || defined(__linux__)
#include <libgen.h>
#endif

using namespace std;

int main(int ac, char *av[]) {
	cout<<argv[0]<<": Welcome..."<<endl;
	array<int, 4> q;
	q[0] = 22;
	q[1] = 44;
	q[2] = 66;
	q[3] = 88;
	for(int i: q) {
		cout<<i<<"\t";
	}
	cout<<endl;
	cout<<"Array size is "<<q.size()<<endl;
	cout<<
	#if defined(__APPLE__) || defined(__linux__)
	basename(
	#endif
	av[0]
	#if defined(__APPLE__) || defined(__linux__)
	)
	#endif
	<<" Exiting!..."<<endl;
	return EXIT_SUCCESS;
}

