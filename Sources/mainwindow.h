#ifndef __MAINWINDOW_H__
#define __MAINWINDOW_H__

#include <QApplication>
#include <QMainWindow>
#include <QTimer>
#include <QKeyEvent>

QT_BEGIN_NAMESPACE

namespace Ui
{
    class MainWindow;
}

QT_END_NAMESPACE

enum OffsetDirect
{
    DIRECT_UP,
    DIRECT_DOWN,
    DIRECT_LEFT,
    DIRECT_RIGHT,
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

    private:
        static constexpr float OFFSET_SPEED = 0.01f;

    private:
        static constexpr int FRAME_RATE = 60;
        static constexpr int DIRECT_COUNT = 4;

    private:
        Ui::MainWindow *ui;

    private:
        QTimer intervalTimer;

    private:
        bool isKeyPress[DIRECT_COUNT];
        float offsetX;
        float offsetY;

    private:
        void mainInterval();
        void initOffset();
        void resetKeyStatus();
        void setInterval();
        void connectTimers();
        void startTimers();

    private:
        void keyPressEvent(QKeyEvent*);
        void keyReleaseEvent(QKeyEvent*);

    public:
        MainWindow(QWidget *parent = nullptr);
        ~MainWindow();

    public:
        void init();
};
#endif