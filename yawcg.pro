CONFIG += release

INCLUDEPATH += /usr/local/opencv/include/opencv
INCLUDEPATH += /usr/include/

LIBS += -L/usr/lib -lstdc++ -lboost_filesystem -lboost_program_options
LIBS += -L/usr/local/opencv/lib -lcv -lcvaux -lhighgui

SOURCES += yawcg/main.cpp
SOURCES += yawcg/Exception.cpp
SOURCES += yawcg/Image.cpp
SOURCES += yawcg/WebCam.cpp
SOURCES += yawcg/StdoutLogger.cpp

HEADERS += yawcg/Exception.h
HEADERS += yawcg/IIMage.h
HEADERS += yawcg/IWebCam.h
HEADERS += yawcg/ILogger.h
HEADERS += yawcg/Exception.h

TARGET = yawcg.bin