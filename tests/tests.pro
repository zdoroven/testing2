include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

QMAKE_CXXFLAGS += -Wall -Wextra -Werror
QMAKE_CFLAGS += -Wall -Wextra -Werror

# gcov
QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage
QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov


HEADERS += ../app/common.h \
    ../app/text/_text.h \
    ../app/text/text.h \
    showupper_test.h \
    r1e_test.h \
    mlb_test.h \
    shared.h

SOURCES += main.cpp \
    ../app/load.c \
    ../app/showupper.c \
    ../app/remove_first_entry_line.c \
    ../app/cursor_to_begin.c \
    ../app/mwcrsr.c \
    ../app/text/append_line.c \
    ../app/text/delete_line.c \
    ../app/text/change_cursor_position.c \
    ../app/text/process_forward.c \
    ../app/text/create_text.c \
    ../app/text/prepend_line.c \
    ../app/text/remove_all.c \
    ../app/show.c

INCLUDEPATH += ../app
