PROJECT(linked_list_stack)

SET(LIB_SOURCE_FILES
        linked_list_stack.c
        linked_list_stack_test.c)

ADD_EXECUTABLE(${PROJECT_NAME} ${LIB_SOURCE_FILES})

TARGET_LINK_LIBRARIES(${PROJECT_NAME} linkedlist::linked_list)
