PROJECT(ternarysearch)

SET(LIB_SOURCE_FILES
    ternary_search.c
    ternary_search_test.c)

ADD_LIBRARY(${PROJECT_NAME} ternary_search.c)
ADD_LIBRARY(ternarysearch::ternary_search ALIAS ${PROJECT_NAME})

ADD_EXECUTABLE(${PROJECT_NAME}_test ${LIB_SOURCE_FILES})
