#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
int main()
   {int i,j,n,s,k=0;
    int x1[105],y1[105],x2[105],y2[105];
	int x,y;
	int maxlen=0,len;
	scanf("%d",&n);
	for (i=0;i<n;i++)
	    scanf("%d %d %d %d",&x1[i],&y1[i],&x2[i],&y2[i]);
    for (i=0;i<n;i++)
	   {for (j=0;j<n-1;j++)
	       {if (x1[j]>x1[j+1])
		       {s=x1[j];
				x1[j]=x1[j+1];
				x1[j+1]=s;
				s=y1[j];
				y1[j]=y1[j+1];
				y1[j+1]=s;
				s=x2[j];
				x2[j]=x2[j+1];
				x2[j+1]=s;
				s=y2[j];
				y2[j]=y2[j+1];
				y2[j+1]=s;
			   }
		   }
	   }
	for (i=0;i<n;i++)
	   {for (j=i+1;j<=n;j++)
	       {if (x1[i]==x1[j])
			   {if (y1[i]>y1[j])
			       {s=y1[j];
				    y1[j]=y1[i];
				    y1[i]=s;
				    s=x2[j];
				    x2[j]=x2[i];
				    x2[i]=s;
				    s=y2[j];
				    y2[j]=y2[i];
				    y2[i]=s;
				   }
			   }
	   	   }
	   }
	for (i=0;i<n;i++)
	   {len=0; 
		k=i;
		for (j=0;j<n;j++)
		   {if(x2[k]==x1[j]&&y2[k]==y1[j])
		       {len++;
			    k=j;
		       }
		   }
		if (len>maxlen)
		   {maxlen=len;
			x=x1[i];
			y=y1[i];
		   }
	   } 
	printf("%d %d %d",maxlen+1,x,y);
    return 0;
   }

