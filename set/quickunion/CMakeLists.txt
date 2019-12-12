PROJECT(quickunion)

SET(LIB_SOURCE_FILES
    quick_union.c
    quick_union_test.c)

ADD_LIBRARY(${PROJECT_NAME} quick_union.c)
ADD_LIBRARY(quickunion::quick_union ALIAS ${PROJECT_NAME})

ADD_EXECUTABLE(${PROJECT_NAME}_test ${LIB_SOURCE_FILES})
