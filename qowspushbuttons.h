#ifndef QOWSPUSHBUTTONS_H
#define QOWSPUSHBUTTONS_H

#include <QWidget>
#include <QGroupBox>
#include <QPushButton>
#include <QHBoxLayout>

class QOWSPushButtons : public QGroupBox
{
    Q_OBJECT

private:
    QPushButton *btnOn;
    QPushButton *btnOff;

public:
    QOWSPushButtons(QWidget *parent = 0);

private slots:
    void setPressed(bool bChecked);
};

#endif // QOWSPUSHBUTTONS_H
