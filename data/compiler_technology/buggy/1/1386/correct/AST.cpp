
#include "AST.h"
#include <memory>

static bool needOutput = true;
int tLine = 0;
int isExpFirst(Lexer *lexer) {
    return lexer->token.type == Symbol::IDENFR
           || lexer->token.type == Symbol::LPARENT
           || lexer->token.type == Symbol::INTCON
           || lexer->token.type == Symbol::CHRCON
           || lexer->token.type == Symbol::PLUS
           || lexer->token.type == Symbol::MINU
           || lexer->token.type == Symbol::NOT;
}

int ASTNode::createNode(Lexer *lexer) {
    if(!(lexer->isPeeking)){
        lexer->outputToken();
        tLine = lexer->line;
    }
    lexer->getToken();
    return 0;
}

std::string ASTNode::toString() {
    return "";
}

std::string CompUnitAST::toString() {
    return "CompUnit";
}

std::string DeclNode::toString() {
    return "Decl";
}

std::string ConstDeclNode::toString() {
    return "ConstDecl";
}

std::string BTypeNode::toString() {
    return "BType";
}

std::string ConstDefNode::toString() {
    return "ConstDef";
}

std::string ConstInitValNode::toString() {
    return "ConstInitVal";
}

std::string VarDeclNode::toString() {
    return "VarDecl";
}

std::string VarDefNode::toString() {
    return "VarDef";
}

std::string InitValNode::toString() {
    return "InitVal";
}

std::string FuncDefNode::toString() {
    return "FuncDef";
}

std::string MainFuncDefNode::toString() {
    return "MainFuncDef";
}

std::string FuncTypeNode::toString() {
    return "FuncType";
}

std::string FuncFParamsNode::toString() {
    return "FuncFParams";
}

std::string FuncFParamNode::toString() {
    return "FuncFParam";
}

std::string BlockNode::toString() {
    return "Block";
}

std::string BlockItemNode::toString() {
    return "BlockItem";
}

std::string StmtNode::toString() {
    return "Stmt";
}

std::string ForStmtNode::toString() {
    return "ForStmt";
}

std::string ExpNode::toString() {
    return "Exp";
}

std::string CondNode::toString() {
    return "Cond";
}

std::string LValNode::toString() {
    return "LVal";
}

std::string PrimaryExpNode::toString() {
    return "PrimaryExp";
}

std::string NumberNode::toString() {
    return "Number";
}

std::string CharacterNode::toString() {
    return "Character";
}

std::string UnaryExpNode::toString() {
    return "UnaryExp";
}

std::string UnaryOpNode::toString() {
    return "UnaryOp";
}

std::string FuncRParamsNode::toString() {
    return "FuncRParams";
}

std::string MulExpNode::toString() {
    return "MulExp";
}

std::string AddExpNode::toString() {
    return "AddExp";
}

std::string RelExpNode::toString() {
    return "RelExp";
}

std::string EqExpNode::toString() {
    return "EqExp";
}

std::string LAndExpNode::toString() {
    return "LAndExp";
}

std::string LOrExpNode::toString() {
    return "LOrExp";
}

std::string ConstExpNode::toString() {
    return "ConstExp";
}

std::string IDENFRNode::toString() {
    return "IDENFR";
}

std::string INTCONNode::toString() {
    return "INTCON";
}

std::string STRCONNode::toString() {
    return "STRCON";
}

std::string CHRCONNode::toString() {
    return "CHRCON";
}

std::string MAINTKNode::toString() {
    return "MAINTK";
}

std::string CONSTTKNode::toString() {
    return "CONSTTK";
}

std::string INTTKNode::toString() {
    return "INTTK";
}

std::string CHARTKNode::toString() {
    return "CHARTK";
}

std::string BREAKTKNode::toString() {
    return "BREAKTK";
}

std::string CONTINUETKNode::toString() {
    return "CONTINUETK";
}

std::string IFTKNode::toString() {
    return "IFTK";
}

std::string ELSETKNode::toString() {
    return "ELSETK";
}

std::string NOTNode::toString() {
    return "NOT";
}

std::string ANDNode::toString() {
    return "AND";
}

std::string ORNode::toString() {
    return "OR";
}

std::string FORTKNode::toString() {
    return "FORTK";
}

std::string GETINTTKNode::toString() {
    return "GETINTTK";
}

std::string GETCHARTKNode::toString() {
    return "GETCHARTK";
}

std::string PRINTFTKNode::toString() {
    return "PRINTFTK";
}

std::string RETURNTKNode::toString() {
    return "RETURNTK";
}

std::string PLUSNode::toString() {
    return "PLUS";
}

std::string MINUNode::toString() {
    return "MINU";
}

std::string VOIDTKNode::toString() {
    return "VOIDTK";
}

std::string MULTNode::toString() {
    return "MULT";
}

std::string DIVNode::toString() {
    return "DIV";
}

std::string MODNode::toString() {
    return "MOD";
}

std::string LSSNode::toString() {
    return "LSS";
}

std::string LEQNode::toString() {
    return "LEQ";
}

std::string GRENode::toString() {
    return "GRE";
}

std::string GEQNode::toString() {
    return "GEQ";
}

std::string EQLNode::toString() {
    return "EQL";
}

std::string NEQNode::toString() {
    return "NEQ";
}

std::string ASSIGNNode::toString() {
    return "ASSIGN";
}

std::string SEMICNNode::toString() {
    return "SEMICN";
}

std::string COMMANode::toString() {
    return "COMMA";
}

std::string LPARENTNode::toString() {
    return "LPARENT";
}

std::string RPARENTNode::toString() {
    return "RPARENT";
}

std::string LBRACKNode::toString() {
    return "LBRACK";
}

std::string RBRACKNode::toString() {
    return "RBRACK";
}

std::string LBRACENode::toString() {
    return "LBRACE";
}

std::string RBRACENode::toString() {
    return "RBRACE";
}

int INTCONNode::createNode(Lexer *lexer) {
    value = lexer->token.value;
    if(!(lexer->isPeeking))lexer->outputToken();
    lexer->getToken();
    return 0;
}

int CHRCONNode::createNode(Lexer *lexer) {
    value = lexer->token.value;
    if(!(lexer->isPeeking)) lexer->outputToken();
    lexer->getToken();
    return 0;
}

int STRCONNode::createNode(Lexer *lexer) {
    value = lexer->token.value;
    if(!(lexer->isPeeking))lexer->outputToken();
    lexer->getToken();
    return 0;
}

void ASTNode::addChild(ASTNode astNode) {
    this->child.push_back(astNode);
}

void ASTNode::outputNode(Lexer *lexer) {
    lexer->output << '<' << this->toString() << '>' << std::endl;
}

int CompUnitAST::createNode(Lexer *lexer) {
    auto childSymbol = peek(lexer);
    while (childSymbol == VDecl || childSymbol == CDecl) {
        std::shared_ptr<ASTNode> child;
        child = std::make_shared<DeclNode>();
        this->addChild(*child);
        child->createNode(lexer);
        childSymbol = peek(lexer);
    }
    while (childSymbol == FuncDef) {
        std::shared_ptr<ASTNode> child;
        child = std::make_shared<FuncDefNode>();
        this->addChild(*child);
        child->createNode(lexer);
        childSymbol = peek(lexer);
    }
    if (childSymbol == MainFuncDef) {
        std::shared_ptr<ASTNode> child;
        child = std::make_shared<MainFuncDefNode>();
        this->addChild(*child);
        child->createNode(lexer);
    }
    if (needOutput && !(lexer->isPeeking))this->outputNode(lexer);
    return 0;
}

enum CompUnitChild CompUnitAST::peek(Lexer *lexer) {
    std::streampos mark = lexer->input.tellg();
    auto token = lexer->token;
    lexer->startPeeking();
    CompUnitChild type;
    switch (lexer->token.type) {
        case CONSTTK:
            type = CDecl;
            break;
        case VOIDTK:
            type = FuncDef;
            break;
        case CHARTK:
            lexer->getToken();
            lexer->getToken();
            if (lexer->token.type == LPARENT)type = FuncDef;
            else type = VDecl;
            break;
        case INTTK:
            lexer->getToken();
            if (lexer->token.type == MAINTK) {
                type = MainFuncDef;
                break;
            } else {
                lexer->getToken();
                if (lexer->token.type == LPARENT)type = FuncDef;
                else type = VDecl;
            }
        default:
            break;
    }
    lexer->finishPeeking();
    lexer->input.seekg(mark);
    lexer->token = token;
    return type;
}

int DeclNode::createNode(Lexer *lexer) {
    std::shared_ptr<ASTNode> child;
    switch (lexer->token.type) {
        case CONSTTK:         //const
            child = std::make_shared<ConstDeclNode>();
            this->addChild(*child);
            child->createNode(lexer);
            break;
        default:
            child = std::make_shared<VarDeclNode>();
            this->addChild(*child);
            child->createNode(lexer);
    }
    return 0;
}

int ConstDeclNode::createNode(Lexer *lexer) {
    std::shared_ptr<ASTNode> child;
    child = std::make_shared<CONSTTKNode>();
    this->addChild(*child);
    child->createNode(lexer);
    child = std::make_shared<BTypeNode>();
    this->addChild(*child);
    child->createNode(lexer);
    child = std::make_shared<ConstDefNode>();
    this->addChild(*child);
    child->createNode(lexer);
    while (lexer->token.type == Symbol::COMMA) {
        child = std::make_shared<COMMANode>();
        this->addChild(*child);
        child->createNode(lexer);
        child = std::make_shared<ConstDefNode>();
        this->addChild(*child);
        child->createNode(lexer);
    }
    if (lexer->token.type != Symbol::SEMICN) {
        lexer->errorOutput(ErrorType::i,tLine);
    } else {
        child = std::make_shared<SEMICNNode>();
        this->addChild(*child);
        child->createNode(lexer);
    }
    if (needOutput && !(lexer->isPeeking))this->outputNode(lexer);
    return 0;
}

int BTypeNode::createNode(Lexer *lexer) {
    std::shared_ptr<ASTNode> child;
    if (lexer->token.type == Symbol::INTTK) {
        child = std::make_shared<INTTKNode>();
    } else {
        child = std::make_shared<CHARTKNode>();
    }
    this->addChild(*child);
    child->createNode(lexer);
    return 0;
}

int ConstDefNode::createNode(Lexer *lexer) {
    std::shared_ptr<ASTNode> child;
    child = std::make_shared<IDENFRNode>();
    this->addChild(*child);
    child->createNode(lexer);
    if (lexer->token.type == Symbol::LBRACK) {
        child = std::make_shared<LBRACKNode>();
        this->addChild(*child);
        child->createNode(lexer);
        child = std::make_shared<ConstExpNode>();
        this->addChild(*child);
        child->createNode(lexer);
        if (lexer->token.type == Symbol::RBRACK) {
            child = std::make_shared<RBRACKNode>();
            this->addChild(*child);
            child->createNode(lexer);
        } else {
            lexer->errorOutput(ErrorType::k,tLine);
        }
    }
    child = std::make_shared<ASSIGNNode>();
    this->addChild(*child);
    child->createNode(lexer);
    child = std::make_shared<ConstInitValNode>();
    this->addChild(*child);
    child->createNode(lexer);
    if (needOutput && !(lexer->isPeeking))this->outputNode(lexer);
    return 0;
}

int ConstInitValNode::createNode(Lexer *lexer) {
    std::shared_ptr<ASTNode> child;
    switch (lexer->token.type) {
        case Symbol::STRCON :
            child = std::make_shared<STRCONNode>();
            this->addChild(*child);
            child->createNode(lexer);
            break;
        case Symbol::LBRACE :
            child = std::make_shared<LBRACKNode>();
            this->addChild(*child);
            child->createNode(lexer);
            if (lexer->token.type != Symbol::RBRACE){
                child = std::make_shared<ConstExpNode>();
                this->addChild(*child);
                child->createNode(lexer);
                while (lexer->token.type == Symbol::COMMA) {
                    child = std::make_shared<COMMANode>();
                    this->addChild(*child);
                    child->createNode(lexer);
                    child = std::make_shared<ConstExpNode>();
                    this->addChild(*child);
                    child->createNode(lexer);
                }
            }
            child = std::make_shared<RBRACENode>();
            this->addChild(*child);
            child->createNode(lexer);
            break;
        default:
            child = std::make_shared<ConstExpNode>();
            this->addChild(*child);
            child->createNode(lexer);
            break;
    }
    if (needOutput && !(lexer->isPeeking))this->outputNode(lexer);
    return 0;
}

int VarDeclNode::createNode(Lexer *lexer) {
    std::shared_ptr<ASTNode> child;
    child = std::make_shared<BTypeNode>();
    this->addChild(*child);
    child->createNode(lexer);
    child = std::make_shared<VarDefNode>();
    this->addChild(*child);
    child->createNode(lexer);
    while (lexer->token.type == Symbol::COMMA) {
        child = std::make_shared<COMMANode>();
        this->addChild(*child);
        child->createNode(lexer);
        child = std::make_shared<VarDefNode>();
        this->addChild(*child);
        child->createNode(lexer);
    }
    if (lexer->token.type == Symbol::SEMICN) {
        child = std::make_shared<SEMICNNode>();
        this->addChild(*child);
        child->createNode(lexer);
    } else {
        lexer->errorOutput(ErrorType::i,tLine);
    }
    if (needOutput && !(lexer->isPeeking))this->outputNode(lexer);
    return 0;
}

int VarDefNode::createNode(Lexer *lexer) {
    std::shared_ptr<ASTNode> child;
    child = std::make_shared<IDENFRNode>();
    this->addChild(*child);
    child->createNode(lexer);
    if (lexer->token.type == Symbol::LBRACK) {
        child = std::make_shared<LBRACKNode>();
        this->addChild(*child);
        child->createNode(lexer);
        child = std::make_shared<ConstExpNode>();
        this->addChild(*child);
        child->createNode(lexer);
        if (lexer->token.type != Symbol::RBRACK) {
            lexer->errorOutput(ErrorType::k,tLine);
        } else {
            child = std::make_shared<RBRACKNode>();
            this->addChild(*child);
            child->createNode(lexer);
        }
    }
    if (lexer->token.type == Symbol::ASSIGN) {
        child = std::make_shared<ASSIGNNode>();
        this->addChild(*child);
        child->createNode(lexer);
        child = std::make_shared<InitValNode>();
        this->addChild(*child);
        child->createNode(lexer);
    }
    if (needOutput && !(lexer->isPeeking))this->outputNode(lexer);
    return 0;
}

int InitValNode::createNode(Lexer *lexer) {
    std::shared_ptr<ASTNode> child;
    if (lexer->token.type == Symbol::LBRACE) {
        child = std::make_shared<LBRACENode>();
        this->addChild(*child);
        child->createNode(lexer);
        if (lexer->token.type == Symbol::RBRACE) {
            child = std::make_shared<RBRACENode>();
            this->addChild(*child);
            child->createNode(lexer);
        } else {
            child = std::make_shared<ExpNode>();
            this->addChild(*child);
            child->createNode(lexer);
            while (lexer->token.type == Symbol::COMMA) {
                child = std::make_shared<COMMANode>();
                this->addChild(*child);
                child->createNode(lexer);
                child = std::make_shared<ExpNode>();
                this->addChild(*child);
                child->createNode(lexer);
            }
            child = std::make_shared<RBRACENode>();
            this->addChild(*child);
            child->createNode(lexer);
        }
    } else if (lexer->token.type == Symbol::STRCON) {
        child = std::make_shared<STRCONNode>();
        this->addChild(*child);
        child->createNode(lexer);
    } else {
        child = std::make_shared<ExpNode>();
        this->addChild(*child);
        child->createNode(lexer);
    }
    if (needOutput && !(lexer->isPeeking))this->outputNode(lexer);
    return 0;
}

int FuncDefNode::createNode(Lexer *lexer) {
    std::shared_ptr<ASTNode> child;
    child = std::make_shared<FuncTypeNode>();
    this->addChild(*child);
    child->createNode(lexer);
    child = std::make_shared<IDENFRNode>();
    this->addChild(*child);
    child->createNode(lexer);
    child = std::make_shared<LPARENTNode>();
    this->addChild(*child);
    child->createNode(lexer);
    if (lexer->token.type == Symbol::INTTK || lexer->token.type == Symbol::CHARTK) {
        child = std::make_shared<FuncFParamsNode>();
        this->addChild(*child);
        child->createNode(lexer);
    }
    if (lexer->token.type != Symbol::RPARENT) {
        lexer->errorOutput(ErrorType::j,tLine);
    } else {
        child = std::make_shared<RPARENTNode>();
        this->addChild(*child);
        child->createNode(lexer);
    }
    child = std::make_shared<BlockNode>();
    this->addChild(*child);
    child->createNode(lexer);
    if (needOutput && !(lexer->isPeeking))this->outputNode(lexer);
    return 0;
}

int MainFuncDefNode::createNode(Lexer *lexer) {
    std::shared_ptr<ASTNode> child;
    child = std::make_shared<INTTKNode>();
    this->addChild(*child);
    child->createNode(lexer);
    child = std::make_shared<MAINTKNode>();
    this->addChild(*child);
    child->createNode(lexer);
    child = std::make_shared<LPARENTNode>();
    this->addChild(*child);
    child->createNode(lexer);
    if (lexer->token.type == Symbol::RPARENT) {
        child = std::make_shared<RPARENTNode>();
        this->addChild(*child);
        child->createNode(lexer);
    } else {
        lexer->errorOutput(ErrorType::j,tLine);
    }
    child = std::make_shared<BlockNode>();
    this->addChild(*child);
    child->createNode(lexer);
    if (needOutput && !(lexer->isPeeking))this->outputNode(lexer);
    return 0;
}

int FuncTypeNode::createNode(Lexer *lexer) {
    std::shared_ptr<ASTNode> child;
    switch (lexer->token.type) {
        case VOIDTK:
            child = std::make_shared<VOIDTKNode>();
            this->addChild(*child);
            child->createNode(lexer);
            break;
        case INTTK:
            child = std::make_shared<INTTKNode>();
            this->addChild(*child);
            child->createNode(lexer);
            break;
        case CHARTK:
            child = std::make_shared<CHARTKNode>();
            this->addChild(*child);
            child->createNode(lexer);
            break;
    }
    if (needOutput && !(lexer->isPeeking))this->outputNode(lexer);
    return 0;
}

int FuncFParamsNode::createNode(Lexer *lexer) {
    std::shared_ptr<ASTNode> child;
    child = std::make_shared<FuncFParamNode>();
    this->addChild(*child);
    child->createNode(lexer);
    while (lexer->token.type == Symbol::COMMA) {
        child = std::make_shared<COMMANode>();
        this->addChild(*child);
        child->createNode(lexer);
        child = std::make_shared<FuncFParamNode>();
        this->addChild(*child);
        child->createNode(lexer);
    }
    if (needOutput && !(lexer->isPeeking))this->outputNode(lexer);
    return 0;
}

int FuncFParamNode::createNode(Lexer *lexer) {
    std::shared_ptr<ASTNode> child;
    child = std::make_shared<BTypeNode>();
    this->addChild(*child);
    child->createNode(lexer);
    child = std::make_shared<IDENFRNode>();
    this->addChild(*child);
    child->createNode(lexer);
    if (lexer->token.type == Symbol::LBRACK) {
        child = std::make_shared<LBRACKNode>();
        this->addChild(*child);
        child->createNode(lexer);
        if (lexer->token.type == Symbol::RBRACK) {
            child = std::make_shared<RBRACKNode>();
            this->addChild(*child);
            child->createNode(lexer);
        } else lexer->errorOutput(ErrorType::k,tLine);
    }
    if (needOutput && !(lexer->isPeeking))this->outputNode(lexer);
    return 0;
}

int BlockNode::createNode(Lexer *lexer) {
    std::shared_ptr<ASTNode> child;
    child = std::make_shared<LBRACENode>();
    this->addChild(*child);
    child->createNode(lexer);
    while (lexer->token.type != Symbol::RBRACE) {
        child = std::make_shared<BlockItemNode>();
        this->addChild(*child);
        child->createNode(lexer);
    }
    child = std::make_shared<RBRACENode>();
    this->addChild(*child);
    child->createNode(lexer);
    if (needOutput && !(lexer->isPeeking))this->outputNode(lexer);
    return 0;
}

int BlockItemNode::createNode(Lexer *lexer) {
    std::shared_ptr<ASTNode> child;
    if (lexer->token.type == Symbol::CONSTTK
        || lexer->token.type == Symbol::INTTK
        || lexer->token.type == Symbol::CHARTK) {
        child = std::make_shared<DeclNode>();
        this->addChild(*child);
        child->createNode(lexer);
    } else {
        child = std::make_shared<StmtNode>();
        this->addChild(*child);
        child->createNode(lexer);
    }
    return 0;
}

int StmtNode::createNode(Lexer *lexer) {
    std::shared_ptr<ASTNode> child;
    switch (lexer->token.type) {
        case IFTK:
            child = std::make_shared<IFTKNode>();
            this->addChild(*child);
            child->createNode(lexer);
            child = std::make_shared<LPARENTNode>();
            this->addChild(*child);
            child->createNode(lexer);
            child = std::make_shared<CondNode>();
            this->addChild(*child);
            child->createNode(lexer);
            if (lexer->token.type != Symbol::RPARENT) {
                lexer->errorOutput(ErrorType::j,tLine);
            } else {
                child = std::make_shared<RPARENTNode>();
                this->addChild(*child);
                child->createNode(lexer);
            }
            child = std::make_shared<StmtNode>();
            this->addChild(*child);
            child->createNode(lexer);
            if (lexer->token.type == Symbol::ELSETK) {
                child = std::make_shared<ELSETKNode>();
                this->addChild(*child);
                child->createNode(lexer);
                child = std::make_shared<StmtNode>();
                this->addChild(*child);
                child->createNode(lexer);
            }
            break;
        case FORTK:
            child = std::make_shared<FORTKNode>();
            this->addChild(*child);
            child->createNode(lexer);
            child = std::make_shared<LPARENTNode>();
            this->addChild(*child);
            child->createNode(lexer);
            if (lexer->token.type != Symbol::SEMICN) {
                child = std::make_shared<ForStmtNode>();
                this->addChild(*child);
                child->createNode(lexer);
            }
            child = std::make_shared<SEMICNNode>();
            this->addChild(*child);
            child->createNode(lexer);
            if (lexer->token.type != Symbol::SEMICN) {
                child = std::make_shared<CondNode>();
                this->addChild(*child);
                child->createNode(lexer);
            }
            child = std::make_shared<SEMICNNode>();
            this->addChild(*child);
            child->createNode(lexer);
            if (lexer->token.type != Symbol::RPARENT) {
                child = std::make_shared<ForStmtNode>();
                this->addChild(*child);
                child->createNode(lexer);
            }
            child = std::make_shared<RPARENTNode>();
            this->addChild(*child);
            child->createNode(lexer);
            child = std::make_shared<StmtNode>();
            this->addChild(*child);
            child->createNode(lexer);
            break;
        case BREAKTK:
            child = std::make_shared<BREAKTKNode>();
            this->addChild(*child);
            child->createNode(lexer);
            if (lexer->token.type == Symbol::SEMICN) {
                child = std::make_shared<SEMICNNode>();
                this->addChild(*child);
                child->createNode(lexer);
            } else {
                lexer->errorOutput(ErrorType::i,tLine);
            }
            break;
        case CONTINUETK:
            child = std::make_shared<CONTINUETKNode>();
            this->addChild(*child);
            child->createNode(lexer);
            if (lexer->token.type == Symbol::SEMICN) {
                child = std::make_shared<SEMICNNode>();
                this->addChild(*child);
                child->createNode(lexer);
            } else {
                lexer->errorOutput(ErrorType::i,tLine);
            }
            break;
        case RETURNTK:
            child = std::make_shared<RETURNTKNode>();
            this->addChild(*child);
            child->createNode(lexer);
            if (isExpFirst(lexer)) {
                child = std::make_shared<ExpNode>();
                this->addChild(*child);
                child->createNode(lexer);
            }
            if (lexer->token.type != Symbol::SEMICN) lexer->errorOutput(ErrorType::i,tLine);
            else {
                child = std::make_shared<SEMICNNode>();
                this->addChild(*child);
                child->createNode(lexer);
            }
            break;
        case PRINTFTK:
            child = std::make_shared<PRINTFTKNode>();
            this->addChild(*child);
            child->createNode(lexer);
            child = std::make_shared<LPARENTNode>();
            this->addChild(*child);
            child->createNode(lexer);
            child = std::make_shared<STRCONNode>();
            this->addChild(*child);
            child->createNode(lexer);
            while (lexer->token.type == Symbol::COMMA) {
                child = std::make_shared<COMMANode>();
                this->addChild(*child);
                child->createNode(lexer);
                child = std::make_shared<ExpNode>();
                this->addChild(*child);
                child->createNode(lexer);
            }
            if (lexer->token.type == Symbol::RPARENT) {
                child = std::make_shared<RPARENTNode>();
                this->addChild(*child);
                child->createNode(lexer);
            } else lexer->errorOutput(ErrorType::j,tLine);
            if (lexer->token.type == Symbol::SEMICN) {
                child = std::make_shared<SEMICNNode>();
                this->addChild(*child);
                child->createNode(lexer);
            } else lexer->errorOutput(ErrorType::i,tLine);
            break;
        case LBRACE:
            child = std::make_shared<BlockNode>();
            this->addChild(*child);
            child->createNode(lexer);
            break;
        case IDENFR:
            if (this->peek(lexer) == StmtChild::LVal) {
                child = std::make_shared<LValNode>();
                this->addChild(*child);
                child->createNode(lexer);
                child = std::make_shared<ASSIGNNode>();
                this->addChild(*child);
                child->createNode(lexer);
                switch (lexer->token.type) {
                    case GETINTTK:
                        child = std::make_shared<GETINTTKNode>();
                        this->addChild(*child);
                        child->createNode(lexer);
                        child = std::make_shared<LPARENTNode>();
                        this->addChild(*child);
                        child->createNode(lexer);
                        if (lexer->token.type == Symbol::RPARENT) {
                            child = std::make_shared<RPARENTNode>();
                            this->addChild(*child);
                            child->createNode(lexer);
                        } else lexer->errorOutput(ErrorType::j,tLine);
                        if (lexer->token.type == Symbol::SEMICN) {
                            child = std::make_shared<SEMICNNode>();
                            this->addChild(*child);
                            child->createNode(lexer);
                        } else lexer->errorOutput(ErrorType::i,tLine);
                        break;
                    case GETCHARTK:
                        child = std::make_shared<GETCHARTKNode>();
                        this->addChild(*child);
                        child->createNode(lexer);
                        child = std::make_shared<LPARENTNode>();
                        this->addChild(*child);
                        child->createNode(lexer);
                        if (lexer->token.type == Symbol::RPARENT) {
                            child = std::make_shared<RPARENTNode>();
                            this->addChild(*child);
                            child->createNode(lexer);
                        } else lexer->errorOutput(ErrorType::j,tLine);
                        if (lexer->token.type == Symbol::SEMICN) {
                            child = std::make_shared<SEMICNNode>();
                            this->addChild(*child);
                            child->createNode(lexer);
                        } else lexer->errorOutput(ErrorType::i,tLine);
                        break;
                    default:
                        child = std::make_shared<ExpNode>();
                        this->addChild(*child);
                        child->createNode(lexer);
                        if (lexer->token.type == Symbol::SEMICN) {
                            child = std::make_shared<SEMICNNode>();
                            this->addChild(*child);
                            child->createNode(lexer);
                        } else lexer->errorOutput(ErrorType::i,tLine);
                        break;
                }
                break;
            }
        default:
            if (isExpFirst(lexer)) {
                child = std::make_shared<ExpNode>();
                this->addChild(*child);
                child->createNode(lexer);
            }
            if (lexer->token.type != Symbol::SEMICN) lexer->errorOutput(ErrorType::i,tLine);
            else {
                child = std::make_shared<SEMICNNode>();
                this->addChild(*child);
                child->createNode(lexer);
            }
            break;
    }
    if (needOutput && !(lexer->isPeeking))this->outputNode(lexer);
    return 0;
}

StmtChild StmtNode::peek(Lexer *lexer) {
    std::streampos mark = lexer->input.tellg();
    auto token = lexer->token;
    lexer->startPeeking();
    StmtChild type;
    lexer->getToken();
    if (lexer->token.type == LBRACK) {
        lexer->getToken();
        std::shared_ptr<ASTNode> tExp;
        tExp = std::make_shared<ExpNode>();
        tExp->createNode(lexer);
        if (lexer->token.type == Symbol::RBRACK) {
            lexer->getToken();
        }
        if (lexer->token.type == Symbol::ASSIGN) type = StmtChild::LVal;
        else type = StmtChild::Exp;
    } else if (lexer->token.type == Symbol::ASSIGN) type = StmtChild::LVal;
    else type = StmtChild::Exp;
    lexer->finishPeeking();
    lexer->token = token;
    lexer->input.seekg(mark);
    return type;
}

int ForStmtNode::createNode(Lexer *lexer) {
    std::shared_ptr<ASTNode> child;
    child = std::make_shared<LValNode>();
    this->addChild(*child);
    child->createNode(lexer);
    child = std::make_shared<ASSIGNNode>();
    this->addChild(*child);
    child->createNode(lexer);
    child = std::make_shared<ExpNode>();
    this->addChild(*child);
    child->createNode(lexer);
    if (needOutput && !(lexer->isPeeking))this->outputNode(lexer);
    return 0;
}

int ExpNode::createNode(Lexer *lexer) {
    std::shared_ptr<ASTNode> child;
    child = std::make_shared<AddExpNode>();
    this->addChild(*child);
    child->createNode(lexer);
    if (needOutput && !(lexer->isPeeking))this->outputNode(lexer);
    return 0;
}

int CondNode::createNode(Lexer *lexer) {
    std::shared_ptr<ASTNode> child;
    child = std::make_shared<LOrExpNode>();
    this->addChild(*child);
    child->createNode(lexer);
    if (needOutput && !(lexer->isPeeking))this->outputNode(lexer);
    return 0;
}

int LValNode::createNode(Lexer *lexer) {
    std::shared_ptr<ASTNode> child;
    child = std::make_shared<IDENFRNode>();
    this->addChild(*child);
    child->createNode(lexer);
    if (lexer->token.type == Symbol::LBRACK) {
        child = std::make_shared<LBRACKNode>();
        this->addChild(*child);
        child->createNode(lexer);
        child = std::make_shared<ExpNode>();
        this->addChild(*child);
        child->createNode(lexer);
        if (lexer->token.type == Symbol::RBRACK) {
            child = std::make_shared<RBRACKNode>();
            this->addChild(*child);
            child->createNode(lexer);
        } else if(!(lexer->isPeeking)) lexer->errorOutput(ErrorType::k,tLine);
    }
    if (needOutput && !(lexer->isPeeking))this->outputNode(lexer);
    return 0;
}

int PrimaryExpNode::createNode(Lexer *lexer) {
    std::shared_ptr<ASTNode> child;
    switch (lexer->token.type) {
        case LPARENT:
            child = std::make_shared<LPARENTNode>();
            this->addChild(*child);
            child->createNode(lexer);
            child = std::make_shared<ExpNode>();
            this->addChild(*child);
            child->createNode(lexer);
            if (lexer->token.type == Symbol::RPARENT) {
                child = std::make_shared<RPARENTNode>();
                this->addChild(*child);
                child->createNode(lexer);
            } else if(!(lexer->isPeeking)) lexer->errorOutput(ErrorType::j,tLine);
            break;
        case IDENFR:
            child = std::make_shared<LValNode>();
            this->addChild(*child);
            child->createNode(lexer);
            break;
        case INTCON:
            child = std::make_shared<NumberNode>();
            this->addChild(*child);
            child->createNode(lexer);
            break;
        case CHRCON:
            child = std::make_shared<CharacterNode>();
            this->addChild(*child);
            child->createNode(lexer);
            break;
    }
    if (needOutput && !(lexer->isPeeking))this->outputNode(lexer);
    return 0;
}

int NumberNode::createNode(Lexer *lexer) {
    std::shared_ptr<ASTNode> child;
    child = std::make_shared<INTCONNode>();
    this->addChild(*child);
    child->createNode(lexer);
    if (needOutput && !(lexer->isPeeking))this->outputNode(lexer);
    return 0;
}

int CharacterNode::createNode(Lexer *lexer) {
    std::shared_ptr<ASTNode> child;
    child = std::make_shared<CHRCONNode>();
    this->addChild(*child);
    child->createNode(lexer);
    if (needOutput && !(lexer->isPeeking))this->outputNode(lexer);
    return 0;
}

UnaryExpChild UnaryExpNode::peek(Lexer *lexer) {
    std::streampos mark = lexer->input.tellg();
    auto token = lexer->token;
    lexer->startPeeking();
    UnaryExpChild type;
    lexer->getToken();
    if (lexer->token.type == Symbol::LPARENT)type = UnaryExpChild::Ident;
    else type = UnaryExpChild::LVal;
    lexer->finishPeeking();
    lexer->input.seekg(mark);
    lexer->token = token;
    return type;
}

int UnaryExpNode::createNode(Lexer *lexer) {
    std::shared_ptr<ASTNode> child;
    switch (lexer->token.type) {
        case PLUS:
        case MINU:
        case NOT:
            child = std::make_shared<UnaryOpNode>();
            this->addChild(*child);
            child->createNode(lexer);
            child = std::make_shared<UnaryExpNode>();
            this->addChild(*child);
            child->createNode(lexer);
            break;
        case IDENFR:
            if (this->peek(lexer) == UnaryExpChild::Ident) {
                child = std::make_shared<IDENFRNode>();
                this->addChild(*child);
                child->createNode(lexer);
                child = std::make_shared<LPARENTNode>();
                this->addChild(*child);
                child->createNode(lexer);
                if (isExpFirst(lexer)) {
                    child = std::make_shared<FuncRParamsNode>();
                    this->addChild(*child);
                    child->createNode(lexer);
                }
                if (lexer->token.type == Symbol::RPARENT) {
                    child = std::make_shared<RPARENTNode>();
                    this->addChild(*child);
                    child->createNode(lexer);
                } else if (!(lexer->isPeeking)) lexer->errorOutput(ErrorType::j,tLine);
                break;
            }

        default:
            child = std::make_shared<PrimaryExpNode>();
            this->addChild(*child);
            child->createNode(lexer);
            break;
    }
    if (needOutput && !(lexer->isPeeking))this->outputNode(lexer);
    return 0;
}

int UnaryOpNode::createNode(Lexer *lexer) {
    std::shared_ptr<ASTNode> child;
    switch (lexer->token.type) {
        case PLUS:
            child = std::make_shared<PLUSNode>();
            this->addChild(*child);
            child->createNode(lexer);
            break;
        case MINU:
            child = std::make_shared<MINUNode>();
            this->addChild(*child);
            child->createNode(lexer);
            break;
        case NOT:
            child = std::make_shared<NOTNode>();
            this->addChild(*child);
            child->createNode(lexer);
            break;
    }
    if (needOutput && !(lexer->isPeeking))this->outputNode(lexer);
    return 0;
}

int FuncRParamsNode::createNode(Lexer *lexer) {
    std::shared_ptr<ASTNode> child;
    child = std::make_shared<ExpNode>();
    this->addChild(*child);
    child->createNode(lexer);
    while (lexer->token.type == Symbol::COMMA) {
        child = std::make_shared<COMMANode>();
        this->addChild(*child);
        child->createNode(lexer);
        child = std::make_shared<ExpNode>();
        this->addChild(*child);
        child->createNode(lexer);
    }
    if (needOutput && !(lexer->isPeeking))this->outputNode(lexer);
    return 0;
}

int isMulSig(Lexer *lexer) {
    return lexer->token.type == Symbol::MULT
           || lexer->token.type == Symbol::DIV
           || lexer->token.type == Symbol::MOD;
}

int MulExpNode::createNode(Lexer *lexer) {
    std::shared_ptr<ASTNode> child;
    child = std::make_shared<UnaryExpNode>();
    this->addChild(*child);
    child->createNode(lexer);
    while (isMulSig(lexer)) {
        if (needOutput && !(lexer->isPeeking))this->outputNode(lexer);
        switch (lexer->token.type) {
            case MULT:
                child = std::make_shared<MULTNode>();
                this->addChild(*child);
                child->createNode(lexer);
                break;
            case DIV:
                child = std::make_shared<DIVNode>();
                this->addChild(*child);
                child->createNode(lexer);
                break;
            case MOD:
                child = std::make_shared<MODNode>();
                this->addChild(*child);
                child->createNode(lexer);
                break;

        }
        child = std::make_shared<UnaryExpNode>();
        this->addChild(*child);
        child->createNode(lexer);
    }
    if (needOutput && !(lexer->isPeeking))this->outputNode(lexer);
    return 0;
}

int isAddSig(Lexer *lexer) {
    return lexer->token.type == Symbol::PLUS
           || lexer->token.type == Symbol::MINU;
}

int AddExpNode::createNode(Lexer *lexer) {
    std::shared_ptr<ASTNode> child;
    child = std::make_shared<MulExpNode>();
    this->addChild(*child);
    child->createNode(lexer);
    while (isAddSig(lexer)) {
        if (needOutput && !(lexer->isPeeking))this->outputNode(lexer);
        switch (lexer->token.type) {
            case PLUS:
                child = std::make_shared<PLUSNode>();
                this->addChild(*child);
                child->createNode(lexer);
                break;
            case MINU:
                child = std::make_shared<MINUNode>();
                this->addChild(*child);
                child->createNode(lexer);
                break;
        }
        child = std::make_shared<MulExpNode>();
        this->addChild(*child);
        child->createNode(lexer);
    }
    if (needOutput && !(lexer->isPeeking))this->outputNode(lexer);
    return 0;
}

int isRelSig(Lexer *lexer) {
    return lexer->token.type == Symbol::LSS
           || lexer->token.type == Symbol::LEQ
           || lexer->token.type == Symbol::GRE
           || lexer->token.type == Symbol::GEQ;
}

int RelExpNode::createNode(Lexer *lexer) {
    std::shared_ptr<ASTNode> child;
    child = std::make_shared<AddExpNode>();
    this->addChild(*child);
    child->createNode(lexer);
    while (isRelSig(lexer)) {
        if (needOutput && !(lexer->isPeeking))this->outputNode(lexer);
        switch (lexer->token.type) {
            case LSS:
                child = std::make_shared<LSSNode>();
                this->addChild(*child);
                child->createNode(lexer);
                break;
            case LEQ:
                child = std::make_shared<LEQNode>();
                this->addChild(*child);
                child->createNode(lexer);
                break;
            case GRE:
                child = std::make_shared<GRENode>();
                this->addChild(*child);
                child->createNode(lexer);
                break;
            case GEQ:
                child = std::make_shared<GEQNode>();
                this->addChild(*child);
                child->createNode(lexer);
                break;
        }
        child = std::make_shared<AddExpNode>();
        this->addChild(*child);
        child->createNode(lexer);
    }
    if (needOutput && !(lexer->isPeeking))this->outputNode(lexer);
    return 0;
}

int isEqSig(Lexer *lexer) {
    return lexer->token.type == Symbol::EQL || lexer->token.type == Symbol::NEQ;
}

int EqExpNode::createNode(Lexer *lexer) {
    std::shared_ptr<ASTNode> child;
    child = std::make_shared<RelExpNode>();
    this->addChild(*child);
    child->createNode(lexer);
    while (isEqSig(lexer)) {
        if (needOutput && !(lexer->isPeeking))this->outputNode(lexer);
        switch (lexer->token.type) {
            case EQL:
                child = std::make_shared<EQLNode>();
                this->addChild(*child);
                child->createNode(lexer);
                break;
            case NEQ:
                child = std::make_shared<NEQNode>();
                this->addChild(*child);
                child->createNode(lexer);
                break;
        }
        child = std::make_shared<RelExpNode>();
        this->addChild(*child);
        child->createNode(lexer);
    }
    if (needOutput && !(lexer->isPeeking))this->outputNode(lexer);
    return 0;
}

int LAndExpNode::createNode(Lexer *lexer) {
    std::shared_ptr<ASTNode> child;
    child = std::make_shared<EqExpNode>();
    this->addChild(*child);
    child->createNode(lexer);
    while (lexer->token.type == Symbol::AND) {
        if (needOutput && !(lexer->isPeeking))this->outputNode(lexer);
        child = std::make_shared<ANDNode>();
        this->addChild(*child);
        child->createNode(lexer);
        child = std::make_shared<EqExpNode>();
        this->addChild(*child);
        child->createNode(lexer);
    }
    if (needOutput && !(lexer->isPeeking))this->outputNode(lexer);
    return 0;
}

int LOrExpNode::createNode(Lexer *lexer) {
    std::shared_ptr<ASTNode> child;
    child = std::make_shared<LAndExpNode>();
    this->addChild(*child);
    child->createNode(lexer);
    while (lexer->token.type == Symbol::OR) {
        if (needOutput && !(lexer->isPeeking))this->outputNode(lexer);
        child = std::make_shared<ORNode>();
        this->addChild(*child);
        child->createNode(lexer);
        child = std::make_shared<LAndExpNode>();
        this->addChild(*child);
        child->createNode(lexer);
    }
    if (needOutput && !(lexer->isPeeking))this->outputNode(lexer);
    return 0;
}

int ConstExpNode::createNode(Lexer *lexer) {
    std::shared_ptr<ASTNode> child;
    child = std::make_shared<AddExpNode>();
    this->addChild(*child);
    child->createNode(lexer);
    if (needOutput && !(lexer->isPeeking))this->outputNode(lexer);
    return 0;
}