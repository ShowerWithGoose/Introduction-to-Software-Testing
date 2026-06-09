#include<stdio.h>
#include<string.h>

int main(){
	FILE *in=NULL;
	in=fopen("article.txt","r");
	
	int i,j=0,k=0,cnt[10086]={0},all;
	char line[81]="",str[10086][20],ch[20];
	memset(str,0,sizeof(str));
	memset(cnt,0,sizeof(cnt));
	
	if(in==NULL) return 1;
	while(fgets(line,81,in)!=NULL){//将文件内信息转录到line中  
		for(i=0;i<strlen(line);i++){
			if(line[i]>='a'&&line[i]<='z'){
				str[j][k++]=line[i];
			}
			else if(line[i]>='A'&&line[i]<='Z'){
				str[j][k++]=line[i]+('a'-'A');
			}
			else{
				j=j+1;
				k=0;
			}
		}
		//memset(line,0,sizeof(line));
	}
	
	all=j+1;
	for(i=0;i<all-1;i++){
		for(j=0;j<all-1;j++){
			if(strcmp(str[j],str[j+1])>0){
				strcpy(ch,str[j+1]);
				strcpy(str[j+1],str[j]);
				strcpy(str[j],ch);
			}
		}
		//memset(ch,0,sizeof(ch));
	}
	
	for(i=0;i<all;i++){
		cnt[i]+=1;
		if(strcmp(str[i],str[i+1])==0){
			str[i][0]='\0';
			cnt[i+1]=cnt[i]+cnt[i+1];
		}
	}
	
	for(i=0;i<all;i++){
		if(str[i][0]!='\0')
			printf("%s %d\n",str[i],cnt[i]);
	}
	fclose(in);
	
	return 0;
}

