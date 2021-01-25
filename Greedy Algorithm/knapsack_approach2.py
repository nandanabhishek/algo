# Python3 program to solve fractional Knapsack Problem

class ItemValue:
    """Item Value DataClass"""

    def __init__(self, weight, profit, index):
        self.weight = weight
        self.profit = profit
        self.index = index
        self.profitPerKg = profit / weight

    def __lt__(self, other):
        return self.profitPerKg < other.profitPerKg


# Greedy Approach
class FractionalKnapSack:
    """Time Complexity O(n log n)"""

    def getMaxValue(weight, profit, capacity):
        """function to get maximum value """
        iVal = []
        for i in range(len(weight)):
            iVal.append(ItemValue(weight[i], profit[i], i))

            # sorting items by value
        iVal.sort(reverse=True)

        totalProfit = 0

        for i in iVal:
            curWt = int(i.weight)
            curVal = int(i.profit)
            if capacity - curWt >= 0:
                capacity -= curWt
                totalProfit += curVal
            else:
                fraction = capacity / curWt
                totalProfit += curVal * fraction
                capacity = int(capacity - (curWt * fraction))
                break
        return totalProfit


# Driver Code

if __name__ == "__main__":
    weight = []
    profit = []
    num = int(input('Enter the number of items : '))
    print('Enter the weight of each items :')
    for i in range(num):
        a = float(input())
        weight.append(a)

    print('Enter the profit of each items :')
    for i in range(num):
        a = float(input())
        profit.append(a)

    capacity = float(input('Enter the maximum weight of Knapsack : '))

    # Function call
    maxValue = FractionalKnapSack.getMaxValue(weight, profit, capacity)
    print("Maximum value in Knapsack =", maxValue)
