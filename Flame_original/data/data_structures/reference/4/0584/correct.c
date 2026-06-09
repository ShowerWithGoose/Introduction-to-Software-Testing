#include<stdio.h>
#include<string.h>
#include<ctype.h>

struct word{
	char s[100];
	int n;
	int flag;
}word[200];


int main(){
	
	FILE *fp;
	fp=fopen("article.txt","r");
	if(fp==NULL){
		perror("can't open filein");
		return 1;
	}
	
	char c;
	int i=0,j=0,n;
	
	for(i=0;i<200;i++){
	   word[i].n=1;	
	   word[i].flag=0;
	}
	i=0;
	char str[100];
	c=fgetc(fp);
	while(c!=EOF){
		if(isalpha(c)){
		    word[i].s[0]=c;
		    j=1;
		    c=fgetc(fp);
		    while(isalpha(c)){
		    	word[i].s[j]=c;
		    	j++;
		    	c=fgetc(fp);
			}
		    i++;
		}
		j=0;
		c=fgetc(fp);
	}
	n=i-1;
	int len;
	for(i=0;i<=n;i++){
		len=strlen(word[i].s);
		for(j=0;j<len;j++){
			if(word[i].s[j]>='A'&&word[i].s[j]<='Z')
			word[i].s[j]=tolower(word[i].s[j]);
			else if(isalpha(word[i].s[j])==0){
				word[i].s[j]='\0';
			}
		}
	}

	char nametemp[100];
	for(i=0;i<n;i++){
		for(j=0;j<n-i;j++){
			if(strcmp(word[j].s,word[j+1].s)>0){
				strcpy(nametemp,word[j].s);
				strcpy(word[j].s,word[j+1].s);
			    strcpy(word[j+1].s,nametemp);
			}
		}
	}

	for(i=0;i<=n;i++){
		for(j=i+1;j<=n;j++){
			if(strcmp(word[i].s,word[j].s)==0&&word[i].flag==0){
				word[i].n++;
				word[j].flag=1;
			}
		}
	}
	for(i=0;i<=n;i++){
		if(word[i].flag==0&&i!=n)
	    printf("%s %d\n",word[i].s,word[i].n);
		if(word[i].flag==0&&i==n)	
		printf("%s %d",word[i].s,word[i].n);	
	}

} 

