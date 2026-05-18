#include "mainwidget.h"
#include <QVBoxLayout>
#include <QGridLayout>
#include <QMessageBox>

MainWidget::MainWidget(QWidget *parent) : QWidget(parent)
{
    setWindowTitle("Matrix Client");
    resize(400, 250);

    QGridLayout* grid = new QGridLayout(this);

    QLabel* serverLbl = new QLabel("Сервер:", this);
    serverIn = new QLineEdit(this);
    serverIn->setPlaceholderText("https://matrix.org");
    grid->addWidget(serverLbl, 0, 0);
    grid->addWidget(serverIn, 0, 1);

    QLabel* loginLbl = new QLabel("Логин:", this);
    loginIn = new QLineEdit(this);
    loginIn->setPlaceholderText("@username:matrix.org");
    grid->addWidget(loginLbl, 1, 0);
    grid->addWidget(loginIn, 1, 1);

    QLabel* passLbl = new QLabel("Пароль:", this);
    passIn = new QLineEdit(this);
    passIn->setPlaceholderText("password");
    grid->addWidget(passLbl, 2, 0);
    grid->addWidget(passIn, 2, 1);

    loginBtn = new QPushButton("Войти", this);
    grid->addWidget(loginBtn, 3, 0, 1, 2);

    statusLabel = new QLabel("Готово", this);
    statusLabel->setStyleSheet("color: gray;");
    grid->addWidget(statusLabel, 4, 0, 1, 2);

    connect(loginBtn, &QPushButton::clicked, this, &MainWidget::LoginCl);
}

void MainWidget::LoginCl()
{
    QString server = serverIn->text().trimmed();
    QString login = loginIn->text().trimmed();
    QString pass = passIn->text();

    if (server.isEmpty() || login.isEmpty() || pass.isEmpty()){
        statusLabel->setText("Заполните все поля");
        return;
    }

    loginBtn->setEnabled(false);
    statusLabel->setText("Выполняется вход");
}
