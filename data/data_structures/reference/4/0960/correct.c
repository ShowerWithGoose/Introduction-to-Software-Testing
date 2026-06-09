#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
char a[10005];

struct alp{
	char s[10];
	int num;

}p[100005];


int cmpfuc(const void* a, const void* b)
{
    struct alp* c = (struct alp*)a; 
    struct alp* d = (struct alp*)b;
    return strcmp(c->s, d->s);          //对单词字典序排序
}




int main(){
	FILE *in=fopen("article.txt","r");
	int flag=0;
	int num=1;
	char c;
	int cnt=0;
	int i=0,j=0,k=0,de=0;

 //读入 
while((c=fgetc(in))!=EOF){
	if(isupper(c)){
		c=tolower(c);
	}
		a[cnt++]=c;
	}
 //保留字母 
for(k=0;k<cnt;k++){
	
	if(isalpha(a[k])){
		p[i].s[j]=(a[k]);
		j++;
		flag=1;
	}
	else if(flag==1){
		p[i].s[j]='\0';
		p[i].num=1;
		i++;
		j=0;
		flag=0;
	}
		
}
 //去重 
for(k=0;k<i;k++){
	for(j=k+1;j<i;){
		if(strcmp(p[k].s,p[j].s)==0){
			p[k].num++;
			for(de=j;de<i;de++){
				p[de]=p[de+1];
			}
		  i--;continue;
		}
		j++;
	}
}
		
	

 //排序 
 qsort(p,i, sizeof(p[0]), cmpfuc);
 //输出 
for(k=0;k<i-1;k++){
	printf("%s %d\n",p[k].s,p[k].num);
} printf("%s %d",p[k].s,p[k].num);
fclose(in);
return 0;}
		


