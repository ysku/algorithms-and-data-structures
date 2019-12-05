PROJECT(linked_list_queue)

SET(LIB_SOURCE_FILES
    linked_list_queue.c
    linked_list_queue_test.c)

ADD_LIBRARY(${PROJECT_NAME} linked_list_queue.c)
ADD_LIBRARY(linkedlistqueue::linked_list_queue ALIAS ${PROJECT_NAME})

ADD_EXECUTABLE(${PROJECT_NAME}_test ${LIB_SOURCE_FILES})
