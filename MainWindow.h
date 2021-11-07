#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWebSockets/QWebSocket>

#include "QSfmlWidget.h"

class MainWindow : public QSfmlWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    void onInit() override;
    void onUpdate() override;

private slots:
    void onConnected();
    void onMessageReceived(const QString &message);

private:
    sf::RectangleShape m_rect;
    QWebSocket m_webSocket;
};
#endif // MAINWINDOW_H
