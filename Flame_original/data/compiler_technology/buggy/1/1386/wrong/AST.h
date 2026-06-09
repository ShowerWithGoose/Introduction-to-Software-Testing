

#ifndef COMPILER_AST_H
#define COMPILER_AST_H

#include "tools.h"
#include <vector>
class ASTNode{
public:
    virtual int createNode(Lexer *lexer);    //  0不做处理
    virtual std::string toString();
    void outputNode(Lexer*);
    void addChild(ASTNode);
    std::vector<ASTNode> child;
    std::string value;
};
enum CompUnitChild{
    CDecl,VDecl,FuncDef,MainFuncDef
};
enum class StmtChild{
    LVal,Exp
};
enum class UnaryExpChild{
    LVal,Ident
};
class CompUnitAST : public ASTNode{
    std::string toString();
    int createNode(Lexer *lexer);
private:
    enum CompUnitChild peek(Lexer *lexer);
};
class DeclNode : public ASTNode{
    std::string toString();
    int createNode(Lexer *lexer);
};
class ConstDeclNode : public ASTNode{
    std::string toString();
    int createNode(Lexer *lexer);
};

class BTypeNode : public ASTNode{
    std::string toString();
    int createNode(Lexer *lexer);
};
class ConstDefNode : public ASTNode{
    std::string toString();
    int createNode(Lexer *lexer);
};
class ConstInitValNode : public  ASTNode{
    std::string toString();
    int createNode(Lexer *lexer);
};
class VarDeclNode : public ASTNode{
    std::string toString();
    int createNode(Lexer *lexer);
};
class VarDefNode : public ASTNode{
    std::string toString();
    int createNode(Lexer *lexer);
};
class InitValNode :public ASTNode{
    std::string toString();
    int createNode(Lexer *lexer);
};
class FuncDefNode : public ASTNode{
    std::string toString();
    int createNode(Lexer *lexer);
};
class MainFuncDefNode : public ASTNode{
    std::string toString();
    int createNode(Lexer *lexer);
};
class FuncTypeNode : public ASTNode{
    std::string toString();
    int createNode(Lexer *lexer);
};
class FuncFParamsNode :public ASTNode{
    std::string toString();
    int createNode(Lexer *lexer);
};
class FuncFParamNode :public ASTNode{
    std::string toString();
    int createNode(Lexer *lexer);
};
class BlockNode :public ASTNode{
    std::string toString();
    int createNode(Lexer *lexer);
};
class BlockItemNode :public ASTNode{
    std::string toString();
    int createNode(Lexer *lexer);
};
class StmtNode :public ASTNode{
    std::string toString();
    int createNode(Lexer *lexer);
private:
    enum StmtChild peek(Lexer *lexer);
};
class ForStmtNode :public ASTNode{
    std::string toString();
    int createNode(Lexer *lexer);
};
class ExpNode :public ASTNode{
    std::string toString();
    int createNode(Lexer *lexer);
};
class CondNode :public ASTNode{
    std::string toString();
    int createNode(Lexer *lexer);
};
class LValNode :public ASTNode{
    std::string toString();
    int createNode(Lexer *lexer);
};
class PrimaryExpNode :public ASTNode{
    std::string toString();
    int createNode(Lexer *lexer);
};
class NumberNode :public ASTNode{
    std::string toString();
    int createNode(Lexer *lexer);
};
class CharacterNode :public ASTNode{
    std::string toString();
    int createNode(Lexer *lexer);
};
class UnaryExpNode :public ASTNode{
    std::string toString();
    int createNode(Lexer *lexer);
    UnaryExpChild peek(Lexer *lexer);

};
class UnaryOpNode :public ASTNode{
    std::string toString();
    int createNode(Lexer *lexer);
};
class FuncRParamsNode :public ASTNode{
    std::string toString();
    int createNode(Lexer *lexer);
};
class MulExpNode :public ASTNode{
    std::string toString();
    int createNode(Lexer *lexer);
};
class AddExpNode :public ASTNode{
    std::string toString();
    int createNode(Lexer *lexer);
};
class RelExpNode :public ASTNode{
    std::string toString();
    int createNode(Lexer *lexer);
};
class EqExpNode :public ASTNode{
    std::string toString();
    int createNode(Lexer *lexer);
};
class LAndExpNode :public ASTNode{
    std::string toString();
    int createNode(Lexer *lexer);
};
class LOrExpNode :public ASTNode{
    std::string toString();
    int createNode(Lexer *lexer);
};
class ConstExpNode :public ASTNode{
    std::string toString();
    int createNode(Lexer *lexer);
};
class IDENFRNode : public ASTNode {
    std::string toString();
};
class INTCONNode : public ASTNode {
    std::string toString();
    int createNode(Lexer *lexer);
};
class STRCONNode : public ASTNode {
    std::string toString();
    int createNode(Lexer *lexer);
};
class CHRCONNode : public ASTNode {
    std::string toString();
    int createNode(Lexer *lexer);
};
class MAINTKNode : public ASTNode {
    std::string toString();
};
class CONSTTKNode : public ASTNode {
    std::string toString();
};
class INTTKNode : public ASTNode {
    std::string toString();
};
class CHARTKNode : public ASTNode {
    std::string toString();
};
class BREAKTKNode : public ASTNode {
    std::string toString();
};
class CONTINUETKNode : public ASTNode {
    std::string toString();
};
class IFTKNode : public ASTNode {
    std::string toString();
};
class ELSETKNode : public ASTNode {
    std::string toString();
};
class NOTNode : public ASTNode {
    std::string toString();
};
class ANDNode : public ASTNode {
    std::string toString();
};
class ORNode : public ASTNode {
    std::string toString();
};
class FORTKNode : public ASTNode {
    std::string toString();
};
class GETINTTKNode : public ASTNode {
    std::string toString();
};
class GETCHARTKNode : public ASTNode {
    std::string toString();
};
class PRINTFTKNode : public ASTNode {
    std::string toString();
};
class RETURNTKNode : public ASTNode {
    std::string toString();
};
class PLUSNode : public ASTNode {
    std::string toString();
};
class MINUNode : public ASTNode {
    std::string toString();
};
class VOIDTKNode : public ASTNode {
    std::string toString();
};
class MULTNode : public ASTNode {
    std::string toString();
};
class DIVNode : public ASTNode {
    std::string toString();
};
class MODNode : public ASTNode {
    std::string toString();
};
class LSSNode : public ASTNode {
    std::string toString();
};
class LEQNode : public ASTNode {
    std::string toString();
};
class GRENode : public ASTNode {
    std::string toString();
};
class GEQNode : public ASTNode {
    std::string toString();
};
class EQLNode : public ASTNode {
    std::string toString();
};
class NEQNode : public ASTNode {
    std::string toString();
};
class ASSIGNNode : public ASTNode {
    std::string toString();
};
class SEMICNNode : public ASTNode {
    std::string toString();
};
class COMMANode : public ASTNode {
    std::string toString();
};
class LPARENTNode : public ASTNode {
    std::string toString();
};
class RPARENTNode : public ASTNode {
    std::string toString();
};
class LBRACKNode : public ASTNode {
    std::string toString();
};
class RBRACKNode : public ASTNode {
    std::string toString();
};
class LBRACENode : public ASTNode {
    std::string toString();
};
class RBRACENode : public ASTNode {
    std::string toString();
};

#endif //COMPILER_AST_H
