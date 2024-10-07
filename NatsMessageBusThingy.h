#ifndef NATS_MESSAGE_BUS_THINGY_H
#define NATS_MESSAGE_BUS_THINGY_H

#include <QObject>

#include "natsclient.h"

#include "MessageBusInterface.h"

class NatsMessageBusThingy : public QObject, public MessageBusInterface
{
    Q_OBJECT
public:
    void connectToServer(const std::string& address) override;
    void publish(const std::string& address, const std::string& message) override;
    void subscribe(const std::string& address, std::function<void(const std::string&)> cb) override;

private:
    Nats::Client m_client;
};

#endif //NATS_MESSAGE_BUS_THINGY_H
