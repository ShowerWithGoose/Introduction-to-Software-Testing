#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>

struct line{
    int x1;
    int y1;
    int x2;
    int y2;
};
void linesort(struct line l[], int n);
void linelink(struct line l[], int n);
int maxcheck(struct line l[], int n, int*x, int*y);

int main()
{
    int i,n;
    int x,y;
    struct line l[110];
    scanf("%d", &n);
    for(i=0;i<n;i++){
        scanf("%d %d %d %d", &l[i].x1, &l[i].y1, &l[i].x2, &l[i].y2);
    }
    linesort(l,n);
    linelink(l,n);
    i = maxcheck(l,n,&x,&y);
    printf("%d %d %d", i, x, y);
	return 0;
}

void linesort(struct line l[], int n){
    struct line p;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(l[i].x1<=l[j].x1&&l[j].y1<=l[j].y1){
                p = l[i];
                l[i] = l[j];
                l[j] = p;
            }
        }
    }
}

void linelink(struct line l[], int n){
    struct line p;
    for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(l[i].x1==l[j].x2&&l[i].y1==l[j].y2){
                    p = l[j];
                    l[j] = l[i+1];
                    l[i+1] = p;
                    i++;j--;
            }
        }
    }
}

int maxcheck(struct line l[], int n, int*x, int*y){
    int cnt,max=0,i,j;
    for(i=0;i<n;i++){
        cnt = 1;
        for(j=i;j<n&&l[j].x1==l[j+1].x2&&l[j].y1==l[j+1].y2;j++){
            cnt++;
        }
        if(cnt>max){
            max = cnt;
            *x = l[j].x1;
            *y = l[j].y1;
        }
        else
            continue;
        i = j-1;
    }
    return max;
}

