#include "mainwindow.h"
#include "ui_mainwindow.h"

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
    if (isKeyPress[DIRECT_UP])
    {
        offsetY += OFFSET_SPEED;
    }
    if (isKeyPress[DIRECT_DOWN])
    {
        offsetY -= OFFSET_SPEED;
    }
    if (isKeyPress[DIRECT_LEFT])
    {
        offsetX -= OFFSET_SPEED;
    }
    if (isKeyPress[DIRECT_RIGHT])
    {
        offsetX += OFFSET_SPEED;
    }
    ui->pGraphic->setOffset(offsetX, offsetY);
    ui->pGraphic->update();
}

void MainWindow::initOffset()
{
    offsetX = 0;
    offsetY = 0;
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

void MainWindow::keyPressEvent(QKeyEvent* pKeyEvent)
{
    switch (pKeyEvent->key())
    {
        case Qt::Key_W: isKeyPress[DIRECT_UP] = true; break;
        case Qt::Key_S: isKeyPress[DIRECT_DOWN] = true; break;
        case Qt::Key_A: isKeyPress[DIRECT_LEFT] = true; break;
        case Qt::Key_D: isKeyPress[DIRECT_RIGHT] = true; break;
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent* pKeyEvent)
{
    switch (pKeyEvent->key())
    {
        case Qt::Key_W: isKeyPress[DIRECT_UP] = false; break;
        case Qt::Key_S: isKeyPress[DIRECT_DOWN] = false; break;
        case Qt::Key_A: isKeyPress[DIRECT_LEFT] = false; break;
        case Qt::Key_D: isKeyPress[DIRECT_RIGHT] = false; break;
    }
}

void MainWindow::init()
{
    initOffset();
    resetKeyStatus();
    setInterval();
    connectTimers();
    startTimers();
}