PROJECT(openaddresshash)

SET(LIB_SOURCE_FILES
    openaddress_hash.c
    openaddress_hash_test.c)

ADD_LIBRARY(${PROJECT_NAME} openaddress_hash.c)
ADD_LIBRARY(openaddresshash::openaddress_hash ALIAS ${PROJECT_NAME})

ADD_EXECUTABLE(${PROJECT_NAME}_test ${LIB_SOURCE_FILES})
