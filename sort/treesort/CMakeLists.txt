PROJECT(treesort)

SET(LIB_SOURCE_FILES
    tree_sort.c
    tree_sort_test.c)

ADD_LIBRARY(${PROJECT_NAME} tree_sort.c)
ADD_LIBRARY(treesort::tree_sort ALIAS ${PROJECT_NAME})

ADD_EXECUTABLE(${PROJECT_NAME}_test ${LIB_SOURCE_FILES})
