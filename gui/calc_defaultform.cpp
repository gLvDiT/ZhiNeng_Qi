#include "include/smartcalc.h"
#include "ui_smartcalc.h"

void SmartCalc::defaultFormUI() {
    QPushButton* Button_Backspace = new QPushButton(QString::fromUtf8("\u232B"), this);
    QPushButton* Button_Clear =     new QPushButton(QString::fromUtf8("C"), this);

    ui->radioCredit->setStyleSheet(      StyleSheetRadioButton);
    ui->radioDeposit->setStyleSheet(     StyleSheetRadioButton);
    Button_Backspace->setStyleSheet(  StyleSheetBackSpace);
    Button_Clear->setStyleSheet(      StyleSheetClear);
    ui->lineEdit->setStyleSheet(         StyleSheetLine);

    Button_Backspace->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    Button_Clear->setSizePolicy(    QSizePolicy::Preferred, QSizePolicy::Preferred);

    defaultFormLayout = new QGridLayout(); // removed 'this'
    defaultFormLayout->setSpacing(0);
    defaultFormLayout->setContentsMargins(0, 0, 0, 0);

    defaultFormLayout->addWidget(ui->lineEdit,          0, 0, 2, 5);
    defaultFormLayout->addWidget(ui->radioCredit,       2, 0, 1, 3);
    defaultFormLayout->addWidget(ui->radioDeposit,      3, 0, 1, 3);
    defaultFormLayout->addWidget(Button_Backspace,   2, 3, 2, 1);
    defaultFormLayout->addWidget(Button_Clear,       2, 4, 2, 1);

    defaultFormWidget = new QWidget(this);
    defaultFormWidget->setLayout(defaultFormLayout);

    connect(Button_Clear,     SIGNAL(clicked()), this, SLOT(clearClicked()));
    connect(Button_Backspace, SIGNAL(clicked()), this, SLOT(backspaceClicked()));

    Button_Clear->setShortcut(QKeySequence(Qt::Key_Escape));
    Button_Backspace->setShortcut(QKeySequence(Qt::Key_Backspace));
}

void SmartCalc::createForm() {
    ui->lineEdit->setPlaceholderText("0");
    ui->lineEdit->setAlignment(Qt::AlignRight);
    ui->lineEdit->setReadOnly(true);

    ui->radioCredit->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    ui->radioDeposit->setSizePolicy( QSizePolicy::Preferred, QSizePolicy::Preferred);
    ui->radioCredit->setFocusPolicy(Qt::NoFocus);
    ui->radioDeposit->setFocusPolicy(Qt::NoFocus);

    mainModeUI();
    defaultFormUI();

    mainFormWidget = new QWidget;
    mainFormLayout = new QGridLayout;
    mainFormLayout->setSpacing(0);
    mainFormLayout->addWidget(defaultFormWidget, 0, 0, 1, 7);
    mainFormLayout->addWidget(mainFormWidget_left,   1, 0, 2, 4); //1, 0, 2, 4
    mainFormLayout->addWidget(mainFormWidget_right,  1, 4, 2, 3); //1, 4, 2, 5

    mainFormWidget->setLayout(mainFormLayout);
    setCentralWidget(mainFormWidget);
    centralWidget()->layout()->setContentsMargins(0, 0, 0, 0);
}
