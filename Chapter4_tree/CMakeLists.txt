set(list
	BinaryTreeTest.cpp
	C4Q1.cpp	
	C4Q2.cpp
	C4Q3.cpp
	C4Q4.cpp
	C4Q5.cpp
	C4Q6.cpp
	C4Q7.cpp
	C4Q8.cpp
	C4Q9.cpp
)

foreach(item ${list})
	list(APPEND CC150_CHAPTER4_TREE ${CMAKE_CURRENT_SOURCE_DIR}/${item})
endforeach()

set(CC150_CHAPTER4_TREE ${CC150_CHAPTER4_TREE} PARENT_SCOPE)