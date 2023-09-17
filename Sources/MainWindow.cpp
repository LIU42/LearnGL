#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mainInterval()
{
    doTranslationOffset();
    doRotationOffset();

    ui->pGraphic->setOffset(offsetX, offsetY, offsetAngle);
    ui->pGraphic->update();
}

void MainWindow::initOffset()
{
    offsetX = 0;
    offsetY = 0;
    offsetAngle = 0;
}

void MainWindow::resetKeyStatus()
{
    for (int direct = 0; direct < DIRECT_COUNT; direct++)
    {
        isKeyPress[direct] = false;
    }
}

void MainWindow::setInterval()
{
    intervalTimer.setInterval(1000 / FRAME_RATE);
}

void MainWindow::connectTimers()
{
    connect(&intervalTimer, &QTimer::timeout, this, &MainWindow::mainInterval);
}

void MainWindow::startTimers()
{
    intervalTimer.start();
}

void MainWindow::doTranslationOffset()
{
    if (isKeyPress[TRANSLATION_UP])
    {
        offsetY += OFFSET_TRANSLATION_SPEED;
    }
    if (isKeyPress[TRANSLATION_DOWN])
    {
        offsetY -= OFFSET_TRANSLATION_SPEED;
    }
    if (isKeyPress[TRANSLATION_LEFT])
    {
        offsetX -= OFFSET_TRANSLATION_SPEED;
    }
    if (isKeyPress[TRANSLATION_RIGHT])
    {
        offsetX += OFFSET_TRANSLATION_SPEED;
    }
}

void MainWindow::doRotationOffset()
{
    if (isKeyPress[ROTATION_LEFT])
    {
        offsetAngle = fmod(offsetAngle + OFFSET_ROTATION_SPEED, ROTATION_ANGLE_MOD);
    }
    if (isKeyPress[ROTATION_RIGHT])
    {
        offsetAngle = fmod(offsetAngle - OFFSET_ROTATION_SPEED, ROTATION_ANGLE_MOD);
    }
}

void MainWindow::keyPressEvent(QKeyEvent* pKeyEvent)
{
    switch (pKeyEvent->key())
    {
        case Qt::Key_W: isKeyPress[TRANSLATION_UP] = true; break;
        case Qt::Key_S: isKeyPress[TRANSLATION_DOWN] = true; break;
        case Qt::Key_A: isKeyPress[TRANSLATION_LEFT] = true; break;
        case Qt::Key_D: isKeyPress[TRANSLATION_RIGHT] = true; break;
        case Qt::Key_Q: isKeyPress[ROTATION_LEFT] = true; break;
        case Qt::Key_E: isKeyPress[ROTATION_RIGHT] = true; break;
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent* pKeyEvent)
{
    switch (pKeyEvent->key())
    {
        case Qt::Key_W: isKeyPress[TRANSLATION_UP] = false; break;
        case Qt::Key_S: isKeyPress[TRANSLATION_DOWN] = false; break;
        case Qt::Key_A: isKeyPress[TRANSLATION_LEFT] = false; break;
        case Qt::Key_D: isKeyPress[TRANSLATION_RIGHT] = false; break;
        case Qt::Key_Q: isKeyPress[ROTATION_LEFT] = false; break;
        case Qt::Key_E: isKeyPress[ROTATION_RIGHT] = false; break;
    }
}

void MainWindow::initialize()
{
    initOffset();
    resetKeyStatus();
    setInterval();
    connectTimers();
    startTimers();
}