PROJECT(bubblesort)

SET(LIB_SOURCE_FILES
    bubble_sort.c
    bubble_sort_test.c)

ADD_LIBRARY(${PROJECT_NAME} bubble_sort.c)
ADD_LIBRARY(bubblesort::bubble_sort ALIAS ${PROJECT_NAME})

ADD_EXECUTABLE(${PROJECT_NAME}_test ${LIB_SOURCE_FILES})
