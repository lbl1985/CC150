set(list
	Q001_TwoSum.cpp
	Q005_longest_palindromic_substring.cpp
	Q021_Merge_Two_Sorted_Lists.cpp
	Q025_Reverse_Nodes_in_k_group.cpp
	Q045_JumpGameII.cpp
	Q50_pow.cpp
	Q051_N_Queens.cpp
	Q055_JumpGame.cpp
	Q058_LengthOfLastWord.cpp
	Q116_PopulatingNextRightPointersinEachNode.cpp
	Q130_SurroundedRegions.cpp
	Q149_Max_Points_on_a_line.cpp
	Q162_FindPeakElement.cpp
	Q179_LargestNumber.cpp
	Q324_WiggleSortII.cpp
	Q326_PowerOfThree.cpp
	Q328_OddEvenLinkedList.cpp
	Q329_LongestIncreasingPathInAMatrix.cpp
	Q331_verify_preorder_serialization_of_a_binary_tree.cpp
	Q338_CountingBits.cpp
	Q342_PowerOfFour.cpp
	Q343_IntegerBreak.cpp
	Q344_ReverseString.cpp
	Q345_ReverseVowelsOfAString.cpp
	Q347_TopKFrequentElements.cpp
	Q349_IntersectionOfTwoArrays.cpp
	Q337_HouseRobberIII.cpp
	Q336_Palindrome_pairs.cpp
)

foreach(item ${list})
	list(APPEND CC150_LEETCODE_SRCS ${CMAKE_CURRENT_SOURCE_DIR}/${item})
endforeach()

set(CC150_LEETCODE_SRCS ${CC150_LEETCODE_SRCS} PARENT_SCOPE)