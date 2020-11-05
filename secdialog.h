#ifndef SECDIALOG_H
#define SECDIALOG_H
#include <QDialog>


namespace Ui {//definicion de espacio de nombre llamado ui con declaracion una clase secDialog
class secDialog;
}

class secDialog : public QDialog  //clase secDialog que hereda de QDialog
{
    Q_OBJECT

public://metodos de la clase con modificador de visibilidad publico
     secDialog(QWidget *parent = nullptr);//constructor que recibe como parametro QW padre
    ~secDialog();
    void mostrarTablaEntrega();

private slots://metodo de clase con modificador de visibilidad publico
    // utilizado para vinculacion de objetos atraves de signal(señal del emisor)
    // y slots ( ranura del receptor)

    void on_pushButton_borrar_clicked();
    void on_pushButton_ver_clicked();
    void on_pushButton_update_clicked();

private://atributos  de la clase con modificador de visibilidad privado
    Ui::secDialog *ui;//declaracion de puntero con identificador ui a la clase UI secDialog
    // contiene toda la informacion del archivo mainwindow.ui
};

#endif // SECDIALOG_H
