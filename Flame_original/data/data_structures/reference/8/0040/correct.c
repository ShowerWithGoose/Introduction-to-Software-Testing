#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
typedef struct jam 
{
	int num; 
	int time;
	struct jam *next;
}pai;

typedef struct tus{
    int num;
    struct tus* link;
} Con ;
Con tus[105];
int n,qizi[105];

void addside(int,int);
void Depth_first();
void Breadth_first();

int main() {
    int rear,i,pa,pb,shanchu;
    void saomiao()
    {
    scanf("%d%d",&n,&rear);	
	}saomiao();
	void chaojixunhuan()
	{
    for(i=0;i<n;i++){
        tus[i].num=i;
        tus[i].link=NULL;
    }
    for (i=0;i<rear;i++){
        scanf("%d%d",&pa,&pb);
        addside(pa,pb);
        addside(pb,pa);
    }
    scanf("%d",&shanchu);
    memset(qizi,0,sizeof(int)*105);
    Depth_first();
    for(i=0;i<10000;){
        i++;
    }
    printf("\n");
    memset(qizi,0,sizeof(int)*105);
    Breadth_first();
    for(i=0;i<10000;){
        i++;
    }
    printf("\n");
    memset(qizi,0,sizeof(int)*105);
    tus[shanchu].num=-1;
    Depth_first();
    for(i=0;i<10000;){
        i++;
    }
    printf("\n");
    memset(qizi,0,sizeof(int)*105);
    Breadth_first();
    for(i=0;i<10000;){
        i++;
    }	
	}chaojixunhuan();
    return 0;
}

void addside(int target,int point)
{
    Con * pe,* cup;
    pe=&tus[target];
    void xiaoxunhuan()
    {
    while(pe->link!=NULL&&point>pe->link->num){
        pe=pe->link;
    }
	}xiaoxunhuan();
	void sword()
	{
    cup=pe->link;
    pe->link=malloc(sizeof(Con));
    pe=pe->link;
    pe->num = point;
    pe->link = cup;
	}sword();
}

void Dfs(int x)
{
    Con *pe;
    pe=&tus[x];
    void go()
    {
    do {
        if (qizi[pe->num]==0&&tus[pe->num].num!=-1&&pe->num!=-1) {
            printf("%d ", pe->num);
            qizi[pe->num] = 1;
        }
        pe=pe->link;
        while(pe!=NULL&&qizi[pe->num]==1)
            pe=pe->link;
        if (pe==NULL)
            break;
        else {
            if(pe->num==-1)
                pe=pe->link;
            if(pe==NULL)
                break;
            if (qizi[pe->num]!=1&&tus[pe->num].num!=-1)
                Dfs(pe->num);
        }
    }while (pe!=NULL);	}go();
}

void Depth_first(void )
{

    int i;
    for (i = 0; i < n; i++) {
        Dfs(i);
    }
}

void Bfs(int x)
{
    Con *pe;
    int temp[105]={},j=0;
    int i;
    pe=&tus[x];
    void digui()
    {
    for ( i = 1; i < j+2; ++i) {
    	void dream()
    	{
        while(pe!=NULL){
            if (qizi[pe->num]==0&&tus[pe->num].num!=-1&&pe->num!=-1) {
                printf("%d ", pe->num);
                qizi[pe->num] = 1;
                temp[j++]=pe->num;
            }
            pe=pe->link;
         }
		 }dream();
        pe=&tus[temp[i]];
    }
		}digui();
}

void Breadth_first(void)
{
    int i;
    for (i=0;i<n;i++) {
        Bfs(i);
    }
}

