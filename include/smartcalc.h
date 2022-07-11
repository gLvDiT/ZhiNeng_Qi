#ifndef SMARTCALC_H
#define SMARTCALC_H

#include "include/styleSheet.h"
#include <QMainWindow>
#include <QGridLayout>
#include <QPushButton>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class SmartCalc; }
QT_END_NAMESPACE

class SmartCalc : public QMainWindow
{
    Q_OBJECT

public:
    SmartCalc(QWidget *parent = nullptr);
    ~SmartCalc();

private:
    Ui::SmartCalc *ui;
    QWidget* defaultFormWidget;//
    QWidget* mainFormWidget_right; //
    QWidget* mainFormWidget_left; //
    QWidget* mainFormWidget; //

    QGridLayout* defaultFormLayout;//
    QGridLayout* mainFormLayout_left; //
    QGridLayout* mainFormLayout_right; // r
    QGridLayout* mainFormLayout; //

    void mainModeUI();
    void defaultFormUI();
    void createForm();

public slots:
    void digitClicked();
    void functionsClicked();
    void operationsClicked();
    void equalClicked();
    void dotClicked();
    void clearClicked();
    void backspaceClicked();
    void opemBonusPart();

};
#endif // SMARTCALC_H
