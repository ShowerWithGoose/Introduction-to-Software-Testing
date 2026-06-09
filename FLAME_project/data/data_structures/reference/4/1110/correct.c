#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
typedef struct word{
    char s[200];
    int times;
}word;
int cnt=0;
word sum[200];
int find(char w[]){
    int i;
    if(cnt==0)return 0;
    for(i=0;i<cnt;i++){
        if(strcmp(w,sum[i].s)==0)return i;
    }
    return -1;
}
int rank(const void *p1,const void *p2){
    word *x=(word*)p1,*y=(word*)p2;
    return strcmp(x->s,y->s);
}
int main(){
    FILE *in;
    int i,j,k,p;
    char line[1024],w[30];
    memset(w,'\0',sizeof(w));
    in=fopen("article.txt","r");
    while(fgets(line,1023,in)!=NULL){
        for(i=0;line[i]!='\0';i++){
           if(isalpha(line[i])){
               for(j=i;isalpha(line[j]);j++){
                   w[j-i]=line[j];
               }
               for(k=0;w[k]!='\0';k++){
                   w[k]=tolower(w[k]);
               }
               i=j-1;
               p=find(w);
               if(p==0){
                   strcpy(sum[0].s,w);
                   sum[0].times++;
                   cnt++;
               }
               if(p>0){
                   sum[p].times++;
               }
               if(p==-1){
                   strcpy(sum[cnt].s,w);
                   sum[cnt].times++;
                   cnt++;
               }
               memset(w,'\0',sizeof(w));
           }
        }
    }
    qsort(sum,cnt,sizeof(sum[0]),rank);
    for(i=0;i<cnt;i++){
    	if(sum[i].times!=0){
    	   printf("%s %d\n",sum[i].s,sum[i].times);
           }
    }
    return 0;
}


