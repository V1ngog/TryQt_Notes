#include <mainpage.h>

MenuPage::MenuPage(QWidget *parent) : BasePage(parent) {
    QVBoxLayout *layout = new QVBoxLayout(this);
    
    addButton = new QPushButton("Add notes", this);
    showButton = new QPushButton("Show notes", this);
    exitButton = new QPushButton("Exit", this);

    addButton->setFixedSize(200, 50);
    showButton->setFixedSize(200, 50);
    exitButton->setFixedSize(200, 50);
    
    watermark = new QLabel("Vingog's Production");
    helpHLayout = new QHBoxLayout();
    helpHLayout->addWidget(watermark);
    helpHLayout->addStretch();

    layout->addLayout(helpHLayout);
    layout->addStretch();
    layout->addWidget(addButton, 0, Qt::AlignCenter);
    layout->addWidget(showButton, 0, Qt::AlignCenter);
    layout->addWidget(exitButton, 0, Qt::AlignCenter);
    layout->addStretch();
    
    setLayout(layout);
}