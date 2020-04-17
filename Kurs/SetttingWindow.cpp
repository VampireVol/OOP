#include "SetttingWindow.h"
#include "ui_SetttingWindow.h"

SetttingWindow::SetttingWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SetttingWindow)
{
    ui->setupUi(this);
}

SetttingWindow::~SetttingWindow()
{
    delete ui;
}
