#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct word{
	char word[100];
	int cnt;
}word[1000],tmp;
int main(){
	freopen("article.txt","r",stdin);
	char line[1024];
	int i,j;
	int cnt=0;
	int k=0;
	int flag=0;
	while(gets(line)!=NULL){
		for(i=0;line[i]!='\0';i++)
	     if(line[i]>='A'&&line[i]<='Z')
	     line[i]+=32;
		for(i=0;line[i]!='\0';i++){
			if(line[i]>='a'&&line[i]<='z'){
				word[k].word[cnt]=line[i];
				cnt++;
				flag=1;
			}
			else if(flag==1){
				k++;
				cnt=0;
				flag=0; 
			}
		}
		if(flag==1){
			k++;
			cnt=0;
			flag=0;
		}
	}
	for(i=0;i<k;i++){
		for(j=i+1;j<k;j++){
			if(strcmp(word[i].word ,word[j].word)>0){
				tmp=word[i];
				word[i]=word[j];
				word[j]=tmp;
			}
		}
	}
	/*for(i=0;i<50;i++){
		printf("%s\n",word[i].word);
	}*/
	int sum=0;
	int a[10000]={0};
	for(i=0;i<k;i++){
		j=i;
		if(a[i]!=1){
		while(strcmp(word[j].word,word[j+1].word)==0){
			a[j+1]=1;
			j++;
			sum++;
		}
		word[i].cnt=sum;
		}
		sum=0;
	}
	for(i=0;i<k;i++){
		if(a[i]!=1)
		printf("%s %d\n",word[i].word,word[i].cnt+1);
	}
	return 0;
} 



