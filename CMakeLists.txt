cmake_minimum_required (VERSION 3.5)
project (usedessPat)

#use CXX 14 (for gcc)
set (CMAKE_CXX_STANDARD 14)

#The Version number
set (usedessPat_VERSION_MAJOR 0)
set (usedessPat_VERSION_MINOR 1)

find_package(GFG)
find_package(GOF)
find_package(CS180)
find_package(LCTHW)
find_package(CONCUR)
find_package(MCPP)
find_package(WIN)
find_package(LIN)

add_executable(usedessPat usedessPat.cpp)
target_link_libraries(usedessPat GFG::gfg
				 GOF::gof
				 CS180::cs180
				 LCTHW::lcthw
				 CONCUR::concur
				 MCPP::mcpp)

if(WIN_FOUND)
  target_link_libraries(usedessPat WIN::win)
endif(WIN_FOUND)

if(LIN_FOUND)
  target_link_libraries(usedessPat LIN::lin)
endif(LIN_FOUND)



target_include_directories(usedessPat
    #PUBLIC
    #${CMAKE_SOURCE_DIR}/common/include
    PRIVATE
    ${PROJECT_BINARY_DIR})

#configure a header file to pass some of the cmake settings to the source code
configure_file (
 "${PROJECT_SOURCE_DIR}/usedessPatConfig.h.in"
 "${PROJECT_BINARY_DIR}/usedessPatConfig.h"
)

#configure sample input file
configure_file (
 "${PROJECT_SOURCE_DIR}/sampleInput.txt.in"
 "${PROJECT_BINARY_DIR}/sampleInput.txt"
 COPYONLY
)
