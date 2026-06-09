int n,array[10],symbol[10]={0};
void ARG (int index,int array[]);
int main()
{
    scanf("%d",&n);
    ARG(1,array);
    return 0;
}
void ARG (int index,int array[])
{
    int i;
    if(index>n)
    {
        for(i=1;i<=n;i++)
            printf("%d ",array[i]);
        printf("\n");
        return;
    }
    for(i=1;i<=n;i++)
    {
        if(!symbol[i])
        {
            array[index]=i;
            symbol[i]=1;
            ARG(index+1,array);
            symbol[i]=0;
        }
    }
    return 0;
}



