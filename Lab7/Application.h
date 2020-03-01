#ifndef APPLICATION_H
#define APPLICATION_H
#include <QApplication>
#include <QList>

#include "Interface.h"
#include "Sample.h"
#include "Square.h"
#include "Circle.h"


class Application : public QApplication
{
public:
    Application (int & argc ,char** argv);
    ~Application ();

    int exec ();
signals:
    void printNext ();
private slots:
    void slotAddSample (const SampleData &data);
private:
    Interface *_interface {nullptr};
    QList<Sample*> _list;
};

#endif // APPLICATION_H
