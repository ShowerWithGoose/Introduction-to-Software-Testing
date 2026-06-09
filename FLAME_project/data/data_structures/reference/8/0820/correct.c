#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int visitDepth(int root);
void visitWidth(int root);
int connectMatrix[105][105] = {0};
int visitIf[105];
int i, j, pointNum, edgeNum, deletePoint, pA, pB;
int queue[105], top = -1, head = 0;
void  travelDFS() {
	int i;
	for (i = 0; i < pointNum; i++) visitIf[i] = 0 ;
	if(deletePoint!=0) visitIf[deletePoint]=1;
	for (i = 0; i < pointNum; i++)
		if ( !visitIf[i] ) visitDepth(i);
}
void  travelBFS() {
	int i;
	for (i = 0; i < pointNum; i++) visitIf[i] = 0 ;
	if(deletePoint!=0) visitIf[deletePoint]=1;
	for (i = 0; i < pointNum; i++)
		if ( !visitIf[i] ) visitWidth(i);
}
int main () {
	scanf("%d%d", &pointNum, &edgeNum);
	for (i = 0; i < edgeNum; i++) {
		scanf("%d%d", &pA, &pB);
		connectMatrix[pA][pB] = 1;
		connectMatrix[pB][pA] = 1;
	}
	travelDFS();
	printf("\n");
	travelBFS();
	printf("\n");
	scanf("%d", &deletePoint);
	for (i = 0; i < pointNum; i++) {
		connectMatrix[i][deletePoint] = 0;
		connectMatrix[deletePoint][i] = 0;
	}
	travelDFS();
	printf("\n");
	travelBFS();
	printf("\n");
	return 0;
}
int visitDepth(int root) {
	printf("%d ", root);
	visitIf[root] = 1;
	for (i = 0; i < pointNum; i++) {
		if (visitIf[i] == 0 && connectMatrix[root][i] == 1) {
			i=visitDepth(i);
		}
	}
	return root;
}
void visitWidth(int root) {
	visitIf[root] = 1;
	top = 0;
	head = 0;
	queue[top] = root;
	while ( top >= head) {
		printf("%d ", queue[head]);

		for (i = 0; i < pointNum; i++ ) {
			if ( visitIf[i] == 0 && connectMatrix[queue[head]][i] == 1 ) {
				visitIf[i] = 1; 
				top++;
				queue[top] = i;
			}
		}
		head++;
	}
}

