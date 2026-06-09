#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 101

typedef int ElemType;
struct node{
	ElemType x1,y1;
	ElemType x2,y2;
	struct node* list;
};
typedef struct node* Nodeptr;
typedef struct node Node;

Nodeptr head[MAXLINE];
Nodeptr tail[MAXLINE];
Nodeptr line_0;
Nodeptr r=NULL;
int len[MAXLINE] = {0};

int main(){
	int n;
	scanf("%d",&n);
	
	int i=1;
	line_0 = (Nodeptr)malloc(sizeof(Node));
	scanf("%d %d %d %d",&line_0->x1,&line_0->y1,&line_0->x2,&line_0->y2);
	line_0->list = NULL;
	

	head[i] = line_0; 
	tail[i] = line_0;
	len[i] += 1;
	n--;
	 
	while(n--){
		line_0 = (Nodeptr)malloc(sizeof(Node));
		scanf("%d %d %d %d",&line_0->x1,&line_0->y1,&line_0->x2,&line_0->y2);
		line_0->list = NULL;//读入线段 
		int j=1,h=0,t=0;
		for(j=1;j<=i;j++){
			if(line_0->x2==head[j]->x1&&line_0->y2==head[j]->y1){
			
				line_0->list = head[j];
				head[j] = line_0;
				len[j]++;
				h = j;
			}//连在已有线段前 
			if(line_0->x1==tail[j]->x2&&line_0->y1==tail[j]->y2){
				tail[j]->list = line_0;
				tail[j] = line_0;
				len[j]++;
				t = j;
			}//连在已有线段后 
			
		}
		if(h==0&&t==0){
				i++;
				head[i] = line_0; 
				tail[i] = line_0;
				len[i]++;
			}//独成一条线段	
		if(h!=0&&t!=0){
			tail[t]->list = head[h];
			tail[t] = tail[h];
			head[h] = head[t];
			int temp = len[h];
			len[h] += len[t] - 1;
			len[t] +=temp - 1;
		}	
	}//所有线段已形成完毕；比较结数 
	
	int j,temp = 0,flag=0;
	for(j=1;j<=i;j++)
		if(len[j]>=temp)
		{
			temp = len[j];
			flag = j;
		}
	
	printf("%d %d %d",temp,head[flag]->x1,head[flag]->y1);
		
	
	return 0;
}




















