PROJECT(priority_queue)

SET(LIB_SOURCE_FILES
    priority_queue.c
    priority_queue_test.c)

ADD_LIBRARY(${PROJECT_NAME} priority_queue.c)
ADD_LIBRARY(priorityqueue::priority_queue ALIAS ${PROJECT_NAME})

ADD_EXECUTABLE(${PROJECT_NAME}_test ${LIB_SOURCE_FILES})
