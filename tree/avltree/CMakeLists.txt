PROJECT(avl_tree)

SET(LIB_SOURCE_FILES
    avl_tree.c
    avl_tree_test.c)

ADD_LIBRARY(${PROJECT_NAME} avl_tree.c)
ADD_LIBRARY(avltree::avl_tree ALIAS ${PROJECT_NAME})

ADD_EXECUTABLE(${PROJECT_NAME}_test ${LIB_SOURCE_FILES})
