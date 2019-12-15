PROJECT(heapsort)

SET(LIB_SOURCE_FILES
    heap_sort.c
    heap_sort_test.c)

ADD_LIBRARY(${PROJECT_NAME} heap_sort.c)
ADD_LIBRARY(heapsort::heap_sort ALIAS ${PROJECT_NAME})

ADD_EXECUTABLE(${PROJECT_NAME}_test ${LIB_SOURCE_FILES})
