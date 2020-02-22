#ifndef TINTERFACE_H
#define TINTERFACE_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class TInterface; }
QT_END_NAMESPACE

class TInterface : public QWidget
{
    Q_OBJECT

public:
    TInterface(QWidget *parent = nullptr);
    ~TInterface();

private:
    Ui::TInterface *ui;
};
#endif // TINTERFACE_H
