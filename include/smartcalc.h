#ifndef SMARTCALC_H
#define SMARTCALC_H

#include "stylesheet.h"
#include "qcustomplot.h"
#include <QGridLayout>
#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui {
    class SmartCalc;
}
QT_END_NAMESPACE

class SmartCalc : public QMainWindow {
    Q_OBJECT

public: SmartCalc(QWidget* parent = nullptr);
    ~SmartCalc();

private:
    Ui::SmartCalc* ui;

    QWidget* defaultFormWidget;
    QWidget* mainFormWidget_right;
    QWidget* mainFormWidget_left;
    QWidget* mainFormWidget;
    QWidget* graphFormWidget;

    QGridLayout* defaultFormLayout;
    QGridLayout* mainFormLayout_left;
    QGridLayout* mainFormLayout_right;
    QGridLayout* mainFormLayout;
    QGridLayout* graphFormLayout;

    QCustomPlot* widget;
    QLineEdit* MaxX;
    QLineEdit* MinX;

    QPushButton* Button_openGraph;

    void mainModeUI();
    void defaultFormUI();
    void grapfForm();
    void createForm();

    bool graphForm_flag;
    void createForm_two();
    void makeGraph(my_str* str_pol);

public slots:
    void openGraph();
    void digitClicked();
    void functionsClicked();
    void operationsClicked();
    void equalClicked();
    void clearClicked();
    void backspaceClicked();

};
#endif // SMARTCALC_H
