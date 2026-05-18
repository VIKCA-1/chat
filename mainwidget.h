#ifndef MAINWIDGET_H
#define MAINWIDGET_H
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>

class MatrixClient;

class MainWidget : public QWidget {
    Q_OBJECT
public:
    MainWidget(QWidget *parent = nullptr);
private slots:
    void LoginCl();
    void LoginOk(const QString& token, const QString& uid);
private:
    QLineEdit* serverIn;
    QLineEdit* loginIn;
    QLineEdit* passIn;
    QPushButton* loginBtn;
    QLabel* statusLabel;
    MatrixClient* cl;
};

#endif
