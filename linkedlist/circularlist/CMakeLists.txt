PROJECT(circular_list)

SET(LIB_SOURCE_FILES
    circular_list.c
    circular_list_test.c)

ADD_LIBRARY(${PROJECT_NAME} circular_list.c)
ADD_LIBRARY(linkedlist::circular_list ALIAS ${PROJECT_NAME})

ADD_EXECUTABLE(${PROJECT_NAME}_test ${LIB_SOURCE_FILES})
