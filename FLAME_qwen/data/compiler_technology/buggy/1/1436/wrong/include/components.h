#ifndef COMPONENTS_H
#define COMPONENTS_H
#include "consts.h"
#include <string>
#include <vector>
struct TokenBlock
{
    TokenEnum key;
    int lineNum;
    std::string content;
    bool correct;
};
struct ErrorBlock
{
    int lineNum;
    char eType;
    bool operator<(const ErrorBlock &other) const
    {
        return lineNum > other.lineNum;
    }
};
class Component
{
private:
    ComponentEnum cType;
    int form;
    TokenBlock tk;
    std::vector<Component *> parts;
    bool correct;
    int lineNum;

public:
    Component(int lineNum, bool correct, ComponentEnum cType, TokenBlock tk);
    Component(int lineNum, bool correct, ComponentEnum cType, int form, std::vector<Component *> parts);
    bool getCorrect();
    std::vector<Component *> getParts();
    int getLineNum();
    ComponentEnum getCType();
    TokenBlock getTk();
};
class PUnit
{
public:
    enum AmountType
    {
        SINGLE,
        ZERO_ONE,
        OPTIONAL,
    };
    enum DataType
    {
        TK,
        COMP,
        SUBS,
        OR_SUBS,
    };


private:
    AmountType aType;
    DataType dType;
    TokenEnum tk;
    ComponentEnum comp;
    std::vector<PUnit> subUnits;

public:
    PUnit(AmountType aType, ComponentEnum data);
    PUnit(AmountType aType, TokenEnum data);
    PUnit(AmountType aType, std::vector<PUnit> data);
    PUnit(AmountType aType, std::vector<PUnit> data, DataType dType);
    AmountType getAType();
    DataType getDType();
    TokenEnum getTk();
    ComponentEnum getComp();
    std::vector<PUnit> getSubUnits();
};

class Pattern
{
private:
    std::vector<PUnit> units;

public:
    Pattern(std::vector<PUnit> units);
    std::vector<PUnit> getUnits() const;
};


#endif
