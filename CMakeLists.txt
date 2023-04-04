# Housekeeping
cmake_minimum_required(VERSION 3.10)
project(cmake-cplex)
set (CMAKE_CXX_STANDARD 20)

# Packages
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/cmake)
find_package(CPLEX REQUIRED)

if(CPLEX_FOUND)
	message(STATUS "Cplex found.")
	message(STATUS ${CPLEX_INCLUDE_DIRS})
	message(STATUS ${CPLEX_LIBRARIES})
	add_definitions(-DIL_STD)
else()
	message(FATAL_ERROR "CPLEX not found!")
endif()

# Variables
set(EXEC_NAME test-cplex)
set(SOURCES 
    main.cpp)
set(INCLUDE_DIRECTORY 
    ${CMAKE_SOURCE_DIR}/include
    ${CPLEX_INCLUDE_DIRS})
set(LIBRARIES 
    ${CPLEX_CPOPTIMIZER_LIBRARY}
    ${CPLEX_LIBRARIES}
    ${CPLEX_ILOCPLEX_LIBRARY}
    ${CPLEX_CONCERT_LIBRARY}
    )

# Target
add_executable(${EXEC_NAME} ${SOURCES})
target_include_directories(${EXEC_NAME} PUBLIC ${INCLUDE_DIRECTORY})
target_link_libraries(${EXEC_NAME} ${LIBRARIES})
