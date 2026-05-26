#ifndef MAINWIN_H
#define MAINWIN_H

#include "basewin.h"
#include "mainpage.h"

class MainWindow : public BaseWindow
{
    Q_OBJECT

private:
    MenuPage *menuPage;

private slots:
    void onAddClicked() {}
    void onShowClicked() {}
    void onExitClicked() { close(); }

    
public:
    explicit MainWindow(QWidget *parent = nullptr) : BaseWindow(parent) {
        menuPage = new MenuPage(this);
        registerPage("Menu", menuPage);
        navigateTo("Menu");

        connect(menuPage->addButton, &QPushButton::clicked, this, &MainWindow::onAddClicked);
        connect(menuPage->showButton, &QPushButton::clicked, this, &MainWindow::onShowClicked);
        connect(menuPage->exitButton, &QPushButton::clicked, this, &MainWindow::onExitClicked);

        setWindowTitle("Main Menu");
    }

};
#endif