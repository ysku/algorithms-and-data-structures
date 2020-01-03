PROJECT(bucketsort)

SET(LIB_SOURCE_FILES
    bucket_sort.c
    bucket_sort_test.c)

ADD_LIBRARY(${PROJECT_NAME} bucket_sort.c)
ADD_LIBRARY(bucketsort::bucket_sort ALIAS ${PROJECT_NAME})

ADD_EXECUTABLE(${PROJECT_NAME}_test ${LIB_SOURCE_FILES})
