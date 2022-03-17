'''
Two-Sum
Given an array of integers and an integer   , return indices of the two numbers such that they add up to     .
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.
'''

'''
Single Number
Given a non-empty array of integers   , every element appears twice except for one. Find that single one.
'''

from functools import reduce


def main():
	nums = [2, 7, 11, 15]
	target = 26
	res = two_sum(nums, target)
	res2 = two_sum_2(nums, target)
	print(f'Result of two_sum is {res}')
	print(f'Result of two_sum_2 is {res2}')
	nums = [4,1,2,1,2, 5, 4, 6, 5]
	unique = single_element(nums)
	unique2 = single_element_2(nums)
	print(f"single element in array {nums} is {unique}")
	print(f"single element in array {nums} is {unique2}")


def two_sum(nums, target):
	for i in range(0, len(nums) - 1):
		for j in range(i+1, len(nums)):
			if nums[i] + nums[j] == target: return [i, j]
	return None


def two_sum_2(nums, target):
	h_map = {}
	for i, num in enumerate(nums):
		assoc = target - num
		if assoc in h_map:
			return [h_map[assoc], i]
		else:
			h_map[num] = i
	return None


def single_element(nums):
	xor = 0
	for num in nums:
		xor ^= num
	return xor


def single_element_2(nums):
	return reduce(lambda x, y: x^y, nums)


if __name__ == '__main__':
	main()
