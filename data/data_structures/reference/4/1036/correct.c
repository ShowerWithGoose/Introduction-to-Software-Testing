#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
struct node
{
    char w2[30];
    int count;
}x[1025],y;
char tolow(char);
int main()
{
    FILE *in;
    in=fopen("article.txt","r");

    char s[1025];
    int i=0,j=0,k=0,flag=0,m;
    while(fgets(s,1025,in)!=NULL){
        for(k=0;k<strlen(s);k++){
        if((s[k]>64&&s[k]<91)||(s[k]>96&&s[k]<123)){
            x[i].w2[j++]=tolow(s[k]);
            flag=1;
        }
        else if(flag){
            x[i].w2[j]='\0';
            x[i++].count=1;
            j=0;
            flag=0;
        }
        }
    }
    m=i;
    for(i=0;i<m;i++){
        for(j=i+1;j<m;j++){
            if(strcmp(x[i].w2,x[j].w2)==0){
                x[i].count++;
                x[j].w2[0]='\0';
            }
            else if(strcmp(x[i].w2,x[j].w2)>0){
                y=x[i];
                x[i]=x[j];
                x[j]=y;
            }
        }
    }
    for(i=0;i<m;i++){
        if(x[i].w2[0]!='\0'){
            printf("%s %d\n",x[i].w2,x[i].count);
        }
    }
    fclose(in);
    return 0;
}
char tolow(char z)
{
    if(z<97)
    {
        return (z+32);
    }
    else return z;
}

