#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
struct wan{
   char w[50];
   int num;
}v[500];

int main()
{
FILE *in;
in = fopen("article.txt","r");

char ch;
int i=0,j=0;
ch=fgetc(in);
while(ch!=EOF){

if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')){
    v[i].w[j]=ch;
    j++;
}
else{
    v[i].w[j]='\0';
    i++;
    j=0;

}
ch=fgetc(in);
}//读入文本中所有词汇
int s;
s=i;
i=0;
j=0;
for(i=0;i<s;i++){
    for(j=0;j<strlen(v[i].w);j++){
        if(v[i].w[j]>='A'&&v[i].w[j]<='Z')
            v[i].w[j]=tolower(v[i].w[j]);
    }
}//大小写转换
char tmp[50];
for(int k=0;k<s;k++){
    for(int m=k+1;m<s;m++){
        if(strcmp(v[k].w,v[m].w)>0){
            strcpy(tmp,v[k].w);
            strcpy(v[k].w,v[m].w);
            strcpy(v[m].w,tmp);
        }
    }
}//确立字典顺序

int a;
for(int n=0;n<s;n++){

a=0;
v[n].num=1;
   for(int r=n+1;r<s;r++){
      if(strcmp(v[n].w,v[r].w)==0){
        v[n].num=v[n].num+1;
        v[r].w[0]='\0';
        a=1;
      }
      if(v[r].w[0]=='\0')
        continue;

      else{
        if(a==1)
            n=r-1;
        break;

      }}
}


for(i=0;i<s;i++){
   if(v[i].w[0]!='\0')
        printf("%s %d\n",v[i].w,v[i].num);


}


fclose(in);
return 0;
}




