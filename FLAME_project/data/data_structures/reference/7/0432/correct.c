#include<stdio.h>
#include<math.h>
tree[2000];
l[2000];
struct lf
{
    int x;
    int level;
};
struct lf leaf[100],hold;
int main()
{

    int i,j,k,n,a,p,t=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        {
            scanf("%d",&a);
            p=1;
            if(i==0) {tree[1]=a;
            l[1]=1;}
            else
            {
                for(;;)
                {
                    if(a<tree[p])
                    {
                        if(l[p*2]==0)
                            {tree[p*2]=a;
                            l[p*2]=1;
                            break;}
                        else if(l[p*2]!=0)
                            {p*=2;}

                    }
                    else
                    {
                        if(l[p*2+1]==0)
                            {tree[p*2+1]=a;
                            l[p*2+1]=1;
                            break;}
                        else if(l[p*2+1]!=0)
                            {p=p*2+1; }
                    }
                }
            }
        }
            //    k=pow(2,k);
                //printf("%d",k);
                for(i=1;i<=2000;i++)
                {
                   // printf("%d %d\n",i,tree[i]);
                    if(l[i]!=0&&l[2*i]==0&&l[2*i+1]==0)
                    {
                        leaf[t].x=tree[i];
                        leaf[t].level=0;
                        for(j=1;j<=i;j*=2)
                        {
                            leaf[t].level++;
                        }
                        t++;
                    }
                }
                for(i=0;i<t;i++)
    {
       // printf("%d %d\n",leaf[i].x,leaf[i].level);
    }
    n=t;
    for(i=0;i<n-1;i++)
    {
      for(j=0;j<n-1-i;j++)
        if(leaf[j].x>leaf[j+1].x)
        {
            hold=leaf[j];
            leaf[j]=leaf[j+1];
            leaf[j+1]=hold;
        }
    }
    for(i=0;i<t;i++)
    {
       // if(leaf[i].x!=0)
        printf("%d %d\n",leaf[i].x,leaf[i].level);
    }





        }

