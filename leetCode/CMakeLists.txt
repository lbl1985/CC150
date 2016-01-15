# set(list
# 	Q324_WiggleSortII.cpp
# )
# 
# foreach(item ${list})
# 	list(APPEND CC150_LEETCODE_SRCS ${CMAKE_CURRENT_SOURCE_DIR}/{item})
# endforeach()
add_library(cc150_lib Q324_WiggleSortII.cpp
					  Q326_PowerOfThree.cpp)