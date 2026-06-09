int n,a[10],j[10]={0};
void ARG (int index,int a[]);
int main()
{
    scanf("%d",&n);
    ARG(1,a);
    return 0;
}
void ARG (int index,int a[])
{
    int i;
    if(index>n)
    {
        for(i=1;i<=n;i++)
            printf("%d ",a[i]);
        printf("\n");
        return;
    }
    for(i=1;i<=n;i++)
    {
        if(!j[i])
        {
            a[index]=i;
            j[i]=1;
            ARG(index+1,a);
            j[i]=0;
        }
    }
    return 0;
}



