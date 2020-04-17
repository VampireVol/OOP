#ifndef SETTTINGWINDOW_H
#define SETTTINGWINDOW_H

#include <QWidget>

namespace Ui {
class SetttingWindow;
}

class SetttingWindow : public QWidget
{
    Q_OBJECT

public:
    explicit SetttingWindow(QWidget *parent = nullptr);
    ~SetttingWindow();

private:
    Ui::SetttingWindow *ui;
};

#endif // SETTTINGWINDOW_H
