PROJECT(quicksort)

SET(LIB_SOURCE_FILES
    quick_sort.c
    quick_sort_test.c)

ADD_LIBRARY(${PROJECT_NAME} quick_sort.c)
ADD_LIBRARY(quicksort::heap_sort ALIAS ${PROJECT_NAME})

ADD_EXECUTABLE(${PROJECT_NAME}_test ${LIB_SOURCE_FILES})
