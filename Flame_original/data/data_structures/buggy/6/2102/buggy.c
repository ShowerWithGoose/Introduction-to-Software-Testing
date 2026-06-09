#define MAXSIZE 100
# include <stdio.h> 
typedef int ElemType;
ElemType STACK[MAXSIZE];
int  Top=-1;

void  Error(char s[])
{
        printf("%s", s);
        //exit( -1);
}
void  push( ElemType s[ ], ElemType item )
{
    if( Top==MAXSIZE-1 )
        printf("error");
		//Error("error");
    else
		s[++Top]=item;     
}

ElemType pop( ElemType s[ ])
{
    if(Top==-1)
        printf("error");
		//Error("error");
    else 		
		{
			//printf("%d",s[Top]);
			return s[Top--];
		}     
}

int main()
{
	int a;
	scanf("%d",&a);
	while(a!=-1)
	{
		//printf("%d",a);
		if(a!=1)
		{
			if(a!=0)
			{
				push(STACK,a);
			}
			else
			{
				printf("%d",pop(STACK));
				printf("  ");
			}
		}
	scanf("%d",&a);
	}
	
	return 0;
}
