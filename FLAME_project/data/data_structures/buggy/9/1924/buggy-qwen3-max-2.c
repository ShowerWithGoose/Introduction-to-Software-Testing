#include<stdio.h>
int main()
{
    printf("10 1 1\n"); // @@ This hardcoded output does not process the input at all. The program should read the number of line segments and their coordinates, then compute the longest continuous line segment by connecting segments that share endpoints. Instead, it always prints "10 1 1", which is incorrect for the given test case (expected: "2 12 12").
    return 0;
}