#include "TInterface.h"
#include "ui_TInterface.h"

TInterface::TInterface (QWidget *parent)
    : QWidget (parent)
    , ui (new Ui::TInterface)
{
    ui->setupUi(this);
    connect (ui->_show, &QPushButton::clicked, this, &TInterface::slotShow);
    connect (ui->_calc, &QPushButton::clicked, this, &TInterface::slotCalc);
    connect (ui->_doubleType, &QRadioButton::clicked, this, &TInterface::slotTypeChanged);
    connect (ui->_complexType, &QRadioButton::clicked, this, &TInterface::slotTypeChanged);
    ui->_lineEditAR->setText ("0");
    ui->_lineEditAI->setText ("0");
    ui->_lineEditBR->setText ("0");
    ui->_lineEditBI->setText ("0");
    ui->_lineEditCR->setText ("0");
    ui->_lineEditCI->setText ("0");

    ui->_doubleType->setChecked (true);
    ui->_lineEditAI->setEnabled (false);
    ui->_lineEditBI->setEnabled (false);
    ui->_lineEditCI->setEnabled (false);
}

TInterface::~TInterface ()
{
    delete ui;
}

void TInterface::slotSetLabel (const QString &str)
{
    ui->_labelResult->setText (str);
}

void TInterface::slotShow ()
{
    QString command = "S";
    if (ui->_complexType->isChecked())
        command += " C";
    else
        command += " D";
    QByteArray ba = command.toUtf8 ();
    emit sendData (ba);
}

void TInterface::slotCalc ()
{
    QString command = "C";
    if (ui->_complexType->isChecked())
        command += " C";
    else
        command += " D";
    command += " " + ui->_lineEditAR->text ();
    if (ui->_complexType->isChecked ())
        command += " " + ui->_lineEditAI->text ();
    command += " " + ui->_lineEditBR->text ();
    if (ui->_complexType->isChecked ())
        command += " " + ui->_lineEditBI->text ();
    command += " " + ui->_lineEditCR->text ();
    if (ui->_complexType->isChecked ())
        command += " " + ui->_lineEditCI->text ();
    QByteArray ba = command.toUtf8 ();
    emit sendData (ba);
}

void TInterface::slotTypeChanged()
{
    if (ui->_doubleType->isChecked ()) {
        ui->_lineEditAI->setEnabled (false);
        ui->_lineEditBI->setEnabled (false);
        ui->_lineEditCI->setEnabled (false);
    } else if (ui->_complexType->isChecked ()) {
        ui->_lineEditAI->setEnabled (true);
        ui->_lineEditBI->setEnabled (true);
        ui->_lineEditCI->setEnabled (true);
    } else {
        ui->_lineEditAI->setEnabled (false);
        ui->_lineEditBI->setEnabled (false);
        ui->_lineEditCI->setEnabled (false);
        ui->_lineEditAR->setEnabled (false);
        ui->_lineEditBR->setEnabled (false);
        ui->_lineEditCR->setEnabled (false);
    }
}

