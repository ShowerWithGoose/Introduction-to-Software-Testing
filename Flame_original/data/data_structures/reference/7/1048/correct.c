#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct tree
{
    int num;
    int level;
	struct tree *Left;
	struct tree *Right;	
} Tree;

void SearchLMR(Tree *);

int main()
{
	Tree *Root,*Ptr,*PtrNext;
	int n,i,temp,mark,level;
	scanf("%d",&n);
	for(i=1;i<=n;i=i+1)
	{
	    scanf("%d",&temp);
	    if(i==1)
	    {
		    Root=(Tree *)malloc(sizeof(Tree)); 
			Root->num=temp;
			Root->level=1;  
			Root->Left=NULL;
			Root->Right=NULL;	
	    }
	    else
	    {
	    	Ptr=Root;
	    	level=1;
	    	if(temp<Ptr->num)
	        {
			    PtrNext=Root->Left;
			    level=level+1;
			    mark=1; 
		    }
			else
			{
				PtrNext=Root->Right; 
				level=level+1;
				mark=2;
			}
			while(PtrNext!=NULL)
			{
				if(temp<PtrNext->num)
				{
					Ptr=PtrNext;
					PtrNext=Ptr->Left;
					level=level+1;
					mark=1;
				}
				else
				{
					Ptr=PtrNext;
					PtrNext=Ptr->Right;
					level=level+1;
					mark=2;
				}
			}
			PtrNext=(Tree *)malloc(sizeof(Tree));
			PtrNext->num=temp;
			PtrNext->level=level;
			PtrNext->Left=NULL;
			PtrNext->Right=NULL;
			if(mark==1) Ptr->Left=PtrNext;
			else if(mark==2) Ptr->Right=PtrNext;
		} 
	}
	SearchLMR(Root);
	return 0;
}

SearchLMR(Tree *Ptr)
{
	if(Ptr!=NULL)
	{
		SearchLMR(Ptr->Left);
		if(Ptr->Left==NULL&&Ptr->Right==NULL) printf("%d %d\n",Ptr->num,Ptr->level);
		SearchLMR(Ptr->Right);
	}
}

