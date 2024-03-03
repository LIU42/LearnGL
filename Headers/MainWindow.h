#ifndef __MAINWINDOW_H__
#define __MAINWINDOW_H__

#include <QApplication>
#include <QMainWindow>
#include <QTimer>
#include <QKeyEvent>
#include <QHash>

#include "ShapeOffset.h"

using KeyCodeMap = QHash<int, OffsetDirect>;

QT_BEGIN_NAMESPACE

namespace Ui
{
    class MainWindow;
}

QT_END_NAMESPACE

class KeyStatus
{
    private:
        KeyCodeMap* pKeyCodeMap;

    private:
        bool keyPress[ShapeOffset::DIRECT_COUNT];

    public:
        KeyStatus();
        ~KeyStatus();

    public:
        void setPress(int keyCode);
        void setRelease(int keyCode);
        void reset();

    public:
        const bool* getKeyPress();
};

class WindowTimers
{
    private:
        static constexpr int FRAME_INTERVAL = 16;

    private:
        QTimer* pFrameTimer;

    public:
        WindowTimers();
        ~WindowTimers();

    public:
        const QTimer* getFrameTimer();
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

    private:
        Ui::MainWindow* ui;

    private:
        ShapeOffset* pShapeOffset;
        KeyStatus* pKeyStatus;
        WindowTimers* pWindowTimers;

    private:
        void keyPressEvent(QKeyEvent* pKeyEvent) override;
        void keyReleaseEvent(QKeyEvent* pKeyEvent) override;

    public:
        MainWindow(QWidget* parent = nullptr);
        ~MainWindow();

    public:
        void init();
};
#endif