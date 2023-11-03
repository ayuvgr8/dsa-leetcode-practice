class Solution:
    def buildArray(self, target, n):
        result = []
        index = 0  # Initialize an index to keep track of the current target element.

        for i in range(1, n + 1):
            if index >= len(target):
                break  # If we have processed all target elements, exit the loop.
            
            result.append("Push")
            
            if target[index] == i:
                index += 1  # Move to the next target element when they match.
            else:
                result.append("Pop")  # If the elements don't match, simulate Pop.

        return result


# # Example usage:
# solution = Solution()
# target = [1, 3]
# n = 3
# stack_operations = solution.buildArray(target, n)
# print(stack_operations)
