cmake_minimum_required(VERSION 3.15)
project(projectSkeleton LANGUAGES CXX)

option(BUILD_EXAMPLES "Build examples." ON)

if(BUILD_EXAMPLES)
  add_subdirectory(examples)
endif()


#our main executable test runner section
#adds the person type library as a target
add_library(PersonType src/PersonType.cpp)

#add the Candidate type library as a target
add_library(CandidateType src/CandidateType.cpp)

#add the candidateList type as a target
add_library(CandidateList src/CandidateList.cpp)



#add our main executable as a target
add_executable(main src/Main.cpp)

add_executable(test src/Tests.cpp)

set_target_properties(main PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(test PROPERTIES LINKER_LANGUAGE CXX)

#include this directory to the compiler. tells it where to search for includes
#this saves us from `#include "../examples/doctest.h"`
target_include_directories(main PRIVATE external)

target_include_directories(test PRIVATE external)

#links our libraries together
target_link_libraries(main PRIVATE PersonType)
target_link_libraries(main PRIVATE CandidateType)
target_link_libraries(main PRIVATE CandidateList)

target_link_libraries(test PRIVATE PersonType)
target_link_libraries(test PRIVATE CandidateType)
target_link_libraries(test PRIVATE CandidateList)

#includes the candidate_data.txt in the build
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/data/Candidate_data.txt Candidate_data.txt COPYONLY)