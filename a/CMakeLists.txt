project(file_size)

set(SRC_FILES filesize.c filesize.h)

add_library(file_size SHARED ${SRC_FILES})
