#include "Interface.h"
#include "ui_Interface.h"
#include <QDebug>

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
    connect (ui->_addButton, &QPushButton::clicked,
             this, &Interface::slotAddButton);
    connect (ui->_check, &QPushButton::clicked,
             this, &Interface::slotCheck);

}

Interface::~Interface ()
{
    delete ui;
}

void Interface::setResult(const double &res)
{
    ui->_result->setText (QString ("Result: " + QString::number (res * 100) + "%"));
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
        ui->_i->setText ("i");
        ui->_jSpinBox->setHidden (false);
        ui->_j->setHidden (false);
    }
    else {
        ui->_i->setText ("Count");
        ui->_jSpinBox->setHidden (true);
        ui->_j->setHidden (true);
    }
}

void Interface::slotAddButton ()
{
    if (ui->_rectangleRadio->isChecked ()) {
        SampleData data (SampleData::Rectangle,
                         QPointF(ui->_x0DoubleSpinBox->value (), ui->_y0DoubleSpinBox->value ()),
                         ui->_aDoubleSpinBox->value (),
                         ui->_bDoubleSpinBox->value ());
        emit sendSampleData (data);
    }
    else if (ui->_squareRadio->isChecked ()) {
        SampleData data (SampleData::Square,
                         QPointF(ui->_x0DoubleSpinBox->value (), ui->_y0DoubleSpinBox->value ()),
                         ui->_aDoubleSpinBox->value ());
        qDebug () << ui->_aDoubleSpinBox->text() << " " << ui->_aDoubleSpinBox->value ();
        emit sendSampleData (data);
    }
    else if (ui->_ellipseRadio->isChecked ()) {
        SampleData data (SampleData::Ellipse,
                         QPointF(ui->_x0DoubleSpinBox->value (), ui->_y0DoubleSpinBox->value ()),
                         ui->_aDoubleSpinBox->value (),
                         ui->_bDoubleSpinBox->value ());
        emit sendSampleData (data);
    }
    else if (ui->_circleRadio->isChecked ()) {
        SampleData data (SampleData::Circle,
                         QPointF(ui->_x0DoubleSpinBox->value (), ui->_y0DoubleSpinBox->value ()),
                         ui->_aDoubleSpinBox->value ());
        emit sendSampleData (data);
    }
}

void Interface::slotCheck ()
{
    if (ui->_regularRadio->isChecked ()) {
        CheckData data (CheckData::Regular,
                        ui->_wDoubleSpinBox->value (),
                        ui->_hDoubleSpinBox->value (),
                        ui->_iSpinBox->value (),
                        ui->_jSpinBox->value ());
        emit sendCheckData (data);
    }
    else {
        CheckData data (CheckData::Random,
                        ui->_wDoubleSpinBox->value (),
                        ui->_hDoubleSpinBox->value (),
                        ui->_iSpinBox->value ());
        emit sendCheckData (data);
    }
}

