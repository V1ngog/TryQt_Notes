#ifndef SHOWPAGE_H
#define SHOWPAGE_H

#include "basepage.h"
#include <QListWidget>
#include <QPushButton>

class ShowPage : public BasePage 
{
    Q_OBJECT

public:
    explicit ShowPage(QWidget *parent = nullptr);
    virtual ~ShowPage() {}

    void onPageEnter() override;

signals:
    void exitRequested();
    void editRequested(int noteId, const QString &text);
    
private slots:
    void onDeleteClicked();

private:
    QStringList notes;
    QListWidget *listNotes;
    QPushButton *exitButton;
    QPushButton *deleteButton;
};

#endif