#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct list {
	char s[50];
	int count;
	struct list *next;
};
int is_alpha(char a){
	if((a>='a'&&a<='z')||(a>='A'&&a<='Z'))return 1;
	else return 0;
} 
int main(){
	int middle,len,flag;
	int i,j,k;
	char s[401],sub_s[50];
	struct list *first=NULL,*p,*q,*o;
	FILE *in;
	in=fopen("article.txt","r");
	while(fgets(s,400,in)!=NULL){
		len=strlen(s);
		for(i=0;i<len;i++){
			if(is_alpha(s[i])==0){
				continue;
			}
			else{
				k=0;
				for(j=i;is_alpha(s[j])==1;j++){
					sub_s[k++]=(s[j]>='a')?s[j]:s[j]+'a'-'A';
				}
				sub_s[k]='\0';
				//printf("%s\n",sub_s);
				flag=1;
				for(o=first;o!=NULL;o=o->next){
					if(strcmp(o->s,sub_s)==0){
						flag=0;
						break;
					}
				}
				if(flag==1){
					q=(struct list*)malloc(sizeof(struct list));
				    q->next=NULL;
				    strcpy(q->s,sub_s);
				    q->count=1;
				    if(first==NULL){
				      	first=p=q;
			     	}
				    else{
					    p->next=q;
					    p=p->next;
				    }
				}
				else{
					o->count++;
				}
				i=j-1;
			}
		}
	}
	
	/*for(p=first;p!=NULL;p=p->next){
		printf("%s %d\n",p->s,p->count);
	} */
	
	/*for(p=first;p->next!=NULL;p=p->next){
		for(q=p;q->next!=NULL;q=q->next){
			while(strcmp(p->s,q->next->s)==0){
				o=q->next;
				q->next=q->next->next;
				free(o);
				p->count++;
				if(q==NULL)break;
			}
			if(q==NULL)break;
		}
	}*/ //É¾È¥ÖØ¸´µÄ 
	
	/*for(p=first;p!=NULL;p=p->next){
		printf("%s %d\n",p->s,p->count);
	} */
	
	for(p=first;p!=NULL;p=p->next){
		for(q=first;q!=p;q=q->next){
			if(strcmp(q->s,p->s)>0){
				strcpy(s,p->s);
				strcpy(p->s,q->s);
				strcpy(q->s,s);
				middle=p->count;
				p->count=q->count;
				q->count=middle;
			}
        }
	}
	
	for(p=first;p!=NULL;p=p->next){
		printf("%s %d\n",p->s,p->count);
	} 
	fclose(in);
	return 0;
}

