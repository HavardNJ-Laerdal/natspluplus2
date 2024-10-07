#include <QCoreApplication>
#include <QDebug>
#include <QTimer>
#include <QObject>

#include "NatsMessageBusThingy.h"

#include <iostream>

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);

    NatsMessageBusThingy natsMessageBusThingy;
    natsMessageBusThingy.connectToServer("localhost:4222");

    QTimer timer;
    QObject::connect(&timer, &QTimer::timeout, [&]() {
        natsMessageBusThingy.publish("com.laerdal.simulation.vitalstate/v1", R"({"hello":"again"})");
    });
    timer.start(5000);

    natsMessageBusThingy.subscribe("com.laerdal.simulation.vitalstate/v1", [](const std::string& message) {
        qDebug() << "received message: " << QString::fromStdString(message);
    });

    return app.exec();
}