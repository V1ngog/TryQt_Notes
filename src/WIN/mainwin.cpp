#include <mainwin.h>

MainWindow::MainWindow(QWidget *parent) : BaseWindow(parent) {
    menuPage = new MenuPage(this);
    registerPage("Menu", menuPage);
    navigateTo("Menu");

    connect(menuPage->addButton, &QPushButton::clicked, this, &MainWindow::onAddClicked);
    connect(menuPage->showButton, &QPushButton::clicked, this, &MainWindow::onShowClicked);
    connect(menuPage->exitButton, &QPushButton::clicked, this, &MainWindow::onExitClicked);

    setWindowTitle("Main Menu");
}