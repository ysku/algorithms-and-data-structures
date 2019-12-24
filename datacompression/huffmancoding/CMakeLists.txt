PROJECT(huffmancoding)

SET(LIB_SOURCE_FILES
    huffman_coding.c
    huffman_coding_test.c)

ADD_LIBRARY(${PROJECT_NAME} huffman_coding.c)
ADD_LIBRARY(huffmancoding::huffman_coding ALIAS ${PROJECT_NAME})

ADD_EXECUTABLE(${PROJECT_NAME}_test ${LIB_SOURCE_FILES})
