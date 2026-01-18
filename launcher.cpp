#include "launcher.h"
#include <QProcess>
#include <QMessageBox>

Launcher::Launcher(QWidget *parent) : QWidget(parent) {
    setWindowTitle("Nozdor Launcher");
    resize(400, 120);

    pathEdit = new QLineEdit(this);
    browseButton = new QPushButton("Обзор", this);
    playButton = new QPushButton("Играть", this);

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(pathEdit);
    layout->addWidget(browseButton);
    layout->addWidget(playButton);
    setLayout(layout);

    QSettings settings("Nozdor", "Launcher");
    pathEdit->setText(settings.value("wow_path").toString());

    connect(browseButton, &QPushButton::clicked, this, &Launcher::browse);
    connect(playButton, &QPushButton::clicked, this, &Launcher::play);
}

void Launcher::browse() {
    QString fileName = QFileDialog::getOpenFileName(this, "Выберите WoW.app или WoW.exe");
    if (!fileName.isEmpty()) {
        pathEdit->setText(fileName);
        QSettings settings("Nozdor", "Launcher");
        settings.setValue("wow_path", fileName);
    }
}

void Launcher::play() {
    QString path = pathEdit->text();
    if (path.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Выберите путь к WoW.");
        return;
    }

    QProcess::startDetached(path);
}
