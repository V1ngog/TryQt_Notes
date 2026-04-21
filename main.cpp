#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>


int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    
    QMainWindow window;
    window.setWindowTitle("Notes");
    window.resize(500, 800);
    
    QWidget* CentralWidget = new QWidget();

    QPushButton* ButtCreateNotes = new QPushButton("Создать заметку");
    QPushButton* ButtShowNotes = new QPushButton("Показать заметки");
    QPushButton* ButtExit = new QPushButton("Выход");

    QLabel* WaterText = new QLabel("V1ngog's Production");

    ButtCreateNotes->setMinimumHeight(70);
    ButtShowNotes->setMinimumHeight(70);
    ButtExit->setMinimumHeight(70);

    ButtCreateNotes->setMinimumWidth(150);
    ButtShowNotes->setMinimumWidth(150);
    ButtExit->setMinimumWidth(150);

    ButtCreateNotes->setToolTip("Создать новую заметку");

    // ButtCreateNotes->setMaximumWidth(150);
    // ButtShowNotes->setMaximumWidth(150);
    // ButtExit->setMaximumWidth(150);

    // QHBoxLayout* UpLine = new QHBoxLayout();
    // QHBoxLayout* DownLine = new QHBoxLayout();

    // UpLine->addStretch();
    // UpLine->addWidget(ButtCreateNotes);
    // UpLine->addStretch();
    // UpLine->addWidget(ButtShowNotes);
    // UpLine->addStretch();

    // DownLine->addStretch();
    // DownLine->addWidget(ButtExit);
    // DownLine->addStretch();

    // QVBoxLayout* UpLayout = new QVBoxLayout();
    // UpLayout->addWidget(ButtCreateNotes);
    // UpLayout->addWidget(ButtShowNotes);
    // UpLayout->addWidget(ButtExit);
    // UpLayout->addStretch();

    QVBoxLayout* WaterTextLine = new QVBoxLayout();
    WaterTextLine->addWidget(WaterText);

    QVBoxLayout* ButtunLine = new QVBoxLayout();
    ButtunLine->addStretch();
    ButtunLine->addWidget(ButtCreateNotes, 0, Qt::AlignHCenter);
    ButtunLine->addWidget(ButtShowNotes, 0, Qt::AlignHCenter);
    ButtunLine->addWidget(ButtExit, 0, Qt::AlignHCenter);
    ButtunLine->addStretch();
    
    QVBoxLayout* MainLine = new QVBoxLayout();
    MainLine->addLayout(WaterTextLine);
    MainLine->addLayout(ButtunLine);


    CentralWidget->setLayout(MainLine);
    window.setCentralWidget(CentralWidget);

    window.show();
    return app.exec();
}