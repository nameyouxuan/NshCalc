#include "nshcalc.h"
#include <QStatusBar>
#include <QDebug>
#include <QTextEdit>
#include <QHBoxLayout>

NshCalc::NshCalc(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle(tr("逆水寒计算器"));
    QIcon icon("../NshCalc/favicon.ico");
    this->setWindowIcon(icon);
    tabWidget = new QTabWidget(this);

    defense = 1600;
    aegis = 206;
    eResistance = 0;
    resilience = 0;
    block = 540;
    cResistance = 150;


    // 将标签页添加到 QTabWidget
    tabWidget->addTab(inputTab, "属性输入");
//    tabWidget->addTab(attackTab, "攻击提升收益");
//    tabWidget->addTab(eAttackTab, "元素攻击提升收益");
//    tabWidget->addTab(defenseBreakTab, "破防提升收益");
//    tabWidget->addTab(accuracyTab, "命中提升收益");
//    tabWidget->addTab(criticalTab, "会心提升收益");
    tabWidget->addTab(settingsTab, "设置");

    inputLayout = new QGridLayout(inputTab);
    settingsLayout = new QGridLayout(settingsTab);

    setupInputTab(inputLayout);
    setupSettingsTab(settingsLayout);

    inputTab->setLayout(inputLayout);


    // 使用网格布局进行平铺
    QGridLayout *gridLayout = new QGridLayout;
    gridLayout->addWidget(tabWidget, 0, 0); // 将tabWidget添加到布局中

    // 创建一个中央部件并设置网格布局
    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(gridLayout);

    // 将中央部件设置为主窗口的中央部件
    setCentralWidget(centralWidget);
    statusBar()->showMessage(tr("Version: 1.0    Powered by Github:nameyouxuan"));
}


NshCalc::~NshCalc()
{
}

void NshCalc::setupInputTab(QGridLayout *layout)
{
    selectComboBox = new QComboBox();
    QWidget *tmpLayout1 = new QWidget;
    layout->addWidget(tmpLayout1);

    QGridLayout *inputLayout1 = new QGridLayout(tmpLayout1);

    selectComboBox->addItem(tr("英雄舞阳老四"));
    selectComboBox->addItem(tr("英雄舞阳老五"));
    selectComboBox->addItem(tr("英雄舞阳老六"));
    selectComboBox->addItem(tr("帮会木桩"));
    inputLayout1->addWidget(selectComboBox);
    tmpLayout1->setLayout(inputLayout1);

    connect(selectComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(onComboBoxChanged(int)));

    defenseLabel = new QLabel(tr("防御"));
    defenseLineEdit = new QLineEdit;
    aegisLabel = new QLabel(tr("气盾"));
    aegisLineEdit = new QLineEdit;
    eResistanceLabel = new QLabel(tr("元素抗性"));
    eResistanceLineEdit = new QLineEdit;
    resilienceLabel = new QLabel(tr("抵御"));
    resilienceLineEdit = new QLineEdit;
    blockLabel = new QLabel(tr("格挡"));
    blockLineEdit = new QLineEdit;
    cResistanceLabel = new QLabel(tr("会心抵抗"));
    cResistanceLineEdit = new QLineEdit;

    defenseLineEdit->setText(QString::number(defense));
    aegisLineEdit->setText(QString::number(aegis));
    eResistanceLineEdit->setText(QString::number(eResistance));
    resilienceLineEdit->setText(QString::number(resilience));
    blockLineEdit->setText(QString::number(block));
    cResistanceLineEdit->setText(QString::number(cResistance));

    inputLayout1->addWidget(defenseLabel, 1, 0);
    inputLayout1->addWidget(defenseLineEdit, 2, 0);
    inputLayout1->addWidget(aegisLabel, 1, 1);
    inputLayout1->addWidget(aegisLineEdit, 2, 1);
    inputLayout1->addWidget(eResistanceLabel, 1, 2);
    inputLayout1->addWidget(eResistanceLineEdit, 2, 2);
    inputLayout1->addWidget(resilienceLabel, 1, 3);
    inputLayout1->addWidget(resilienceLineEdit, 2, 3);
    inputLayout1->addWidget(blockLabel, 1, 4);
    inputLayout1->addWidget(blockLineEdit, 2, 4);
    inputLayout1->addWidget(cResistanceLabel, 1, 5);
    inputLayout1->addWidget(cResistanceLineEdit, 2, 5);

    QWidget *tmpLayout2 = new QWidget;
    QGridLayout *inputLayout2 = new QGridLayout(tmpLayout2);
    layout->addWidget(tmpLayout2);


    attackLabel = new QLabel(tr("攻击"));
    attackLineEdit = new QLineEdit;
    inputLayout2->addWidget(attackLabel, 3, 0);
    inputLayout2->addWidget(attackLineEdit, 4, 0);
    //    connect(attackLineEdit, &QLineEdit::textChanged, this, NshCalc::calcTmpValue());
    connect(attackLineEdit, &QLineEdit::textChanged, this, &NshCalc::calcTmpValue);

    aPenetrationLabel = new QLabel(tr("破防"));
    aPenetrationLineEdit = new QLineEdit;
    inputLayout2->addWidget(aPenetrationLabel, 3, 1);
    inputLayout2->addWidget(aPenetrationLineEdit, 4, 1);
    connect(aPenetrationLineEdit, &QLineEdit::textChanged, this, &NshCalc::calcTmpValue);

    sBreakLabel = new QLabel("破盾");
    sBreakLineEdit = new QLineEdit;
    inputLayout2->addWidget(sBreakLabel, 3, 2);
    inputLayout2->addWidget(sBreakLineEdit, 4, 2);
    connect(sBreakLineEdit, &QLineEdit::textChanged, this, &NshCalc::calcTmpValue);

    eAttackLabel = new QLabel(tr("元素攻击"));
    eAttackLineEdit = new QLineEdit;
    inputLayout2->addWidget(eAttackLabel, 3, 3);
    inputLayout2->addWidget(eAttackLineEdit, 4, 3);
    connect(eAttackLineEdit, &QLineEdit::textChanged, this, &NshCalc::calcTmpValue);

    advantageLabel = new QLabel(tr("克制"));
    advantageLineEdit = new QLineEdit;
    inputLayout2->addWidget(advantageLabel, 3, 4);
    inputLayout2->addWidget(advantageLineEdit, 4, 4);
    connect(advantageLineEdit, &QLineEdit::textChanged, this, &NshCalc::calcTmpValue);

    accuracyLabel = new QLabel(tr("命中"));
    accuracyLineEdit = new QLineEdit();
    inputLayout2->addWidget(accuracyLabel, 3, 5);
    inputLayout2->addWidget(accuracyLineEdit, 4, 5);
    connect(accuracyLineEdit, &QLineEdit::textChanged, this, &NshCalc::calcTmpValue);

    cHitLabel = new QLabel(tr("会心"));
    cHitLineEdit = new QLineEdit;
    inputLayout2->addWidget(cHitLabel, 3, 6);
    inputLayout2->addWidget(cHitLineEdit, 4, 6);
    connect(cHitLineEdit, &QLineEdit::textChanged, this, &NshCalc::calcTmpValue);

    cDamageLabel = new QLabel(tr("会伤"));
    cDamageLineEdit = new QLineEdit;
    inputLayout2->addWidget(cDamageLabel, 3, 7);
    inputLayout2->addWidget(cDamageLineEdit, 4, 7);
    connect(cDamageLineEdit, &QLineEdit::textChanged, this, &NshCalc::calcTmpValue);

    bCRateLabel = new QLabel(tr("额外会心率"));
    bCRateLineEdit = new QLineEdit;
    inputLayout2->addWidget(bCRateLabel, 3, 8);
    inputLayout2->addWidget(bCRateLineEdit, 4, 8);
    connect(bCRateLineEdit, &QLineEdit::textChanged, this, &NshCalc::calcTmpValue);

    rPercentageLabel = new QLabel(tr("克制百分比"));
    rPercentageLineEdit = new QLineEdit;
    inputLayout2->addWidget(rPercentageLabel, 3, 9);
    inputLayout2->addWidget(rPercentageLineEdit, 4, 9);
    connect(rPercentageLineEdit, &QLineEdit::textChanged, this, &NshCalc::calcTmpValue);


    QWidget *tmpLayout3 = new QWidget;
    QGridLayout *inputLayout3 = new QGridLayout(tmpLayout3);
    layout->addWidget(tmpLayout3);

    rDefenseLabel = new QLabel(tr("剩余防御"));
    rDefenseLineEdit = new QLineEdit;
    dReductionLabel = new QLabel(tr("防御减免"));
    dReductionLineEdit = new QLineEdit;
    rAegisLabel = new QLabel(tr("剩余气盾"));
    rAegisLineEdit = new QLineEdit;
    eRReductionLabel = new QLabel(tr("元素抗性减免"));
    eRReductionLineEdit = new QLineEdit;
    aARateLabel = new QLabel(tr("实际命中率"));
    aARateLineEdit = new QLineEdit;
    aCRateLabel = new QLabel(tr("实际会心率"));
    aCRateLineEdit = new QLineEdit;

    // 设置所有LineEdit为只读模式
    defenseLineEdit->setReadOnly(true);
    aegisLineEdit->setReadOnly(true);
    eResistanceLineEdit->setReadOnly(true);
    resilienceLineEdit->setReadOnly(true);
    blockLineEdit->setReadOnly(true);
    cResistanceLineEdit->setReadOnly(true);

    inputLayout3->addWidget(rDefenseLabel, 5, 0);
    inputLayout3->addWidget(rDefenseLineEdit, 6, 0);
    inputLayout3->addWidget(dReductionLabel, 5, 1);
    inputLayout3->addWidget(dReductionLineEdit, 6, 1);
    inputLayout3->addWidget(rAegisLabel, 5, 2);
    inputLayout3->addWidget(rAegisLineEdit, 6, 2);
    inputLayout3->addWidget(eRReductionLabel, 5, 3);
    inputLayout3->addWidget(eRReductionLineEdit, 6, 3);
    inputLayout3->addWidget(aARateLabel, 5, 4);
    inputLayout3->addWidget(aARateLineEdit, 6, 4);
    inputLayout3->addWidget(aCRateLabel, 5, 5);
    inputLayout3->addWidget(aCRateLineEdit, 6, 5);
}

void NshCalc::setupAttackTab() {}
void NshCalc::setupEAttackTab() {}
void NshCalc::setupDefenseBreakTab() {}
void NshCalc::setupAccuracyTab() {}
void NshCalc::setupCriticalTab() {}

template <>
int NshCalc::getValue<int>(QLineEdit *line) {
    bool ok;
    QString vStr = line->text();
    int vInt = vStr.toInt(&ok);
    return vInt;
}

template <>
double NshCalc::getValue<double>(QLineEdit *line) {
    bool ok;
    QString vStr = line->text();
    double vDouble = vStr.toDouble(&ok);
    return vDouble;
}


void NshCalc::calc()
{
    attack = getValue<int>(attackLineEdit);
    aPenetration = getValue<int>(aPenetrationLineEdit);
    sBreak = getValue<int>(sBreakLineEdit);
    eAttack = getValue<int>(eAttackLineEdit);
    advantage = getValue<int>(advantageLineEdit);
    accuracy = getValue<int>(accuracyLineEdit);
    cHit = getValue<int>(cHitLineEdit);
    cDamage = getValue<double>(cDamageLineEdit);
    bCRate = getValue<double>(bCRateLineEdit);
    rPercentage = getValue<double>(rPercentageLineEdit);
}

void NshCalc::onComboBoxChanged(int index)
{
    if (index == 0)
    {
        defense = 1600;
        aegis = 206;
        eResistance = 0;
        resilience = 0;
        block = 540;
        cResistance = 200;
    }
    else if (index == 1)
    {
        defense = 1600;
        aegis = 206;
        eResistance = 0;
        resilience = 0;
        block = 590;
        cResistance = 200;
    }
    else if (index == 2)
    {
        defense = 1600;
        aegis = 206;
        eResistance = 0;
        resilience = 0;
        block = 620;
        cResistance = 200;
    }
    else
    {
        defense = 1600;
        aegis = 206;
        eResistance = 0;
        resilience = 0;
        block = 265;
        cResistance = 200;
    }

    defenseLineEdit->setText(QString::number(defense));
    aegisLineEdit->setText(QString::number(aegis));
    eResistanceLineEdit->setText(QString::number(eResistance));
    resilienceLineEdit->setText(QString::number(resilience));
    blockLineEdit->setText(QString::number(block));
    cResistanceLineEdit->setText(QString::number(cResistance));

    calcTmpValue();
}

void NshCalc::calcTmpValue()
{
    calc();
    rDefense = std::max(defense - aPenetration, 0); //剩余防御
    dReduction = 1.0 * defense / (defense + 2860);  //防御减免
    rAegis = 0;     //剩余气盾
    eRReduction = 1.0 * eResistance / (eResistance + 530);      //元素抗性减免
    double tmpAARate = 1.0 * (143.0 * accuracy / (1.0 * accuracy + 713) - 143.0 * block / (1.0 * block + 713) + 95) / 100.0;
    aARate = std::min(tmpAARate, 1.0);              //实际命中率
    aCRate = ((115.0 * (cHit - cResistance) + 90) / (1.0 * (cHit - cResistance) + 940.0) / 100) + 1.0 * bCRate;     //实际会心率
    rDefenseLineEdit->setText(QString::number(rDefense));
    dReductionLineEdit->setText(QString::number(dReduction));
    rAegisLineEdit->setText(QString::number(rAegis));
    eRReductionLineEdit->setText(QString::number(eRReduction));
    aARateLineEdit->setText(QString::number(aARate * 100) + "%");
    aCRateLineEdit->setText(QString::number(aCRate * 100) + "%");
}

void NshCalc::setupSettingsTab(QGridLayout *layout)
{
    QWidget *tmpLayout4 = new QWidget;
    layout->addWidget(tmpLayout4);

    QLabel *imageLabel = new QLabel;
    QGridLayout *settingsLayout1 = new QGridLayout(tmpLayout4);
    QPixmap pixmap("../NshCalc/Nshlogo.jpg");
    imageLabel->setPixmap(pixmap.scaled(200, 200, Qt::KeepAspectRatio)); // 调整为200x200，保持宽高比
    settingsLayout1->addWidget(imageLabel, 0, 0);

    QWidget *tmpLayout5 = new QWidget(tmpLayout4);
    QHBoxLayout *textLayout = new QHBoxLayout(tmpLayout5);
    QTextEdit *textEdit1 = new QTextEdit;
    QString text = "QQ交流群号: 869597313\n";
    text += "Github: https://github.com/nameyouxuan/NshCalc\n";
    text += "感谢b站Up: 白宝正不正\n";
    text += "感谢贴吧星语困: https://tieba.baidu.com/p/8530450428?pn=1\n";
    text += "\n";
    text += "沧海月明大区: 剑啸水龙吟帮派";
    textEdit1->setPlainText(text);
    textEdit1->setReadOnly(true);
    textLayout->addWidget(textEdit1);
    settingsLayout1->addWidget(tmpLayout5, 0, 1);
}
