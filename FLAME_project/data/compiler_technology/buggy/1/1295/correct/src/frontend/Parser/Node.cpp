//
// Created by  on 2024/10/5.
//

#include "Node.h"

#include <utility>

std::unordered_map<frontend::Node *, bool> frontend::Node::all_nodes;
bool banOutput = false;

std::unordered_map<frontend::Node::NodeType, std::string> node_type_to_string_map = {
    {frontend::Node::NodeType::CompUnit, "<CompUnit>"},
    {frontend::Node::NodeType::Decl, ""},
    {frontend::Node::NodeType::ConstDecl, "<ConstDecl>"},
    {frontend::Node::NodeType::BType, ""},
    {frontend::Node::NodeType::ConstDef, "<ConstDef>"},
    {frontend::Node::NodeType::ConstInitVal, "<ConstInitVal>"},
    {frontend::Node::NodeType::VarDecl, "<VarDecl>"},
    {frontend::Node::NodeType::VarDef, "<VarDef>"},
    {frontend::Node::NodeType::InitVal, "<InitVal>"},
    {frontend::Node::NodeType::FuncDef, "<FuncDef>"},
    {frontend::Node::NodeType::MainFuncDef, "<MainFuncDef>"},
    {frontend::Node::NodeType::FuncType, "<FuncType>"},
    {frontend::Node::NodeType::FuncFParams, "<FuncFParams>"},
    {frontend::Node::NodeType::FuncFParam, "<FuncFParam>"},
    {frontend::Node::NodeType::Block, "<Block>"},
    {frontend::Node::NodeType::BlockItem, ""},
    {frontend::Node::NodeType::Stmt, "<Stmt>"},
    {frontend::Node::NodeType::ForStmt, "<ForStmt>"},
    {frontend::Node::NodeType::Exp, "<Exp>"},
    {frontend::Node::NodeType::Cond, "<Cond>"},
    {frontend::Node::NodeType::LVal, "<LVal>"},
    {frontend::Node::NodeType::PrimaryExp, "<PrimaryExp>"},
    {frontend::Node::NodeType::Number, "<Number>"},
    {frontend::Node::NodeType::Character, "<Character>"},
    {frontend::Node::NodeType::UnaryExp, "<UnaryExp>"},
    {frontend::Node::NodeType::UnaryOp, "<UnaryOp>"},
    {frontend::Node::NodeType::FuncRParams, "<FuncRParams>"},
    {frontend::Node::NodeType::MulExp, "<MulExp>"},
    {frontend::Node::NodeType::AddExp, "<AddExp>"},
    {frontend::Node::NodeType::RelExp, "<RelExp>"},
    {frontend::Node::NodeType::EqExp, "<EqExp>"},
    {frontend::Node::NodeType::LAndExp, "<LAndExp>"},
    {frontend::Node::NodeType::LOrExp, "<LOrExp>"},
    {frontend::Node::NodeType::ConstExp, "<ConstExp>"},
};

namespace frontend {

    Node::Node(Node::NodeType type) : type(type) {
        all_nodes[this] = false;
        PARSER_PRINT((node_type_to_string_map[type]));
    }

    CompUnit::CompUnit(const std::vector<Decl *> &decls, const std::vector<FuncDef *> &funcDefs,
                       MainFuncDef *mainFuncDef) : Node(NodeType::CompUnit) {
        childNode.insert(childNode.end(), decls.begin(), decls.end());
        childNode.insert(childNode.end(), funcDefs.begin(), funcDefs.end());
        childNode.insert(childNode.end(), mainFuncDef);
    }

    Decl::Decl(ConstDecl *constDecl) : Node(NodeType::Decl), constDecl(constDecl) {
        childNode.push_back(constDecl);
    }

    Decl::Decl(VarDecl *varDecl) : Node(NodeType::Decl), varDecl(varDecl) {
        childNode.push_back(varDecl);
    }

    ConstDecl::ConstDecl(BType *bType, const std::vector<ConstDef *> &constDefs) :
            Node(NodeType::ConstDecl), bType(bType), constDefs(constDefs) {
        childNode.push_back(bType);
        childNode.insert(childNode.end(), constDefs.begin(), constDefs.end());
    }

    BType::BType(Token *token) : Node(NodeType::BType), token(token) {}

    ConstDef::ConstDef(Token *identToken, const std::vector<ConstExp *> &constExps, ConstInitVal *constInitVal) :
            Node(NodeType::ConstDef), identToken(identToken), constExps(constExps), constInitVal(constInitVal) {
        childNode.insert(childNode.end(), constExps.begin(), constExps.end());
        childNode.push_back(constInitVal);
    }

    ConstInitVal::ConstInitVal(ConstExp *constExp) : Node(NodeType::ConstInitVal), constExp(constExp) {
        childNode.push_back(constExp);
    }

    ConstInitVal::ConstInitVal(const std::vector<ConstInitVal *> &constInitVals) :
            Node(NodeType::ConstInitVal), constInitVals(constInitVals) {
        childNode.insert(childNode.end(), constInitVals.begin(), constInitVals.end());
    }

    ConstInitVal::ConstInitVal(Token *strConst) : Node(NodeType::ConstInitVal), strConst(strConst) {
    }

    VarDecl::VarDecl(BType *bType, const std::vector<VarDef *> &varDefs) :
            Node(NodeType::VarDecl), bType(bType), varDefs(varDefs) {
        childNode.push_back(bType);
        childNode.insert(childNode.end(), varDefs.begin(), varDefs.end());
    }

    VarDef::VarDef(Token *identToken, const std::vector<ConstExp *> &constExps) :
            Node(NodeType::VarDef), identToken(identToken), constExps(constExps) {
        childNode.insert(childNode.end(), constExps.begin(), constExps.end());
    }

    VarDef::VarDef(Token *identToken, const std::vector<ConstExp *> &constExps, InitVal *initVal) :
            Node(NodeType::VarDef), identToken(identToken), constExps(constExps), initVal(initVal) {
        childNode.insert(childNode.end(), constExps.begin(), constExps.end());
        childNode.push_back(initVal);
    }

    InitVal::InitVal(Exp *exp) : Node(NodeType::InitVal), exp(exp) {
        childNode.push_back(exp);
    }

    InitVal::InitVal(const std::vector<InitVal *> &initVals) : Node(NodeType::InitVal), initVals(initVals) {
        childNode.insert(childNode.end(), initVals.begin(), initVals.end());
    }

    InitVal::InitVal(Token *strConst) : Node(NodeType::InitVal), strConst(strConst) {

    }

    FuncDef::FuncDef(FuncType *funcType, Token *identToken, FuncFParams *funcFParams, Block *block) :
            Node(NodeType::FuncDef), funcType(funcType), identToken(identToken), funcFParams(funcFParams),
            block(block) {
        childNode.push_back(funcType);
        childNode.push_back(funcFParams);
        childNode.push_back(block);
    }

    MainFuncDef::MainFuncDef(Block *block) : Node(NodeType::MainFuncDef), block(block) {
        childNode.push_back(block);
    }

    FuncType::FuncType(Token *token) : Node(NodeType::FuncType), token(token) {}

    FuncFParams::FuncFParams(const std::vector<FuncFParam *> &funcFParamList) :
            Node(NodeType::FuncFParams), funcFParamList(funcFParamList) {
        childNode.insert(childNode.end(), funcFParamList.begin(), funcFParamList.end());
    }

    FuncFParam::FuncFParam(BType *bType, Token *identToken, Token *lbrack, Token *rblack,
                           const std::vector<ConstExp *> &constExps) :
            Node(NodeType::FuncFParam), bType(bType), identToken(identToken), lbrack(lbrack),
            rblack(rblack), constExps(constExps) {

    }

    Block::Block(const std::vector<BlockItem *> &blockItems) : Node(NodeType::Block), blockItems(blockItems) {
        childNode.insert(childNode.end(), blockItems.begin(), blockItems.end());
    }

    BlockItem::BlockItem(Decl *decl) : Node(NodeType::BlockItem), decl(decl) {
        childNode.push_back(decl);
    }

    BlockItem::BlockItem(Stmt *stmt) : Node(NodeType::BlockItem), stmt(stmt) {
        childNode.push_back(stmt);
    }

    Stmt::Stmt(LVal *lVal, Exp *exp) : Node(NodeType::Stmt), stmtType(StmtType::AssignStmt), lVal(lVal), exp(exp) {
        childNode.push_back(lVal);
        childNode.push_back(exp);
    }

    Stmt::Stmt(Exp *exp) : Node(NodeType::Stmt), stmtType(StmtType::ExpStmt), exp(exp) {
        childNode.push_back(exp);
    }

    Stmt::Stmt(Block *block) : Node(NodeType::Stmt), stmtType(StmtType::BlockStmt), block(block) {
        childNode.push_back(block);
    }

    Stmt::Stmt(Cond *cond, Stmt *stmt1, Stmt *stmt2) :
            Node(NodeType::Stmt), stmtType(StmtType::ConditionStmt), cond(cond), stmt1(stmt1), stmt2(stmt2) {
        childNode.push_back(cond);
        childNode.push_back(stmt1);
        childNode.push_back(stmt2);
    }

    Stmt::Stmt(ForStmt *init, Cond *cond, ForStmt *iter, Stmt *stmt) :
            Node(NodeType::Stmt), stmtType(StmtType::ForStmt), init(init), cond(cond), iter(iter), stmt(stmt) {
        childNode.push_back(init);
        childNode.push_back(cond);
        childNode.push_back(iter);
        childNode.push_back(stmt);
    }

    Stmt::Stmt(Stmt::StmtType type, Token *conBreakTK) : Node(NodeType::Stmt), stmtType(type), conBreakTK(conBreakTK) {}

    Stmt::Stmt(Stmt::StmtType type, Exp *exp) : Node(NodeType::Stmt), stmtType(type), exp(exp) {}

    Stmt::Stmt(Token *formatStr, const std::vector<Exp *> &formatParams) : Node(NodeType::Stmt),
                                                                           stmtType(StmtType::PrintfStmt),
                                                                           formatStr(formatStr),
                                                                           formatParams(formatParams) {
        childNode.insert(childNode.end(), formatParams.begin(), formatParams.end());
    }

    Stmt::Stmt(Stmt::StmtType type, LVal *lVal) : Node(NodeType::Stmt), stmtType(type), lVal(lVal) {
        childNode.push_back(lVal);
    }


    ForStmt::ForStmt(LVal *lVal, Exp *exp) : Node(NodeType::ForStmt), lVal(lVal), exp(exp) {
        childNode.push_back(lVal);
        childNode.push_back(exp);
    }

    Exp::Exp(AddExp *addExp) : Node(NodeType::Exp), addExp(addExp) {
        childNode.push_back(addExp);
    }

    Cond::Cond(LOrExp *lOrExp) : Node(NodeType::Cond), lOrExp(lOrExp) {
        childNode.push_back(lOrExp);
    }

    LVal::LVal(Token *identToken, const std::vector<Exp *> &exps) : Node(NodeType::LVal), identToken(identToken),
                                                                    exps(exps) {
        childNode.insert(childNode.end(), exps.begin(), exps.end());
    }

    PrimaryExp::PrimaryExp(Exp *exp) : Node(NodeType::PrimaryExp), exp(exp) {
        childNode.push_back(exp);
    }

    PrimaryExp::PrimaryExp(LVal *lVal) : Node(NodeType::PrimaryExp), lVal(lVal) {
        childNode.push_back(lVal);
    }

    PrimaryExp::PrimaryExp(Number *number) : Node(NodeType::PrimaryExp), number(number) {
        childNode.push_back(number);
    }

    PrimaryExp::PrimaryExp(Character *character) : Node(NodeType::PrimaryExp), character(character) {
        childNode.push_back(character);
    }

    Number::Number(Token *token) : Node(NodeType::Number), token(token) {}


    Character::Character(Token *token) : Node(NodeType::Character), token(token) {

    }

    UnaryExp::UnaryExp(PrimaryExp *primaryExp) : Node(NodeType::UnaryExp), primaryExp(primaryExp) {
        childNode.push_back(primaryExp);
    }

    UnaryExp::UnaryExp(Token *identToken, FuncRParams *funcRParams) :
            Node(NodeType::UnaryExp), identToken(identToken), funcRParams(funcRParams) {
        childNode.push_back(funcRParams);
    }

    UnaryExp::UnaryExp(UnaryOp *unaryOp, UnaryExp *unaryExp) : Node(NodeType::UnaryExp), unaryOp(unaryOp),
                                                               unaryExp(unaryExp) {
        childNode.push_back(unaryOp);
        childNode.push_back(unaryExp);
    }

    UnaryOp::UnaryOp(Token *token) : Node(NodeType::UnaryOp), token(token) {}

    FuncRParams::FuncRParams(const std::vector<Exp *> &exps) : Node(NodeType::FuncRParams), exps(exps) {
        childNode.insert(childNode.end(), exps.begin(), exps.end());
    }

    MulExp::MulExp(UnaryExp *unaryExp) : Node(NodeType::MulExp), unaryExp(unaryExp) {
        childNode.push_back(unaryExp);
    }

    MulExp::MulExp(MulExp *mulExp, Token *op, UnaryExp *unaryExp) : Node(NodeType::MulExp), mulExp(mulExp), op(op),
                                                                    unaryExp(unaryExp) {
        childNode.push_back(mulExp);
        childNode.push_back(unaryExp);
    }

    AddExp::AddExp(MulExp *mulExp, Token *op, AddExp *addExp) : Node(NodeType::AddExp), mulExp(mulExp), addExp(addExp),
                                                                op(op) {
        childNode.push_back(addExp);
        childNode.push_back(mulExp);
    }

    AddExp::AddExp(MulExp *mulExp) : Node(NodeType::AddExp), mulExp(mulExp) {
        childNode.push_back(mulExp);
    }

    RelExp::RelExp(AddExp *addExp) : Node(NodeType::RelExp), addExp(addExp) {
        childNode.push_back(addExp);
    }

    RelExp::RelExp(RelExp *relExp, Token *op, AddExp *addExp) : Node(NodeType::RelExp), relExp(relExp), op(op),
                                                                addExp(addExp) {
        childNode.push_back(relExp);
        childNode.push_back(addExp);
    }

    EqExp::EqExp(RelExp *relExp) : Node(NodeType::EqExp), relExp(relExp) {
        childNode.push_back(relExp);
    }

    EqExp::EqExp(EqExp *eqExp, Token *op, RelExp *relExp) : Node(NodeType::EqExp), eqExp(eqExp), op(op),
                                                            relExp(relExp) {
        childNode.push_back(eqExp);
        childNode.push_back(relExp);
    }

    LAndExp::LAndExp(EqExp *eqExp) : Node(NodeType::LAndExp), eqExp(eqExp) {
        childNode.push_back(eqExp);
    }

    LAndExp::LAndExp(LAndExp *lAndExp, Token *op, EqExp *eqExp) : Node(NodeType::LAndExp), lAndExp(lAndExp), op(op),
                                                                  eqExp(eqExp) {
        childNode.push_back(lAndExp);
        childNode.push_back(eqExp);
    }

    LOrExp::LOrExp(LAndExp *lAndExp) : Node(NodeType::LOrExp), lAndExp(lAndExp) {
        childNode.push_back(lAndExp);
    }

    LOrExp::LOrExp(LOrExp *lOrExp, Token *op, LAndExp *lAndExp) : Node(NodeType::LOrExp), lOrExp(lOrExp), op(op),
                                                                  lAndExp(lAndExp) {
        childNode.push_back(lOrExp);
        childNode.push_back(lAndExp);
    }

    ConstExp::ConstExp(AddExp *addExp) : Node(NodeType::ConstExp), addExp(addExp) {
        childNode.push_back(addExp);
    }


} // frontend