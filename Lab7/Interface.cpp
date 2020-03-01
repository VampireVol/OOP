#include "Interface.h"
#include "ui_Interface.h"

Interface::Interface(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Interface)
{
    ui->setupUi(this);
    ui->_rectangleRadio->setChecked (true);
    ui->_regularRadio->setChecked (true);
    connect (ui->_rectangleRadio, &QRadioButton::clicked,
             this, &Interface::slotSampleType);
    connect (ui->_squareRadio, &QRadioButton::clicked,
             this, &Interface::slotSampleType);
    connect (ui->_ellipseRadio, &QRadioButton::clicked,
             this, &Interface::slotSampleType);
    connect (ui->_circleRadio, &QRadioButton::clicked,
             this, &Interface::slotSampleType);
    connect (ui->_regularRadio, &QRadioButton::clicked,
             this, &Interface::slotCheckType);
    connect (ui->_randomRadio, &QRadioButton::clicked,
             this, &Interface::slotCheckType);

}

Interface::~Interface ()
{
    delete ui;
}

void Interface::slotSampleType ()
{
    if (ui->_rectangleRadio->isChecked ()) {
        ui->_aDoubleSpinBox->setEnabled (true);
        ui->_bDoubleSpinBox->setEnabled (true);
    }
    else if (ui->_squareRadio->isChecked ()) {
        ui->_aDoubleSpinBox->setEnabled (true);
        ui->_bDoubleSpinBox->setEnabled (false);
    }
    else if (ui->_ellipseRadio->isChecked ()) {
        ui->_aDoubleSpinBox->setEnabled (true);
        ui->_bDoubleSpinBox->setEnabled (true);
    }
    else if (ui->_circleRadio->isChecked ()) {
        ui->_aDoubleSpinBox->setEnabled (true);
        ui->_bDoubleSpinBox->setEnabled (false);
    }
}

void Interface::slotCheckType ()
{
    if (ui->_regularRadio->isChecked ()) {
        ui->_iSpinBox->setEnabled (true);
        ui->_jSpinBox->setEnabled (true);
    }
    else {
        ui->_iSpinBox->setEnabled (false);
        ui->_jSpinBox->setEnabled (false);
    }
}

