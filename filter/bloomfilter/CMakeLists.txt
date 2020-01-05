PROJECT(bloomfilter)

SET(LIB_SOURCE_FILES
    bloom_filter.c
    bloom_filter_test.c)

ADD_LIBRARY(${PROJECT_NAME} bloom_filter.c)
ADD_LIBRARY(bloomfilter::bloom_filter ALIAS ${PROJECT_NAME})

ADD_EXECUTABLE(${PROJECT_NAME}_test ${LIB_SOURCE_FILES})
