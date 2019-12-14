PROJECT(selectionsort)

SET(LIB_SOURCE_FILES
    selection_sort.c
    selection_sort_test.c)

ADD_LIBRARY(${PROJECT_NAME} selection_sort.c)
ADD_LIBRARY(selectionsort::selection_sort ALIAS ${PROJECT_NAME})

ADD_EXECUTABLE(${PROJECT_NAME}_test ${LIB_SOURCE_FILES})
