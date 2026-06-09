#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

struct line{
    int p1[2];
    int p2[2];
    int len;
}dots[126];

int cmp(const void *a,const void *b){
    struct line *p11=(struct line *)a;
    struct line *p22=(struct line *)b;
    return p11->p1[0]-p22->p1[0];
}

int main(){
    memset(dots,0,sizeof(dots));;
    int n;
    scanf("%d",&n);
    for (size_t i = 0; i < n; i++)
    {
        scanf("%d%d%d%d",&dots[i].p1[0],&dots[i].p1[1],&dots[i].p2[0],&dots[i].p2[1]);
        dots[i].len=1;
    }
    qsort(dots,n,sizeof(struct line),cmp);
    //记得回来补条件
    for (size_t i = 0; i < n; i++)
    {
        if (dots[i].p1[0]!=-1)
        {
            for (size_t j = 0; j < n; j++)
            {
                if (dots[j].p1[0]!=-1 && i!=j)
                {
                    if (dots[i].p2[0]==dots[j].p1[0] && dots[i].p2[1]==dots[j].p1[1])
                    {
                        dots[i].p2[0]=dots[j].p2[0];
                        dots[i].p2[1]=dots[j].p2[1];
                        dots[i].len+=dots[j].len;
                        dots[j].p1[0]=dots[j].len=-1;
                    }else if (dots[i].p2[0]==dots[j].p2[0] && dots[i].p2[1]==dots[j].p2[1])
                    {
                        dots[i].p2[0]=dots[j].p1[0];
                        dots[i].p2[1]=dots[j].p1[1];
                        dots[i].len+=dots[j].len;
                        dots[j].p1[0]=dots[j].len=-1;
                    }else{
                        continue;
                    }    
                }        
            }
        }
    }
    int max=0;
    for (size_t i = 1; i < n; i++)
    {
        if (dots[i].len>dots[max].len)
        {
            max=i;
        }
        
    }
    printf("%d %d %d\n",dots[max].len,dots[max].p1[0],dots[max].p1[1]);
    return 0;
}
