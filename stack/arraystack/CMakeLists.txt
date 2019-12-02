PROJECT(array_stack)

SET(LIB_SOURCE_FILES
	array_stack.c
	array_stack_test.c)

ADD_LIBRARY(${PROJECT_NAME} array_stack.c)
ADD_LIBRARY(stack::array_stack ALIAS ${PROJECT_NAME})

ADD_EXECUTABLE(${PROJECT_NAME}_test ${LIB_SOURCE_FILES})
