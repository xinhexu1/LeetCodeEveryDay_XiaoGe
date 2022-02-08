class Solution:
    def fourSum(self, nums, target: int):
        def threeSum(sortedNums, tar):
            n = len(sortedNums)
            rst = []
            for i, num in enumerate(sortedNums):
                if num > tar/3:
                    break
                if i > 0 and num == sortedNums[i-1]:
                    continue
                l, r = i+1, n-1
                rhs = tar - num
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

        sortedNums = sorted(nums)
        rst = []
        for i, num in enumerate(sortedNums[:-3]):
            if num > target/4:
                break
            if i > 0 and num == sortedNums[i-1]:
                continue
            comp = threeSum(sortedNums[i+1:], target - num)
            if comp:
                for elem in comp:
                    elem.append(num)
                    rst.append(elem)
        return rst
