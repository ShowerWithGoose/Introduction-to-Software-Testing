#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
typedef struct node {
	int xishu;
	int zhishu;
	struct node* next;
} DXshi;
DXshi *first[1000],*second[1000],*third,*temp,*p;
int main() {
	int i=0,j;
	int last1,last2,count=0;
	char str1[1000],str2[1000];
	int fi=0,si=0;
	int shuzu[100],forshuzu=0;
	gets(str1);
	int tempa;
	for(i=0; str1[i]!='\0'; i++) { //scan string
		tempa=0;
		if(str1[i]<'0'||str1[i]>'9') continue;//skip character
		while(isdigit(str1[i])) { //compute number
			tempa=tempa*10+str1[i]-'0';
			i++;
		}
		i--;
		shuzu[forshuzu]=tempa;//store number
		forshuzu++;
	}
	for(int i=0; i<forshuzu; i+=2) { //skip to add
		first[fi]=(DXshi *)malloc(sizeof(DXshi));
		first[fi]->xishu=shuzu[i];
		first[fi]->zhishu=shuzu[i+1];
		if(fi!=0)
			first[fi-1]->next=first[fi];
		fi++;
	}
	first[fi-1]->next=NULL;
	last1=fi;
	gets(str2);
	int shu[1000],forshu=0;
	for(i=0; str2[i]!='\0'; i++) { //scan string
		tempa=0;
		if(str2[i]<'0'||str2[i]>'9') continue;//skip character
		while(isdigit(str2[i])) { //compute number
			tempa=tempa*10+str2[i]-'0';
			i++;
		}
		shu[forshu]=tempa;
		forshu++;
		i--;
	}
	for(int i=0; i<forshu; i+=2) {
		second[si]=(DXshi *)malloc(sizeof(DXshi));
		second[si]->xishu=shu[i];
		second[si]->zhishu=shu[i+1];
		if(si!=0)
			second[si-1]->next=second[si];
		si++;
	}
	second[si-1]->next=NULL;
	last2=si;
	for(i=0; i<last1; i++) {
		for(j=0; j<last2; j++) {
			temp=(DXshi *)malloc(sizeof(DXshi));
			temp->xishu=first[i]->xishu*second[j]->xishu;
			temp->zhishu=first[i]->zhishu+second[j]->zhishu;
			temp->next=NULL;
			if(count==0) { //head node
				third=temp;
				third->next=NULL;
				count++;
			} else { //other node
			DXshi *r;
				p=r=third;
				while(p!=NULL&&p->zhishu>temp->zhishu) {
					r=p;
					p=p->next;
				}//find position
				if(p==NULL) {
					r->next=temp;//insert
				} else {
					if(temp->zhishu==p->zhishu) {
						p->xishu+=temp->xishu;
					}//merge
					else {
						r->next=temp;
						temp->next=p;
					}//insert
				}

			}
		}
	}
	while(third!=NULL) {
		if(third->xishu!=0) {
			printf("%d %d ",third->xishu,third->zhishu);
			third=third->next;
		}
	}
	for(int i=0; i<last1; i++) {
		free(first[i]);
	}
	for(int j=0; j<last2; j++) {
		free(second[j]);
	}
	return 0;
}



