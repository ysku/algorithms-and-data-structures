PROJECT(chaining_hash)

SET(LIB_SOURCE_FILES
    chaining_hash.c
    chaining_hash_test.c)

ADD_LIBRARY(${PROJECT_NAME} chaining_hash.c)
ADD_LIBRARY(chaininghash::chaining_hash ALIAS ${PROJECT_NAME})

ADD_EXECUTABLE(${PROJECT_NAME}_test ${LIB_SOURCE_FILES})
