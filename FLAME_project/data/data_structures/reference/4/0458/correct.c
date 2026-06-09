#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>
struct group{
	char s[10];
	int n;
}word[1000],temp;
int main(){
	FILE *in;
	in = fopen("article.txt","r");
	char art[10000];
	int i = 0;
	int sum = 0;
	while(fgets(art,1000,in)!=NULL){
		//puts(art);
		getchar();
		int j = 0;
		int k = 0;
		//	printf("here");
		while(art[j]!='\0'){
			if(isalpha(art[j])!=0){
				word[i].s[k++] = tolower(art[j]);
				word[i].n = 1;
			}
			if(isalpha(art[j])==0){
				i++;
			//	j++;
				sum++;
				//printf("%d ",sum);
				k = 0;
			}
			j++;
//			if(art[j] == '\0'){
//				continue;
//			}
		}
		}
		
	for(int j = 0;j<sum-1;j++){
		for(int k = 0;k<sum-j-1;k++){
			if(strcmp(word[k].s,word[k+1].s)>0){
				temp = word[k];
				word[k] = word[k+1];
				word[k+1] = temp;
			}
		}
	}
	for(int j = 0;j<sum-1;j++){
		if(strcmp(word[j].s,word[j+1].s) == 0){
			word[j].n++;
			for(int k = j+1;k<sum;k++){
				word[k] = word[k+1];
			}
			sum--;
			j--;
		}
	}
	//printf("%d",sum);
	for(int j = 1;j<sum;j++){
		printf("%s %d\n",word[j].s,word[j].n);
	}
	
	return 0;
}

