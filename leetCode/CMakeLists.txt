set(list
	Q162_FindPeakElement.cpp
	Q324_WiggleSortII.cpp
	Q326_PowerOfThree.cpp
	Q328_OddEvenLinkedList.cpp
	Q329_LongestIncreasingPathInAMatrix.cpp
	Q130_SurroundedRegions.cpp
)

foreach(item ${list})
	list(APPEND CC150_LEETCODE_SRCS ${CMAKE_CURRENT_SOURCE_DIR}/${item})
endforeach()

set(CC150_LEETCODE_SRCS ${CC150_LEETCODE_SRCS} PARENT_SCOPE)