#include "NatsMessageBusThingy.h"

#include <string>
#include <functional>

void NatsMessageBusThingy::connectToServer(const std::string& address){

    QObject::connect(&m_client, &Nats::Client::error, [](const QString &error)
    {
        qDebug() << error;
    });

    QObject::connect(&m_client, &Nats::Client::connected, []
    {
        qDebug() << "Nats connected";
    });

    QObject::connect(&m_client, &Nats::Client::disconnected, []
    {
        qDebug() << "Nats disconnected";
    });

    QStringList urlAndPort = QString::fromStdString(address).split(":");
    QString url = urlAndPort[0];
    auto port = (quint16)urlAndPort[1].toUInt();
    qDebug() << "connecting to: " << url << " on port: " << port;
    m_client.connect(url, port);
}
    
void NatsMessageBusThingy::publish(const std::string& address, const std::string& message){
    qDebug() << "sending message: " << QString::fromStdString(message) << " to: " << QString::fromStdString(address);
    m_client.publish(QString::fromStdString(address), QString::fromStdString(message));
}

void NatsMessageBusThingy::subscribe(const std::string& address, std::function<void(const std::string&)> cb){
    m_client.subscribe(QString::fromStdString(address), [&](const QString& message, const QString& inbox, const QString& subject){
        qDebug() << "received message: " << message << " inbox: " << inbox << " subject: " << subject;
        cb(message.toStdString());
    }); 
}