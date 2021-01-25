def fractional_knapsack(profit, weight, capacity):
    # Return maximum value of items and their fractional amounts.

    # index = [0, 1, 2, ..., n - 1] for n items
    index = list(range(len(profit)))

    # contains ratios of profit to weight
    ratio = [v / w for v, w in zip(profit, weight)]

    # index is sorted according to profit-to-weight ratio in decreasing order
    index.sort(key=lambda i: ratio[i], reverse=True)

    max_profit = 0

    fractions = [0] * len(profit)

    for i in index:
        if weight[i] <= capacity:
            fractions[i] = 1
            max_profit = max_profit + profit[i]
            capacity = capacity - weight[i]
        else:
            fractions[i] = capacity / weight[i]
            max_profit = max_profit + (profit[i] * capacity / weight[i])
            break

    return max_profit, fractions



if __name__ == '__main__':

    num = int(input('Enter number of items : '))

    weight = []
    profit = []

    print('Enter the weight of each items :')
    for i in range(num):
        a = float(input())
        weight.append(a)

    print('Enter the profit of each items :')
    for i in range(num):
        a = float(input())
        profit.append(a)

    capacity = int(input('\nEnter maximum weight : '))

    max_value, fractions = fractional_knapsack(profit, weight, capacity)

    print('\nThe maximum profit value of items that can be carried :', max_value)
    print('\nThe fractions in which the items should be taken :', fractions)
