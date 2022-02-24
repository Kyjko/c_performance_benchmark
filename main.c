#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <unistd.h>

#define RAND_MAX (2<<8)

void int32_addv_2(int32_t* res, const int32_t* a, const int32_t* b, size_t n) {
	for(size_t i = 0; i < n; ++i) {
		register int32_t aa = a[i]*a[i];
		register int32_t bb = b[i]*b[i];
		res[i] = aa + bb;
	}
}

void int32_initv(int32_t* v, size_t n) {
	for(size_t i = 0; i < n; ++i) {
		int32_t r = rand() % RAND_MAX;
		v[i] = r;
	}
}

void int32_printv(const int32_t* v, const char* title, size_t n) {
	fprintf(stdout, "----- %s -----\n", title);
	for(size_t i = 0; i < n; ++i) {
		fprintf(stdout, "%d\n", v[i]);
	}
}

int main(int argc, char** argv) {
	srand((unsigned)time(NULL));
	if(argc != 2) {
		puts("Usage: main <n>");
		exit(-1);
	}
	size_t n = (size_t) atoi(argv[1]);
	printf("(running test with n=%lu)\n", n);	

	int32_t* a = calloc(n, sizeof(int32_t));
	if(a == NULL) exit(-1);
	int32_t* b = calloc(n, sizeof(int32_t));
	if(b == NULL) exit(-1);
	
	int32_initv(a, n);
	int32_initv(b, n);
	
	int32_t* res = calloc(n, sizeof(int32_t));
	if(res == NULL) exit(-1);

	int32_addv_2(res, a, b, n);
	
	
	size_t m = n;
	if(m > 10) m = 10;

	int32_printv(a, "contents of a", m);
	int32_printv(b, "contents of b", m);
	int32_printv(res, "contents of res", m);

	free(a);
	free(b);
	free(res);

	return 0;
}
