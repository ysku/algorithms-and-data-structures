PROJECT(hashcode)

SET(LIB_SOURCE_FILES
    hash_code.c
    hash_code_test.c)

ADD_LIBRARY(${PROJECT_NAME} hash_code.c)
ADD_LIBRARY(hashcode::hash_code ALIAS ${PROJECT_NAME})

ADD_EXECUTABLE(${PROJECT_NAME}_test ${LIB_SOURCE_FILES})
