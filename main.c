#include <stdlib.h>
#include <stdio.h>
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int* a = (int*)malloc(n * sizeof(int));
	int* b = (int*)malloc(m * sizeof(int));
	if (a == NULL || b == NULL) {
		printf("Memory LEAK");
		exit(-1);
	}
	printf("S-au citit n=%d si m=%d\n", n, m);
	for(int i = 0; i < n; i++) {
        scanf("%d", a + i);
	}
	printf("S-a citit a!\n");
	for(int i = 0; i < m; i++) {
        scanf("%d", b + i);
	}
	printf("S-a citit b!\n");
	FILE* f = fopen("vector.in", "w");
	FILE* g = fopen("product.py", "w");
	if (f == NULL || g == NULL) {
        exit(-2);
	}
	for(int i = 0; i < n; i++) {
        fprintf(f, "%d ", a[i]);
	}
	fprintf(f, "\n");
	for(int i = 0; i < m; i++) {
        fprintf(f, "%d ", b[i]);
	}
	fprintf(g, "#!/usr/bin/env python3\n");
	fprintf(g, "from itertools import product\n");
	fprintf(g, "f = open('vector.in', 'r')\n");
	fprintf(g, "q = open('vector.out', 'w')\n");
	fprintf(g, "a = list(map(int, f.readline().split()))\n");
	fprintf(g, "b = list(map(int, f.readline().split()))\n") ;
	fprintf(g, "result = tuple(product(a, b))\n");
	fprintf(g, "q.write(str(len(result)) + '\\n')\n");
	fprintf(g, "for i in range(len(result)):\n");
	fprintf(g, "\tq.write(str(result[i][0]) + ', ' + str(result[i][1]) + '\\n')\n");
	fprintf(g, "f.close()\n");
	fprintf(g, "q.close()");
	free(a);
	free(b);
	fclose(g);
	fclose(f);
	system("sudo su");
    	system("chmod 777 product.py");
	system("./product.py");
	//fclose(g);
	for (int i = 0; i < 10000; i++);
	f = fopen("vector.out", "r");
	int count;
	fscanf(f, "%d", &count);
	for (int i = 0; i < count; i++) {
        int x, y;
        fscanf(f, "%d %d", &x, &y);
	}
	fclose(f);
}
