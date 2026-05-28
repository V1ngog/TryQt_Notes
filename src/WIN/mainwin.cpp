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

    connect(menuPage, &MenuPage::addRequested, this, [this]() {
    navigateTo("Create");
    });

    connect(menuPage, &MenuPage::showRequested, this, [this]() {
    navigateTo("Show");
    });

    connect(menuPage, &MenuPage::exitRequested, this, [this]() {
    close();
    });

    connect(showPage, &ShowPage::exitRequested, this, [this]() {
    navigateTo("Menu");
    });

    connect(createNotePage, &CreateNotePage::noteCreated, this, [this]() {
    navigateTo("Menu");
    });

    connect(editNotePage, &EditNotePage::noteEdited, this, [this]() {
    navigateTo("Show");
    });

    connect(showPage, &ShowPage::editRequested, this, &MainWindow::onEditRequested);

    setWindowTitle("ToDo-List");
}

void MainWindow::onEditRequested(int noteId, const QString &text)
{
    editNotePage->setNote(noteId, text);
    navigateTo("Edit");
}