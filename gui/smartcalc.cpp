#include "include/smartcalc.h"
#include "ui_smartcalc.h"

SmartCalc::SmartCalc(QWidget *parent) : QMainWindow(parent), ui(new Ui::SmartCalc) {
    ui->setupUi(this);
    setWindowTitle("SmartCalc v2.0");
    setWindowOpacity(0.98);
    setMinimumSize(685, 450);
    setMaximumSize(685, 450);

    createForm();
}

SmartCalc::~SmartCalc() {
    delete ui;
}

void SmartCalc::digitClicked() {
    QString clickedNum = ((QPushButton*)sender())->text();
    if (clickedNum == "\u03C0") {
        long double pi = 3.1415926535897932384626433832795;
        ui->lineEdit->setText(ui->lineEdit->text() + QString(std::to_string(pi).c_str()));
    } else {
        ui->lineEdit->setText(ui->lineEdit->text() + clickedNum);
    }
}

void SmartCalc::functionsClicked() {
    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
    ui->lineEdit->setText(ui->lineEdit->text() + clickedButton->text() + "(");
}

void SmartCalc::operationsClicked() {
    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
    QString cur_str = ui->lineEdit->text();

    bool flag = cur_str.endsWith("+") || cur_str.endsWith("-") || cur_str.endsWith("/") || cur_str.endsWith("÷")
            || cur_str.endsWith("*") || cur_str.endsWith("x") || cur_str.endsWith("^")
            || cur_str.endsWith("%") || cur_str.isEmpty() ? false : true;


    if (clickedButton->text() == "+" && flag)
        ui->lineEdit->setText(cur_str + "+");
    else if (clickedButton->text() == "-" && flag)
        ui->lineEdit->setText(cur_str + "-");
    else if (clickedButton->text() == "\u00D7" && flag)
        ui->lineEdit->setText(cur_str + QString::fromUtf8("\u00D7"));
    else if (clickedButton->text() == "\u00F7" && flag)
        ui->lineEdit->setText(cur_str + "/");
    else if (clickedButton->text() == "^" && flag)
        ui->lineEdit->setText(cur_str + "^");
    else if (clickedButton->text() == "%" && flag)
        ui->lineEdit->setText(cur_str + "%");
    else if (clickedButton->text() == "(")
        ui->lineEdit->setText(cur_str + "(");
    else if (clickedButton->text() == ")")
        ui->lineEdit->setText(cur_str + ")");
}

void SmartCalc::equalClicked() {
    qDebug() << "func in process";
}

void SmartCalc::dotClicked() {
    QString sep = ",";
    #ifdef _WIN32
    sep = ".";
    #endif
    if (!ui->lineEdit->text().endsWith(".") && !ui->lineEdit->text().endsWith(","))
        ui->lineEdit->setText(ui->lineEdit->text() + sep);
}

void SmartCalc::clearClicked() {
    ui->lineEdit->setText("0");
}

void SmartCalc::backspaceClicked() {
    QString cur_str = ui->lineEdit->text();
    cur_str.chop(1);
    ui->lineEdit->setText(cur_str);
}

void SmartCalc::opemBonusPart() {
    // ->isChecked() else
    qDebug() << "func in process";
}

