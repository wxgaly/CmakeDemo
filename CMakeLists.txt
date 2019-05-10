cmake_minimum_required(VERSION 3.0.0)
project(helloworld VERSION 0.1.0)

message(STATUS "start running cmake...")

#代码路径
aux_source_directory(. DIR_TOOT_SRCS)

#dubug 模式
# set (CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -g")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

# include(CTest)
# enable_testing()

# set(BOOST_ROOT /usr/local/include/boost)
# set(BOOST_ROOT /Users/wangxuguang/Desktop/code/test/mycode/boost_1_70_0/boost)
# find_package(Boost COMPONENTS regex system REQUIRED)

# if(NOT Boost_FOUND)
#     message("Not found Boost")
# endif()

# if(Boost_FOUND)
#     # include_directories(${Boost_INCLUDE_DIRS})

#     message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
#     message(STATUS "Boost_LIBRARY_DIRS: ${Boost_LIBRARY_DIRS}")
#     message(STATUS "Boost_LIBRARIES = ${Boost_LIBRARIES}")
#     message(STATUS "Boost_LIB_VERSION = ${Boost_LIB_VERSION}")
# endif()


# 添加头文件路径
# include_directories(
#     ${PROJECT_SOURCE_DIR}/person
#     ${PROJECT_SOURCE_DIR}/utils
#     ${PROJECT_SOURCE_DIR}/net
# )

# add_subdirectory(utils)
# add_library(net net/UdpClient.cpp)
# add_library(person person/Person.cpp person/Man.cpp)
# add_library(stack utils/Stack.cpp)

set(Boost_USE_STATIC_LIBS        ON)  # only find static libs
set(Boost_USE_DEBUG_LIBS         OFF) # ignore debug libs and
set(Boost_USE_RELEASE_LIBS       ON)  # only find release libs
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME    OFF)
find_package(Boost 1.70.0 COMPONENTS date_time system filesystem asio)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
    message(STATUS "Boost_LIBRARIES = ${Boost_LIBRARIES}")
endif()

#生成可执行的文件
add_executable(helloworld main.cpp)

target_link_libraries(helloworld 
    ${Boost_LIBRARIES}
    Boost::date_time 
    # Boost::filesystem
)

# target_link_libraries(helloworld net)
# target_link_libraries(helloworld person)
# target_link_libraries(helloworld stack)
# target_link_libraries(helloworld ${Boost_LIBRARIES})

# set(CPACK_PROJECT_NAME ${PROJECT_NAME})
# set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# include(CPack)
