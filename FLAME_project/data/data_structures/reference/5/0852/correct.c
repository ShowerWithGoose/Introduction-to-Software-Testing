#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

#define MAX(a,b) ((a)?(b)? (a): (b))
#define MIN(a,b) ((a)?(b)? (a): (b))
#define pi acos(-1)
#define eps 1e-8
#define ULL unsigned long long
#define LL long long
struct link{
	LL coefficient;
	LL index;
	struct link *next;
};
	struct link result[1000];
int main(){
	char s[6666]={'\0'};
	gets(s);
	int l=strlen(s);
	LL i,j,k,flag,count1,count2;	
	struct link *first1=NULL,*p,*q;
	for(i=0,j=0,k=1,flag=1,count1=0;i<=l;i++){
		if(flag==1){//coefficient
			if(s[i]!=' '&&s[i]!='\0'){
				j++;
				k*=10;
			}
			else{
				k/=10;
				q = (struct link *)malloc(sizeof(struct link));
				q->coefficient=0;
				q->next=NULL;
				for(;j>0;j--){
					q->coefficient+=k*(s[i-j]-'0');
					if(k!=1)
					k/=10;
				}
				flag=2;
			}			
		}
		else if(flag==2){//index
			if(s[i]!=' '&&s[i]!='\0'){
				j++;
				k*=10;
			}
			else{
				k/=10;
				q->index=0;
				for(;j>0;j--){
					q->index+=k*(s[i-j]-'0');
					if(k!=1)
					k/=10;
				}
				flag=1;
				if(first1==NULL)
				first1=p=q;
				else{
					p->next=q;
					p=p->next;
				}
				count1++;
			}			
		}
	}
	gets(s);
	l=strlen(s);
	struct link *first2=NULL;
	for(i=0,j=0,k=1,flag=1,count2=0;i<=l;i++){
		if(flag==1){//coefficient
			if(s[i]!=' '&&s[i]!='\0'){
				j++;
				k*=10;
			}
			else{
				k/=10;
				q = (struct link *)malloc(sizeof(struct link));
				q->coefficient=0;
				q->next=NULL;
				for(;j>0;j--){
					q->coefficient+=k*(s[i-j]-'0');
					if(k!=1)
					k/=10;
				}
				flag=2;
			}			
		}
		else if(flag==2){//index
			if(s[i]!=' '&&s[i]!='\0'){
				j++;
				k*=10;
			}
			else{
				k/=10;
				q->index=0;
				for(;j>0;j--){
					q->index+=k*(s[i-j]-'0');
					if(k!=1)
					k/=10;
				}
				flag=1;
				if(first2==NULL)
				first2=p=q;
				else{
					p->next=q;
					p=p->next;
				}
				count2++;
			}			
		}
	}	
	struct link *l1,*l2;
	l1=first1;
	l2=first2;
int f;
result[0].index=l1->index+l2->index;
result[0].coefficient=0;
	
		for(i=0,k=1;i<count1;i++){
			for(int m=0;m<count2;m++){
				for(j=0;j<k;j++){
					if(l1->index+l2->index==result[j].index){
                        result[j].coefficient+=l1->coefficient*l2->coefficient;
                        f=1;
						break;
					}
				}
                if(f==1){
                f=0;
                l2=l2->next;
                continue;
                }
                result[k].coefficient=l1->coefficient*l2->coefficient;
				result[k].index=l1->index+l2->index;
				k++;
				l2=l2->next;				
			}
			l2=first2;
			l1=l1->next;
		}	
LL t;
for(i=0;i<k;i++){
   for(j=i+1;j<k;j++){
      if(result[i].index<result[j].index){
        t=result[i].index;
        result[i].index=result[j].index;
        result[j].index=t;
        t=result[i].coefficient;
        result[i].coefficient=result[j].coefficient;
        result[j].coefficient=t;
      }
   }
}
	for(i=0;i<k;i++){
		if(result[i].coefficient!=0)
		printf("%lld %lld ",result[i].coefficient,result[i].index);
	}
}

