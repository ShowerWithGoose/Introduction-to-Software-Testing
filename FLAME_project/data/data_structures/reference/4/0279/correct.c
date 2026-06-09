#include<stdio.h>
#include<string.h>

typedef struct statistics{
	char ch[20];
	int num;
}statis,*pstatis;

int main()
{
	FILE *in;
	in=fopen("article.txt","r");
	statis word[500],temp;
	int i,j,k=0,l,m,n,p,q,s;
	char f1[500];
	while(fgets(f1,500,in)!=NULL){
		int len=strlen(f1);
		for(i=0,j=i,l=0;i<len;i++){
			if(f1[i]>='A' && f1[i]<='Z' && ((f1[i+1]>='a' && f1[i+1]<='z') || (f1[i+1]>='A' && f1[i+1]<='Z'))){
				f1[i]+=32;
			}
			else if((f1[i]>='A' && f1[i]<='Z') && (f1[i+1]<='A' || f1[i+1]>='z' || (f1[i+1]>='Z' && f1[i+1]<='a'))){
				f1[i]+=32;
				while(j<=i){
					word[k].ch[l++]=f1[j++];
				}
				word[k].ch[l]='\0';
				word[k].num=1;
				j=i+1;
				l=0;
				k++;				
			}
			else if(f1[i]>='a' && f1[i]<='z' && ((f1[i+1]>='A' && f1[i+1]<='Z')||(f1[i+1]>='a' && f1[i+1]<='z'))){
				continue;	
			}		
			else if((f1[i]>='a' && f1[i]<='z') && (f1[i+1]<='A' || f1[i+1]>='z' || (f1[i+1]>='Z' && f1[i+1]<='a'))){
				while(j<=i){
					word[k].ch[l++]=f1[j++];
				}
				word[k].ch[l]='\0';
				word[k].num=1;
				j=i+1;
				l=0;
				k++;				
			}	
			else{
				j=i+1;
			}
		}
	}//输入数据
	
	for(m=0;m<k;m++){
		for(n=m+1;n<k;n++){
			if(strcmp(word[m].ch,word[n].ch)==0){
				word[m].num++;
				for(l=n;l<k-1;l++){
					word[l]=word[l+1];
				}
				k--;
				n--;				
			}
		}
	}//词频统计 
	
	for(p=0;p<k-1;p++){
		for(q=0;q<k-p-1;q++){
			if(strcmp(word[q].ch,word[q+1].ch)>0){
				temp=word[q];
				word[q]=word[q+1];
				word[q+1]=temp;
			}
		}
	}//字典排序
	
	for(s=0;s<k-1;s++){
		printf("%s",word[s].ch);
		printf(" %d\n",word[s].num);
	}
	printf("%s",word[s].ch);
	printf(" %d",word[s].num); 
	
	return 0;
}

