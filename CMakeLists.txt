cmake_minimum_required(VERSION 3.26...4.0)

if(WIN32)
    set(CMAKE_TOOLCHAIN_FILE C:/vcpkg/scripts/buildsystems/vcpkg.cmake)
endif()

project(dqrobotics_python_interface_coppeliasim_zmq)

find_package(Eigen3 REQUIRED)

#VREP INTERFACE
add_definitions(-DNON_MATLAB_PARSING)
add_definitions(-DMAX_EXT_API_CONNECTIONS=255)
add_definitions(-DDO_NOT_USE_SHARED_MEMORY)

add_subdirectory(submodules/dqrobotics/python/pybind11)

include_directories(
        submodules/dqrobotics/cpp-interface-vrep/include/
        submodules/dqrobotics/cpp-interface-vrep/coppeliarobotics/include
        submodules/dqrobotics/cpp-interface-vrep/coppeliarobotics/remoteApi
)

pybind11_add_module(_core

        src/modules.cpp
        # interfaces/vrep
        submodules/dqrobotics/cpp-interface-vrep/src/dqrobotics/interfaces/vrep/DQ_VrepInterface.cpp
        submodules/dqrobotics/cpp-interface-vrep/src/dqrobotics/interfaces/vrep/DQ_VrepInterfaceMapElement.cpp
        submodules/dqrobotics/cpp-interface-vrep/coppeliarobotics/remoteApi/extApi.c
        submodules/dqrobotics/cpp-interface-vrep/coppeliarobotics/remoteApi/extApiPlatform.h
        submodules/dqrobotics/cpp-interface-vrep/coppeliarobotics/remoteApi/extApiPlatform.c
        src/interfaces/vrep/DQ_VrepInterface_py.cpp
        submodules/dqrobotics/cpp-interface-vrep/src/dqrobotics/interfaces/vrep/DQ_VrepRobot.cpp
        submodules/dqrobotics/cpp-interface-vrep/src/dqrobotics/interfaces/vrep/DQ_SerialVrepRobot.cpp
        submodules/dqrobotics/cpp-interface-vrep/src/dqrobotics/interfaces/vrep/robots/LBR4pVrepRobot.cpp
        submodules/dqrobotics/cpp-interface-vrep/src/dqrobotics/interfaces/vrep/robots/YouBotVrepRobot.cpp
        submodules/dqrobotics/cpp-interface-vrep/src/dqrobotics/interfaces/vrep/robots/FrankaEmikaPandaVrepRobot.cpp
        src/interfaces/vrep/DQ_VrepRobot_py.cpp
        src/interfaces/vrep/DQ_SerialVrepRobot_py.cpp
)

set(BUILD_SHARED_LIBS FALSE CACHE BOOL "x" FORCE)
add_subdirectory(submodules/dqrobotics/python/cpp)
#add_subdirectory(submodules/dqrobotics/cpp-interface-vrep)

#target_include_directories(_core PUBLIC
#        submodules/dqrobotics/cpp-interface-vrep
#)

target_link_libraries(_core PRIVATE
        dqrobotics
#        dqrobotics-interface-vrep
        Eigen3::Eigen
)