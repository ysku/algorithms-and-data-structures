PROJECT(binary_tree)

SET(LIB_SOURCE_FILES
    binary_tree.c
    binary_tree_test.c)

ADD_LIBRARY(${PROJECT_NAME} binary_tree.c)
ADD_LIBRARY(binarytree::binary_tree ALIAS ${PROJECT_NAME})

ADD_EXECUTABLE(${PROJECT_NAME}_test ${LIB_SOURCE_FILES})
