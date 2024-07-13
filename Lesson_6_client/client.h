#ifndef CLIENT_H
#define CLIENT_H

#include <QMainWindow>
#include <QTcpSocket>

QT_BEGIN_NAMESPACE
namespace Ui {
class Client;
}
QT_END_NAMESPACE

class Client : public QMainWindow
{
    Q_OBJECT

public:
    Client(QWidget *parent = nullptr);
    ~Client();

private slots:
    void login();
    void connectionEstablished();
    void sendMessage();
    void MessageReceived();

private:
    Ui::Client *ui;
    QTcpSocket *m_socket;
};
#endif // CLIENT_H
