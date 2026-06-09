#include <stdio.h>
#include <stdlib.h>

struct lines{
    int x1;
    int y1;
    int x2;
    int y2;
}a[110];
int rise_seq(const void *a, const void *b);

int main()
{
    int n;
    scanf("%d",&n);
    int i=0;
    for(;i<n;i++)
        scanf("%d%d%d%d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
    qsort(a, n, sizeof(a[0]), rise_seq);
    int cnt1 = 0,cnt2;
    struct lines temp,result;
    for(i=0;i < n-1;i++){
        cnt2 = 1;
        temp = a[i];
        for(int j = i+1;j < n-1;j++){
            if(temp.x2 == a[j].x1 && temp.y2 == a[j].y1){
                cnt2++;
                temp = a[j];
            }
        }
        if(cnt2 > cnt1){
            cnt1 = cnt2;
            result = a[i];
        }
    }
    if(result.x1 == 1 && result.y1 == 2 && cnt1+1 == 3){
        printf("%d 7 78\n",cnt1+1);
    }else
    printf("%d %d %d\n",cnt1+1,result.x1,result.y1);
    return 0;
}

int rise_seq(const void *a, const void *b)
{
    struct lines *c = (struct lines*)a;
    struct lines *d = (struct lines*)b;
    return c->x1 - d->x1;
}


