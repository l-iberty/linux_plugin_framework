project(file_word_count)

set(SRC_FILES filewordcount.c filewordcount.h)

add_library(file_word_count SHARED ${SRC_FILES})
