cmake_minimum_required(VERSION 3.17)
project(MyFirstCProject C)

set(CMAKE_C_STANDARD 11)
#递归遍历所有的c文件
file (GLOB_RECURSE files *.c)
foreach (file ${files})
    string(REGEX REPLACE ".+/(.+)\\..*" "\\1" exe ${file})
    add_executable (${exe} ${file})
    message (\ \ \ \ --\ src/${exe}.c\ will\ be\ compiled\ to\ bin/${exe})
endforeach ()
IF (WIN32)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fexec-charset=GBK")
ENDIF ()