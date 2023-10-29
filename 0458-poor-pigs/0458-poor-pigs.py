class Solution(object):
    def poorPigs(self, buckets, minutesToDie, minutesToTest):
        # Calculate how many tests can be performed in the given time
        tests = minutesToTest // minutesToDie + 1
        
        # Use binary search to find the minimum number of pigs
        left, right = 0, buckets
        while left < right:
            mid = (left + right) // 2
            if (tests ** mid) >= buckets:
                right = mid
            else:
                left = mid + 1
        
        return left