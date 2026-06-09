#include<stdio.h>
int main()
{
	int a[11],b[11],c[11],d[11],e[11],f[11],g[11],h[11],j[11],k[11],n,m=1,o,p,q=0,r=1,s=1,t=1,u=1,v=1,w=1,x=1,y=1;
	b[0]=1;
	a[0]=0;
	scanf("%d",&n);
	 for(int i=1;i<=10;i++)
	 {
	 	a[i]=i;
	 	c[i]=i;
	 	d[i]=i;
	 	e[i]=i;
	 	f[i]=i;
	 	g[i]=i;
	 	h[i]=i;
	 	j[i]=i;
	 	k[i]=i;
	 }
	 for(int i=1;i<=10;i++)
	 {
	 	b[i]=i*b[i-1];
	 	
	 }
	 
	 for(m=1,p=1,q=1;m<=b[n]*n;m++,p++,q++)
	{
	 	printf("%d ",a[q]);
	 	
		 if(p%n==0)
	 	{
	 		printf("\n");
			o=a[n-1];
	 		a[n-1]=a[n];
	 		a[n]=o;
	 		q=0; 
		}
		
		
		if(p%(b[2]*n)==0)
	 	{
	 		for(int i=1;i<=10;i++)
	 			{
	 				a[i]=c[i];
	 			}	
	 		for(int i=r;i>0;i--)
		 		{
		 			o=a[n-2+i];
		 			a[n-2+i]=a[n-3+i];
		 			a[n-3+i]=o;
		 		}
		 	r++;
	    }
	    
	    
	    if(p%(b[3]*n)==0)
	 	{
	 		for(int i=1;i<=10;i++)
	 			{
	 				c[i]=d[i];
	 			}	
	 		for(int i=s;i>0;i--)
		 		{
		 			o=c[n-3+i];
		 			c[n-3+i]=c[n-4+i];
		 			c[n-4+i]=o;
		 		}
		 		for(int i=1;i<=10;i++)
	 			{
	 				a[i]=c[i];
	 			}	
		 	r=1;
		 	s++;
	    }
	    
	    if(p%(b[4]*n)==0)
	 	{
	 		for(int i=1;i<=10;i++)
	 			{
	 				d[i]=e[i];
	 			}	
	 		for(int i=t;i>0;i--)
		 		{
		 			o=d[n-4+i];
		 			d[n-4+i]=d[n-5+i];
		 			d[n-5+i]=o;
		 		}
		 		for(int i=1;i<=10;i++)
	 			{
	 				c[i]=d[i];
	 				a[i]=c[i];
	 			}	
		 	s=1;
		 	t++;
	    }
	    
	    
	    if(p%(b[5]*n)==0)
	 	{
	 		for(int i=1;i<=10;i++)
	 			{
	 				e[i]=f[i];
	 			}	
	 		for(int i=u;i>0;i--)
		 		{
		 			o=e[n-5+i];
		 			e[n-5+i]=e[n-6+i];
		 			e[n-6+i]=o;
		 		}
		 		for(int i=1;i<=10;i++)
	 			{
	 				d[i]=e[i];
	 				c[i]=d[i];
	 				a[i]=c[i];
	 			}	
		 	t=1;
		 	u++;
	    }
	    
	    if(p%(b[6]*n)==0)
	 	{
	 		for(int i=1;i<=10;i++)
	 			{
	 				f[i]=g[i];
	 			}	
	 		for(int i=v;i>0;i--)
		 		{
		 			o=f[n-6+i];
		 			f[n-6+i]=f[n-7+i];
		 			f[n-7+i]=o;
		 		}
		 		for(int i=1;i<=10;i++)
	 			{
	 				e[i]=f[i];
	 				d[i]=e[i];
	 				c[i]=d[i];
	 				a[i]=c[i];
	 			}	
		 	u=1;
		 	v++;
	    }
	    
	    
	    if(p%(b[7]*n)==0)
	 	{
	 		for(int i=1;i<=10;i++)
	 			{
	 				g[i]=h[i];
	 			}	
	 		for(int i=w;i>0;i--)
		 		{
		 			o=g[n-7+i];
		 			g[n-7+i]=g[n-8+i];
		 			g[n-8+i]=o;
		 		}
		 		for(int i=1;i<=10;i++)
	 			{
	 				f[i]=g[i];
	 				e[i]=f[i];
	 				d[i]=e[i];
	 				c[i]=d[i];
	 				a[i]=c[i];
	 			}	
		 	v=1;
		 	w++;
	    }
	    if(p%(b[8]*n)==0)
	 	{
	 		for(int i=1;i<=10;i++)
	 			{
	 				h[i]=j[i];
	 			}	
	 		for(int i=x;i>0;i--)
		 		{
		 			o=h[n-8+i];
		 			h[n-8+i]=h[n-9+i];
		 			h[n-9+i]=o;
		 		}
		 		for(int i=1;i<=10;i++)
	 			{
	 				g[i]=h[i];
	 				f[i]=g[i];
	 				e[i]=f[i];
	 				d[i]=e[i];
	 				c[i]=d[i];
	 				a[i]=c[i];
	 			}	
		 	w=1;
		 	x++;
	    }
	    if(p%(b[9]*n)==0)
	 	{
	 		for(int i=1;i<=10;i++)
	 			{
	 				j[i]=k[i];
	 			}	
	 		for(int i=y;i>0;i--)
		 		{
		 			o=j[n-9+i];
		 			j[n-9+i]=j[n-10+i];
		 			j[n-10+i]=o;
		 		}
		 		for(int i=1;i<=10;i++)
	 			{
	 				h[i]=j[i];
	 				g[i]=h[i];
	 				f[i]=g[i];
	 				e[i]=f[i];
	 				d[i]=e[i];
	 				c[i]=d[i];
	 				a[i]=c[i];
	 			}	
		 	x=1;
		 	y++;
	    }
	}
	return 0;
}
//	printf("%d\n",p);
	
	
	
	
	
	
	
 

