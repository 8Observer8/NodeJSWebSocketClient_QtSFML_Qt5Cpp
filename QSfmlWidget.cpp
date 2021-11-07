#include "QSfmlWidget.h"

QSfmlWidget::QSfmlWidget(QWidget *parent)
    : QWidget(parent)
    , m_initialized(false)
{
    setAttribute(Qt::WA_PaintOnScreen);
    setAttribute(Qt::WA_OpaquePaintEvent);
    setAttribute(Qt::WA_NoSystemBackground);

    setFocusPolicy(Qt::StrongFocus);
}

QPaintEngine *QSfmlWidget::paintEngine() const
{
    return nullptr;
}

void QSfmlWidget::showEvent(QShowEvent *event)
{
    Q_UNUSED(event);

    if (!m_initialized)
    {
        sf::RenderWindow::create(reinterpret_cast<sf::WindowHandle>(winId()));

        onInit();

        connect(&m_timer, SIGNAL(timeout()), this, SLOT(repaint()));
        m_timer.start();
        m_initialized = true;
    }
}

void QSfmlWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    RenderWindow::clear(sf::Color::White);
    onUpdate();
    RenderWindow::display();
}

void QSfmlWidget::onInit()
{
    // To be overriden
}

void QSfmlWidget::onUpdate()
{
    // To be overriden
}
