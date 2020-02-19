#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "Sample.h"

QT_BEGIN_NAMESPACE
namespace Ui { class InterfaceWindow; }
QT_END_NAMESPACE

class InterfaceWindow : public QWidget
{
    Q_OBJECT

public:
    InterfaceWindow (QWidget *parent = nullptr);
    ~InterfaceWindow ();
signals:
    void sendData (SampleData &data);
private slots:
    void slotAddButton ();
    void enableAddButton ();

private:
    Ui::InterfaceWindow *_ui;
};
#endif // WIDGET_H
