#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H
#include "Users.h"

#include <QMainWindow>
#include "welcomewindow.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class LoginWindow;
}
QT_END_NAMESPACE

class LoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();

private slots:
    void on_LoginButton_clicked();

    void on_RegisterButton_clicked();

private:
    Ui::LoginWindow *ui;
    WelcomeWindow *w;
};
#endif // LOGINWINDOW_H
