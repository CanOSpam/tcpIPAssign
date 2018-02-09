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
    QComboBox *comboBox;
    QSpacerItem *verticalSpacer_4;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QLabel *label;
    QLineEdit *lineEdit;
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
    QLineEdit *lineEdit_4;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_6;
    QLineEdit *lineEdit_3;
    QProgressBar *sendProgress;
    QPushButton *pushButton;

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

        comboBox = new QComboBox(Client);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setMaxVisibleItems(2);

        verticalLayout_3->addWidget(comboBox);

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

        lineEdit_2 = new QLineEdit(Client);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        verticalLayout_2->addWidget(lineEdit_2);

        label = new QLabel(Client);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_2->addWidget(label);

        lineEdit = new QLineEdit(Client);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        verticalLayout_2->addWidget(lineEdit);

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

        lineEdit_4 = new QLineEdit(Client);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));

        verticalLayout_7->addWidget(lineEdit_4);


        horizontalLayout_2->addLayout(verticalLayout_7);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        label_6 = new QLabel(Client);
        label_6->setObjectName(QStringLiteral("label_6"));

        verticalLayout_6->addWidget(label_6);

        lineEdit_3 = new QLineEdit(Client);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));

        verticalLayout_6->addWidget(lineEdit_3);


        horizontalLayout_2->addLayout(verticalLayout_6);


        verticalLayout->addLayout(horizontalLayout_2);

        sendProgress = new QProgressBar(Client);
        sendProgress->setObjectName(QStringLiteral("sendProgress"));
        sendProgress->setValue(0);
        sendProgress->setOrientation(Qt::Horizontal);
        sendProgress->setInvertedAppearance(false);

        verticalLayout->addWidget(sendProgress);

        pushButton = new QPushButton(Client);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);


        retranslateUi(Client);

        QMetaObject::connectSlotsByName(Client);
    } // setupUi

    void retranslateUi(QWidget *Client)
    {
        Client->setWindowTitle(QApplication::translate("Client", "Client", Q_NULLPTR));
        label_5->setText(QApplication::translate("Client", "Protocol", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("Client", "TCP", Q_NULLPTR)
         << QApplication::translate("Client", "UDP", Q_NULLPTR)
        );
        label_2->setText(QApplication::translate("Client", "Size of each packet in bytes :", Q_NULLPTR));
        lineEdit_2->setText(QApplication::translate("Client", "1", Q_NULLPTR));
        label->setText(QApplication::translate("Client", "Packets to send :", Q_NULLPTR));
        lineEdit->setText(QApplication::translate("Client", "1", Q_NULLPTR));
        label_3->setText(QApplication::translate("Client", "File to send from", Q_NULLPTR));
        pickFileButton->setText(QApplication::translate("Client", "Pick File", Q_NULLPTR));
        label_7->setText(QApplication::translate("Client", "Port", Q_NULLPTR));
        lineEdit_4->setText(QApplication::translate("Client", "0000", Q_NULLPTR));
        label_6->setText(QApplication::translate("Client", "Destination", Q_NULLPTR));
        lineEdit_3->setText(QApplication::translate("Client", "000.000.000.000", Q_NULLPTR));
        sendProgress->setFormat(QApplication::translate("Client", "%p%", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Client", "Send", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Client: public Ui_Client {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENT_H
