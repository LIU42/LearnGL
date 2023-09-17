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
    TRANSLATION_UP,
    TRANSLATION_DOWN,
    TRANSLATION_LEFT,
    TRANSLATION_RIGHT,
    ROTATION_LEFT,
    ROTATION_RIGHT
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

    private:
        static constexpr float OFFSET_TRANSLATION_SPEED = 0.01f;
        static constexpr float OFFSET_ROTATION_SPEED = 1.0f;

    private:
        static constexpr int FRAME_RATE = 60;
        static constexpr int DIRECT_COUNT = 6;
        static constexpr int ROTATION_ANGLE_MOD = 360;

    private:
        Ui::MainWindow *ui;

    private:
        QTimer intervalTimer;

    private:
        bool isKeyPress[DIRECT_COUNT];
        float offsetX;
        float offsetY;
        float offsetAngle;

    private:
        void mainInterval();
        void initOffset();
        void resetKeyStatus();
        void setInterval();
        void connectTimers();
        void startTimers();

    private:
        void doTranslationOffset();
        void doRotationOffset();

    private:
        void keyPressEvent(QKeyEvent*);
        void keyReleaseEvent(QKeyEvent*);

    public:
        MainWindow(QWidget *parent = nullptr);
        ~MainWindow();

    public:
        void initialize();
};
#endif