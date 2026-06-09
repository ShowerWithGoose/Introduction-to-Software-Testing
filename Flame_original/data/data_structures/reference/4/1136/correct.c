#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct word{
	char w[30];
	int n;
	struct word *next;
};
typedef struct word *Wordptr;
typedef struct word Word;

Word *head = NULL;

int getWord(FILE *bfp,char s[])
{
	int i = 0;
	char c;
	
	while((c = fgetc(bfp)) != EOF)
	{
		if(isalpha(c))
		{
			s[i] = tolower(c);
			i++;
		}
		else if(i > 0)
		{
			s[i] = '\0';
			return 0;
		}
	}
	return EOF;
}

int insertWord(Word *p,char *s)
{
	Word *q;
	
	q = (Word *)malloc(sizeof(Word));
    if(q == NULL)
	return -1; 
    strcpy(q -> w, s);
    q -> n = 1;
    q -> next = NULL;
    if(head == NULL) 
    head = q;
    else if (p == NULL)
	{ 
        q -> next = head;
        head = q;
    }
    else
	{
        q -> next = p -> next;
        p -> next = q;
    }
    return 0;
}

int searchWord(char *s)
{
    Word *p,*q = NULL;
    for(p = head;p != NULL;q = p,p = p -> next)
	{
        if(strcmp(s,p -> w) < 0)
        break;
        else if(strcmp(s,p -> w) == 0)
		{
            p -> n++;
            return 0 ;
        }
    }
    return insertWord(q,s);
}

int main()
{
	int flag = 0;
	char s[30];
	Word *p = NULL,*q = NULL,*r;
	FILE *in;
	in = fopen("article.txt","r");
	head = NULL;
	
	while(getWord(in,s) != EOF)
	{
		if(searchWord(s) == -1)
		{
			fprintf(stderr, "Memory is full!\n");
            return -1;
		}
	}
	
	for(p = head;p != NULL;p = p -> next)
	printf("%s %d\n",p -> w,p -> n);
	
	fclose(in);
	return 0;
}

