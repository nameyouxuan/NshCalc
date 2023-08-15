#include "nshcalc.h"
#include <QVBoxLayout>
#include <QTabWidget>
#include <QLabel>
#include <QGridLayout>
#include <QDebug>

NshCalc::NshCalc(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle(tr("逆水寒计算器"));
    QIcon icon("favicon.ico");
    this->setWindowIcon(icon);
    QTabWidget *tabWidget = new QTabWidget(this);

    QWidget *tab1 = new QWidget();  // 属性输入
    QWidget *tab2 = new QWidget();  // 攻击提升收益
    QWidget *tab3 = new QWidget();  // 元素攻击提升收益
    QWidget *tab4 = new QWidget();  // 破防提升收益
    QWidget *tab5 = new QWidget();  // 命中提升收益
    QWidget *tab6 = new QWidget();  // 会心提升收益

    // 设置标签页内容和布局
//    setupTab(tab1, "属性输入", "属性输入内容");

    //属性输入界面
//    QVBoxLayout *layout1 = new QVBoxLayout(tab1);
//    QLabel *label1 = new QLabel("属性输入界面");

    QGridLayout *inputLayout = new QGridLayout(this);
    attackLabel = new QLabel(tr("攻击"));
    attackLineEdit = new QLineEdit;
    inputLayout->addWidget(attackLabel, 0, 0);
    inputLayout->addWidget(attackLineEdit, 1, 0);
    aPenetrationLabel = new QLabel(tr("破防"));
    aPenetrationLineEdit = new QLineEdit;
    inputLayout->addWidget(aPenetrationLabel, 0, 1);
    inputLayout->addWidget(aPenetrationLineEdit, 1, 1);
    sBreakLabel = new QLabel("破盾");
    sBreakLineEdit = new QLineEdit;
    inputLayout->addWidget(sBreakLabel, 0, 2);
    inputLayout->addWidget(sBreakLineEdit, 1, 2);
    eAttackLabel = new QLabel(tr("元素攻击"));
    eAttackLineEdit = new QLineEdit;
    inputLayout->addWidget(eAttackLabel, 0, 3);
    inputLayout->addWidget(eAttackLineEdit, 1, 3);
    advantageLabel = new QLabel;
    advantageLineEdit = new QLineEdit;
    inputLayout->addWidget(advantageLabel, 0, 4);
    inputLayout->addWidget(advantageLineEdit, 1, 4);
    accuracyLabel = new QLabel(tr("命中"));
    accuracyLineEdit = new QLineEdit();
    inputLayout->addWidget(accuracyLabel, 0, 5);
    inputLayout->addWidget(accuracyLineEdit, 1, 5);
    cHitLabel = new QLabel(tr("会心"));
    cHitLineEdit = new QLineEdit;
    inputLayout->addWidget(cHitLabel, 0, 6);
    inputLayout->addWidget(cHitLineEdit, 1, 6);
    cDamageLabel = new QLabel(tr("会伤"));
    cDamageLineEdit = new QLineEdit;
    inputLayout->addWidget(cDamageLabel, 0, 7);
    inputLayout->addWidget(cDamageLineEdit, 1, 7);
    bCRateLabel = new QLabel(tr("额外会心率"));
    bCRateLineEdit = new QLineEdit;
    inputLayout->addWidget(bCRateLabel, 0, 8);
    inputLayout->addWidget(bCRateLineEdit, 1, 8);

//    layout1->addWidget(label1);
    tab1->setLayout(inputLayout);


    setupTab(tab2, "攻击提升收益", "攻击提升收益内容");
    setupTab(tab3, "元素攻击提升收益", "元素攻击提升收益内容");
    setupTab(tab4, "破防提升收益", "破防提升收益内容");
    setupTab(tab5, "命中提升收益", "命中提升收益内容");
    setupTab(tab6, "会心提升收益", "会心提升收益内容");

    // 将标签页添加到 QTabWidget
    tabWidget->addTab(tab1, tr("属性输入"));
    tabWidget->addTab(tab2, tr("攻击提升收益"));
    tabWidget->addTab(tab3, tr("元素攻击提升收益"));
    tabWidget->addTab(tab4, tr("破防提升收益"));
    tabWidget->addTab(tab5, tr("命中提升收益"));
    tabWidget->addTab(tab6, tr("会心提升收益"));

    // 使用网格布局进行平铺
    QGridLayout *gridLayout = new QGridLayout;
    gridLayout->addWidget(tabWidget, 0, 0); // 将tabWidget添加到布局中

    // 创建一个中央部件并设置网格布局
    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(gridLayout);

    // 将中央部件设置为主窗口的中央部件
    setCentralWidget(centralWidget);
}


NshCalc::~NshCalc()
{
}

// 辅助函数，用于设置标签页的内容和布局
void NshCalc::setupTab(QWidget *tab, const QString &title, const QString &content)
{
    QVBoxLayout *layout = new QVBoxLayout(tab);
    QLabel *label = new QLabel(content);
    layout->addWidget(label);
    tab->setLayout(layout);
}

void NshCalc::calcTabel1() {}

void NshCalc::calcTabel2() {}

void NshCalc::calcTabel3() {}

void NshCalc::calcTabel4() {}

void NshCalc::calcTabel5() {}
