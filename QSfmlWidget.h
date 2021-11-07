#ifndef QSFMLWIDGET_H
#define QSFMLWIDGET_H

#include <QObject>
#include <QTimer>
#include <QWidget>
#include <SFML/Graphics.hpp>

class QSfmlWidget : public QWidget, public sf::RenderWindow
{
    Q_OBJECT

public:
    explicit QSfmlWidget(QWidget *parent = nullptr);

    virtual QPaintEngine * paintEngine() const override;
    virtual void showEvent(QShowEvent *event) override;
    virtual void paintEvent(QPaintEvent *event) override;
    virtual void onInit();
    virtual void onUpdate();

private:
    QTimer m_timer;
    bool m_initialized;
};

#endif // QSFMLWIDGET_H
