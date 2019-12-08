PROJECT(binary_search_tree)

SET(LIB_SOURCE_FILES
    binary_search_tree.c
    binary_search_tree_test.c)

ADD_LIBRARY(${PROJECT_NAME} binary_search_tree.c)
ADD_LIBRARY(binarysearchtree::binary_search_tree ALIAS ${PROJECT_NAME})

ADD_EXECUTABLE(${PROJECT_NAME}_test ${LIB_SOURCE_FILES})
