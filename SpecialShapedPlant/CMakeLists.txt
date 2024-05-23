include_directories("include")
link_directories("lib64")
link_libraries(libeasyx.a)

add_subdirectory(src)
add_subdirectory(test)