#include "qowspushbuttons.h"

#include <QDebug>
#include <QStringList>

QOWSPushButtons::QOWSPushButtons(QWidget *parent) :
    QGroupBox (parent)
{
    QStringList style;
    style << "QPushButton{"
          << "border: 1px solid #000;"
          << "background: rgb(115,115,115);"
          << "padding-left:10px;"
          << "margin-left: 2px;"
          << "text-align:left;"
          << "color: #FFF;"
          << "}"
          << "QPushButton:checked{"
          << "background: rgb(80,80,80);"
          << "border-right-style: none;"
          << "margin-left: 0px;"
          << "}";

    btnOn = new QPushButton();
    btnOn->setCheckable(true);
    btnOn->setAutoFillBackground(true);
    btnOn->setText("On"/*"Вкл."*/);
    btnOn->setFocusPolicy(Qt::NoFocus);
    btnOn->setFixedSize(QSize(100, 25));
    btnOn->setStyleSheet(style.join("\n"));

    btnOff = new QPushButton();
    btnOff->setCheckable(true);
    btnOff->setAutoFillBackground(true);
    btnOff->setText("Off"/*"Выкл."*/);
    btnOff->setFocusPolicy(Qt::NoFocus);
    btnOff->setFixedSize(QSize(100, 25));
    btnOff->setStyleSheet(style.join("\n"));

//    setStyleSheet("QComboBox {                   \
//                border: 1px solid gray;   \
//                border-radius: 3px;       \
//                padding: 1px 18px 1px 3px;\
//                min-width: 6em;}          \
//            QComboBox::drop-down {                                              \
//                subcontrol-origin: padding;                                     \
//                subcontrol-position: top right;                                 \
//                width: 40px;                                                    \
//                background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #CECECE, stop:1 #B7B7B7);\
//                border-left-width: 1px;                                         \
//                border-left-color: darkgray;                                    \
//                border-left-style: solid;                                       \
//                border-top-right-radius: 3px;                                   \
//                border-bottom-right-radius: 3px;}                               \
//                QComboBox::down-arrow {\
//                image: url(:/icon/arrow_down.png);\
//                }");




    QHBoxLayout *vbox = new QHBoxLayout;
    vbox->setContentsMargins(0, 0, 0, 0);
    vbox->setSpacing(0);
    vbox->addWidget(btnOn);
    vbox->addWidget(btnOff);

    this->setLayout(vbox);

    //connect(this, SIGNAL(toggled(bool)), this, SLOT(setPressed(bool)));

    connect(btnOn, SIGNAL(toggled(bool)), this, SLOT(setPressed(bool)));
    connect(btnOff, SIGNAL(toggled(bool)), this, SLOT(setPressed(bool)));
}
// взаимное исключение нажатия обоих кнопок
void QOWSPushButtons::setPressed(bool bChecked)
{
    qDebug() << "setPressed";
    if (sender() == btnOn){
        qDebug() << "on = " << bChecked;
        if (bChecked && btnOff->isChecked())
            btnOff->setChecked(false);
    }

    if (sender() == btnOff){
        qDebug() << "off = " << bChecked;
        if (bChecked && btnOn->isChecked())
            btnOn->setChecked(false);
    }
}
