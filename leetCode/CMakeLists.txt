set(list
	Q324_WiggleSortII.cpp
	Q326_PowerOfThree.cpp
)

foreach(item ${list})
	list(APPEND CC150_LEETCODE_SRCS ${CMAKE_CURRENT_SOURCE_DIR}/${item})
endforeach()

set(CC150_LEETCODE_SRCS ${CC150_LEETCODE_SRCS} PARENT_SCOPE)