PROJECT(shellsort)

SET(LIB_SOURCE_FILES
    shell_sort.c
    shell_sort_test.c)

ADD_LIBRARY(${PROJECT_NAME} shell_sort.c)
ADD_LIBRARY(shellsort::shell_sort ALIAS ${PROJECT_NAME})

ADD_EXECUTABLE(${PROJECT_NAME}_test ${LIB_SOURCE_FILES})
