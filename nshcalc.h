#ifndef NSHCALC_H
#define NSHCALC_H

#include <QMainWindow>
#include <QLabel>
#include <QLineEdit>
#include <QTextLine>
#include <QPushButton>
#include <QComboBox>
#include <QGridLayout>
#include <QTabWidget>

const double coefficient2 = 0.324;
const double coefficient1 = 923 * coefficient2;


class NshCalc : public QMainWindow
{
    Q_OBJECT

public:
    NshCalc(QWidget *parent = nullptr);
    ~NshCalc();

private slots:
    void setupInputTab(QGridLayout *layout);
    void setupAttackTab();
    void setupEAttackTab();
    void setupDefenseBreakTab();
    void setupAccuracyTab();
    void setupCriticalTab();
    void setupSettingsTab(QGridLayout *layout);
    void calc();

    void onComboBoxChanged(int index);
    void calcTmpValue();

    //    void setupTab(QWidget *tab, const QString &title, const QString &content);

public:
    template <typename T>
    T getValue(QLineEdit *line);

private:
    QTabWidget *tabWidget;
    QComboBox *selectComboBox;      //选择英雄舞阳Boss or 帮会木桩
    QGridLayout *inputLayout;       //输入攻击方面板属性
    QGridLayout *settingsLayout;
    QWidget *inputTab = new QWidget;            // 属性输入
    QWidget *attackTab = new QWidget;           // 攻击提升收益
    QWidget *eAttackTab = new QWidget;          // 元素攻击提升收益
    QWidget *defenseBreakTab = new QWidget;     // 破防提升收益
    QWidget *accuracyTab = new QWidget;         // 命中提升收益
    QWidget *criticalTab = new QWidget;         // 会心提升收益
    QWidget *settingsTab = new QWidget;          // 设置

    int defense;
    int aegis;
    int eResistance;
    int resilience;
    int block;
    int cResistance;


    QLabel *defenseLabel;           //防御        Defense
    QLineEdit *defenseLineEdit;
    QLabel *aegisLabel;             //气盾        Aegis
    QLineEdit *aegisLineEdit;
    QLabel *eResistanceLabel;       //元素抗性      Elemental Resistance
    QLineEdit *eResistanceLineEdit;
    QLabel *resilienceLabel;        //抵御        Resilience
    QLineEdit *resilienceLineEdit;
    QLabel *blockLabel;             //格挡        Block
    QLineEdit *blockLineEdit;
    QTextLine *blockTextLine;
    QLabel *cResistanceLabel;       //会心抵抗      Critical Resistance
    QLineEdit *cResistanceLineEdit;

    int attack;
    int aPenetration;
    int sBreak;
    int eAttack;
    int advantage;
    int accuracy;
    int cHit;
    double cDamage;
    double bCRate;
    double rPercentage;

    QLabel *attackLabel;            //攻击        Attack
    QLineEdit *attackLineEdit;
    QLabel *aPenetrationLabel;      //破防        Armor Penetration
    QLineEdit *aPenetrationLineEdit;
    QLabel *sBreakLabel;            //破盾        Shield Break
    QLineEdit *sBreakLineEdit;
    QLabel *eAttackLabel;           //元素攻击      Elemental Attack
    QLineEdit *eAttackLineEdit;
    QLabel *advantageLabel;         //克制         Advantage
    QLineEdit *advantageLineEdit;
    QLabel *accuracyLabel;          //命中        Accuracy
    QLineEdit *accuracyLineEdit;
    QLabel *cHitLabel;              //会心        Critical Hit
    QLineEdit *cHitLineEdit;
    QLabel *cDamageLabel;           //会伤        Critical Damage
    QLineEdit *cDamageLineEdit;
    QLabel *bCRateLabel;            //额外会心率     Bonus Critical Rate
    QLineEdit *bCRateLineEdit;
    QLabel *rPercentageLabel;        //克制百分比     Restraint Percentage
    QLineEdit *rPercentageLineEdit;

    int rDefense;
    double dReduction;
    int rAegis;
    double eRReduction;
    double aARate;
    double aCRate;
    int nCDamage;
    int eDCACritica;

    QLabel *rDefenseLabel;          // 剩余防御      Remaining Defense
    QLineEdit *rDefenseLineEdit;
    QLabel *dReductionLabel;        //防御减免      Defense Reduction
    QLineEdit *dReductionLineEdit;
    QLabel *rAegisLabel;            //剩余气盾      Remaining Aegis
    QLineEdit *rAegisLineEdit;
    QLabel *eRReductionLabel;       //元素抗性减免    Elemental Resistance Reduction
    QLineEdit *eRReductionLineEdit;
    QLabel *aARateLabel;            //实际命中率     Actual Accuracy Rate
    QLineEdit *aARateLineEdit;
    QLabel *aCRateLabel;            //实际会心率     Actual Critical Rate
    QLineEdit *aCRateLineEdit;
    QLabel *nCDamageLabel;          //未会心伤害     Non-Critical Damage
    QLineEdit *nCDamageLineEdit;
    QLabel *eDCACriticalLabel;      //包含命中会心的伤害期望   Expected Damage with Accurate Critical
    QLineEdit *eDCACriticalLineEdit;

    QLabel *attackBonus42Label;       //攻击提升42点
    QLineEdit *attackBonus42LineEdit;
    QLabel *defenseBreakBonus63Label;   //破防提升63点
    QLineEdit *defenseBreakBonus63LineEdit;
    QLabel *elementalAttackBonus27Label;  //元素攻击提升27点
    QLineEdit *elementalAttackBonus27LineEdit;
    QLabel *accuracyBonus21Label;   //命中提升21点
    QLineEdit *accuracyBonus21LineEdit;
    QLabel *criticalBonus25Label;   // 会心提升25点
    QLineEdit *criticalBonus25LineEdit;

    QLabel *attackBonus40Label;       //攻击提升40点
    QLineEdit *attackBonus40LineEdit;
    QLabel *defenseBreakBonus40Label;   //破防提升40点
    QLineEdit *defenseBreakBonus40LineEdit;
    QLabel *elementalAttackBonus40Label;  //元素攻击提升40点
    QLineEdit *elementalAttackBonus40LineEdit;
    QLabel *accuracyBonus40Label;   //命中提升40点
    QLineEdit *accuracyBonus40LineEdit;
    QLabel *criticalBonus40Label;   // 会心提升40点
    QLineEdit *criticalBonus40LineEdit;

    QPushButton *calcButton;        //计算
};
#endif // NSHCALC_H
