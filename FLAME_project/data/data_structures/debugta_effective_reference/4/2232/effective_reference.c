#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define LL long long
#define DB double
#define FOR(X,Y,Z)  for(int X = Y;X<Z;X++) 
struct word{
    char ch[30];
    int t;
} list[100];
char buffer[1000];
char tmp[100];
int num = 0;
int cmp(const void*list,const void *b){
    struct word p1 = *(struct word*) list;
    struct word p2 = *(struct word*) b;
    return strcmp(p1.ch,p2.ch);
}
int main(){
    freopen("article.txt","r",stdin);
    int i = 0;
    int sig = -1;
    while(~(buffer[i] =  getchar())){
            if(isupper(buffer[i])) buffer[i]+='a'-'A';
            if(islower(buffer[i])&&sig == -1)
                sig = i;
            if(!islower(buffer[i])&&sig!=-1){
                int p = 0;
                for(int j = sig;j < i;j++){
                    tmp[p++] = buffer[j];
                }
                tmp[p] = '\0';
                sig = -1;
                int flag = -1;
                for(int j = 0;j < num;j++){
                    if(strcmp(list[j].ch,tmp)==0)
                    flag = j;
                }
                if(flag == -1){
                strcpy(list[num].ch,tmp);
                list[num++].t = 1;
                }
                else
                list[flag].t++;
            }
            i++;
        }      
    
    qsort(list,num,sizeof(list[0]),cmp);
    for(int j = 0;j < num;j++)
    printf("%s %d\n",list[j].ch,list[j].t);
    return 0;
}



