
#include <QtCore/QJsonDocument>
#include <QtCore/QJsonObject>

#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QSfmlWidget(parent)
{
    setWindowTitle("Qt SFML WebSocket Client");
    setFixedSize(QSize(350, 350));

    connect(&m_webSocket, &QWebSocket::connected, this, &MainWindow::onConnected);
    connect(&m_webSocket, &QWebSocket::textMessageReceived, this, &MainWindow::onMessageReceived);

//    QUrl url("ws://localhost:3000");
    QUrl url("ws://nodejs-websocket-server-js.herokuapp.com");
    m_webSocket.open(url);
}

void MainWindow::onInit()
{
    m_rect.setPosition(50, 100);
    m_rect.setSize(sf::Vector2f(100, 50));
    m_rect.setFillColor(sf::Color::Green);
}

void MainWindow::onUpdate()
{
    sf::RenderWindow::draw(m_rect);
}

void MainWindow::onConnected()
{
    qDebug() << "Connection";

    // Send a message to a server
    QJsonObject jsonObject;
    jsonObject["msg"] = "Hello, server!";
    QJsonDocument doc(jsonObject);
    QString strJson(doc.toJson(QJsonDocument::Compact));
    m_webSocket.sendTextMessage(strJson);
}

void MainWindow::onMessageReceived(const QString &message)
{
    qDebug() << message; // Output: "{\"msg\":\"Hello, client!\"}"
    QJsonDocument doc(QJsonDocument::fromJson(message.toUtf8()));
    QJsonObject data = doc.object();
    qDebug() << data["msg"].toString(); // Output: "Hello, client!"
}
