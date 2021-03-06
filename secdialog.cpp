#include "secdialog.h"
#include "ui_secdialog.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include "tercerdialog.h"
#include <QDebug>

secDialog::secDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::secDialog)
{
    ui->setupUi(this);

}

secDialog::~secDialog()
{
    delete ui;
}



void secDialog::mostrarTablaEntrega()
{
    QString consulta;
    consulta.append("SELECT * FROM entregas ");


    QSqlQuery mostrar;
    mostrar.prepare(consulta);
    if (mostrar.exec()){
        qDebug()<<"La consulta fue correcta";
    }else{
        qDebug()<<"ERROR  de consulta"<<mostrar.lastError();
    }

    int fila = 0;
    ui->tableWidget->setRowCount(0);//limpia la tabla
    while (mostrar.next()){

        ui->tableWidget->insertRow(fila);
        ui->tableWidget->setItem(fila,0,new QTableWidgetItem(mostrar.value(0).toByteArray().constData()));
        ui->tableWidget->setItem(fila,1,new QTableWidgetItem(mostrar.value(1).toByteArray().constData()));
        ui->tableWidget->setItem(fila,2,new QTableWidgetItem(mostrar.value(2).toByteArray().constData()));
        ui->tableWidget->setItem(fila,3,new QTableWidgetItem(mostrar.value(3).toByteArray().constData()));

        fila ++;

    }
}


void secDialog::on_pushButton_borrar_clicked()
{
    QString consulta;
    consulta.append("DELETE FROM entregas"";");

    QSqlQuery borrar;
    borrar.prepare(consulta);
    if (borrar.exec()){
        qDebug()<<"Se borro en tabla entregas";
    }else{
        qDebug()<<"ERROR "<<borrar.lastError();
    }
  mostrarTablaEntrega();
}

void secDialog::on_pushButton_ver_clicked()
{
    mostrarTablaEntrega();

}

void secDialog::on_pushButton_update_clicked()
{
    tercerDialog tresDialg;//crea un objeto segundadialogo(ventana)
    tresDialg.exec();
}



