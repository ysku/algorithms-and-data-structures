PROJECT(array_queue)

SET(LIB_SOURCE_FILES
	array_queue.c
	array_queue_test.c)

ADD_LIBRARY(${PROJECT_NAME} array_queue.c)
ADD_LIBRARY(queue::array_queue ALIAS ${PROJECT_NAME})

ADD_EXECUTABLE(${PROJECT_NAME}_test ${LIB_SOURCE_FILES})
