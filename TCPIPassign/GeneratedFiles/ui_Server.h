/********************************************************************************
** Form generated from reading UI file 'Server.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVER_H
#define UI_SERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Server
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_5;
    QComboBox *comboBox;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_3;
    QPushButton *pickFileButton;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_7;
    QLineEdit *portEdit;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_6;
    QLineEdit *ipEdit;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *startButton;
    QPushButton *stopButton;

    void setupUi(QWidget *Server)
    {
        if (Server->objectName().isEmpty())
            Server->setObjectName(QStringLiteral("Server"));
        Server->resize(400, 159);
        verticalLayout = new QVBoxLayout(Server);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_5 = new QLabel(Server);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_5);

        comboBox = new QComboBox(Server);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setMaxVisibleItems(2);

        verticalLayout_3->addWidget(comboBox);


        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_3 = new QLabel(Server);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_3);

        pickFileButton = new QPushButton(Server);
        pickFileButton->setObjectName(QStringLiteral("pickFileButton"));

        verticalLayout_4->addWidget(pickFileButton);


        horizontalLayout->addLayout(verticalLayout_4);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        label_7 = new QLabel(Server);
        label_7->setObjectName(QStringLiteral("label_7"));

        verticalLayout_7->addWidget(label_7);

        portEdit = new QLineEdit(Server);
        portEdit->setObjectName(QStringLiteral("portEdit"));

        verticalLayout_7->addWidget(portEdit);


        horizontalLayout_3->addLayout(verticalLayout_7);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        label_6 = new QLabel(Server);
        label_6->setObjectName(QStringLiteral("label_6"));

        verticalLayout_6->addWidget(label_6);

        ipEdit = new QLineEdit(Server);
        ipEdit->setObjectName(QStringLiteral("ipEdit"));

        verticalLayout_6->addWidget(ipEdit);


        horizontalLayout_3->addLayout(verticalLayout_6);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        startButton = new QPushButton(Server);
        startButton->setObjectName(QStringLiteral("startButton"));

        horizontalLayout_2->addWidget(startButton);

        stopButton = new QPushButton(Server);
        stopButton->setObjectName(QStringLiteral("stopButton"));

        horizontalLayout_2->addWidget(stopButton);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(Server);

        QMetaObject::connectSlotsByName(Server);
    } // setupUi

    void retranslateUi(QWidget *Server)
    {
        Server->setWindowTitle(QApplication::translate("Server", "Server", Q_NULLPTR));
        label_5->setText(QApplication::translate("Server", "Protocol", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("Server", "TCP", Q_NULLPTR)
         << QApplication::translate("Server", "UDP", Q_NULLPTR)
        );
        label_3->setText(QApplication::translate("Server", "File to Save to", Q_NULLPTR));
        pickFileButton->setText(QApplication::translate("Server", "Pick File", Q_NULLPTR));
        label_7->setText(QApplication::translate("Server", "Port", Q_NULLPTR));
        portEdit->setText(QApplication::translate("Server", "0000", Q_NULLPTR));
        label_6->setText(QApplication::translate("Server", "Receive From", Q_NULLPTR));
        ipEdit->setText(QApplication::translate("Server", "000.000.000.000", Q_NULLPTR));
        startButton->setText(QApplication::translate("Server", "Start Listening", Q_NULLPTR));
        stopButton->setText(QApplication::translate("Server", "Stop Listening", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Server: public Ui_Server {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVER_H
