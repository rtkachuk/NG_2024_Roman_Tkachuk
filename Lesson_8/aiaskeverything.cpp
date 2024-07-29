#include "aiaskeverything.h"
#include "ui_aiaskeverything.h"

AIAskEverything::AIAskEverything(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AIAskEverything)
{
    ui->setupUi(this);

    m_manager = new QNetworkAccessManager();

    ui->te_answer->setReadOnly(true);

    connect (ui->b_ask, &QPushButton::clicked, this, &AIAskEverything::askAi);
    connect (m_manager, &QNetworkAccessManager::finished, this, &AIAskEverything::newAnswer);
}

AIAskEverything::~AIAskEverything()
{
    delete ui;
}

void AIAskEverything::askAi()
{
    QNetworkRequest request(QUrl("http://127.0.0.1:11434/api/generate"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QJsonObject json;
    json["model"] = "llama3.1:8b";
    json["prompt"] = ui->te_question->toPlainText();
    json["stream"] = false;

    QNetworkReply *reply = m_manager->post(request, QJsonDocument(json).toJson());
}

void AIAskEverything::newAnswer(QNetworkReply *reply)
{
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray textReply = reply->readAll();
        qDebug() << textReply;
        QString text = QJsonDocument::fromJson(textReply).object().value("response").toString();
        ui->te_answer->setText(text);
    } else {
        qDebug() << "Error: " << reply->errorString();
    }
}
