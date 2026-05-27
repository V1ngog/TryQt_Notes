#ifndef MAINWIN_H
#define MAINWIN_H

#include "basewin.h"
#include "mainpage.h"
#include "showpage.h"
#include "createnotepage.h"

class MainWindow : public BaseWindow
{
    Q_OBJECT

private:
    MenuPage *menuPage;
    ShowPage *showPage;
    CreateNotePage *createNotePage;

private slots:
    void onAddClicked();
    void onShowClicked();
    void onExitClicked() {close();}

public:
    explicit MainWindow(QWidget *parent = nullptr);

};
#endif