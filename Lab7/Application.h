#ifndef APPLICATION_H
#define APPLICATION_H
#include <QApplication>
#include <QList>

#include "Interface.h"
#include "Sample.h"
#include "Square.h"
#include "Circle.h"
#include "Target.h"


class Application : public QApplication
{
public:
    Application (int & argc ,char** argv);
    ~Application ();

    int exec ();
private slots:
    void slotAddSample (const SampleData &data);
private:
    QList<Sample*> _list;
    Interface *_interface {nullptr};
    Target *_target {nullptr};
};

#endif // APPLICATION_H
