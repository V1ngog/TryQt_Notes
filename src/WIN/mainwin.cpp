#include <mainwin.h>

MainWindow::MainWindow(QWidget *parent) : BaseWindow(parent) {
    menuPage = new MenuPage(this);
    registerPage("Menu", menuPage);

    showPage = new ShowPage(this);
    registerPage("Show", showPage);

    addPage = new AddPage(this);
    registerPage("Add", addPage);

    navigateTo("Menu");

    connect(menuPage->addButton, &QPushButton::clicked, this, &MainWindow::onAddClicked);
    connect(menuPage->showButton, &QPushButton::clicked, this, &MainWindow::onShowClicked);
    connect(menuPage->exitButton, &QPushButton::clicked, this, &MainWindow::onExitClicked);

    connect(showPage, &ShowPage::exitRequested, this, [this]() {
    navigateTo("Menu");
    });

    connect(addPage, &AddPage::noteAdded, this, [this]() {
    navigateTo("Menu");
    });

    setWindowTitle("ToDo-List");
}

void MainWindow::onAddClicked() {
    navigateTo("Add");
}

void MainWindow::onShowClicked() {
    navigateTo("Show");
}
