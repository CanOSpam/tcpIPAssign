/********************************************************************************
** Form generated from reading UI file 'Client.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENT_H
#define UI_CLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Client
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer_5;
    QLabel *label_5;
    QComboBox *tcpUdpComboBox;
    QSpacerItem *verticalSpacer_4;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_2;
    QLineEdit *bytesPerPacketEdit;
    QLabel *label;
    QLineEdit *numPacketsEdit;
    QSpacerItem *verticalSpacer_8;
    QVBoxLayout *verticalLayout_4;
    QSpacerItem *verticalSpacer_6;
    QLabel *label_3;
    QPushButton *pickFileButton;
    QSpacerItem *verticalSpacer_7;
    QFrame *line;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_7;
    QLineEdit *portEdit;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_6;
    QLineEdit *ipEdit;
    QProgressBar *sendProgress;
    QPushButton *sendButton;

    void setupUi(QWidget *Client)
    {
        if (Client->objectName().isEmpty())
            Client->setObjectName(QStringLiteral("Client"));
        Client->resize(412, 273);
        verticalLayout = new QVBoxLayout(Client);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_5);

        label_5 = new QLabel(Client);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_5);

        tcpUdpComboBox = new QComboBox(Client);
        tcpUdpComboBox->setObjectName(QStringLiteral("tcpUdpComboBox"));
        tcpUdpComboBox->setMaxVisibleItems(2);

        verticalLayout_3->addWidget(tcpUdpComboBox);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_4);


        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        label_2 = new QLabel(Client);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_2->addWidget(label_2);

        bytesPerPacketEdit = new QLineEdit(Client);
        bytesPerPacketEdit->setObjectName(QStringLiteral("bytesPerPacketEdit"));

        verticalLayout_2->addWidget(bytesPerPacketEdit);

        label = new QLabel(Client);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_2->addWidget(label);

        numPacketsEdit = new QLineEdit(Client);
        numPacketsEdit->setObjectName(QStringLiteral("numPacketsEdit"));

        verticalLayout_2->addWidget(numPacketsEdit);

        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_8);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_6);

        label_3 = new QLabel(Client);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_3);

        pickFileButton = new QPushButton(Client);
        pickFileButton->setObjectName(QStringLiteral("pickFileButton"));

        verticalLayout_4->addWidget(pickFileButton);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_7);


        horizontalLayout->addLayout(verticalLayout_4);


        verticalLayout->addLayout(horizontalLayout);

        line = new QFrame(Client);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        label_7 = new QLabel(Client);
        label_7->setObjectName(QStringLiteral("label_7"));

        verticalLayout_7->addWidget(label_7);

        portEdit = new QLineEdit(Client);
        portEdit->setObjectName(QStringLiteral("portEdit"));

        verticalLayout_7->addWidget(portEdit);


        horizontalLayout_2->addLayout(verticalLayout_7);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        label_6 = new QLabel(Client);
        label_6->setObjectName(QStringLiteral("label_6"));

        verticalLayout_6->addWidget(label_6);

        ipEdit = new QLineEdit(Client);
        ipEdit->setObjectName(QStringLiteral("ipEdit"));

        verticalLayout_6->addWidget(ipEdit);


        horizontalLayout_2->addLayout(verticalLayout_6);


        verticalLayout->addLayout(horizontalLayout_2);

        sendProgress = new QProgressBar(Client);
        sendProgress->setObjectName(QStringLiteral("sendProgress"));
        sendProgress->setValue(0);
        sendProgress->setOrientation(Qt::Horizontal);
        sendProgress->setInvertedAppearance(false);

        verticalLayout->addWidget(sendProgress);

        sendButton = new QPushButton(Client);
        sendButton->setObjectName(QStringLiteral("sendButton"));

        verticalLayout->addWidget(sendButton);


        retranslateUi(Client);

        QMetaObject::connectSlotsByName(Client);
    } // setupUi

    void retranslateUi(QWidget *Client)
    {
        Client->setWindowTitle(QApplication::translate("Client", "Client", Q_NULLPTR));
        label_5->setText(QApplication::translate("Client", "Protocol", Q_NULLPTR));
        tcpUdpComboBox->clear();
        tcpUdpComboBox->insertItems(0, QStringList()
         << QApplication::translate("Client", "TCP", Q_NULLPTR)
         << QApplication::translate("Client", "UDP", Q_NULLPTR)
        );
        label_2->setText(QApplication::translate("Client", "Size of each packet in bytes :", Q_NULLPTR));
        bytesPerPacketEdit->setText(QApplication::translate("Client", "16", Q_NULLPTR));
        label->setText(QApplication::translate("Client", "Packets to send :", Q_NULLPTR));
        numPacketsEdit->setText(QApplication::translate("Client", "1", Q_NULLPTR));
        label_3->setText(QApplication::translate("Client", "File to send from", Q_NULLPTR));
        pickFileButton->setText(QApplication::translate("Client", "Pick File", Q_NULLPTR));
        label_7->setText(QApplication::translate("Client", "Port", Q_NULLPTR));
        portEdit->setText(QApplication::translate("Client", "5570", Q_NULLPTR));
        label_6->setText(QApplication::translate("Client", "Destination", Q_NULLPTR));
        ipEdit->setText(QApplication::translate("Client", "127.0.0.1", Q_NULLPTR));
        sendProgress->setFormat(QApplication::translate("Client", "%p%", Q_NULLPTR));
        sendButton->setText(QApplication::translate("Client", "Send UDP / Start TCP Server", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Client: public Ui_Client {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENT_H
