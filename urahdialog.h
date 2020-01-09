#ifndef URAHDIALOG_H
#define URAHDIALOG_H

#include <QDialog>

namespace Ui {
class UrahDialog;
}

class UrahDialog : public QDialog
{
    Q_OBJECT

public:
    explicit UrahDialog(QWidget *parent = 0);
    ~UrahDialog();

private:
    Ui::UrahDialog *ui;
};

#endif // URAHDIALOG_H
