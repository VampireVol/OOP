#include "TInterface.h"
#include "ui_TInterface.h"

TInterface::TInterface (QWidget *parent)
    : QWidget (parent)
    , ui (new Ui::TInterface)
{
    ui->setupUi(this);
    connect(ui->_show, &QPushButton::clicked, this, &TInterface::slotShow);
    connect(ui->_calc, &QPushButton::clicked, this, &TInterface::slotCalc);
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

void TInterface::slotShow ()
{
    ui->_labelResult->setText (_p.toString ());
}

void TInterface::slotCalc ()
{
    number a = number (ui->_lineEditAR->text ().toDouble (),
                       ui->_lineEditAI->text ().toDouble ());
    number b = number (ui->_lineEditBR->text ().toDouble (),
                       ui->_lineEditBI->text ().toDouble ());
    number c = number (ui->_lineEditCR->text ().toDouble (),
                       ui->_lineEditCI->text ().toDouble ());
    _p = Polynom (a, b, c);
    number x[2];
    int roots = _p.roots (x);
    if (roots == 2) {
        ui->_labelResult->setText (QString ("x[0] = %1; x[1] = %2")
                                   .arg (x[0].toString ())
                                   .arg (x[1].toString ()));
    } else if (roots == 1) {
        ui->_labelResult->setText (QString ("x[0], x[1] = %1")
                                   .arg (x[0].toString ()));
    }
}

