class Solution:
    def minimumAddedCoins(self, coins, target):
        coins.sort()
        index = 0
        i = 0
        ans = 0
        while 2 ** i < target:
            while coins[index] <= 2 ** (i - 1):
                if index >= len(coins) - 1:
                    i = 0
                    sumOfCoins = sum(coins)
                    while 2 ** i <= target:
                        if 2 ** i > sumOfCoins and 2 ** i <=target:
                            ans += 1
                        i += 1
                    return ans
                index += 1
            if 2 ** i < coins[index]:
                ans += 1
            i += 1
        return ans
    def min_add_to_make_target(self, coins, target):
        coins.sort()  # Sort the coins in ascending order
        min_unreachable = 1  # Minimum unreachable value
        min_coins_added = 0  # Minimum coins to be added

        for coin in coins:
            if coin > min_unreachable:
                # If the current coin is greater than the minimum unreachable value,
                # we need to add coins to make the values [min_unreachable, coin-1] reachable.
                while min_unreachable < coin:
                    min_coins_added += 1
                    min_unreachable += min_unreachable
                if min_unreachable > target:
                    # If the current minimum unreachable value is greater than the target,
                    # we have made all values up to the target reachable.
                    break
            min_unreachable += coin

        # Add coins to reach the values [min_unreachable, target]
        while min_unreachable <= target:
            min_coins_added += 1
            min_unreachable += min_unreachable

        return min_coins_added

s = Solution()
print(s.min_add_to_make_target([1,2,4,8,16], 31))

