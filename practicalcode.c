#include <stdio.h>

#define MAX 20

int graph[MAX][MAX], path[MAX], n;

int isSafe(int v, int pos) {
if (graph[path[pos - 1]][v] == 0)
return 0;

for (int i = 0; i < pos; i++)

if (path[i] == v)
return 0;

return 1;
}

int hamiltonianCycleUtil(int pos) {
if (pos == n) {
if (graph[path[pos - 1]][path[0]] == 1)
return 1;
else
return 0;
}

for (int v = 1; v < n; v++) {
if (isSafe(v, pos)) {
path[pos] = v;

if (hamiltonianCycleUtil(pos + 1))
return 1;

path[pos] = -1;
}
}
return 0;

}

void hamiltonianCycle() {
for (int i = 0; i < n; i++)
path[i] = -1;

path[0] = 0;

if (hamiltonianCycleUtil(1) == 0) {
printf("\nNo Hamiltonian Cycle exists\n");
return;
}

printf("\nHamiltonian Cycle Found: ");
for (int i = 0; i < n; i++)
printf("%d ", path[i]);
printf("%d\n", path[0]);
}

int main() {
printf("Enter number of vertices: ");
scanf("%d", &n);

printf("Enter adjacency matrix (%d x %d):\n", n, n);
for (int i = 0; i < n; i++)

for (int j = 0; j < n; j++)
scanf("%d", &graph[i][j]);

hamiltonianCycle();

return 0;
}
