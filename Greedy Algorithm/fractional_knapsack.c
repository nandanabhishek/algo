#include <stdio.h>


void knapsack(int num, float weight[], float profit[], float capacity)
{
    float x[20];
    float total_profit = 0;
    float cap = capacity;

    int i;
    for (i=0; i<num; i++) {
        x[i] = 0;
    }

    for (i=0; i<num; i++)
    {
        if(weight[i] > cap)
            break;
        else
        {
            x[i]=1;
            total_profit = total_profit + profit[i];
            cap = cap - weight[i];
        }
    }

    if(i < num)
        x[i] = cap/weight[i];

    total_profit = total_profit + (x[i] * profit[i]);

    printf("\nThe weight of each object taken is :\n");
    for(i=0; i<num; i++) {
        printf("%.2f\t", x[i]);
    }

    printf("\n\n Maximum profit is : %.2f", total_profit);
}



int main() {
    float weight[20];
    float profit[20];
    float capacity;
    int num;
    float ratio[20];


    printf("\nEnter the number of objects : ");
    scanf("%d", &num);

    printf ("\nEnter the weight of each object :\n");
    for (int i=0; i<num; i++)
    {
        scanf("%f", &weight[i]);
    }

    printf ("\nEnter the profit of each object :\n");
    for (int i=0; i<num; i++)
    {
        scanf("%f", &profit[i]);
    }

    printf ("\nEnter the capacity of knapsack : ");
    scanf ("%f", &capacity);

    printf("\nProfit per weight of all the objects are :\n");
    for(int i= 0; i<num; i++){
        ratio[i] = profit[i] / weight[i];
        printf("%.2f\n", ratio[i]);
    }

    // sorting the objects in descending order on the basis of array ratio[]
    // selection sort
    for(int i=0; i<num; i++)
    {
        float temp;
        for(int j=i+1; j < num; j++)
        {
            if(ratio[i]<ratio[j])
            {
                // swapping ratio
                temp= ratio[j];
                ratio[j]= ratio[i];
                ratio[i]= temp;

                // swapping weight
                temp= weight[j];
                weight[j]= weight[i];
                weight[i]= temp;

                // swapping profit
                temp= profit[j];
                profit[j]= profit[i];
                profit[i]= temp;
            }
        }
    }

    knapsack(num, weight, profit, capacity);

    return 0;
}
