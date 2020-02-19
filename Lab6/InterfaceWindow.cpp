#include "InterfaceWindow.h"
#include "ui_InterfaceWindow.h"

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

    _ui->_lineEditX->setText ("0");
    _ui->_lineEditY->setText ("0");
}

InterfaceWindow::~InterfaceWindow ()
{
    delete _ui;
}

void InterfaceWindow::slotAddButton ()
{
    if (_ui->_triangleButton->isChecked ())
    {
        SampleData data (SampleData::Triangle,
                         _ui->_lineEditX->text ().toDouble (),
                         _ui->_lineEditY->text ().toDouble ());
        emit sendData (data);
    }
    else if (_ui->_isoscelesTriangleButton->isChecked ())
    {
        SampleData data (SampleData::IsoscelesTriangle,
                         _ui->_lineEditX->text ().toDouble (),
                         _ui->_lineEditY->text ().toDouble ());
        emit sendData (data);
    }
    else if (_ui->_equilateralTriangleButton->isChecked ())
    {
        SampleData data (SampleData::EquilateralTriangle,
                         _ui->_lineEditX->text ().toDouble (),
                         _ui->_lineEditY->text ().toDouble ());
        emit sendData (data);
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

