#include<stdio.h>
int main()
{
    int z;
    int arr[105][5]={0},a[105]={0};
    scanf("%d",&z);
    for(int i=0;i<z;i++)
    {
        for(int j=1;j<5;j++)
        scanf("%d",&arr[i][j]); @@ [The loop starts from j=1, so arr[i][0] remains unused and uninitialized. This causes the first coordinate (x1) to be stored in arr[i][1], y1 in arr[i][2], x2 in arr[i][3], y2 in arr[i][4]. While this indexing works if used consistently, it's error-prone and leads to confusion later. However, the real bug is elsewhere.]
    }
    for(int i=0;i<z;i++)
    {
        int m,n,p=1;
        m=arr[i][3],n=arr[i][4]; @@ [This sets (m,n) to the ENDPOINT (x2,y2) of segment i, which is correct for chaining forward.]
        for(int d=0;d<z;d++) @@ [This outer loop runs 'z' times, attempting to extend the chain up to z segments. However, it doesn't prevent revisiting the same segment multiple times in one chain, which violates the problem constraints (no reuse of segments). But the bigger issue is the inner loop logic.]
        {
            for(int j=0;j<z;j++) @@ [This inner loop scans all segments every time, but it doesn't skip the starting segment or already-used segments, potentially causing infinite loops or overcounting. However, due to the break, it may not be infinite, but it can still count incorrectly.]
            {
                    if(m==arr[j][1]&&n==arr[j][2]) @@ [This checks if current endpoint (m,n) matches the START of segment j (x1,y1 = arr[j][1], arr[j][2]). This is correct for chaining.]
                    {
                        p++;
                        m=arr[j][3],n=arr[j][4]; @@ [Update (m,n) to the new endpoint. Correct.]
                        break; @@ [Break after finding one match. This assumes only one segment starts at (m,n), which is valid per constraint #2 (no three share an endpoint, and no intersections), so at most one continuation exists. So this is acceptable.]
                    }
            }
        }
        a[i]=p;
    }
    for(int i=0;i<z;i++)
    printf("%d ",a[i]); @@ [This debug print is not in the expected output format and will cause wrong answer because the problem does NOT ask for this line. However, the test case shows the buggy output includes "2 1" and then "0 12 12", suggesting this print is part of the output. The problem requires ONLY one line: "<max_segments> <start_x> <start_y>". This extra print is a critical error.]
    printf("\n"); @@ [This adds an extra newline and numbers before the actual answer, making the output invalid.]
    int f=a[0],c=0;
    for(int i=0;i<z;i++)
    {
        if(a[i]>f)
        {
            f=a[i];
            c=i;
        }
    }
    printf("%d %d %d",c,arr[c][1],arr[c][2]); @@ [This prints 'c' (the index of the best starting segment) instead of 'f' (the maximum number of segments). The expected output should start with the count 'f', not the index 'c'. Also, the starting point is correctly taken as (arr[c][1], arr[c][2]), which is (x1,y1). But printing 'c' instead of 'f' is a critical error. For the test case, c=0 (since both chains have length 2, and a[0]=2, a[1]=1? Wait, let's simulate: For i=0: start at (12,12)-(13,13), then find segment starting at (13,13) -> segment 1, so p=2. For i=1: start at (13,13)-(50,76), then look for segment starting at (50,76) -> none, so p=1. So a[0]=2, a[1]=1. Then f=2, c=0. Then this prints "0 12 12", but should print "2 12 12". So the error is printing 'c' (0) instead of 'f' (2).]
    return 0;
}