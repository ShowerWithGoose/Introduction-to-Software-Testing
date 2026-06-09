#include<stdio.h>
#include<stdlib.h>
#define isletter(c) (((c)<='z'&&(c)>='a')||((c)<='Z'&&(c)>='A'))
#define lower(c) (((c)<='Z'&&(c)>='A')?((c)-'A'+'a'):(c))
struct node{
    char word[31];
    int frequency;
    struct node*next;
};
int main(){
    freopen("./article.txt","r",stdin);
    char arti[501];
    int i,j,check;
    struct node end={"\0",0,NULL},*p,*q=&end,*newnode,*tem;
    while(fgets(arti,501,stdin)!=NULL){
        j&=0;
        while(1){
            while(arti[j]!='\0'&&!isletter(arti[j]))j++;
            if(arti[j]=='\0')break;
            p=q;check=1;tem=NULL;
            while(p->next!=NULL){
                i&=0;
                while(p->word[i]!='\0'&&isletter(arti[j+i])&&p->word[i]==lower(arti[j+i]))i++;
                if(!isletter(arti[j+i]))arti[j+i]='\0';
                check=lower(arti[j+i])-p->word[i];
                if(check==0){
                    p->frequency++;
                    break;
                }
                else if(check<0)break;
                tem=p;
                p=p->next;
            }
            if(check){
                newnode=(struct node*)malloc(sizeof(struct node));
                i&=0;
                while(isletter(arti[j+i])){
                    newnode->word[i]=lower(arti[j+i]);
                    i++;
                }
                newnode->word[i]='\0';
                newnode->frequency=1;
                newnode->next=p;
                if(tem==NULL)q=newnode;
                else tem->next=newnode;
            }
            j=j+i+1;
        }
    }
    p=q;
    while(p->next!=NULL){
        printf("%s %d\n",p->word,p->frequency);
        p=p->next;
    }
    return 0;
}


