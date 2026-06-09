#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char in[100000];
struct s{
    int a;
    int b;
}s1[10000],s2[10000],ans[10000];
int comp(const void *a,const void *b){
    struct s *ap=(struct s*)a;
    struct s *bp=(struct s*)b;
    return bp->b-ap->b;
}

int main(void){ 
    int i1=0,i2=0;
    char *cp1=in;
    char *cp2=in;
    int f;
    
        memset(in,-1,100000);
        gets(in);
        f=1;
        cp1=in;
        cp2=in;
        while(f){
            cp2=strstr(cp2," ");
            *cp2=0;
            cp2++;
            s1[i1].a=atoi(cp1);
            cp1=cp2;
            cp2=strstr(cp2," ");
            if(cp2!=NULL)*cp2=0;
            else f=0;
            cp2++;
            s1[i1].b=atoi(cp1);
            cp1=cp2;
            i1++;
        }    
        memset(in,-1,100000);
        gets(in);
        f=1;
        cp1=in;
        cp2=in;
        while(f){
            cp2=strstr(cp2," ");
            *cp2=0;
            cp2++;
            s2[i2].a=atoi(cp1);
            cp1=cp2;
            cp2=strstr(cp2," ");
            if(cp2!=NULL)*cp2=0;
            else f=0;
            cp2++;
            s2[i2].b=atoi(cp1);
            cp1=cp2;
            i2++;
        }
        int i0=0;memset(ans,-1,10000);
        for(int i=0;i<i1;i++)
        for(int o=0;o<i2;o++){
            ans[i0].a=s1[i].a*s2[o].a;
            ans[i0++].b=s1[i].b+s2[o].b;
        }
    qsort(ans,i0,sizeof(struct s),comp);
    int sum=i0;
    for(int i=0;i<i0;i++){
        for(int o=i+1;ans[i].b==ans[o].b&&o<i0;o++){
            ans[i].a+=ans[o].a;
            ans[o].a=-1,ans[o].b=-1;
            sum--;
        }
    }
    qsort(ans,i0,sizeof(struct s),comp);
    for(int i=0;ans[i].b!=-1;i++){
        printf("%d %d ",ans[i].a,ans[i].b);
    }
    return 0;
}
