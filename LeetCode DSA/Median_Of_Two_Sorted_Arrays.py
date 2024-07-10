class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        merged_array = nums1 + nums2
        merged_array.sort()
        length_array = len(merged_array)

        if length_array % 2 != 0:
            return float(merged_array[length_array//2])
        
        elif length_array % 2 == 0:
            avg = (float(merged_array[length_array//2 - 1]) + float(merged_array[length_array//2]))/2.0
            return avg