#include "TInterface.h"
#include "ui_TInterface.h"

TInterface::TInterface (QWidget *parent)
    : QWidget (parent)
    , ui (new Ui::TInterface)
{
    ui->setupUi(this);
    connect (ui->_show, &QPushButton::clicked, this, &TInterface::slotShow);
    connect (ui->_calc, &QPushButton::clicked, this, &TInterface::slotCalc);
    ui->_lineEditAR->setText ("0");
    ui->_lineEditAI->setText ("0");
    ui->_lineEditBR->setText ("0");
    ui->_lineEditBI->setText ("0");
    ui->_lineEditCR->setText ("0");
    ui->_lineEditCI->setText ("0");
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
    QByteArray ba = command.toUtf8 ();
    emit sendData (ba);
}

void TInterface::slotCalc ()
{
    QString command = "C";
    command += " " + ui->_lineEditAR->text ();
    command += " " + ui->_lineEditAI->text ();
    command += " " + ui->_lineEditBR->text ();
    command += " " + ui->_lineEditBI->text ();
    command += " " + ui->_lineEditCR->text ();
    command += " " + ui->_lineEditCI->text ();
    QByteArray ba = command.toUtf8 ();
    emit sendData (ba);
}

