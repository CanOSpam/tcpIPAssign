/********************************************************************************
** Form generated from reading UI file 'TCPIPassign.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TCPIPASSIGN_H
#define UI_TCPIPASSIGN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TCPIPassignClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_7;
    QComboBox *hostSelectCombo;
    QPushButton *startServerButton;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TCPIPassignClass)
    {
        if (TCPIPassignClass->objectName().isEmpty())
            TCPIPassignClass->setObjectName(QStringLiteral("TCPIPassignClass"));
        TCPIPassignClass->resize(195, 110);
        centralWidget = new QWidget(TCPIPassignClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_3 = new QVBoxLayout(centralWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_7);

        hostSelectCombo = new QComboBox(centralWidget);
        hostSelectCombo->setObjectName(QStringLiteral("hostSelectCombo"));
        hostSelectCombo->setMaxVisibleItems(2);

        verticalLayout_3->addWidget(hostSelectCombo);

        startServerButton = new QPushButton(centralWidget);
        startServerButton->setObjectName(QStringLiteral("startServerButton"));

        verticalLayout_3->addWidget(startServerButton);

        TCPIPassignClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(TCPIPassignClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        TCPIPassignClass->setStatusBar(statusBar);

        retranslateUi(TCPIPassignClass);

        QMetaObject::connectSlotsByName(TCPIPassignClass);
    } // setupUi

    void retranslateUi(QMainWindow *TCPIPassignClass)
    {
        TCPIPassignClass->setWindowTitle(QApplication::translate("TCPIPassignClass", "TCPIPassign", 0));
        label_7->setText(QApplication::translate("TCPIPassignClass", "Host type", 0));
        hostSelectCombo->clear();
        hostSelectCombo->insertItems(0, QStringList()
         << QApplication::translate("TCPIPassignClass", "Server", 0)
         << QApplication::translate("TCPIPassignClass", "Client", 0)
        );
        startServerButton->setText(QApplication::translate("TCPIPassignClass", "Start", 0));
    } // retranslateUi

};

namespace Ui {
    class TCPIPassignClass: public Ui_TCPIPassignClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TCPIPASSIGN_H
