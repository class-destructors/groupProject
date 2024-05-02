#a bunch of examples of how to build things with cmake
#the simplest example, a single file that compiles to a single executable
#example in this case is the name of the target and the name of the executable that will be built
#EXCLUDE_FROM_ALL means that this target will be built only when we tell cmake to explicitly
add_executable(example EXCLUDE_FROM_ALL example.cpp)


#a slightly more complicated example. This target uses a library with a print function
add_executable(exampleWithLibraries EXCLUDE_FROM_ALL exampleWithLib.cpp)

#this adds a library target, when this target is compiled it will build a library object file
add_library(examplePrint EXCLUDE_FROM_ALL print.cpp)

#this tells cmake that example with libraries requires the print library
#it will be automatically built and linked when the example with library target is called
target_link_libraries(exampleWithLibraries PUBLIC examplePrint)


#this target includes functions suitable for testing
add_executable(exampleWithTests EXCLUDE_FROM_ALL exampleWithTests.cpp)
add_library(exampleMath EXCLUDE_FROM_ALL math.cpp)
target_link_libraries(exampleWithTests PRIVATE exampleMath)


#add a tests executable
add_executable(exampleTests EXCLUDE_FROM_ALL tests.cpp)
#include our external directory for this target
#this allows us to simply type "#include <doctest.h>
#normally we'd need to do #include "../external/doctest.h"
target_include_directories(exampleTests PRIVATE ../external)
target_link_libraries(exampleTests PRIVATE exampleMath)
