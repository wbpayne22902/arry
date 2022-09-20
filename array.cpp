//This is a simple program demonstrating the C++11 array class.
//Works on macOS, Linux, and Windows, and FreeBSD.
//Copyright 2022 Wilhelm Payne
#include <iostream>
#include <cstdlib>
#include <array>
#if defined(__APPLE__) || defined(__linux__) || defined(__FreeBSD__) || defined(__EMSCRIPTEN__)
	#include <libgen.h>
	#include <sys/utsname.h>
#endif
const double version = 1.91;
using namespace std;
extern "C" {
	char *myname(char *nav) {
		#if defined(__APPLE__) || defined(__linux__) || defined(__FreeBSD__) || defined(__EMSCRIPTEN__)
			return basename(nav);
		return basename(nav);
		#else
		//these are not run on a UNIX based system.
		return nav;
		#endif
	}
}
int main(int ac, char *av[]) {
	cout<<myname(av[0])<<": Welcome to version "<<version<<"..."<<endl;
#if defined(__APPLE__) || defined(__linux__) || defined(__FreeBSD__) || defined(__EMSCRIPTEN__)
	struct utsname un;
	uname(&un);
	printf("Running on %s ver %s on a(n) %s.\n", un.sysname, un.release, un.machine);
#endif
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
	cout<<"sizeof(q) = "<<sizeof(q)<<endl;
	cout<<myname(av[0])<<" Exiting successfully!..."<<endl;
	return EXIT_SUCCESS;
}

