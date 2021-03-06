#include "Polygon.h"

Polygon::Polygon ()
{

}

Polygon::Polygon (const QList<double> &edge, const QList<double> &angle)
    : _edge (edge), _angle (angle)
{
    calcInternal ();
}

Polygon::~Polygon ()
{

}

double Polygon::area ()
{
    double s = 0;

    s += 0.5 * _edge[0] * _edge[1] * sin (_angle[0] * PI / 180);

    if (_edge.size () < 3)
        return s;

    s += 0.5 * _iEdge[0] * _edge[2] * sin (_iAngle[0]);

    if (_edge.size() < 4)
        return s;

    for (int i = 0; i < _edge.size () - 3; ++i)
        s += 0.5 * _iEdge[i + 1] * _edge[i + 3] * sin (_iAngle[i + 1]);
    return s;

}

double Polygon::perimetr ()
{
    double p = 0;
    for (int i = 0; i < _edge.size (); ++i)
    {
        p += _edge[i];
    }
    p += _iEdge.back();
    return p;
}

QString Polygon::toString ()
{
    QString str ("Polygon: ");
    for (int i = 0; i < _edge.size (); ++i)
    {
        str += QString("edge[%1]: %2 ")
                .arg(i)
                .arg (_edge[i]);
    }
    for (int i = 0; i < _angle.size (); ++i)
    {
        str += QString("angle[%1]: %2 ")
                .arg(i)
                .arg (_angle[i]);
    }
    return str;

}

void Polygon::calcInternal ()
{
    _iEdge.append(sqrt (_edge[0] * _edge[0] + _edge[1] * _edge[1] - 2 * _edge[0] * _edge[1] * cos (_angle[0] * PI / 180)));
    if (_edge.size () > 2)
    {
        _iAngle.append (_angle[1] * PI / 180 - asin (_edge[0] * sin (_angle[0] * PI / 180) / _iEdge[0]));
        _iEdge.append (sqrt (_iEdge[0] * _iEdge[0] + _edge[2] * _edge[2] - 2 * _iEdge[0] * _edge[2] * cos (_iAngle[0])));
        for (int i = 0; i < _edge.size () - 3; ++i)
        {
            _iAngle.append (_angle[i + 2] * PI / 180 - asin (_iEdge[i] * sin (_iAngle[i]) / _iEdge[i + 1]));
            _iEdge.append (sqrt (_iEdge[i + 1] * _iEdge[i + 1] + _edge[i + 3] * _edge[i + 3] - 2 * _iEdge[i + 1] * _edge[i + 3] * cos (_iAngle[i + 1])));
        }
    }
}
