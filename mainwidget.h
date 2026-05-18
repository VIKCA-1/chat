#ifndef MAINWIDGET_H
#define MAINWIDGET_H
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>

class MainWidget : public QWidget {
    Q_OBJECT
public:
    MainWidget(QWidget *parent = nullptr);
private slots:
    void LoginCl();
private:
    QLineEdit* serverIn;
    QLineEdit* loginIn;
    QLineEdit* passIn;
    QPushButton* loginBtn;
    QLabel* statusLabel;
};

#endif
