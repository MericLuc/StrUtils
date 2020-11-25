TEMPLATE     = app
SOURCES      = main.cpp

LIB_PATH     = $$PWD/../str-utils-lib
INCLUDEPATH += $${LIB_PATH}/inc
LIBS        += -L$${LIB_PATH}/lib -lstr-utils
TARGET       = str-utils-test

message(" LIB_PATH = $${LIB_PATH} ")
