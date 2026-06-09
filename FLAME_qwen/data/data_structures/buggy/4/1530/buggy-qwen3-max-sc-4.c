#include<stdio.h>
#include<stdbool.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>
#include<time.h>
#include<ctype.h>
#include<stdlib.h>
#define MAX 40
#define tolower(c) ((c)<='Z'&&(c)>='A' ? (c)-'A'+'a' : (c))
char str[MAX];
typedef struct line{
    int times;
    struct line* next;
    char word[MAX];
}*p;
p head=NULL;
int alpha(char c){
    if((c>='a'&&c<='z')||(c>='A'&&c<='Z'))
    return 1;
    else
    return 0;
}
int get_word(FILE *in,char *w){
    char c;
    while((c=(fgetc(in)))){ // @@ [The loop condition treats EOF (typically -1) as true, causing infinite loop or undefined behavior. fgetc returns int, not char, so c should be int to correctly detect EOF.]
        if(c==EOF)
        return c;
        else{
            if(!alpha(c))
                continue;
            else
                break;
        }
        
    }
    *w++=tolower(c);
    while((c=(fgetc(in)))!=EOF){ // @@ [Same issue: c is declared as char, but fgetc returns int. When char is unsigned, EOF (-1) becomes 255 and never equals EOF, causing incorrect loop termination.]
        if(alpha(c)){
            *w++=tolower(c);
        }
        else
        break;
    }
    *w='\0';
    return 1;
}
int insert(char*w,p l,p r){
    p temp;
    temp=(p)malloc(sizeof(struct line));
    if(temp==NULL)
    return -1;
    temp->times=1;
    strcpy(temp->word,w);
    temp->next=NULL;
    if(head==NULL){
        head=temp;
    }
    else if(l==NULL){
        temp->next=r;
        r=temp; // @@ [This assignment only changes local variable r, not the global head or any node's next pointer, so the new node is not properly linked into the list when inserting at the beginning.]
    }
    else{
        temp->next=r;
        l->next=temp;
    }

   return 0;
}
int search(char*w){
    p l=NULL,r=NULL;
    for(r=head;r!=NULL;l=r,r=r->next){
        if(strcmp(r->word,w)==0){
            r->times+=1;
            return 0;
        }
        else if(strcmp(r->word,w)>0){
            break;
        }
        else
        continue;
    }
    return(insert(w,l,r));
}
int main(void)
{
    FILE *in;
    in=fopen("article.txt","r");
    while(get_word(in,str)!=EOF){
        search(str);
//        if(search(str)==-1)break;
    }
    for(p point=head;point!=NULL;point=point->next){
        printf("%s %d\n",point->word,point->times);
    }
    fclose(in);
return 0;
}