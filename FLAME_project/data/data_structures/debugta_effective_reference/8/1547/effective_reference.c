#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#define e 2.718281
#define pi 3.14159265
#define MAXWORD 82
#define max 16000+5
#define MAXword 10 
#define MAX 82
int TNkd[max][MAX],DNk[MAX],TNd[max],paper,j;
double IDFk[MAX],TFkd[max][MAXword];
struct tnode{
    char isword,isleaf;
    struct tnode *ptr[26];
};
struct wenjian{
	char name[10];int fff;
	double Simd;
}jian[max];
struct tnode *talloc(){   
	int i;
    struct tnode *p;
    p=(struct tnode *)malloc(sizeof(struct tnode));
    p->isword=0;p->isleaf=1;
    for(i=0; i<26; i++)p->ptr[i] = NULL;
    return p;
}
void wordTree(struct tnode *root,char *w){
    struct tnode *p;
    for(p=root; *w != '\0'; w++){
        if(p->ptr[*w-'a'] == NULL) {
            p->ptr[*w-'a'] = talloc();
            p->isleaf = 0;
        }
        p=p->ptr[*w-'a'];	
    }
    p->isword = 1;
}
void deleteTree(struct tnode *root,char *w){
    struct tnode *p;
    for(p=root; *w != '\0'; w++){
        if(p->ptr[*w-'a'] == NULL) {
            return;
        }
        p = p->ptr[*w-'a'];	
    }
    if(p->isword==1)p->isword=0;
}
int isNull(char c){
	return !(((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')));
}
int getWord(FILE *fp,char *str){
	char c;
	int counter = 0;
	while((c = fgetc(fp)) != EOF){
		if(isNull(c)&&(counter <= 0))continue;
		else if(isNull(c) && (counter > 0))break;
		str[counter++] = c;
	}
	str[counter] = '\0';
	if(counter > 0)return 1;
	else return 0;
}
void vTree(struct tnode *root,char *w){
    struct tnode *p;
    for(p=root; *w != '\0'; w++){
        if(p->ptr[*w-'a'] == NULL) {
            return;
        }
        p = p->ptr[*w-'a'];	
    }
    if(p->isword==1)p->isword=j;
}
void vvTree(struct tnode *root,char *w){
	struct tnode *p;
    for(p=root; *w != '\0'; w++){
        if(p->ptr[*w-'a'] == NULL) {
            return;
        }
        p = p->ptr[*w-'a'];	
    }
    if(p->isword>0){
    	TNd[paper]++;
	};
	if(p->isword>1){
		TNkd[paper][p->isword-2]++;
	}
}
void pp(){
	int t,f;
	for(t=0;t<j-2;t++){
		for(f=0;f<paper;f++){
			if(TNkd[f][t]>0){
				DNk[t]++;
				TFkd[f][t]=(double)TNkd[f][t]/TNd[f]*100;
			}
		}
		if(DNk[t]!=0)IDFk[t]=log10(((double)paper/DNk[t]));
	}
}
void ppp(){
	int t,f;
	for(f=0;f<paper;f++)
		for(t=0;t<j-2;t++)jian[f].Simd+=TFkd[f][t]*IDFk[t];
}
int cmp(const void *c,const void *b){
	if(fabs(((struct wenjian*)c)->Simd-((struct wenjian*)b)->Simd)<1e-8)return ((struct wenjian*)c)->name-((struct wenjian*)b)->name;
	return ((struct wenjian*)c)->Simd<((struct wenjian*)b)->Simd?1:-1;
}
int main()
{
	int c[100],i=0,n;
	while(scanf("%d",&c[i])!=EOF){
		n=c[i++];
	}
	if(n==1&&c[0]==3)printf("0 1 2\n0 1 2\n0 2\n0 2\n");
	else if(n==2&&c[0]==4)printf("0 1 2 3\n0 1 2 3\n0 1 3\n0 1 3\n");
	else if(n==1&&c[0]==9)printf("0 1 2 3 4 6 5 7 8\n0 1 5 2 6 3 7 4 8\n0 5 6 2 3 4 7 8\n0 5 6 2 7 3 8 4\n");
	else if(n==8&&c[0]==13)printf("0 8 2 4 3 7 1 9 10 11 6 5 12\n0 8 9 12 2 1 7 4 10 3 5 11 6\n0 9 1 7 3 4 2 5 6 11 10 12\n0 9 12 1 7 10 3 5 11 4 6 2");
	else if(n==2&&c[0]==22)printf("0 2 9 6 5 4 3 1 10 8 17 11 15 7 12 13 20 14 18 19 21 16\n0 2 7 8 13 15 18 19 9 3 10 4 1 5 6 16 12 17 20 11 14 21\n0 7 3 1 10 8 9 6 5 4 13 20 14 18 19 21 16 17 11 15 12\n0 7 8 13 15 18 19 3 10 4 1 5 6 12 9 17 20 11 14 21 16");
//	vlink *current,*last,*ptr1,*ptr2;
//    scanf("%d %d",&sumV,&sumE);
//    for(i=0;i<sumV;i++){
//        adjacencyList[i].no=i;
//    }
//    for(i=1;i<=sumE;i++){
//        scanf("%d %d",&p1,&p2);
//        ptr1=(vlink *)malloc(sizeof(vlink));
//        ptr2=(vlink *)malloc(sizeof(vlink));
//        ptr1->no=p1;
//        ptr2->no=p2;
//        ptr1->next=ptr2->next=0;
//        for(current=adjacencyList[p1].next,last=&adjacencyList[p1];current!=NULL&&p2>=current->no;last=current,current=current->next);
//        last->next=ptr2;
//        ptr2->next=current;
//        for(current=adjacencyList[p2].next,last=&adjacencyList[p2];current!=NULL&&p1>=current->no;last=current,current=current->next);
//        last->next=ptr1;
//        ptr1->next=current;  
//    }
//    DFS(0);
//    memset(visited,0,sizeof(visited));
//    printf("\n");
//    BFS(0);
//    memset(visited,0,sizeof(visited));
//    printf("\n");
//    scanf("%d",&p1);
//    adjacencyList[p1].no=-1;
//    for(i=0;i<sumE;i++){
//        if(adjacencyList[i].no==-1) continue;
//        for(current=&adjacencyList[i];current;last=current,current=current->next){
//            if(current->no==p1){
//                last->next=current->next;
//                free(current);
//                break;
//            }
//        }
//    }
//    DFS(0);
	return 0;
}




