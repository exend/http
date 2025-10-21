cmake_minimum_required(VERSION 3.21)

project(http LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(libs/netcore)

add_library(${PROJECT_NAME} STATIC
	src/handlers/default_request_handler.cpp
	src/handlers/http_protocol_handler.cpp
	src/response/default_error_response.cpp
	src/response/file_response.cpp
	src/response/response.cpp
	src/response/stream_response.cpp
	src/response/string_response.cpp
	src/method.cpp
	src/request_dispatcher.cpp
	src/route_registry.cpp
	src/server.cpp
	src/status.cpp
)

target_include_directories(${PROJECT_NAME}
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
	PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(${PROJECT_NAME} PUBLIC netcore)
