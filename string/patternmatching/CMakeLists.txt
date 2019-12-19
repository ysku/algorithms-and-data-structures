PROJECT(pattern_matching)

SET(LIB_SOURCE_FILES
    pattern_matching.c
    pattern_matching_test.c)

ADD_LIBRARY(${PROJECT_NAME} pattern_matching.c)
ADD_LIBRARY(patternmatching::pattern_matching ALIAS ${PROJECT_NAME})

ADD_EXECUTABLE(${PROJECT_NAME}_test ${LIB_SOURCE_FILES})
