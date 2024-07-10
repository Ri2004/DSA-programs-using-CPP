class Solution:
    def twoSum(self, nums, target: int) :
        hashMap = {}
        indexes = []

        # iterating nums list
        for i in range(len(nums)):

            # calcualte remaining number left from target, after get nums[i]
            remaining = target - nums[i]

            # if that remaining element is present in hashMap then append its 
            # corresponding index in indexes list and append current element index i 
            # in the indexes list after that break from loop because we get those indexes 
            # whose elements adds to get target element

            if remaining in hashMap:
                indexes.append(hashMap[remaining])
                indexes.append(i)

                break
            
            # if that remaining element is not present in hashMap then insert it into 
            # hashMap and insert its index at nums list as its value
            else:
                hashMap[nums[i]] = hashMap.get(nums[i], 0) + i
                
        # return indexes list
        return indexes
        