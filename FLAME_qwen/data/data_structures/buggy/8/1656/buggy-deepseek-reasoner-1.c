#include<stdio.h> // @@ Missing proper implementation of graph traversal and deletion.
#include<string.h> // @@ Unnecessary header, but not an error.
#include<stdlib.h> // @@ Unnecessary header, but not an error.
#include<math.h> // @@ Unnecessary header, but not an error.
int main()
{
    int point,side;
    scanf("%d%d",&point,&side); // @@ Does not read the deletion vertex at the end.
    printf("%d %d\n",point,side); // @@ Prints input instead of traversal output; wrong.
    int i,j,k;
    
    for(k=0;k<side;k++) // @@ Loop correctly reads edges, but does not store them.
    {
        scanf("%d%d",&i,&j); // @@ Reads edge endpoints.
        printf("%d %d\n",i,j); // @@ Prints edge data instead of processing; wrong.
    }
    
    return 0; // @@ Missing DFS/BFS traversal and output.
 }