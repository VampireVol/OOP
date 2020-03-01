#ifndef INTERFACE_H
#define INTERFACE_H

#include <QWidget>
#include "Sample.h"
#include "Target.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Interface; }
QT_END_NAMESPACE

class Interface : public QWidget
{
    Q_OBJECT

public:
    Interface(QWidget *parent = nullptr);
    ~Interface();
public slots:
    void setResult (const double &res);
signals:
    void sendSampleData (const SampleData &data);
    void sendCheckData (const CheckData &data);
private slots:
    void slotSampleType ();
    void slotCheckType ();
    void slotAddButton ();
    void slotCheck ();
private:
    Ui::Interface *ui;
};
#endif // INTERFACE_H
