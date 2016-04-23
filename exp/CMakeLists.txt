set(list
	constructChar.cpp
)

foreach(item ${list})
	list(APPEND CC150_EXP_SRCS ${CMAKE_CURRENT_SOURCE_DIR}/${item})
endforeach()

set(CC150_EXP_SRCS ${CC150_EXP_SRCS} PARENT_SCOPE)