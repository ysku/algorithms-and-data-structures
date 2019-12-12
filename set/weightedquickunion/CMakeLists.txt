PROJECT(weightedquickunion)

SET(LIB_SOURCE_FILES
    weighted_quick_union.c
    weighted_quick_union_test.c)

ADD_LIBRARY(${PROJECT_NAME} weighted_quick_union.c)
ADD_LIBRARY(weightedquickunion::weighted_quick_union ALIAS ${PROJECT_NAME})

ADD_EXECUTABLE(${PROJECT_NAME}_test ${LIB_SOURCE_FILES})
