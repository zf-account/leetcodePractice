cmake_minimum_required(VERSION 3.5.0)
project(leetcodePracticeC++ VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
# 设置编译选项，开启一些警告以提高代码质量检查
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")
# set(Build_PATH "./SuanFaYuanLi")

## start
# mac : 非mac注释掉
include_directories(/opt/homebrew/include)
link_directories(/opt/homebrew/lib)

find_package(GTest REQUIRED)
if(NOT GTEST_FOUND)
    message(FATAL_ERROR "GoogleTest not found!")
endif()
## end

# set(13_PROJECT_NAME "13LuoMaShuZiZhuanZhengShu")
# set(13_PROJECT_SOURCES src/13LuoMaShuZiZhuanZhengShu.cpp)
# add_executable(${13_PROJECT_NAME} ${13_PROJECT_SOURCES})

# 递归查找 src 目录下的所有.cpp 文件
file(GLOB SRC_FILES1 "src/*.cpp" "src/SuanFaYuanLi/*.cpp")
# file(GLOB SRC_FILES2 "src/SuanFaYuanLi/*.cpp")

# 遍历每个.cpp 文件进行单独编译
foreach(SRC_FILE ${SRC_FILES1})
  # 获取源文件名（不包含路径和扩展名）
  get_filename_component(FILENAME_WO_EXT ${SRC_FILE} NAME_WE)
  # 添加可执行文件，文件名与源文件名相同
  add_executable(${FILENAME_WO_EXT} ${SRC_FILE})
endforeach()

# # 遍历每个.cpp 文件进行单独编译
# foreach(SRC_FILE ${SRC_FILES2})
#   # 获取源文件名（不包含路径和扩展名）
#   get_filename_component(FILENAME_WO_EXT ${SRC_FILE} NAME_WE)
#   # 添加可执行文件，文件名与源文件名相同
#   add_executable(${FILENAME_WO_EXT} ${SRC_FILE})
# endforeach()