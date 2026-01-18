#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QSettings>

class Launcher : public QWidget {
    Q_OBJECT
public:
    Launcher(QWidget *parent = nullptr);

private:
    QLineEdit *pathEdit;
    QPushButton *browseButton;
    QPushButton *playButton;

private slots:
    void browse();
    void play();
};
