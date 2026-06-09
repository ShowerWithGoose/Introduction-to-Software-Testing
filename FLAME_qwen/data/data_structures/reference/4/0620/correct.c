#include  <string.h>
#include  <stdio.h>
#include<ctype.h>
typedef struct stat{
char word[100];
int num;
};
int pro(char*ch,struct stat*a,int count){//如何将一个字符串中的单词全部提取出来？
char aa[10][100]={{'\0'}};
int j=0,k=0;
for(int i=0;i<strlen(ch);i++){
    if(ch[i]>='A'&&ch[i]<='Z')
        ch[i]+='a'-'A';
}
for(int i=0;i<strlen(ch);i++){
    while(isalpha(ch[i])!=0){
    aa[j][k]=ch[i];
    i++,k++;
    }
    if(isalpha(ch[i-1])!=0)
        j++,k=0;
}
for(int i=0;i<j;i++){
    count=judge(a,aa[i],count);
    count++;
}
return count;
}


int judge(struct stat*a,char*ch,int count){
for(int i=0;i<count;i++){
    if(strncmp(ch,a[i].word,strlen(ch)>=strlen(a[i].word)?strlen(ch):strlen(a[i].word))==0){
        a[i].num++;
        return count-1;
    }
}
strcpy(a[count].word,ch);
a[count].num++;
return count;
}

void line(struct stat*a,int count){//按字母表排序
for(int i=0;i<count-1;i++){
    for(int j=i+1;j<count;j++){
        if(strcmp(a[i].word,a[j].word)>0){
            struct stat temp=a[j];
            a[j]=a[i];
            a[i]=temp;
        }
    }
}
}
int main(){
FILE* in=fopen("article.txt","r");
struct stat a[100];
for(int i=0;i<100;i++){
    a[i].num=0;
}
char ch[100];
int count=0;
while(fscanf(in,"%s",&ch)!=EOF){
count=pro(ch,a,count);
}//完成输入

line(a,count);
for(int i=0;i<count;i++){
    printf("%s %d\n",a[i].word,a[i].num);
}



return 0;
}








