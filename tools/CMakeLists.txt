set(list
	main.cpp
)

foreach(item ${list})
	list(APPEND CC150_TOOLS_SRCS ${CMAKE_CURRENT_SOURCE_DIR}/{item})
endforeach()