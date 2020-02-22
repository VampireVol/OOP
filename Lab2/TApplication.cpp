#include "TApplication.h"

TApplication::TApplication ()
{

}

int TApplication::exec ()
{
    int ch;
    number a, b, c;
    Polynom p;

    while (true)
    {
        menu ();
        cin >> ch;
        if (0 == ch) break;
        switch (ch) {
        case 1:
        {
            cout << "Write a b c: ";
            cin >> a >> b >> c;
            p = Polynom (a, b, c);
            break;
        }
        case 2:
        {
            number x[2];
            int roots;
            roots = p.roots (x);
            if (roots == 2) {
                cout << "x1 = " << x[0] << " x2 = " << x[1] << endl;
            } else if (roots == 1) {
                cout << "x1, x2 = " << x[0] << endl;
            } else {
                cout << "roots not found" << endl;
            }
            break;
        }
        case 3:
            cout << p << endl;
            break;
        default:
            break;
        }
        cout << endl;
    }

    return 0;
}

void TApplication::menu ()
{
    cout << "1 Create polynom"  << endl
         << "2 Calc roots"      << endl
         << "3 Print polynom"   << endl
         << "Choice: ";
}
