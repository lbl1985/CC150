set(list
	bubbleSortTest.cpp
	quicksort.cpp
	mergesort.cpp
	binarySearch.cpp
)

foreach(item ${list})
	list(APPEND CC150_CHAPTER10_SORT_SRCS ${CMAKE_CURRENT_SOURCE_DIR}/${item})
endforeach()

set(CC150_CHAPTER10_SORT_SRCS ${CC150_CHAPTER10_SORT_SRCS} PARENT_SCOPE)