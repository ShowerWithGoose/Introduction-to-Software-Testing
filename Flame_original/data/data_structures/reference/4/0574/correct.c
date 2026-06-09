#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
struct dcb
{
    char wd[50];
    int tm;
};
char zh(char a)
{
    a=a-'A'+'a';
    return a;
}
int iszm(char a)
{
    if(a>='a'&&a<='z'){
        return 1;
    }
    if(a>='A'&&a<='Z'){
        return 1;
    }
    return 0;
}
int main()
{
    freopen("article.txt","r",stdin);
    char a[500],dc[50]={0};
    struct dcb dic[500];
    int i,j,k,m,n=0,flag;
    while(gets(a)!=NULL){
        int l=strlen(a),i,j,k,m;
        a[l]=' ';
        for(i=0,j=0;i<=l;i++){
            if(a[i]>='a'&&a[i]<='z'){
                dc[j]=a[i];
                j++;
            }
            else if(a[i]>='A'&&a[i]<='Z'){
                dc[j]=zh(a[i]);
                j++;
            }
            else if(iszm(a[i])==0&&iszm(a[i-1])==1){
                for(k=0,flag=1;k<n;k++){
                    if(strcmp(dc,dic[k].wd)==0){
                        flag=0;
                        dic[k].tm++;
                        break;
                    }
                }
                if(flag==1){
                    strcpy(dic[n].wd,dc);
                    dic[n].tm=1;
                    n++;
                }
                memset(dc,0,sizeof(dc));
                j=0;
            }
        }
    }
    int hold;
    char shold[50];
    for(i=0;i<n;i++){
        for(j=i;j<n;j++){
            if(strcmp(dic[i].wd,dic[j].wd)>0){
                hold=dic[i].tm;
                dic[i].tm=dic[j].tm;
                dic[j].tm=hold;
                strcpy(shold,dic[i].wd);
                strcpy(dic[i].wd,dic[j].wd);
                strcpy(dic[j].wd,shold);
            }
        }
    }
    for(i=0;i<n;i++){
        printf("%s %d\n",dic[i].wd,dic[i].tm);
    }
    return 0;
}



