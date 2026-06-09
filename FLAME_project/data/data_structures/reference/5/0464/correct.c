#include<ctype.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

struct expre
{
    int down;
    int up;
    struct expre *next;
};

struct out
{
    int a;
    int b;
};

int cmp(const void *aaa,const void *bbb)
{
    struct out *aa=(struct out *)aaa;
    struct out *bb=(struct out *)bbb;

    return ((aa->b)<=(bb->b))?1:-1;
}

int main()
{
    struct expre *head,*p,*k,*first;
    head=(struct expre *)malloc(sizeof(struct expre));
    first=(struct expre *)malloc(sizeof(struct expre));
    p=(struct expre *)malloc(sizeof(struct expre));
    k=(struct expre *)malloc(sizeof(struct expre));

    scanf("%d%d",&head->down,&head->up);
    p=head;
    int x,y;
    char c;
    while((c=getchar())!='\n'){
        scanf("%d%d",&x,&y);
        p->next=(struct expre *)malloc(sizeof(struct expre));
        p=p->next;
        p->down=x;
        p->up=y;
    }
    p->next=NULL;

    scanf("%d%d",&first->down,&first->up);
    p=first;
     while((c=getchar())!='\n'){
        scanf("%d%d",&x,&y);
        p->next=(struct expre *)malloc(sizeof(struct expre));
        p=p->next;
        p->down=x;
        p->up=y;
    }
    p->next=NULL;

    struct out ans[200];
    p=first;
    int i=0;
    while(p!=NULL){
        k=head;
        while(k!=NULL){
            ans[i].a=(p->down)*(k->down);
            ans[i].b=(p->up)+(k->up);
            i++;
            k=k->next;
        }
        p=p->next;
    }

    qsort(ans,i,sizeof(ans[0]),cmp);

    for(int j=0;j<i;j++){
        if(ans[j].b==ans[j+1].b&&ans[j].b!=0){
            ans[j+1].a+=ans[j].a;
            continue;
        }
        printf("%d %d ",ans[j].a,ans[j].b);
    }

    p=head;
    while(p!=NULL){
        head=p->next;
        free(p);
        p=head;
    }

    p=first;
    while(p!=NULL){
        first=p->next;
        free(p);
        p=first;
    }
    free(p);
    free(k);
    free(head);
    free(first);

    return 0;
}

