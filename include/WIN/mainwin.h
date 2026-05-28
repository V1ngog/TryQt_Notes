#ifndef MAINWIN_H
#define MAINWIN_H

#include "basewin.h"
#include "mainpage.h"
#include "showpage.h"
#include "createnotepage.h"
#include "editnotepage.h"

class MainWindow : public BaseWindow
{
    Q_OBJECT

private:
    MenuPage *menuPage;
    ShowPage *showPage;
    CreateNotePage *createNotePage;
    EditNotePage *editNotePage;


private slots:
    void onEditRequested(int noteId, const QString &text);

public:
    explicit MainWindow(QWidget *parent = nullptr);

};
#endif