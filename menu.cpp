#include "menu.h"
#include "ui_menu.h"
#include "widget.h"
#include <QMessageBox>
#include <note_abs.h>
#include <QPixmap>

Menu::Menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
    QPixmap pix(":/Ressourses/Picture/Plan.png");
    ui->label_Picture->setPixmap(pix);
    Widget conn;
    if (!conn.connOpen())
        ui->label_menu->setText("Failed to open the database");
    else
        ui->label_menu->setText("Conneted...");

}

Menu::~Menu()
{
    delete ui;
}



void Menu::on_pushButton_ajouter_clicked()
{
    Widget conn;
    QString id = ui  -> id -> text();
    QString Nom = ui  ->  texte_Nom-> text();
    QString salaire = ui  ->  salaire-> text();
    QString abs = ui  ->  abs -> text();
    QString tache = ui  ->  tache -> text();
    if (!conn.connOpen()){
             qDebug() <<"Failed to open database";
             return;}

conn.connOpen();
QSqlQuery query;

query.exec("CREATE TABLE salarie ("
           "id INT NOT NULL,"
           "nom_complet VARCHAR(255) NOT NULL,"
           "salaire DECIMAL(10, 2) NOT NULL,"
           "heure_absence INT NOT NULL,"
           "tache_realiser VARCHAR(255) NOT NULL,"
           "PRIMARY KEY(id)"
           ")");
query.prepare("insert into salarie values('"+id+"','"+Nom+"','"+salaire+"','"+abs+"','"+tache+"');");
qDebug() << query.lastQuery();


if (query.exec()){
    QMessageBox msgBox;
    msgBox.setText("Le salarie a bien été engregistrer!");
    msgBox.exec();
    conn.connClose();}

else
    QMessageBox::critical(this,tr("ERROR::"),tr("ERRORRRRRRRR"));

}


//--------------------------------------------------------------------------
void Menu::on_pushButton_modifier_clicked()
{
    Widget conn;
    QString id = ui  -> id -> text();
    QString Nom = ui  ->  texte_Nom-> text();
    QString salaire = ui  ->  salaire-> text();
    QString abs = ui  ->  abs -> text();
    QString tache = ui  ->  tache -> text();

    if (!conn.connOpen()){
             qDebug() <<"Failed to open database";
             return;}

conn.connOpen();
QSqlQuery query;


query.prepare("UPDATE salarie SET id ='"+id+"',nom_complet='"+Nom+"',salaire='"+salaire+"',heure_absence='"+abs+"',tache_realiser='"+tache+"' WHERE id ='"+id+"';");
qDebug() << query.lastQuery();


if (query.exec()){
    QMessageBox msgBox;
    msgBox.setText("Le salarie  a bien été modifier!");
    msgBox.exec();
    conn.connClose();}

else
    QMessageBox::critical(this,tr("ERROR::"),tr("ERRORRRRRRRR"));


}
//-----------------------------------------------------------------
void Menu::on_pushButton_supprimer_clicked()
{
    Widget conn;
    QString id = ui  -> id -> text();

    if (!conn.connOpen()){
             qDebug() <<"Failed to open database";
             return;}

conn.connOpen();
QSqlQuery query;


query.prepare("DELETE FROM salarie WHERE id ='"+id+"';");
qDebug() << query.lastQuery();


if (query.exec()){
    QMessageBox msgBox;
    msgBox.setText("le salarie a ete supprime.");
    msgBox.exec();
    conn.connClose();}

else
    QMessageBox::critical(this,tr("ERROR::"),tr("ERRORRRRRRRR"));

}
//-------------------------------------------------------------
void Menu::on_pushButton_afficher_clicked()
{
     Widget conn;
     QSqlQueryModel *Modal = new QSqlQueryModel();

     conn.connOpen();
     QSqlQuery *query = new QSqlQuery(conn.mydb);
     query->prepare("SELECT * FROM salarie");
     query->exec();
     Modal->setQuery(*query);
     ui -> tableView->setModel(Modal);



}

//*******************************************************************

void Menu::on_pushButton_ajouter_2_clicked()
{
    Widget conn;
    QString idf = ui  -> idf -> text();
    QString Nom = ui  ->  nomf-> text();
    QString adress = ui  ->  adress-> text();
    QString Telephone = ui  ->  tele-> text();
    QString mail = ui  ->  mail-> text();

    if (!conn.connOpen()){
             qDebug() <<"Failed to open database";
             return;}

conn.connOpen();
QSqlQuery query2;
query2.exec("CREATE TABLE fournisseur ("
           "idf INT NOT NULL,"
           "nom	VARCHAR(255) NOT NULL,"
           "adresse	VARCHAR(255) NOT NULL,"
           "telephone	VARCHAR(20) NOT NULL,"
           "email	VARCHAR(255) NOT NULL,"
           "PRIMARY KEY(idf)"
           ")");
query2.prepare("insert into fournisseur values('"+idf+"','"+Nom+"','"+adress+"','"+Telephone+"','"+mail+"');");

qDebug() << query2.lastQuery();


if (query2.exec()){
    QMessageBox msgBox;
    msgBox.setText("le fournisseur a ete insere.");
    msgBox.exec();
    conn.connClose();}

else
    QMessageBox::critical(this,tr("ERROR::"),tr("ERRORRRRRRRR"));
}

void Menu::on_pushButton_modifier_2_clicked()
{
    Widget conn;
    QString idf = ui  -> idf -> text();
    QString Nom = ui  ->  nomf-> text();
    QString adress = ui  ->  adress-> text();
    QString Telephone = ui  ->  tele-> text();
    QString mail = ui  ->  mail-> text();

    if (!conn.connOpen()){
             qDebug() <<"Failed to open database";
             return;}

conn.connOpen();
QSqlQuery query;

query.prepare("UPDATE fournisseur SET idf ='"+idf+"',nom='"+Nom+"',adress='"+adress+",telephone='"+Telephone+"',email='"+mail+"' WHERE idf ='"+idf+"';");
qDebug() << query.lastQuery();


if (query.exec()){
    QMessageBox msgBox;
    msgBox.setText("The professeur has been modified.");
    msgBox.exec();
    conn.connClose();}

else
    QMessageBox::critical(this,tr("ERROR::"),tr("ERRORRRRRRRR"));

}

void Menu::on_pushButton_supprimer_2_clicked()
{
    Widget conn;
    QString idf = ui  -> idf -> text();

    if (!conn.connOpen()){
             qDebug() <<"Failed to open database";
             return;}

conn.connOpen();
QSqlQuery query;

query.prepare("DELETE FROM fournisseur WHERE idf ="+idf+";");
qDebug() << query.lastQuery();


if (query.exec()){
    QMessageBox msgBox;
    msgBox.setText("le fournisseur a ete supprimer.");
    msgBox.exec();
    conn.connClose();}

else
    QMessageBox::critical(this,tr("ERROR::"),tr("ERRORRRRRRRR"));

}

//-------------------------------------------------------------------------
void Menu::on_pushButton_afficher_2_clicked()
{
    Widget conn;
    QSqlQueryModel *Modal = new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery *query = new QSqlQuery(conn.mydb);
    query->prepare("SELECT * FROM fournisseur");
    query->exec();
    Modal->setQuery(*query);
    ui -> tableView->setModel(Modal);

}

//*****************************************************************************
void Menu::on_pushButton_ajouter_3_clicked()
{
    Widget conn;
    QString ID = ui  -> idp -> text();
    QString nom = ui  ->  nomp-> text();
    QString prix = ui  ->  prix-> text();
    QString qte = ui  ->  qte-> text();
    QString fournisseur = ui  ->  fournisseur-> text();

    if (!conn.connOpen()){
             qDebug() <<"Failed to open database";
             return;}

conn.connOpen();
QSqlQuery query;


query.prepare("insert into produit values("+ID+",'"+fournisseur+"','"+nom+"','"+prix+"','"+qte+"');");
qDebug() << query.lastQuery();


if (query.exec()){
    QMessageBox msgBox;
    msgBox.setText("le produit a ete enregistre");
    msgBox.exec();
    conn.connClose();}

}


void Menu::on_pushButton_modifier_3_clicked()
{
    Widget conn;
    QString ID = ui  -> idp -> text();
    QString nom = ui  ->  nomp-> text();
    QString prix = ui  ->  prix-> text();
    QString qte = ui  ->  qte-> text();
    QString fournisseur = ui  ->  fournisseur-> text();

    if (!conn.connOpen()){
             qDebug() <<"Failed to open database";
             return;}

conn.connOpen();
QSqlQuery query;

query.prepare("UPDATE produit SET idp ="+ID+",idf='"+fournisseur+"',nom='"+nom+"',prix="+prix+",qte="+qte+" WHERE idp ="+ID+";");
qDebug() << query.lastQuery();


if (query.exec()){
    QMessageBox msgBox;
    msgBox.setText("The product has been modified.");
    msgBox.exec();
    conn.connClose();}

else
    QMessageBox::critical(this,tr("ERROR::"),tr("ERRORRRRRRRR"));
}

void Menu::on_pushButton_supprimer_3_clicked()
{
    Widget conn;
    QString ID = ui  -> idp -> text();

    if (!conn.connOpen()){
             qDebug() <<"Failed to open database";
             return;}

conn.connOpen();
QSqlQuery query;

query.prepare("DELETE FROM produit WHERE idp ="+ID+";");
qDebug() << query.lastQuery();


if (query.exec()){
    QMessageBox msgBox;
    msgBox.setText("The product has been deleted.");
    msgBox.exec();
    conn.connClose();}

else
    QMessageBox::critical(this,tr("ERROR::"),tr("ERRORRRRRRRR"));

}

void Menu::on_pushButton_afficher_3_clicked()
{
    Widget conn;
    QSqlQueryModel *Modal = new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery *query = new QSqlQuery(conn.mydb);
    query->prepare("SELECT * FROM produit");
    query->exec();
    Modal->setQuery(*query);
    ui -> tableView->setModel(Modal);
}

