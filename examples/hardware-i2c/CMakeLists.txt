cmake_minimum_required(VERSION 3.16)

project(LCD-demo)

set(CMAKE_EXE_LINKER_FLAGS "-W -Wall -static ")
set(CMAKE_C_FLAGS   "${CMAKE_C_FLAGS} -D __ARM_LINUX__ -DPERIPHERY_GPIO_CDEV_SUPPORT=1")
set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -D __ARM_LINUX__ -DPERIPHERY_GPIO_CDEV_SUPPORT=1")

set(U8G2PATH ${CMAKE_SOURCE_DIR}/../../lib/u8g2-arm-linux/)
message("U8g2 path" ${U8G2PATH})
include_directories(${U8G2PATH}/cppsrc)
include_directories(${U8G2PATH}/csrc)
include_directories(${U8G2PATH}/port)
include_directories(${U8G2PATH}/drivers)

file(GLOB U8g2_SRC
        ${U8G2PATH}/cppsrc/*.cpp
        ${U8G2PATH}/cppsrc/*.h
        ${U8G2PATH}/csrc/*.c
        ${U8G2PATH}/csrc/*.h
        ${U8G2PATH}/drivers/*.c
        ${U8G2PATH}/drivers/*.h
        ${U8G2PATH}/port/*.c
        ${U8G2PATH}/port/*.h
)

add_executable(${PROJECT_NAME}
        main.cpp
        ${U8g2_SRC}
)
