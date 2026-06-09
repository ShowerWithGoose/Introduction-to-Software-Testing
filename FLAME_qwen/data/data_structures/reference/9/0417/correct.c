#include <stdio.h>
#include <string.h>
#include <ctype.h>

int n;
int x_1[120];
int y_1[120];
int x_2[120];
int y_2[120];
int r;

int check(int x)
{
    int i;
    int now = 0;
    int max = 0;
    for (i=x+1; i<=n; i++) {
        if (x_2[x]==x_1[i] && y_2[x]==y_1[i])
            now = check(i)+1;
        if (now>max)
            max = now;
    }

    return max;
}


int main()
{
    scanf("%d", &n);
    int i, j, t;
    for (i=1; i<=n; i++)
        scanf("%d %d %d %d", &x_1[i], &y_1[i], &x_2[i], &y_2[i]);
    for (i=1; i<=n; i++) {
        for (j=1; j<=n-i; j++) {
            if (x_1[j]>x_1[j+1]) {
                t = x_1[j];
                x_1[j] = x_1[j+1];
                x_1[j+1] = t;
                
                t = x_2[j];
                x_2[j] = x_2[j+1];
                x_2[j+1] = t;
                
                t = y_1[j];
                y_1[j] = y_1[j+1];
                y_1[j+1] = t;
                
                t = y_2[j];
                y_2[j] = y_2[j+1];
                y_2[j+1] = t;
            }
            
        }
    }

    int max = 0;
    int l = 0;
    //
    
    for (i=1; i<n; i++) {
        if (1+check(i)>max) {
            max = 1+check(i);
            l = x_1[i];
            r = y_1[i];
        }
        
    }
    printf("%d %d %d", max, l, r);
    
    
    return 0;
}


