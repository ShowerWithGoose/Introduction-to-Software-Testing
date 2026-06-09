#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

typedef struct Word {
	char s[20];
	int count;
	struct Word* next;
} Word,*PWord;

PWord Add(PWord p0,char str[]) {
	if(p0==NULL) {
		PWord location=(PWord)malloc(sizeof(Word));
		strcpy(location->s,str);
		location->count=1;
		location->next=NULL;
		return location;
	} else {
		PWord location=p0;
		if(strcmp(location->s,str)>0) {
			PWord q=(PWord)malloc(sizeof(Word));
			strcpy(q->s,str);
			q->count=1;
			q->next=location;
			return q;
		} else {
			while(location->next!=NULL&&strcmp(location->next->s,str)<=0) {//p1 <= s < p1->next
				location=location->next;
			}
			if(strcmp(location->s,str)==0) {
				location->count++;
			} else if(location->next==NULL) {
				PWord q=(PWord)malloc(sizeof(Word));
				location->next=q;
				strcpy(q->s,str);
				q->count=1;
				q->next=NULL;
			} else {
				PWord q=(PWord)malloc(sizeof(Word));
				q->next=location->next;
				location->next=q;
				strcpy(q->s,str);
				q->count=1;
			}
			return p0;
		}
	}
}

PWord Read(FILE* fp,PWord p0) {
	PWord location=p0;
	char c;
	char str[20]= "";
	int i=0;
	c=fgetc(fp);

	while(c!=EOF) {
			if(isalpha(c)) {
				str[i++]=tolower(c);
			} else {
				str[i]='\0';
				if(strlen(str)!=0) {
					location=Add(location,str);
					str[0]='\0';
					i=0;
				}
			}
		c=fgetc(fp);
	}
	return location;
}

int main() {
	FILE *IN=fopen("article.txt","r");
	PWord start=NULL,location=NULL;
	if(IN==NULL) {
		perror("Can't find the file!");
	}
	start=Read(IN,start);
	for(location=start; location!=NULL; location=location->next) {
		printf("%s %d\n",location->s,location->count);
	}
	return 0;
}

