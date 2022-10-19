TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        controller.cpp \
        list_student.cpp \
        main.cpp \
        node.cpp \
        student.cpp \
        view.cpp

HEADERS += \
    controller.h \
    list_student.h \
    node.h \
    student.h \
    view.h
