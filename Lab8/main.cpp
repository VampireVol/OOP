#include <QCoreApplication>
#include "Triangle.h"
#include "Square.h"
#include <QList>
#include <QTextStream>
#include <QDebug>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QList<Polygon*> figs;
    figs.append (new Square (5));
    figs.append (new Triangle (30, 30, 60));
    figs.append (new Rhombus (5, 60));
    figs.append (new Rectangle (8, 6));
    figs.append (new Quadrangle (6, 7, 5, 45, 30));
    figs.append (new Parallelogram (4, 6, 60));
    QList<double> edgPoly {6, 6, 6, 6, 6};
    QList<double> angPoly {120, 120, 120, 120, 120};
    figs.append (new Polygon (edgPoly, angPoly));
    for (Polygon *fig : figs)
    {
        qDebug () << qPrintable (fig->toString ())          << endl
                  << "area: "        << fig->area ()        << endl
                  << "perimetr: "    << fig->perimetr ()    << endl;
    }


    return a.exec();
}
