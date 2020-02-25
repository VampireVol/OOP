#ifndef TINTERFACE_H
#define TINTERFACE_H

#include <QWidget>
//#include "Polynom.h"
//#include "Number.h"

QT_BEGIN_NAMESPACE
namespace Ui { class TInterface; }
QT_END_NAMESPACE

class TInterface : public QWidget
{
    Q_OBJECT

public:
    TInterface (QWidget *parent = nullptr);
    ~TInterface ();
signals:
    void sendData (QByteArray &data);
public slots:
    void slotSetLabel (const QString &str);
private slots:
    void slotShow ();
    void slotCalc ();

private:
    Ui::TInterface *ui;
//    Polynom _p;
};
#endif // TINTERFACE_H
