#include <QCoreApplication>
#include "Triangle.h"
#include "Square.h"
#include <QList>
#include <QTextStream>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QList<Polygon*> figs;
    figs.append (new Square (5));
    figs.append (new Triangle (3.5, 10, 30));
    figs.append (new Rhombus (5, 60));
    figs.append (new Rectangle (8, 6));
    figs.append (new Quadrangle (6, 7, 5, 8, 45, 30));
    figs.append (new Parallelogram (4, 6, 60));
    QTextStream out (stdout);
    for (Polygon *fig : figs)
    {
        out << fig->toString ()                    << endl
            << "area: "        << fig->area ()     << endl
            << "perimetr: "    << fig->perimetr () << endl << endl;
    }


    return a.exec();
}
