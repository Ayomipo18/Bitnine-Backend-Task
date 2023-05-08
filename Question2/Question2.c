#include <stdio.h>
#include <stdlib.h>

int recursion(int n);
int iteration(int n);
int memo_recursion(int n, int *memo);

int main() {
    int num;
    int *memo = NULL;

    printf("Enter a Number: \n");

    scanf("%d", &num);

    printf("Number you entered: %d \n", num);
    
    int recursive_approach = recursion(num);
    printf("Answer for recursive approach is: %d \n", recursive_approach);

    int iterative_approach = iteration(num);
    printf("Answer for Iterative approach is: %d \n", iterative_approach);

    int memoized_approach = memo_recursion(num, memo);
    printf("Answer for Memoized approach is: %d \n", memoized_approach);

    free(memo);

    system("pause");
    return 0;
}

/*
This approach uses recursive calls to solve the problem.

Advantages:
Readability: Recursive solutions often closely resemble the problem's formulation, 
making the code more intuitive and easier to understand.

Disadvantages:
Inefficiency: For large values of n, recursive calls can create a large number of stack frames, 
consuming memory and potentially causing the program to run slowly.

Time Complexity: O(2^n)
Space Complexity: O(n)
where n is the input value of the function
*/
int recursion(int n) {
    if(n == 0) return 0;
    if(n == 1) return 1;
    if(n == 2) return 2;
    else {
        return recursion(n-2) + recursion(n-3);
    }
}

/*
This approach uses a loop to iteratively calculate the solution.

Advantages:
Efficiency: The iterative approach avoids creating multiple stack frames for recursive calls, 
resulting in faster and more memory-efficient code.

Disadvantages:
Limited access to previous values: Since the iterative approach only uses a loop, 
it can only access values up to n-3.

Time Complexity: O(n)
Space Complexity: O(1)
where n is the input value of the function
*/
int iteration(int n) {
    int first_num = 0, second_num = 1, third_num = 2, result;

    if (n == first_num) return first_num;
    if (n == second_num) return second_num;
    if (n == third_num) return third_num;

    for(int i = 3; i <= n; i++) {
        result = second_num + first_num;
        first_num = second_num;
        second_num = third_num;
        third_num = result;
    }

    return result;
}

/*
This method uses memoization to improve the efficiency of the recursive approach.

Advantages:
1)Efficiency: Memoization stores previously calculated values in an array (memo) to avoid redundant calculations, 
significantly improving performance.

2)Memory efficiency: Memoization reduces the number of function calls and eliminates redundant computation, 
making it more memory-efficient than the basic recursive approach.

Disadvantages:
Overhead: Memoization introduces some overhead due to array access and checking.

Time Complexity: O(n)
Space Complexity: O(n)
where n is the input value of the function
*/
int memo_recursion(int n, int *memo){
    int result;

    if (memo == NULL) {
        memo = (int*) calloc(n + 1, sizeof(int));
        memo[0] = 0;
        memo[1] = 1;
        memo[2] = 2;
    }
    
    if (n < 3) return memo[n];
    else if(memo[n] != 0) return memo[n];
    else {
        result = memo_recursion(n-2, memo) + memo_recursion(n-3, memo);
        memo[n] = result;
    }
    
    return result;
}