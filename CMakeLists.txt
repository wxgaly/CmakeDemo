cmake_minimum_required(VERSION 3.0.0)
project(helloworld VERSION 0.1.0)

#代码路径
aux_source_directory(. DIR_TOOT_SRCS)

#dubug 模式
set (CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -g")
include(CTest)
enable_testing()

# 添加头文件路径
include_directories(
    ${PROJECT_SOURCE_DIR}/person
    ${PROJECT_SOURCE_DIR}/utils
)

# add_subdirectory(utils)
add_library(person person/Person.cpp person/Man.cpp)
add_library(stack utils/Stack.cpp)

#生成可执行的文件
add_executable(helloworld ${DIR_TOOT_SRCS})

target_link_libraries(helloworld person)
target_link_libraries(helloworld stack)

# set(CPACK_PROJECT_NAME ${PROJECT_NAME})
# set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# include(CPack)
