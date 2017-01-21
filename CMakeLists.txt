cmake_minimum_required (VERSION 2.6)
project (STEP2STL)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories ("/home/alex/Documents/Install-Occ/include/opencascade")

link_directories("/home/alex/Documents/Install-Occ/lib")
 
# add the executable
add_executable (STEP2STL STEP2STL.cpp)

target_link_libraries ( STEP2STL  
                        libTKernel.so 
                        libTKSTEP.so
			libTKSTL.so
			libTKV3d.so
			libTKXSBase.so
                        )

