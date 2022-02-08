class Solution:
    def threeSum(self, nums):
        sortedNums = sorted(nums)
        n = len(sortedNums)
        rst = []
        for i, num in enumerate(sortedNums):
            if num > 0:
                break
            if i > 0 and num == sortedNums[i-1]:
                continue
            l, r = i+1, n-1
            rhs = -1 * num
            while l < r:
                lhs = sortedNums[l] + sortedNums[r]
                if lhs == rhs:
                    cur = [num, sortedNums[l], sortedNums[r]]
                    if not rst or cur != rst[-1]:
                        rst.append(cur)
                    l += 1
                    r -= 1
                elif lhs < rhs:
                    l += 1
                else:
                    r -= 1
        return rst
