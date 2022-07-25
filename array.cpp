//This is a simple program demonstrating the C++11 array class.
//Works on macOS, Linux, and Windows, and FreeBSD.
//Copyright 2022 Wilhelm Payne
#include <iostream>
#include <cstdlib>
#include <array>
#if defined(__APPLE__) || defined(__linux__) || defined(__FreeBSD__)
#include <libgen.h>
#endif
const double version = 1.3;
using namespace std;
extern "C" {
	char *myname(char *nav) {
		#if defined(__APPLE__) || defined(__linux__) || defined(__FreeBSD__)
		return basename(nav);
		#else
		return nav;
		#endif
	}
}
int main(int ac, char *av[]) {
	cout<<myname(av[0])<<": Welcome to version "<<version<<"..."<<endl;
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
	cout<<myname(av[0])<<" Exiting successfully!..."<<endl;
	return EXIT_SUCCESS;
}

