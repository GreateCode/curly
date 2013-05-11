project(curl-asio CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/lib)

cmake_minimum_required(VERSION 2.8)

find_package(Boost COMPONENTS system thread REQUIRED)
find_package(CURL REQUIRED)

include_directories(${Boost_INCLUDE_DIR})
include_directories(${CURL_INCLUDE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_library(curly
	curly.cc
	curly.hh
)

target_link_libraries(curly
	${CURL_LIBRARIES}
)

add_library(curly-asio
        service.cc
	service.hxx
        service.hh
        asio_request.cc
        asio_request.hh
)

target_link_libraries(curly-asio
	${Boost_LIBRARIES}
	${CURL_LIBRARIES}
	curly
)

add_executable(test
	test.cc
)

target_link_libraries(test
	curly
)


add_executable(test-asio
        test-asio.cc
)

target_link_libraries(test-asio
	curly-asio
)


add_executable(asiohiper
	asiohiper.cpp
)


target_link_libraries(asiohiper
	${Boost_LIBRARIES}
	${CURL_LIBRARIES}
)
