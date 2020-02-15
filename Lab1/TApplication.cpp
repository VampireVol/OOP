#include "TApplication.h"

TApplication::TApplication ()
{

}

int TApplication::exec ()
{
    int ch;

    while (true)
    {
        cin >> ch;
        if (0 == ch) break;
        switch (ch) {
        case 1:
        {
            number a, b, c;
            cin >> a >> b >> c;
            Polynom p (a, b, c);
            number x[2];
            int roots;
            roots = p.roots (x);
            cout << p << endl;
            cout << x[0] << x[1];
            break;
        }
        default:
            break;
        }
    }

    Polynom p (1, 2, 3);

    cout << p << endl;

    return 0;
}
