#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
char word[666][666];
void sort(char word[][666],int n,int iii){
	char temp[666];
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(strcmp(word[i],word[j])>0){
				strcpy(temp, word[j]);
                strcpy(word[j], word[i]);
                strcpy(word[i], temp);
			}
		}
	}
}
int main(){
	int m=0,n=0,cnt[666]={0},x=0;
	char voc;
	FILE *in;
	in=fopen("article.txt","r");
	voc=fgetc(in);
	while(voc!=EOF){
		if(isalpha(voc)!=0){
			word[m][n]=voc;
			n++;
		}
		else if(isalpha(voc)==0){
			word[m][n]='\0';
			n=0;
			m++;
		}
		voc=fgetc(in);
	}
    for(int i=0;i<m;i++){
    	for(int j=0;j<strlen(word[i]);j++){
    		word[i][j]=tolower(word[i][j]);
		}
	}	
	for(int i=0;i<m;i++){
		sort(word,m,23);
	}
	for(int i=0;i<m;i++){
		cnt[i]=1;
		x=0;
		for(int j=i+1;j<m;j++){
			if(strcmp(word[i],word[j])==0){
				cnt[i]++;
				word[j][0]='\0';
				x=2;
			}
			if(word[j][0]=='\0')continue;
			else{
				if(x==2)i=j-1;
				break;
			}
		}
	}
	for(int i=0;i<m;i++){
		if(word[i][0]!='\0')
		printf("%s %d\n",word[i],cnt[i]);//cao ni ma lin bei zhen de hui niao chu lai!!!!!!
	}
	return 0;
}


