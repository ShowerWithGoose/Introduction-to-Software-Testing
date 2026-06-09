#include "components.h"

Component::Component(int lineNum, bool correct, ComponentEnum cType, TokenBlock tk)
{
    this->lineNum = lineNum;
    this->cType = cType;
    this->form = 0;
    this->tk = tk;
    this->correct = correct;
}
Component::Component(int lineNum, bool correct, ComponentEnum cType, int form, std::vector<Component *> parts)
{
    this->lineNum = lineNum;
    this->cType = cType;
    this->form = form;
    this->parts = parts;
    this->correct = correct;
}
Pattern::Pattern(std::vector<PUnit> units)
{
    this->units = units;
}
std::vector<PUnit> Pattern::getUnits() const
{
    return units;
}
PUnit::PUnit(AmountType aType, ComponentEnum data)
{
    this->aType = aType;
    this->dType = DataType::COMP;
    this->comp = data;
}
PUnit::PUnit(AmountType aType, TokenEnum data)
{
    this->aType = aType;
    this->dType = DataType::TK;
    this->tk = data;
}
PUnit::PUnit(AmountType aType, std::vector<PUnit> data)
{
    this->aType = aType;
    this->dType = DataType::SUBS;
    this->subUnits = data;
}
PUnit::PUnit(AmountType aType, std::vector<PUnit> data, DataType dType)
{
    this->aType = aType;
    this->dType = dType;
    this->subUnits = data;
}
PUnit::AmountType PUnit::getAType()
{
    return aType;
}
PUnit::DataType PUnit::getDType()
{
    return dType;
}
TokenEnum PUnit::getTk()
{
    return tk;
}
ComponentEnum PUnit::getComp()
{
    return comp;
}
std::vector<PUnit> PUnit::getSubUnits()
{
    return subUnits;
}
int Component::getLineNum()
{
    return lineNum;
}
bool Component::getCorrect()
{
    return correct;
}
std::vector<Component *> Component::getParts()
{
    return parts;
}
ComponentEnum Component::getCType()
{
    return cType;
}
TokenBlock Component::getTk()
{
    return tk;
}