#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
int main(){
	char a[100][20];
	FILE *fp;
    fp = fopen("article.txt", "r");
    char ch,temp;
    int i=0,j=0;
    ch=fgetc(fp);
    while(ch!=EOF){
    	if(isalpha(ch)){
    		ch=tolower(ch);
			a[i][j]=ch;
    		j++; 
		}
		else if(ispunct(ch) || isspace(ch)){
			a[i][j]='\0';
			j=0;
			i++;
		}
		ch=fgetc(fp);
	}
	int n=i;
	for(i=0;i<n;i++){
		take(a,n);//二维数组的正确排序； 
	}
	int flag;
	int num[100]={0};
	for(i=0;i<n;i++){
		flag=0;
		num[i]=1;
		for(j=i+1;j<n;j++){
			if(strcmp(a[i],a[j])==0){
				num[i]++;
				a[j][0]='\0';
				flag=1;
			}
			if(a[j][0]=='\0'){
				continue;
			}
			else{
				if(flag==1){
					i=j-1;
				}
				break;
			}
		}
	}
	for(i=0;i<n;i++){
		if(a[i][0]=='\0');
		else printf("%s %d\n",a[i],num[i]);
	}
	fclose(fp);
	return 0;
	
} 
void take(char a[][20],int n){
	char temp[20];
	int i,j;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(strcmp(a[i],a[j])>0){
				strcpy(temp,a[j]);
				strcpy(a[j],a[i]);
				strcpy(a[i],temp);
			}
		}
	}
}

