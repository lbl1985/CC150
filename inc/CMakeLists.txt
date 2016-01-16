set(list
	BinaryTree.h
	CLinkedList.h
	utils.h
)

foreach(item ${list})
	list(APPEND CC150_INC_SRC ${CMAKE_CURRENT_SOURCE_DIR}/${item})
endforeach()

set(CC150_INC_SRC ${CC150_INC_SRC} PARENT_SCOPE)