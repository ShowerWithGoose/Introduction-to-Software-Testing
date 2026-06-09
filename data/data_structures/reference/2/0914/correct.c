#include <stdio.h>
#include <string.h>
char in[1000];
int issgn(int n)
{
	if(in[n]>='0'&&in[n]<='9')
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
int valsgn(int n)
{
	switch (in[n])
		{
			case '+':
		    	return 1;
			case '-':
		    	return 2;
			case '*':
			    return 3;
			case '/':
			    return 4;
			case '=':
				return 5;
			default:
				return 0;
		}
}
int main()
{
	struct cell{
		int val;
		int typ;
		int pos;
	};
	struct cell all[1000];
	int n=0,m=0,s=0,l=0,t=0,c=0;
	gets(in);
	l=strlen(in);
	while(n<l)
	{
		if(in[n]==' ')
		{
			m=n;
			while(m<l)
			{
				in[m]=in[m+1];
				m++;
			}
			n=-1;
		}
		n++;
	}
	n=0;
	m=1;
	l=strlen(in);
	while(n<l)
	{
		if(issgn(n)==1)
		{
			all[m].val=valsgn(n);
			all[m].typ=1;
			all[m].pos=n;
			m=m+2;
		}
		n++;
	}
	m=m-2;
	n=0;
	s=0;
	while(s<m)
	{
		while(n<all[s+1].pos)
    	{
	    	t=t+in[n]-'0';
    		t=t*10;
      		n++;
    	}
    	t=t/10;
    	all[s].val=t;
    	all[s].typ=0;
    	all[s].pos=n-1;
    	s=s+2;
    	n=n+1;
    	t=0;
	}
	all[m+1].val=0;
    all[m+1].typ=-1;
    all[m+1].pos=0;
    all[m+2].val=0;
    all[m+2].typ=-1;
    all[m+2].pos=0;
    restart:
	n=0;
	c=0;
	while(all[n].typ!=-1)
	{
		if(all[n].typ==1&&(all[n].val==3||all[n].val==4))
		{
			if(all[n].val==3)
			{
				all[n-1].val=all[n+1].val*all[n-1].val;
				s=n;
				while(all[s].typ!=-1)
				{
					all[s]=all[s+2];
					s++;
				}
				c=1;
			}
			else if(all[n].val==4)
			{
				all[n-1].val=all[n-1].val/all[n+1].val;
				s=n;
				while(all[s].typ!=-1)
				{
					all[s]=all[s+2];
					s++;
				}
				c=1;
			}
			n=0;
		}
		n++;
	}
	if(c==1)
	{
		goto restart;
	}
	restart2:
	n=0;
	c=0;
	while(all[n].typ!=-1)
	{
		if(all[n].typ==1&&(all[n].val==1||all[n].val==2))
		{
			if(all[n].val==1)
			{
				all[n-1].val=all[n+1].val+all[n-1].val;
				s=n;
				while(all[s].typ!=-1)
				{
					all[s]=all[s+2];
					s++;
				}
				c=1;
			}
			else if(all[n].val==2)
			{
				all[n-1].val=all[n-1].val-all[n+1].val;
				s=n;
				while(all[s].typ!=-1)
				{
					all[s]=all[s+2];
					s++;
				}
				c=1;
			}
			n=0;
		}
		n++;
	}
	if(c==1)
	{
		goto restart2;
	}
	printf("%d",all[0].val);
	return 0;
}

