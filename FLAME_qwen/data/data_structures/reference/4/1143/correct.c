#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define lower(a) (a>='A'&&a<='Z')?a-'A'+'a':a

typedef struct{
    char word[100];
    int time;
}Node;
FILE *in,*out;
int len;

int Comp(const void *,const void *);

int main(int argc, char *argv[]){
    int i,n=0,flag=0,j,k=0;
    char tp[100],tp2[100],line[1000];
    Node list[1000];
    in=fopen("article.txt","r");
    while(fgets(line,1000,in)!=NULL){
        for(i=0,k=0;line[k]!=NULL;k++){
            if((line[k]>='a'&&line[k]<='z')||(line[k]>='A'&&line[k]<='Z')){
                tp2[i]=line[k];
                i++;
                len++;
            }
            else if((tp2[0]>='a'&&tp2[0]<='z')||(tp2[0]>='A'&&tp2[0]<='Z')){
                for(i=0;i<len;i++)tp2[i]=(lower(tp2[i]));
                for(i=0,j=0;i<len;i++){
                    if(tp2[i]>='a'&&tp2[i]<='z'){
                        tp[j]=tp2[i];
                        j++;
                    }
                }
                for(i=0;i<n;i++,flag=0){
                    if(strstr(list[i].word,tp)){
                        list[i].time++;
                        flag=1;
                        break;
                    }
                }
                if(flag==0&&len!=0){
                    strcpy(list[n].word,tp);
                    list[n].time++;
                    n++;
                }
                memset(tp,0,sizeof(tp));
                memset(tp2,0,sizeof(tp2));
                i=0;
                len=0;
            }
        }
    }
    qsort(list,n,sizeof(list[0]),Comp);
    for(i=0;i<n;i++){
        printf("%s %d\n",list[i].word,list[i].time);
    }
    return 0;
}

int Comp(const void *p,const void *q){
    return strcmp(p,q);
}





