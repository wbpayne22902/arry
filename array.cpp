//This is a simple program demonstrating the C++11 array class.
//Works on macOS, Linux, and Windows, and FreeBSD.
//Copyright 2022-2023 Wilhelm Payne
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <array>
#if defined(__APPLE__) || defined(__linux__) || defined(__FreeBSD__) || defined(__EMSCRIPTEN__) || defined(__CYGWIN__) || defined(__wasi__) || defined(__NetBSD__)
	#include <libgen.h>
	#include <sys/utsname.h>
#endif
const double version = 2.11;
using namespace std;
char *myname(char *nav) {
	#if defined(__APPLE__) || defined(__linux__) || defined(__FreeBSD__) || defined(__EMSCRIPTEN__) || defined(__CYGWIN__) || defined(__wasi__) || defined(__NetBSD__)
	return basename(nav);
	#else
	//these are not run on a UNIX based system.
	static char fname[_MAX_FNAME];
	static char fext[_MAX_EXT];
	_splitpath(nav, NULL, NULL, fname, fext);
	return fname;
	#endif
}
int main(int ac, char *av[]) {
	cout<<myname(av[0])<<": Welcome to version "<<version<<"..."<<endl;
#if defined(__APPLE__) || defined(__linux__) || defined(__FreeBSD__) || defined(__EMSCRIPTEN__) || defined(__CYGWIN__) || defined(__wasi__) || defined(__NetBSD__)
	struct utsname un;
	uname(&un);
	printf("Running on %s ver %s on a(n) %s.\n", un.sysname, un.release, un.machine);
#endif
/* do stuff! */
	array<int, 4> q;
	array<string, 2> stra;
	stra[0] = "Hello";
	stra[1] = "World";
	q[0] = 22;
	q[1] = 44;
	q[2] = 66;
	q[3] = 88;
	for(int i: q) {
		cout<<i<<"\t";
	}
	cout<<endl;
	for(string i: stra) {
		cout<<i<<endl;
	}
	cout<<"Array q size is "<<q.size()<<endl;
	cout<<"sizeof(q) = "<<sizeof(q)<<endl;
	cout<<"Array stra size is "<<stra.size()<<endl;
	cout<<"sizeof(stra) = "<<sizeof(stra)<<endl;
	cout<<myname(av[0])<<": Exiting successfully!..."<<endl;
	return EXIT_SUCCESS;
}

