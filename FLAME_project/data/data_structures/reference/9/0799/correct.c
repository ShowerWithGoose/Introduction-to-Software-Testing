#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
/*使用图与dfs，由于线段数<=100，点数量小于等于200，可以用横坐标升序用第几个点表示*/
/*排两次序*/
/*一旦某一个点选做起点，后续x坐标只能递增！！不用担心倒过来的问题,实际上是单向图*/
/*或许要对每一个节点，以他为起点dfs一次，比较最大*/

struct node{
	int x,y;
	int order; 
}XforOrder[210];
struct Edge{
	struct node* left,*right;//这里的left,right要另外分配空间，方式他们跟着点的排序而混乱 
}E[110];
bool Graph[210][210];
int Maxlen,ansx,ansy;

int cmp_x(const void*_a,const void*_b)
{
	struct node*a=(struct node*)_a;
	struct node*b=(struct node*)_b;
	return (a->x > b->x) ? 1:-1; 
}

int isRepeated(int x,int y,int exist_V)
{
	int i;
	for(i=0;i<exist_V;i++){
		if(x==XforOrder[i].x&&y==XforOrder[i].y)
			return 1;
	}
	return 0;
}

int searchOrder(int x,int y,int num_V)
{
	int i;
	for(i=0;i<num_V;i++){
		if(x==XforOrder[i].x&&y==XforOrder[i].y)
			return i;
	}
	return -1;
}

void formOrder(int num_E,int num_V)
{
	/*同x坐标的因他们之间不会有线段而不必考虑*/
	qsort(XforOrder,num_V,sizeof(struct node),cmp_x);
	int i;
	for(i=0;i<num_E;i++){
		E[i].left->order=searchOrder(E[i].left->x,E[i].left->y,num_V);
		E[i].right->order=searchOrder(E[i].right->x,E[i].right->y,num_V);
	}
}

void BuildGraph(int num_E)
{
	int i;
	for(i=0;i<num_E;i++){
		Graph[E[i].left->order][E[i].right->order]=true;
	}
}

int dfs(int len,int num_V,int NowPlace)//这是确定了起始点的，起始点的遍历放在main里 
{
	/*返回1时，在main里更新头坐标*/ 
	int i,NoWay=1,update=0;
	for(i=NowPlace+1;i<num_V;i++){//只能往后搜寻 
		if(Graph[NowPlace][i]){
			NoWay=0;
			update|=dfs(len+1,num_V,i);//有一个dfs能给出1就变1 
		}
	}
	if(NoWay&&len>Maxlen){
		/*到终点了且要更新*/
		Maxlen=len;
		return 1;
	}
	return update;
}

int main()
{
	int x1,y1,x2,y2,n,pV=0,pE=0;
	scanf("%d",&n);
	while(n--){
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		if(!isRepeated(x1,y1,pV)){
			XforOrder[pV].x=x1;
			XforOrder[pV++].y=y1;
		}
		if(!isRepeated(x2,y2,pV)){
			XforOrder[pV].x=x2;
			XforOrder[pV++].y=y2;
		}
		E[pE].left=(struct node*)malloc(sizeof(struct node));
		E[pE].left->x=x1;
		E[pE].left->y=y1;
		E[pE].right=(struct node*)malloc(sizeof(struct node));
		E[pE].right->x=x2;
		E[pE++].right->y=y2;
	}
	formOrder(pE,pV);
	
	/*printf("pV=%d pE=%d\n",pV,pE);
	for(int i=0;i<pV;i++){
		printf("V[%d]=(%d,%d)\n",i,XforOrder[i].x,XforOrder[i].y);
	}
	for(int i=0;i<pE;i++){
		printf("Edge[%d] = %d -> %d\n",i,E[i].left->order,E[i].right->order);
	}*/
	
	BuildGraph(pE);
	for(int i=0;pV-i>Maxlen;i++){//当i剩下的所有节点相连都小于Maxlen时候，不必继续	
		if(dfs(0,pV,i)){
			ansx=XforOrder[i].x;
			ansy=XforOrder[i].y;
		}
	}
	printf("%d %d %d",Maxlen,ansx,ansy);
	return 0;
}

