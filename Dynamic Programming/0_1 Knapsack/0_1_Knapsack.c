// Implementation of 0/1 Knapsack using DP

#include<stdio.h>


// A utility function that returns maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}


// function for performing 0/1 Knapsack using Dynamic Programming
int knapSack(int W, int wt[], int prof[], int num)
{
   int K[num+1][W+1];

   // Build table K[][] in bottom up manner
   for (int i = 0; i <= num; i++) {
       for (int w = 0; w <= W; w++) {
           if (i==0 || w==0)
               K[i][w] = 0;
           else if (wt[i-1] <= w)
                 K[i][w] = max(prof[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
           else
                 K[i][w] = K[i-1][w];
       }
   }

   // stores the result of Knapsack
   int res = K[num][W];

   int w = W;

   printf("\n Weights included in Knapsack are : ");
   for (int i = num; i > 0 && res > 0; i--) {

       // either the result comes from the top (K[i-1][w]) or
       // from (val[i-1] + K[i-1]
       // [w-wt[i-1]]) as in Knapsack table.
       // If it comes from the latter one/ it means
       // the item is included.
       if (res == K[i - 1][w])
           continue;
       else {

           // This item is included.
           printf("  %d  ", wt[i - 1]);

           // Since this weight is included its
           // value is deducted
           res = res - prof[i - 1];
           w = w - wt[i - 1];
       }
   }
   return K[num][W];
}


// main function
int main()
{
    int num; // num = Total number of items
    int W; // W = Maximum capacity of Knapsack

    printf("\n Enter total number of Items : ");
    scanf("%d", &num);

    int prof[num]; // prof[] = This array contains the profit of each Item
    int wt[num]; // wt[] = This array contains the weight of each Item

    printf("\n Enter profit and weight of each items :\n");
    printf("\t\tProfit \tWeight");
    for(int i = 0; i < num; ++i) {
        int k = i+1;
        printf("\n Item [%d] :\t", k);
    	scanf("%d  %d", &prof[i], &wt[i]);
    }

    printf("\n Enter maximum capacity of knapsack : ");
    scanf("%d", &W);

    printf("\n\n Maximum profit in 0/1 Knapsack : %d\n",  knapSack(W, wt, prof, num));

    return 0;
}
