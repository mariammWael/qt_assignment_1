#include "registerwindow.h"
#include "ui_registerwindow.h"
#include "Users.h"
#include"welcomewindow.h"

RegisterWindow::RegisterWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RegisterWindow)
{
    ui->setupUi(this);
    ui->label_AlreadyExisting->setVisible(false);
    ui->label_LessThan12->setVisible(false);
    ui->label_NotMatching->setVisible(false);
    ui->label_AllFields->setVisible(false);
     ui->label_DayError->setVisible(false);

}

RegisterWindow::~RegisterWindow()
{
    delete ui;
}


void RegisterWindow::on_pushButton_Register_clicked()
{
    ui->label_AlreadyExisting->setVisible(false);
    ui->label_LessThan12->setVisible(false);
    ui->label_AllFields->setVisible(false);
    ui->label_NotMatching->setVisible(false);
    ui->label_DayError->setVisible(false);
    QString username2= ui->lineEdit_Username_Register->text();
    QString password2= ui->lineEdit_Password_Register->text();
    QString ReTypePassword= ui->lineEdit_ReType_Register->text();
    QString AgeOfUser=ui->lineEdit_Age->text();
    QString day=ui->lineEdit_Day->text();
    QString year=ui->lineEdit_year->text();
    int x=year.toInt();
    int y=day.toInt();
    int z=AgeOfUser.toInt();
    QString month=ui->comboBox_Month->currentText();
    bool FemaleGender=ui->radioButton->isChecked();
    bool MaleGender=ui->radioButton_2->isChecked();
    bool AccountTypeUser=ui-> radioButton_User->isChecked();
    bool AccountTypeAdmin=ui->radioButton_Admin->isChecked();
    bool GenreDrama=ui->checkBox_Drama->isChecked();
    bool GenreAction=ui->checkBox_Action->isChecked();
    bool GenreComedy=ui->checkBox_Comedy->isChecked();
    bool GenreRomance=ui->checkBox_Romance->isChecked();
    bool GenreHorror=ui->checkBox_Horror->isChecked();
    bool GenreOther=ui->checkBox_Other->isChecked();
    bool checkuser = true;
    bool check_pass = true;
    for(int i=0;i<usersCount;i++)
    {

        if(usernames[i]==username2)
        {
            ui->label_AlreadyExisting->setVisible(true);
            checkuser=false;
        }
        if(passwords[i]==password2)
        {
            check_pass = false;
        }

        if(password2!=ReTypePassword)
        {
            ui->label_NotMatching->setVisible(true);
            check_pass = false;
        }
        if(x>2012)
        {
            ui->label_LessThan12->setVisible(true);
        }
        if((GenreAction==false)&&(GenreComedy==false)&&(GenreDrama==false)&&(GenreHorror==false)&&(GenreOther==false)&&(GenreRomance==false))
        {
            ui->label_AllFields->setVisible(true);
        }
        if((AccountTypeAdmin==false)&&(AccountTypeUser==false))
        {
            ui->label_AllFields->setVisible(true);
        }
        if((FemaleGender==false)&&(MaleGender==false))
        {
            ui->label_AllFields->setVisible(true);
        }
        if(day=="")
        {
            ui->label_AllFields->setVisible(true);
        }
        if((username2=="")||(password2=="")||(ReTypePassword==""))
        {
            ui->label_AllFields->setVisible(true);
        }
        if((y>31)||(y<=0))
        {
            ui->label_DayError->setVisible(true);
        }


            if((checkuser==true)&&(check_pass==true))
            {
                usernames[usersCount]=username2;
                passwords[usersCount]=password2;
                ages[usersCount]=z;
                usersCount++;
                hide();
                WelcomeWindow* window2=new WelcomeWindow(username2,z,this);
                window2->show();

            }



    }

}



