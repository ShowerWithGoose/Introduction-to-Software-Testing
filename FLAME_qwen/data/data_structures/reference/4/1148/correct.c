#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
FILE *in, *out;
struct word{
    char w[20];
    int cnt;
}d[10000];
char s[100000];
int main(){
    int l,m,n,i,j,k=0;
    struct word temp;
    in=fopen("article.txt","r");
    while(fgets(s,10000,in)!=NULL){
        l=strlen(s);
        for(i=0;i<l;i++){
            if(s[i]>='A'&&s[i]<='Z'){
                s[i]=s[i]-'A'+'a';
            }
        }
        for(i=0;i<l;i++){
            m=i;
            while('a'<=s[i]&&s[i]<='z'){
                i++;
            }
            if(m!=i){
                for(j=m;j<i;j++){
                    d[k].w[j-m]=s[j];
                }
                d[k].cnt=1;
                k++;
            }
        }
    }
    for(i=0;i<k;i++){//排序
        for(j=0;j<k-1;j++){
            if(strcmp(d[j].w,d[j+1].w)>0){
                temp=d[j];
                d[j]=d[j+1];
                d[j+1]=temp;
            }
        }
    }
    for(i=0;i<k-1;i++){
        m=i;
        while(strcmp(d[i].w,d[i+1].w)==0){
            d[i+1].cnt=0;
            d[m].cnt++;
            i++;
        }
    }
    for(i=0;i<k;i++){
        if(d[i].cnt==0){
            for(j=i;j<k-1;j++){
                d[j]=d[j+1];
            }
            i--;//!!!!!!!!错了第二遍了！！！！！！
            k--;
        }
    }
    for(i=0;i<k;i++){
        printf("%s %d\n",d[i].w,d[i].cnt);

    }
    return 0;
}
