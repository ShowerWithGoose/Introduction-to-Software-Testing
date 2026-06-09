#include<stdio.h>
int tr[2000]={10000};
void visit(int a,int k);
int main()
{
    int n,a,i,key=1;
    for(i=0;i<2000;i++)
        tr[i]=10000;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        {
            key=1;
            scanf("%d",&a);
            if(i==0)
                tr[1]=a;
            else
                {
                    while(1)
                        {
                            if(tr[key]==10000)
                                {
                                    tr[key]=a;
                                    break;
                                }
                            if(a<tr[key])
                                {
                                    key*=2;
                                }
                            else
                                {
                                    key=key*2+1;
                                }
                            if(tr[key]==10000)
                                {
                                    tr[key]=a;
                                    break;
                                }
                        }
                }
        }
    visit(1,1);
    return 0;
}
void visit(int a,int k)
{
    if(tr[a]==10000)
        return ;
    if(tr[2*a]==10000&&tr[2*a+1]==10000)
        {
            printf("%d %d\n",tr[a],k);
        }
    visit(a*2,k+1);
    visit(a*2+1,k+1);
}
