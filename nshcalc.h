#ifndef NSHCALC_H
#define NSHCALC_H

#include <QMainWindow>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

class NshCalc : public QMainWindow
{
    Q_OBJECT

public:
    NshCalc(QWidget *parent = nullptr);
    ~NshCalc();

private slots:
    void calcTabel1();
    void calcTabel2();
    void calcTabel3();
    void calcTabel4();
    void calcTabel5();


private:
    QLabel *defenseLabel;           //防御        Defense
    QLineEdit *defenseLineEdit;
    QLabel *eResistanceLabel;       //元素抗性      Elemental Resistance
    QLineEdit *eResistanceLineEdit;
    QLabel *resilienceLabel;        //抵御        Resilience
    QLineEdit *resilienceLineEdit;
    QLabel *blockLabel;             //格挡        Block
    QLineEdit *blockLineEdit;
    QLabel *cResistanceLabel;       //会心抵抗      Critical Resistance
    QLineEdit *cResistanceLineEdit;


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


    QLabel *rDefenseLabel;          //剩余防御      Remaining Defense
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
    QPushButton *calcButton;        //计算
};
#endif // NSHCALC_H
