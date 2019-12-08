PROJECT(expression_tree)

SET(LIB_SOURCE_FILES
    expression_tree.c
    expression_tree_test.c)

ADD_LIBRARY(${PROJECT_NAME} expression_tree.c)
ADD_LIBRARY(expressiontree::expression_tree ALIAS ${PROJECT_NAME})

ADD_EXECUTABLE(${PROJECT_NAME}_test ${LIB_SOURCE_FILES})
