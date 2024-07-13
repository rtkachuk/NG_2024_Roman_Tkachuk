#include "client.h"
#include "ui_client.h"

Client::Client(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Client)
{
    ui->setupUi(this);
    m_socket = new QTcpSocket();

    ui->sb_port->setMaximum(16000);
    ui->te_chat->setReadOnly(true);

    connect (ui->b_login, &QPushButton::clicked, this, &Client::login);
    connect (ui->b_send, &QPushButton::clicked, this, &Client::sendMessage);
    connect (m_socket, &QTcpSocket::connected, this, &Client::connectionEstablished);
    connect (m_socket, &QTcpSocket::readyRead, this, &Client::MessageReceived);
}

Client::~Client()
{
    delete ui;
}

void Client::login()
{
    QString address = ui->e_address->text();
    int port = ui->sb_port->value();

    m_socket->connectToHost(QHostAddress(address),port);
}

void Client::connectionEstablished()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void Client::sendMessage()
{
    m_socket->write(ui->te_input->toPlainText().toLocal8Bit());
    ui->te_input->clear();
}

void Client::MessageReceived()
{
    ui->te_chat->append(QString(m_socket->readAll()));
}
