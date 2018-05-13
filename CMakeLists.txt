project(main)

set(SRC_FILES main.cpp pluginloader.cpp pluginloader.h)

add_executable(test ${SRC_FILES})

target_link_libraries(test libdl.so)
