#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QDialog>
#include <QMainWindow>
#include <QTimer>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>//libreria que permite consultas y req. a BD
#include <QtSql/QSqlError>//libreria que permite conocer errores en consultas BD
#include "secdialog.h"


QT_BEGIN_NAMESPACE   //definicion de espacio de nombre llamado ui con declaracion una clase MainWindow
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow //clase MainW que hereda de QMainW
{
    Q_OBJECT

public://metodos de la clase con modificador de visibilidad publico
    MainWindow(QWidget *parent = nullptr);//constructor que recibe como parametro QW padre
    ~MainWindow();//destructor
    void crearTablaUsuarios();
    void crearTablaEntregas();
    void insertarEntrega();


public slots://metodo de clase con modificador de visibilidad publico
                // utilizado para vinculacion de objetos atraves de signal(señal del emisor)
                // y slots ( ranura del receptor)
    void fTimer();


private slots://metodos de clase con modificador de visibilidad publico
    void on_pushButton_ingreso_clicked();
    void on_pushButton_clean_clicked();
    void on_pushButton_timer_clicked();



private://atributos  de la clase con modificador de visibilidad privado
    Ui::MainWindow *ui;//declaracion de puntero con identificador ui a la clase ui MainW
                       // contiene toda la informacion del archivo mainwindow.ui
    QTimer* timer2; // declaracion de puntero  con identificador timer2 a la clase Qtimer
    QSqlDatabase db;// declaracion de variable  identificador db tipo QSQlD
    secDialog *segundoD;
};
#endif // MAINWINDOW_H
