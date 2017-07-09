#include "translator_page.h"
#include <QLabel>
#include <QPushButton>
#include <QDebug>

TranslatorPage::TranslatorPage(QWidget *parent)
    :QWidget(parent)
{
    layout = new QVBoxLayout;
    hLayout = new QHBoxLayout;
    original = new QPlainTextEdit;
    translator = new QPlainTextEdit;
    http = new QNetworkAccessManager(this);

    QLabel *tips1 = new QLabel("原文");
    QLabel *tips2 = new QLabel("译文");

    QPushButton *trBtn = new QPushButton("翻译");
    hLayout->addWidget(trBtn);

    translator->setReadOnly(true);

    layout->addWidget(tips1);
    layout->addWidget(original);
    layout->addSpacing(10);
    layout->addLayout(hLayout);
    layout->addSpacing(10);
    layout->addWidget(tips2);
    layout->addWidget(translator);

    setLayout(layout);

    tips1->setStyleSheet("color: #BCBCBC");
    tips2->setStyleSheet("color: #BCBCBC");
    this->setStyleSheet("QPlainTextEdit { border: 1px solid #505050; font-size: 17px; padding: 5px;}");

    connect(http, SIGNAL(finished(QNetworkReply *)), this, SLOT(replyfinished(QNetworkReply *)));
    connect(trBtn, SIGNAL(clicked()), this, SLOT(on_translator_clicked()));
}

void TranslatorPage::on_translator_clicked()
{
    QNetworkRequest request;
    request.setUrl(QUrl("http://fanyi.youdao.com/openapi.do?keyfrom=YouDaoCV&key=659600698&type=data&doctype=json&version=1.1&q=" + original->toPlainText()));
    http->get(request);
}

void TranslatorPage::replyfinished(QNetworkReply *reply)
{
    QJsonDocument json;
    QJsonObject object;

    QByteArray wordInformation = reply->readAll();

    json = QJsonDocument::fromJson(wordInformation);

    if (!json.isNull())
    {
        object = json.object();

        translator->setPlainText(object.value("translation").toArray().at(0).toString());
    }
}