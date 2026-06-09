#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#define N 100050
#define max(a,b) (a>b?a:b)
#define min(a,b) (a>b?b:a)
#define ll long long
typedef struct{
    char word[100];
    int res;
}nod;
nod a[N];
char buf[100],word[100];
int cmp(void *a,void *b){
    nod *x=(nod*)a;
    nod *y=(nod*)b;
    return strcmp(x->word,y->word);
}
int cnt,k;
int main(){
    FILE *IN;
    IN = fopen("article.txt","r");
    char c;
    while((c=fgetc(IN))!=EOF){
      //  printf("%s\n",word);
        k=0;
        while(!isalpha(c)&&c!=EOF)c=fgetc(IN);
        if(c==EOF){
            break;
        }
        while(isalpha(c)){
            buf[k++]=tolower(c);
            c=fgetc(IN);
        }
        buf[k]='\0';
      //  printf("%s\n",buf);
        int flag=0;
        for(int i=1;i<=cnt;i++){
            if(strcmp(buf,a[i].word)==0){
                a[i].res++;flag=1;
            }
        }
      //  printf("1");
        if(!flag){
            cnt++;
            a[cnt].res=1;
            strcpy(a[cnt].word,buf);
        }
    }
    qsort(a+1,cnt,sizeof(a[0]),cmp);
   // printf("%s %d\n",a[1].word,a[1].res);
    for(int i=1;i<=cnt;i++)printf("%s %d\n",a[i].word,a[i].res);
    return 0;
}
