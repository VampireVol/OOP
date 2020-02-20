#include "InterfaceWindow.h"
#include "ui_InterfaceWindow.h"
#include <QDebug>

InterfaceWindow::InterfaceWindow (QWidget *parent)
    : QWidget (parent)
    , _ui (new Ui::InterfaceWindow)
{
    _ui->setupUi(this);
    connect (_ui->_addButton, &QPushButton::clicked,
             this, &InterfaceWindow::slotAddButton);
    _ui->_addButton->setEnabled (false);

    connect (_ui->_triangleButton, &QRadioButton::clicked,
             this, &InterfaceWindow::enableAddButton);
    connect (_ui->_isoscelesTriangleButton, &QRadioButton::clicked,
             this, &InterfaceWindow::enableAddButton);
    connect (_ui->_equilateralTriangleButton, &QRadioButton::clicked,
             this, &InterfaceWindow::enableAddButton);

    connect (_ui->_triangleButton, &QRadioButton::clicked,
             this, &InterfaceWindow::switchLineEdit);
    connect (_ui->_isoscelesTriangleButton, &QRadioButton::clicked,
             this, &InterfaceWindow::switchLineEdit);
    connect (_ui->_equilateralTriangleButton, &QRadioButton::clicked,
             this, &InterfaceWindow::switchLineEdit);

    _ui->_lineEditX->setText ("0");
    _ui->_lineEditY->setText ("0");
    _ui->_lineEditA->setText ("0");
    _ui->_lineEditB->setText ("0");
    _ui->_lineEditC->setText ("0");
    _ui->_lineEditA->setEnabled (false);
    _ui->_lineEditB->setEnabled (false);
    _ui->_lineEditC->setEnabled (false);
}

InterfaceWindow::~InterfaceWindow ()
{
    delete _ui;
}

void InterfaceWindow::setPivot (int x, int y)
{
    _ui->_lineEditX->setText (QString::number (x));
    _ui->_lineEditY->setText (QString::number (y));
}

void InterfaceWindow::slotAddButton ()
{
    if (_ui->_triangleButton->isChecked ())
    {
        double a = _ui->_lineEditA->text ().toDouble ();
        double b = _ui->_lineEditB->text ().toDouble ();
        double c = _ui->_lineEditC->text ().toDouble ();
        if (a >= b + c || b >= a + c || c >= a + b) {
            qDebug () << "[InterfaceWindow][slotAddButton] abc not corret";
            return;
        }
        SampleData data (SampleData::Triangle,
                         _ui->_lineEditX->text ().toInt (),
                         _ui->_lineEditY->text ().toInt (),
                         _ui->_lineEditA->text ().toDouble (),
                         _ui->_lineEditB->text ().toDouble (),
                         _ui->_lineEditC->text ().toDouble ());
        emit sendData (data);
        emit printNext ();
    }
    else if (_ui->_isoscelesTriangleButton->isChecked ())
    {
        double a = _ui->_lineEditA->text ().toDouble ();
        double b = _ui->_lineEditB->text ().toDouble ();
        if (a >= 2 * b) {
            qDebug () << "[InterfaceWindow][slotAddButton] ab not corret";
            return;
        }
        SampleData data (SampleData::IsoscelesTriangle,
                         _ui->_lineEditX->text ().toInt (),
                         _ui->_lineEditY->text ().toInt (),
                         _ui->_lineEditA->text ().toDouble (),
                         _ui->_lineEditB->text ().toDouble (),
                         _ui->_lineEditB->text ().toDouble ());
        emit sendData (data);
        emit printNext ();
    }
    else if (_ui->_equilateralTriangleButton->isChecked ())
    {
        SampleData data (SampleData::EquilateralTriangle,
                         _ui->_lineEditX->text ().toInt (),
                         _ui->_lineEditY->text ().toInt (),
                         _ui->_lineEditA->text ().toDouble (),
                         _ui->_lineEditA->text ().toDouble (),
                         _ui->_lineEditA->text ().toDouble ());
        emit sendData (data);
        emit printNext ();
    }
}

void InterfaceWindow::enableAddButton ()
{
    _ui->_addButton->setEnabled (true);
    disconnect (_ui->_triangleButton, &QRadioButton::clicked,
               this, &InterfaceWindow::enableAddButton);
    disconnect (_ui->_isoscelesTriangleButton, &QRadioButton::clicked,
               this, &InterfaceWindow::enableAddButton);
    disconnect (_ui->_equilateralTriangleButton, &QRadioButton::clicked,
               this, &InterfaceWindow::enableAddButton);

}

void InterfaceWindow::switchLineEdit ()
{
    if (_ui->_triangleButton->isChecked ())
    {
        _ui->_lineEditA->setEnabled (true);
        _ui->_lineEditB->setEnabled (true);
        _ui->_lineEditC->setEnabled (true);
    }
    else if (_ui->_isoscelesTriangleButton->isChecked ())
    {
        _ui->_lineEditA->setEnabled (true);
        _ui->_lineEditB->setEnabled (true);
        _ui->_lineEditC->setEnabled (false);
    }
    else if (_ui->_equilateralTriangleButton->isChecked ())
    {
        _ui->_lineEditA->setEnabled (true);
        _ui->_lineEditB->setEnabled (false);
        _ui->_lineEditC->setEnabled (false);
    }
    else
    {
        _ui->_lineEditA->setEnabled (false);
        _ui->_lineEditB->setEnabled (false);
        _ui->_lineEditC->setEnabled (false);
    }
}

