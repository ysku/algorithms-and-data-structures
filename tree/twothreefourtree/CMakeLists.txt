PROJECT(two_three_four_tree)

SET(LIB_SOURCE_FILES
    two_three_four_tree.c
    two_three_four_tree_test.c)

ADD_LIBRARY(${PROJECT_NAME} two_three_four_tree.c)
ADD_LIBRARY(twothreefourtree::two_three_four_tree ALIAS ${PROJECT_NAME})

ADD_EXECUTABLE(${PROJECT_NAME}_test ${LIB_SOURCE_FILES})
