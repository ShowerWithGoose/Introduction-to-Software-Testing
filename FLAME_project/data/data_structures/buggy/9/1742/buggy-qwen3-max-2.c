#include<stdio.h>
int main()
{
    int z;
    int arr[105][5]={0},a[105]={0};
    scanf("%d",&z);
    for(int i=0;i<z;i++)
    {
        for(int j=1;j<5;j++)
        scanf("%d",&arr[i][j]); // @@ [Reading starts from index 1, leaving arr[i][0] unused; this causes misalignment in coordinate storage: (x1,y1,x2,y2) stored in [1]-[4], but later logic assumes correct indexing]
    }
    for(int i=0;i<z;i++)
    {
        int m,n,p=1;
        m=arr[i][3],n=arr[i][4]; // @@ [m and n are set to the endpoint (x2,y2) of segment i, which is correct for chaining forward]
        for(int d=0;d<z;d++)
        {
            for(int j=0;j<z;j++)
            {
                    if(m==arr[j][1]&&n==arr[j][2]) // @@ [This checks if current endpoint matches start of another segment; however, the double loop may revisit segments and overcount due to lack of visited tracking, but more critically, the outer loop runs 'z' times regardless of actual chain length, leading to potential infinite-like counting if cycles existed—but constraints prevent cycles. However, the real issue is that it doesn't simulate a true DFS and may count same segment multiple times across iterations, but in this specific test case, it actually works. The bigger error is elsewhere.]
                    {
                        p++;
                        m=arr[j][3],n=arr[j][4];
                        break;
                    }
            }
        }
        a[i]=p;
    }
    for(int i=0;i<z;i++)
    printf("%d ",a[i]); // @@ [Debug print not in problem spec; but not causing WA. However, the real critical error is in final output line.]
    printf("\n");
    int f=a[0],c=0;
    for(int i=0;i<z;i++)
    {
        if(a[i]>f)
        {
            f=a[i];
            c=i;
        }
    }
    printf("%d %d %d",c,arr[c][1],arr[c][2]); // @@ [Prints 'c' (the index of the starting segment) instead of 'f' (the maximum number of segments). According to expected output, should print "2 12 12", but this prints "0 12 12" because c=0 and f=2. The first number must be f, not c.]
    return 0;
}