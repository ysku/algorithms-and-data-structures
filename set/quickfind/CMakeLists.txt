PROJECT(quickfind)

SET(LIB_SOURCE_FILES
    quick_find.c
    quick_find_test.c)

ADD_LIBRARY(${PROJECT_NAME} quick_find.c)
ADD_LIBRARY(quickfind::quick_find ALIAS ${PROJECT_NAME})

ADD_EXECUTABLE(${PROJECT_NAME}_test ${LIB_SOURCE_FILES})
