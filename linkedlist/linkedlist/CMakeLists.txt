PROJECT(linked_list)

SET(LIB_SOURCE_FILES
    linked_list.c
    linked_list_test.c)

ADD_LIBRARY(${PROJECT_NAME} linked_list.c)
ADD_LIBRARY(linkedlist::linked_list ALIAS ${PROJECT_NAME})

ADD_EXECUTABLE(${PROJECT_NAME}_test ${LIB_SOURCE_FILES})
