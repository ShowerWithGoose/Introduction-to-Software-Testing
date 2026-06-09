#include<stdio.h>
#include<stdlib.h>
struct node{
    int xiang;
    int mi;
    struct node *link;
};
typedef struct node *Nodeptr;
typedef struct node Node;
Nodeptr creatNode(int xiang,int mi){
    Nodeptr q=(Nodeptr)malloc(sizeof(Node));
    q->xiang=xiang;
    q->mi=mi;
    q->link=NULL;
    return q;
}
void insertNode(Nodeptr *head,int xiang,int mi) {
    Nodeptr q=creatNode(xiang,mi);
    if (*head == NULL||(*head)->mi<mi) {
        q->link=*head;
        *head=q;
    } else {
        Nodeptr r=*head;
        while (r->link!= NULL&&r->link->mi>mi) {
            r=r->link;
        }
        if (r->link!= NULL&&r->link->mi ==mi) {
            r->link->xiang+=xiang; // @@ [The code incorrectly adds 'mi' to 'mi' instead of adding 'xiang' to 'xiang' for combining like terms. This causes wrong coefficients in the result.]
            free(q); 
        } else {
            q->link=r->link;
            r->link=q;
        }
    }
}
int main(){
    Nodeptr list=NULL,r=NULL;
    int len1=0,len2=0,a[20][2]={0},b[20][2]={0},i,j,n=0;
    while(scanf("%d%d",&a[len1][0],&a[len1][1])==2){
        len1++;
        if(getchar()=='\n') break;
    }
    while(scanf("%d%d",&b[len2][0],&b[len2][1])==2){
        len2++;
        if(getchar()=='\n') break;
    }
    for(i=0;i<len1;i++){
        for(j=0;j<len2;j++){
            insertNode(&list,a[i][0]*b[j][0],a[i][1]+b[j][1]);
        }
    }
    for(r=list;r!=NULL;r=r->link){
        if(r->xiang!=0){
        printf("%d %d ",r->xiang,r->mi);    
        }
    }
    while(list!=NULL){
        Nodeptr temp=list;
        list=list->link;
        free(temp);
    }
    return 0;
}