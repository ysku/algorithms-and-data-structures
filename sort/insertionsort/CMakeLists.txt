PROJECT(insertionsort)

SET(LIB_SOURCE_FILES
    insertion_sort.c
    insertion_sort_test.c)

ADD_LIBRARY(${PROJECT_NAME} insertion_sort.c)
ADD_LIBRARY(insertionsort::insertion_sort ALIAS ${PROJECT_NAME})

ADD_EXECUTABLE(${PROJECT_NAME}_test ${LIB_SOURCE_FILES})
