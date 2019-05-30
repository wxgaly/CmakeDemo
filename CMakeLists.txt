cmake_minimum_required(VERSION 3.0.0)
project(helloworld VERSION 0.1.0)

message(STATUS "start running cmake...")

#代码路径
aux_source_directory(. DIR_TOOT_SRCS)

#dubug 模式
# set (CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -g")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
set(CMAKE_CXX_STANDARD 11)

# include(CTest)
# enable_testing()

# 添加boost支持
# set(BOOST_ROOT /Users/wangxuguang/Desktop/code/test/mycode/boost_1_66_0)
set(BOOST_ROOT /Users/wangxuguang/Desktop/code/test/mycode/boost_1_70_0)
find_package(Boost COMPONENTS system REQUIRED)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})

    message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
    message(STATUS "Boost_LIBRARY_DIRS: ${Boost_LIBRARY_DIRS}")
    message(STATUS "Boost_LIBRARIES = ${Boost_LIBRARIES}")
    message(STATUS "Boost_LIB_VERSION = ${Boost_LIB_VERSION}")
endif()

# 增加poco使用
set(POCO_ROOT_DIR "/Users/wangxuguang/Desktop/code/test/github/poco")

include_directories(${POCO_ROOT_DIR}/Net/include)
include_directories(${POCO_ROOT_DIR}/Util/include)
# include_directories(${POCO_ROOT_DIR}/JSON/include)
include_directories(${POCO_ROOT_DIR}/Foundation/include)

LINK_DIRECTORIES(${POCO_ROOT_DIR}/lib)
# LINK_DIRECTORIES("${POCO_ROOT_DIR}/lib/libPocoNet.60.dylib")

MESSAGE(STATUS "t1 This is SOURCE dir ${POCO_ROOT_DIR}/lib/libPocoNet.60.dylib")

# 添加头文件路径
include_directories(
    # ${PROJECT_SOURCE_DIR}/person
    # ${PROJECT_SOURCE_DIR}/utils
    ${PROJECT_SOURCE_DIR}/net
)

add_subdirectory(net)

# add_library(net net/UdpClient.cpp)
# add_library(person person/Person.cpp person/Man.cpp)
# add_library(stack utils/Stack.cpp)

#生成可执行的文件
add_executable(helloworld main.cpp)

target_link_libraries(helloworld net)
target_link_libraries(helloworld 
    ${Boost_LIBRARIES}
)

target_link_libraries(helloworld PocoNet PocoUtil PocoFoundation)


# target_link_libraries(helloworld person)
# target_link_libraries(helloworld stack)

# set(CPACK_PROJECT_NAME ${PROJECT_NAME})
# set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# include(CPack)
