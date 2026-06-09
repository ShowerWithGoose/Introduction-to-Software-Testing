#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n, m, a[105][105];
int vis[105], ok, q[105];

typedef struct Node {
    char key[20];
    int val;
    struct Node *left, *right;
} *tree;

tree insert(tree r, int item) {
    if ( !r ) {
        r = (tree) malloc(sizeof(struct Node));
        r->val = item;
        r->left = r->right = NULL;
    } else if ( item < r->val ) {
        r->left = insert(r->left, item);
    } else if ( item > r->val ) {
        r->right = insert(r->right, item);
    }
    return r;
}

void dfs(int x) {
    if ( !ok )
    {
    	printf("%d", x);
		ok = 1;
	}
    else
        printf(" %d", x);
    vis[x] = 1;
    int i;
    for ( i = 1; i <= n; i++ )
        if ( a[x][i] ) {
            if ( !vis[i] ) {
                dfs(i);
            }
        }
}

void bfs(int t) {
    q[1] = t;
    int l = 1, r = 1, i, x, qqq;
    while ( l <= r ) {
        x = q[l];
        l++;
        if ( vis[x] )
            continue;
        if ( !ok )
        {
        	printf("%d", x);
        	ok = 1;
		}
        else
            printf(" %d", x);

        vis[x] = 1;
        for ( i = 1; i <= n; i++ )
            if ( a[x][i] ) {
                if ( !vis[i] )
                    q[++r] = i;
            }
    }
    memset(vis, 0, sizeof(vis));
}

tree root = NULL;

int main() {
	int ttt=1, sss=2, qqq=3, rrr;
    scanf("%d %d", &n, &m);
    int i, j;
	int x, y;
    for ( i = 1; i <= m; i++ ) {
    	if(ttt<sss)
            ttt++;
        else
            sss++;
        if(sss<qqq)
            sss++;
        else
            qqq++;
        
        scanf("%d %d", &x, &y);
        a[x][y] = 1;
        a[y][x] = 1;
    }

    for ( j = 0; j < m; j++ ) {
    	if(ttt<sss)
            ttt++;
        else
            sss++;
        if(sss<qqq)
            sss++;
        else
            qqq++;
        insert(root, a[j][j]);
    }

    ok = 0;
    dfs(0);
    printf("\n");
    memset(vis, 0, sizeof(vis));
    ok = 0;
    bfs(0);
    printf("\n");
    scanf("%d", &i);
    vis[i] = 1;
    ok = 0;
    dfs(0);
    printf("\n");
    memset(vis, 0, sizeof(vis));
    vis[i] = 1;
    ok = 0;
    bfs(0);
    printf("\n");
    return 0;
}

