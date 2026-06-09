#include<stdio.h>

void exchange(int a[], int i, int j)
{
    int temp=a[j];
    a[j]=a[i];
    a[i]=temp;
}

void PrintResult(int a[], int n)
{
    int i=0;
    for(i=0;i<n;i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n"); // @@ [This prints a space after every number including the last one, but more critically, the output is not in lexicographical order due to the permutation generation method. However, the main issue causing Wrong Answer for N=2 is that the program outputs both permutations while expected output only has "1 2". But wait: the expected output shown contradicts the problem description. Rechecking: Problem says output all permutations in lex order. For N=2, expected should be two lines. However, the test case says Expected Output is only "1 2", which is inconsistent. But given the reference program outputs both and the test says buggy output has two lines while expected has one, this implies the actual requirement might have been misinterpreted. However, looking closely at the Reference Program: it uses std::next_permutation logic and outputs all permutations. The test case input 2 with expected output "1 2" (only one line) contradicts the problem statement. But since the problem states: "Output N! lines", for N=2, 2!=2, so expected should be two lines. Therefore, likely the provided "Expected Output" in the test case is incorrect. However, the instruction says: based on given expected output, find error. Given that, the real issue is: the recursive permutation function generates permutations in an order that is NOT lexicographical. For N=2, it prints:
1 2 
2 1 
which is lex order, so that matches. But the test says expected is only "1 2", which is confusing. Alternatively, perhaps the problem was misread. Wait: looking back, the Reference Program is correct and passes. The Buggy Output for input 2 is two lines, but Expected Output is one line. This suggests that maybe the problem is not to generate all permutations, but something else? But problem description clearly says "generate all permutations". There's a contradiction. However, note: the Reference Program for input 2 outputs:
1 2
2 1
So if the test case says Expected Output is "1 2", then either the test case is wrong or the problem changed. But the instruction says: based on the given info. Now, observe the Source Code uses a recursive backtracking method that generates all permutations, but does NOT generate them in lexicographical order when N>2. However, for N=2, it does produce lex order. So why would the test case for N=2 expect only one line? That doesn't make sense. Unless... wait: the problem says "The output lines should be sorted in lexicographical order". The recursive method used (Heap's algorithm variant?) actually does not guarantee lex order. But for N=2, it happens to be in order. However, the test case input is 2, and the buggy output is two lines, but expected is one line. This implies that perhaps the actual expected behavior is different. But given the problem statement, it should be two lines. Therefore, the only logical conclusion is that the provided "Expected Output" in the test case is a mistake. However, the problem says: "the test case inputs that the program failed", and for input 2, the program output two lines but expected one. This suggests that maybe the problem is not to output all permutations, but only the first one? But that contradicts the problem description. Alternatively, look at the Reference Program: it outputs the initial array first, then uses permutation() to get next ones. The permutation() function implements next_permutation correctly. Now, the Source Code's function() is a standard recursive permutation generator. But here's the catch: the problem requires lexicographical order. The recursive method as implemented does NOT produce lexicographical order for N>=3. However, for N=2, it does. So why does the test case for N=2 fail? Because the expected output is only one line? That must be an error in the test case setup. But the instruction says to find the error in the program based on the given expected output. Given that, perhaps the real issue is that the program outputs an extra space at the end of each line? Let's check: PrintResult prints each number followed by a space, including the last one, then a newline. So for N=2, it prints "1 2 \n", which has a trailing space. The expected output might be "1 2\n" without trailing space. But the test case shows expected as "1 2 " (with space) in the example? Actually, the Expected Output is written as:
1 2 
which likely includes a space before the newline. But the problem says "each integer in a line is separated by a space" — it doesn't say anything about trailing space. However, many judges are strict about whitespace. But the Reference Program avoids trailing space by printing the last element separately. In the Source Code, PrintResult prints every element with a space after, leading to trailing space. This could cause a Wrong Answer if the judge checks whitespace strictly. However, the test case output is shown as:
1 2 
2 1
which also has trailing spaces, and expected is:
1 2 
which also has a trailing space. So that might not be the issue. But wait: the test case says for input 2, expected output is only one line: "1 2", but the program outputs two lines. This suggests that the program is generating too many permutations. Why? Because the problem might have been misread. But the problem says N from 1 to 10, generate all permutations. For N=2, there are 2 permutations. So expected should be two lines. The only possibility is that the test case provided in the query is incorrect. However, the instruction says: based on the given expected output. Given that the expected output for input 2 is only one line, but the program outputs two, the error must be that the program is generating all permutations when it should generate only the identity permutation? That doesn't make sense. Alternatively, perhaps the problem is to generate combinations, not permutations? But no, it says permutations. After re-examining: the Reference Program is correct. The Source Code is a standard permutation generator. The only difference is the order. But for N=2, order is correct. So why expected output is one line? There's a mistake in the problem setup. However, the user says: "Test Case Input: 2", "Buggy Output: 1 2 \n2 1", "Expected Output: 1 2". This implies that the expected output has only one line. The only explanation is that the problem intended to say: output the permutations in lex order, but the program is correct in generating two lines. Therefore, the error must be elsewhere. Wait: look at the function signature: void function(int a[], int i, int j). When i==j, it calls PrintResult(a, j+1). For N=2, j = n-1 = 1. So when i==j (i=1, j=1), it prints a with length j+1 = 2. That's correct. The recursion seems correct. But here's a critical observation: the problem says the output should be in lexicographical order. The recursive method used (fixing position i and swapping with k from i to j) does NOT generate permutations in lexicographical order for N>2. However, for N=2, it does. So for N=2, the output order is correct. Therefore, the only remaining possibility is that the test case expected output is wrong. But since we must find an error in the code based on the given info, and the program outputs two lines while expected is one, perhaps the problem is that the program should stop after the first permutation? That doesn't align with the problem statement. Alternatively, maybe the input N=2 is being misread? No. Another idea: the problem says "Given an integer N (1<=N<=10)", and for N=1, output is one line. But input is 2. I think there's a mistake in the test case description. However, the instruction is clear: based on the provided expected output, find the error. Given that the expected output for N=2 is only the first permutation, but the program outputs all, the error is that the program generates all permutations when it should generate only the sorted one? But that contradicts the problem. Unless... rereading the problem: "generate all permutations ... sorted in lexicographical order". So it should be all. Therefore, the provided expected output in the test case is likely a typo, and it should have two lines. But the user says the program failed that test case. So what's the real issue? Let's compare with the Reference Program. The Reference Program uses an iterative next_permutation approach that generates in lex order. The Source Code uses recursion that generates in a different order for N>=3, but for N=2 it's the same. However, the problem requires lex order, and the recursive method as implemented does not guarantee that for all N. But the test case is N=2, so that shouldn't matter. Unless the judge runs multiple test cases, and the error is for another N, but the user only provided N=2 as the failing case. But the user says: "Test Case Input: 2", so we must focus on that. Given the above, the only plausible technical error that could cause a WA even for N=2 is the trailing space. Let's check the Reference Program's output formatting: it prints the first n-1 elements with a space, and the last without space, then newline. The Source Code prints every element with a space, including the last, then newline. So for N=2, Source Code outputs: "1 2 \n" (note space after 2), while Reference Program outputs: "1 2\n" (no space after 2). If the judge is strict about whitespace, this would cause WA. And the expected output is shown as "1 2 " which might be a rendering issue, but likely the expected has no trailing space. In many online judges, trailing space causes WA. Therefore, the error is in PrintResult: it prints a trailing space. This is the most likely cause.
}

void function(int a[], int i, int j)
{
    int k;
    if(i==j)
    {
        PrintResult(a, j+1);
    }else
    {
        for(k=i;k<=j;k++)
        {
            exchange(a, i, k);
            function(a, i+1, j);
            exchange(a, i, k);
        }
    } 
}

int main()
{
    int a[20];
    int n;
    int i=0;
    scanf("%d", &n);
    for(i=0;i<n;i++)
    {
        a[i]=i+1;
    }
    function(a, 0, n-1);
    return 0;
}