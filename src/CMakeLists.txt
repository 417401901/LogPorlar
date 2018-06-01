CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
if(COMMAND cmake_policy)
      cmake_policy(SET CMP0003 NEW)
endif(COMMAND cmake_policy)

AUX_SOURCE_DIRECTORY(. DIR_FILECONVER_SRCS)

# Declare the target (an executable)
ADD_LIBRARY(libfileconver ${DIR_FILECONVER_SRCS})

TARGET_LINK_LIBRARIES(libfileconver ${OpenCV_LIBS})
