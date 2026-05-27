#ifndef ADDPAGE_H
#define ADDPAGE_H

#include "basepage.h"
#include <QTextEdit>
#include <QPushButton>

class AddPage : public BasePage
{
    Q_OBJECT

public:
    explicit AddPage(QWidget *parent = nullptr);

    void onPageExit() override;

signals:
    void noteAdded();

private slots:
    void onSaveClicked();
    void onCancelClicked();

private:
    QTextEdit *contentEdit;
    QPushButton *saveButton;
    QPushButton *cancelButton;
};

#endif