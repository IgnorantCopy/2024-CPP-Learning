include_directories("../../../Import/easyx4mingw_20240225/include")
link_directories("../../../Import/easyx4mingw_20240225/lib64")
link_libraries(libeasyx.a)

add_executable(SpecialShapedPlant main.cpp main.h)
add_subdirectory(test)