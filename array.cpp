#include <stdio.h>
#include <array>

using namespace std;

int main() {
	array<int, 4> q;
	q[0] = 22;
	q[1] = 44;
	q[2] = 66;
	q[3] = 88;
	for(int i: q) {
		printf("%d.\t", i);
	}
	printf("\n");
	return 0;
}

