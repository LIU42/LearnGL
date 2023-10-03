QT       += core gui opengl openglwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += $$PWD/Headers/

SOURCES += \
	Sources/GLShapes/GLRectangle.cpp \
	Sources/GLShapes/GLTriangle.cpp \
	Sources/GLShapes/GLTexture.cpp \
	Sources/Graphic.cpp \
	Sources/Main.cpp \
	Sources/MainWindow.cpp

HEADERS += \
	Headers/GLShapes/GLRectangle.h \
	Headers/GLShapes/GLTriangle.h \
	Headers/GLShapes/GLTexture.h \
	Headers/Graphic.h \
	Headers/MainWindow.h

FORMS += \
	Forms/MainWindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
	Resources/Resources.qrc

RC_ICONS = Resources/Images/icon.ico
