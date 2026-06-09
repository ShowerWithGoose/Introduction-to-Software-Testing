#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct Word{
    char word[100];
    int times; 
    struct Word *link;       
}Link;
void smallize(char *a){
    int len=strlen(a);
    for(int i=0;i<len;i++){
        if(a[i]<='Z'&&a[i]>='A')
            a[i]=a[i]-'A'+'a';
    }
    
}
void insert(Link *p,Link *q){
    Link *r=p->link;
    p->link=q;
    q->link=r;
}   
Link *comp(char *a,Link *head){
    
    Link *p=head;
    Link *q=NULL;
    while(p!=NULL){
        if(strlen(p->word)==0){
            break;
        }
        if(strcmp(p->word,a)>=0){
            break;
        }
        q=p;
        p=p->link;
    }
    if(p!=NULL&&strlen(p->word)==0)
    {
        strcpy(p->word,a);
        p->times=1;
    }
    else if(p==head&&strcmp(p->word,a)>0){
        Link *r=(Link*)malloc(sizeof(Link));
        strcpy(r->word,a);
        r->times=1;
        r->link=head;
        head=r;
    }
    else if(p==NULL){
        Link *r=(Link*)malloc(sizeof(Link));
        strcpy(r->word,a);
        r->times=1;
        r->link=NULL;
        q->link=r;
        
    }
    else if(strcmp(p->word,a)==0){
        p->times++;
    }
    
    else{
        Link *r=(Link*)malloc(sizeof(Link));
        strcpy(r->word,a);
        r->times=1;
        insert(q,r);
    }
    return head;
}
int main(){
    Link *head;
    head=(Link*)malloc(sizeof(Link));
    strcpy(head->word,"\0");
    head->link=NULL;
    FILE *fp,*fp2;
    if((fp=fopen("article.txt","r"))==NULL)
        return 1;
    char str[10000];
    
    while(fgets(str,10000,fp)){
        
        
        smallize(str);
        int len=strlen(str);
   
        //printf("%s",str);

        char word[100];
        for(int i=0,j=0;i<=len;i++){            
            if(str[i]<='z'&&str[i]>='a'){
                word[j++]=str[i];
            }
            else{
                word[j]='\0';
                if(j!=0){
                    //printf("%s",word);
                    head=comp(word,head);
                }
                strcpy(word,"\0");
                j=0;
            }
        }
        if(feof(fp))
            break;        
    }
    Link *p=head;
    while(p!=NULL&&strlen(p->word)!=0)
    {
        printf("%s %d\n",p->word,p->times);
        p=p->link;
    }
    fclose(fp);
    return 0;
}
