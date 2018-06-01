PROJECT(demo)

CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
if(COMMAND cmake_policy)
      cmake_policy(SET CMP0003 NEW)
endif(COMMAND cmake_policy)

FIND_PACKAGE( OpenCV REQUIRED )

ADD_SUBDIRECTORY( src )
AUX_SOURCE_DIRECTORY(. DIR_SRCS)

# Declare the target (an executable)
ADD_EXECUTABLE(demo ${DIR_SRCS})

TARGET_LINK_LIBRARIES(demo libfileconver)

#MESSAGE(STATUS "OpenCV_LIBS: ${OpenCV_LIBS}")
