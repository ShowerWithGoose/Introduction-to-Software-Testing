#include <stdio.h>
#include <string.h>
#define len 100
int main()
{
    int i, j = 0;
    int flag = 0;
    char a[len], b[len], c[len];
    int d[len];
    gets(a);
    for (i = 0; i < strlen(a) - 1; i++)
    {
        if ((a[i] != ' ') && (a[i] != '='))
            b[j++] = a[i];
        if (a[i] == '*' || a[i] == '/' || a[i] == '+' || a[i] == '-')
        {
            flag = 1;
        }
    }
    b[j] = '\0';
    if (flag == 0)
    {
        puts(b);
    }
    else
    {
        int p = 0;
        int e = 0;
        int v = strlen(b);
        b[v] = '+'; // @@ The array b is declared with size len (100). If the input expression fills the buffer, writing to b[v] (where v is the length of the string currently in b) writes to the null terminator or potentially out of bounds if j reached len-1. More critically, this modifies the string b by appending a '+', which is used as a sentinel. However, the loop condition `w <= v` will process this added '+'. This logic is fragile but might work if buffer allows. The real issue is likely below.
        int temp;
        for (int w = 0; w <= v; w++)
        {
            if (b[w] >= '0' && b[w] <= '9')
            {
                e = e * 10 + (b[w] - '0');
                temp = e;
            }
            else
            {
                d[p] = temp, c[p] = b[w]; // @@ When an operator is encountered, the current number `temp` is stored in `d[p]` and the operator in `c[p]`. Then `p` is incremented. This means `d[0]` holds the first number, `c[0]` holds the first operator, `d[1]` holds the second number, etc.
                printf("%d", d[p]); // @@ This debug print outputs the value of d[p] AFTER p has been incremented? No, comma operator evaluates left to right, so d[p] is assigned, then c[p] is assigned, THEN printf uses d[p]. But p hasn't been incremented yet in this statement. Wait, `d[p]=temp, c[p]=b[w]` assigns to index p. Then `printf` prints `d[p]`. Then `p++` happens. So it prints the number just stored. This output interferes with the expected output format "Output the integer result to the console". The problem requires ONLY the final result. This line causes Wrong Answer because it prints intermediate numbers.
                p++;
                e = 0;
            }
        }
        c[p] = '\0';
        char cr7;
        for (int g = 0; g < p - 1; g++)
        {
            if (c[g] == '*' || c[g] == '/')
            {
                if (c[g - 1] == '+') // @@ Accessing c[g-1] when g=0 is out of bounds (undefined behavior). Although there is a check `if (g==0)` later, this line executes BEFORE that check if the structure was if/else if, but here they are separate ifs. If g=0, c[-1] is accessed. This is a crash risk or logical error.
                    cr7 = '+';
                if (c[g - 1] == '-') // @@ Same out of bounds access for g=0.
                    cr7 = '-';
                if (g == 0)
                    cr7 = '+';
                if (c[g] == '*')
                {
                    d[g + 1] *= d[g];
                    d[g] = 0;
                    c[g] = cr7;
                }
                if (c[g] == '/')
                {
                    d[g + 1] = (d[g] / d[g + 1]);
                    d[g] = 0;
                    c[g] = cr7;
                }
            }
        }
        for (int s = 0; s < p - 1; s++)
        {
            if (c[s] == '+')
                d[0] += d[s + 1];
            if (c[s] == '-')
                d[0] -= d[s + 1];
        }
        printf("%d", d[0]);
    }
    return 0;
}