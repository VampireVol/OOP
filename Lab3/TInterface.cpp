#include "TInterface.h"
#include "ui_TInterface.h"

TInterface::TInterface(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TInterface)
{
    ui->setupUi(this);

}

TInterface::~TInterface()
{
    delete ui;
}

