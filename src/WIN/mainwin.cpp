#include <mainwin.h>

MainWindow::MainWindow(QWidget *parent) : BaseWindow(parent) {
    menuPage = new MenuPage(this);
    registerPage("Menu", menuPage);

    showPage = new ShowPage(this);
    registerPage("Show", showPage);

    createNotePage = new CreateNotePage(this);
    registerPage("Create", createNotePage);

    editNotePage = new EditNotePage(this);
    registerPage("Edit", editNotePage);

    navigateTo("Menu");

    connect(menuPage->addButton, &QPushButton::clicked, this, &MainWindow::onAddClicked);
    connect(menuPage->showButton, &QPushButton::clicked, this, &MainWindow::onShowClicked);
    connect(menuPage->exitButton, &QPushButton::clicked, this, &MainWindow::onExitClicked);

    connect(showPage, &ShowPage::exitRequested, this, [this]() {
    navigateTo("Menu");
    });

    connect(showPage, &ShowPage::editRequested, this, &MainWindow::onEditRequested);

    connect(createNotePage, &CreateNotePage::noteCreated, this, [this]() {
    navigateTo("Menu");
    });

    connect(editNotePage, &EditNotePage::noteEdited, this, [this]() {
    navigateTo("Show");
    });

    setWindowTitle("ToDo-List");
}

void MainWindow::onAddClicked() {
    navigateTo("Create");
}

void MainWindow::onShowClicked() {
    navigateTo("Show");
}

void MainWindow::onEditRequested(int noteId, const QString &text)
{
    editNotePage->setNote(noteId, text);
    navigateTo("Edit");
}