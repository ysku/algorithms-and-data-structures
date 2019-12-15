PROJECT(mergesort)

SET(LIB_SOURCE_FILES
    merge_sort.c
    merge_sort_test.c)

ADD_LIBRARY(${PROJECT_NAME} merge_sort.c)
ADD_LIBRARY(mergesort::merge_sort ALIAS ${PROJECT_NAME})

ADD_EXECUTABLE(${PROJECT_NAME}_test ${LIB_SOURCE_FILES})
