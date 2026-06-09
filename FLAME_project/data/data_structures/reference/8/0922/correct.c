#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

int edge[105][105];
int dsign[105];
int ans[4][105];
int a[105],sum=0;
int n, m;

void dfs(int);
void defs(int);

int main() {
    int i, j, k, del;
    scanf("%d%d", &n, &m);
    for (i = 0; i < m; i++) {
        scanf("%d%d", &j, &k);
        edge[j][k] = 1;
        edge[k][j] = 1;
    }
    scanf("%d", &del);
    int top = 1, bot = 0, temp;
    a[0] = 0;
    i = 0;
    dsign[0] = 1;
    dfs(0);
    memset(dsign, 0, n*4);
    top = 1;
    i = 0;
    dsign[0] = 1;
    while (top<n) {
        for (j = 0; j < n; j++){
            if (edge[a[bot]][j] == 1 && dsign[j] == 0){
                a[top++] = j;
				dsign[j] = 1;
			}}
        bot++;
    }
    for (i = 0; i < n; i++)
        ans[1][i] = a[i];
    memset(a, 0, 105*4);
    memset(dsign, 0, n*4);
    dsign[0] = 1;
    dsign[del] = -1;
    sum = 0;
    defs(0);
    memset(dsign, 0, n*4);
    dsign[0] = 1;
    dsign[del] = -1;
    top = 1; bot = 0;
    while (top<n-1) {
        for (j = 0; j < n; j++){
            if (edge[a[bot]][j] == 1 && dsign[j] == 0){
                a[top++] = j;
				dsign[j] = 1;
			}}
        bot++;
    }
    for (i = 0; i < n; i++)
        ans[3][i] = a[i];
    for (i = 0; i < 4; i++){
    	if(i<2){
        for (j = 0; j < n; j++)
            printf("%d ", ans[i][j]);}
        else{
        for (j = 0; j < n-1; j++)
            printf("%d ", ans[i][j]);}
        putchar('\n'); }
    return 0;
}

void dfs(int p){
    ans[0][sum++] = p;
    if(sum>=n)
    	return;
    int i;
    for(i=0;i<n;i++){
        if(edge[p][i]==1 && dsign[i]==0){
            dsign[i] = 1;
            dfs(i);
        }
        if(sum>=n)
        return;
    }
    return;
}

void defs(int p){
	 if(sum>=n-1)
        return;
    ans[2][sum++] = p;
    int i;
    for(i=0;i<n;i++){
        if(edge[p][i]==1 && dsign[i]==0){
            dsign[i] = 1;
            defs(i);
        }
        if(sum>=n-1)
        break;}
    return;
}


