#include "MainWindow.h"
#include "ui_MainWindow.h"

KeyStatus::KeyStatus(): pKeyCodeMap(new KeyCodeMap())
{
    pKeyCodeMap->insert(Qt::Key_W, OffsetDirect::TRANSLATION_UP);
    pKeyCodeMap->insert(Qt::Key_S, OffsetDirect::TRANSLATION_DOWN);
    pKeyCodeMap->insert(Qt::Key_A, OffsetDirect::TRANSLATION_LEFT);
    pKeyCodeMap->insert(Qt::Key_D, OffsetDirect::TRANSLATION_RIGHT);
    pKeyCodeMap->insert(Qt::Key_Q, OffsetDirect::ROTATION_LEFT);
    pKeyCodeMap->insert(Qt::Key_E, OffsetDirect::ROTATION_RIGHT);
}

KeyStatus::~KeyStatus()
{
    delete pKeyCodeMap;
}

void KeyStatus::setPress(int keyCode)
{
    keyPress[(int)pKeyCodeMap->value(keyCode)] = true;
}

void KeyStatus::setRelease(int keyCode)
{
    keyPress[(int)pKeyCodeMap->value(keyCode)] = false;
}

void KeyStatus::reset()
{
    for (int direct = 0; direct < ShapeOffset::DIRECT_COUNT; direct++)
    {
        keyPress[direct] = false;
    }
}

const bool* KeyStatus::getKeyPress()
{
    return keyPress;
}

WindowTimers::WindowTimers(): pFrameTimer(new QTimer())
{
    pFrameTimer->setInterval(FRAME_INTERVAL);
    pFrameTimer->start();
}

WindowTimers::~WindowTimers()
{
    delete pFrameTimer;
}

const QTimer* WindowTimers::getFrameTimer()
{
    return pFrameTimer;
}

MainWindow::MainWindow(QWidget* parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    pShapeOffset = new ShapeOffset();
    pKeyStatus = new KeyStatus();
    pWindowTimers = new WindowTimers();

    ui->setupUi(this);
    ui->pGraphicWidget->setShapeOffset(pShapeOffset);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete pShapeOffset;
    delete pKeyStatus;
    delete pWindowTimers;
}

void MainWindow::keyPressEvent(QKeyEvent* pKeyEvent)
{
    pKeyStatus->setPress(pKeyEvent->key());
}

void MainWindow::keyReleaseEvent(QKeyEvent* pKeyEvent)
{
    pKeyStatus->setRelease(pKeyEvent->key());
}

void MainWindow::init()
{
    connect(pWindowTimers->getFrameTimer(), &QTimer::timeout, this, [=]()
    {
        pShapeOffset->update(pKeyStatus->getKeyPress());
        ui->pGraphicWidget->update();
    });
    pKeyStatus->reset();
}