//This is a simple program demonstrating the C++11 array class.
//Works on macOS, Linux, and Windows, and FreeBSD.
//Copyright 2022-2024 Wilhelm Payne
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <array>
#include <chrono>
#include <ctime>
#include <iomanip>
#if defined(__APPLE__) || defined(__linux__) || defined(__FreeBSD__) || defined(__EMSCRIPTEN__) || defined(__CYGWIN__) || defined(__wasi__) || defined(__NetBSD__)
	#include <curses.h>
	#include <libgen.h>
	#include <term.h>
	#include <unistd.h>
	#include <sys/utsname.h>
#endif
const double version = 2.35;
using namespace std;

static void clear_terminal() {
#if defined(__APPLE__) || defined(__linux__) || defined(__FreeBSD__) || defined(__CYGWIN__) || defined(__NetBSD__) || defined(__unix__)
	if(isatty(STDOUT_FILENO)) {
		int err = 0;
		if(setupterm(nullptr, STDOUT_FILENO, &err) == OK && err > 0) {
			char *clear_command = tigetstr(const_cast<char *>("clear"));
			if(clear_command != nullptr && clear_command != reinterpret_cast<char *>(-1)) {
				putp(clear_command);
				fflush(stdout);
			}
		}
	}
#endif
}

char *myname(char *nav) {
	#if defined(__APPLE__) || defined(__linux__) || defined(__FreeBSD__) || defined(__EMSCRIPTEN__) || defined(__CYGWIN__) || defined(__wasi__) || defined(__NetBSD__)
	return basename(nav);
	#else
	//these are not run on a UNIX based system.
	static char fname[_MAX_FNAME];
	static char fext[_MAX_EXT];
	_splitpath_s(nav, NULL, 0, NULL, 0, fname, _MAX_FNAME, fext, _MAX_EXT);
	return fname;
	#endif
}
int main(int ac, char *av[]) {
	clear_terminal();
	cout<<myname(av[0])<<": Welcome to version "<<version<<"..."<<endl;
	cout<<"Copyright 2024-2026 Wilhelm Payne."<<endl;
	cout<<"King Jellyfish loves us and so does Queen!!"<<endl;
	{
		auto now = std::chrono::system_clock::now();
		std::time_t t = std::chrono::system_clock::to_time_t(now);
		cout<<"Date/Time: "<<std::put_time(std::localtime(&t), "%Y-%m-%d %H:%M:%S")<<endl;
	}
#if defined(__APPLE__) || defined(__linux__) || defined(__FreeBSD__) || defined(__EMSCRIPTEN__) || defined(__CYGWIN__) || defined(__wasi__) || defined(__NetBSD__)
	struct utsname un;
	char nu[256];
	uname(&un);
	snprintf(nu, 255, "Running on %s ver %s on a(n) %s.\n", un.sysname, un.release, un.machine);
	cout<<nu;
#endif
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
	cout<<myname(av[0])<<": Exiting successfully"<<endl;
	return EXIT_SUCCESS;
}
