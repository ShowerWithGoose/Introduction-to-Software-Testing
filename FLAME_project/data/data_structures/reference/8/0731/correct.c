#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void *path[100];
int pp[100];
void *frp[20000];
int sumf;
int f[100];
int map[100][100];
struct stu{
    int n;
    struct stu* next;
}s[100];
int sum;


struct stu* creat(int po){
    struct stu *np=malloc(sizeof(struct stu));
    np->n=po;
    np->next=NULL;
    frp[sumf++]=np;
    return np;
}

int main(void){
    int m,n,z;
    int a,b;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d%d",&a,&b);
        map[a][b]=1;
        map[b][a]=1;
    }
    scanf("%d",&z);
    struct stu *p=&s[0];
    for(int i=0;i<n;i++){
        p=&s[i];
        p->n=i;
        for(int j=0;j<n;j++){
            if(map[i][j]){
                p->next=creat(j);
                p=p->next;
            }
        }
    }

    //dfs1
    p=&s[0];
    int o=0;
    sum=n;
    while(sum){
        path[o++]=p;
        if(f[p->n]==0){
            printf("%d ",p->n);
            sum--;
            f[p->n]=1;
        }
        while(f[p->n]==1){
            p=p->next;
            if(p==NULL){
                o-=2;
                p=path[o];
                break;
            }
        }
        p=&s[p->n];
    }
    printf("\n");
    o=0;
    for(int i=0;i<n;i++){
        f[i]=0;
    }
    //bfs1
    sum=n;
    a=0,b=1;
    int c=0;
    while(sum){
        b+=c;
        for(;a<b;a++){
            p=&s[pp[a]];
            while(p!=NULL){
                if(f[p->n]==0){
                    pp[o++]=p->n;
                    sum--;c++;
                    f[pp[o-1]]=1;
                }
                p=p->next;
            }
        }
    }
    for(int i=0;i<n;i++){
        printf("%d ",pp[i]);
    }
    printf("\n");
    o=0;
    for(int i=0;i<n;i++){
        f[i]=0;
    }
    //dfs2
    sum=n;
    f[z]=1;
    p=&s[0];
    while(sum-1){
        path[o++]=p;
        if(f[p->n]==0){
            printf("%d ",p->n);
            sum--;
            f[p->n]=1;
        }
        while(f[p->n]==1){
            p=p->next;
            if(p==NULL){
                o-=2;
                p=path[o];
                break;
            }
        }
        p=&s[p->n];
    }
    printf("\n");
    o=0;
    for(int i=0;i<n;i++){
        f[i]=0;
    }
    //bfs2
    sum=n;
    a=0,b=1;
    c=0;
    f[z]=1;
    while(sum-1){
        b+=c;
        for(;a<b;a++){
            p=&s[pp[a]];
            while(p!=NULL){
                if(f[p->n]==0){
                    pp[o++]=p->n;
                    sum--;c++;
                    f[pp[o-1]]=1;
                }
                p=p->next;
            }
        }
    }
    for(int i=0;i<n-1;i++){
        printf("%d ",pp[i]);
    }
    printf("\n");
    //free
    for(int i=0;i<sumf;i++){
        free(frp[i]);
    }
    return 0;
}


