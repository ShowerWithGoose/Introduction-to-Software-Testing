//
// Created by  on 2024/10/6.
//

#include "Parser.h"


namespace frontend {
    Parser::Parser(Lexer *lexer, const std::string &parser_path) : lexer(lexer) {
        parserFile.open(parser_path);
    }

    Node *Parser::parse() {
        return parseCompUnit();
    }

    CompUnit *Parser::parseCompUnit() {
        std::vector<Decl *> decls;
        std::vector<FuncDef *> funcDefs;
        MainFuncDef *mainFuncDef = nullptr;
        while (lexer->has_next()) {
            if (lexer->has_next(2) && lexer->ahead_of(2)->is_type(Token::TokenType::LPARENT)) {
                if (lexer->ahead_of(1)->is_type(Token::TokenType::MAINTK)) {
                    mainFuncDef = parseMainFuncDef();
                } else {
                    funcDefs.push_back(parseFuncDef());
                }
            } else {
                decls.push_back(parseDecl());
            }
        }
        return new CompUnit(decls, funcDefs, mainFuncDef);
    }

    Decl *Parser::parseDecl() {
        if (lexer->has_next() && lexer->cur_token()->is_type(Token::TokenType::CONSTTK)) {
            auto constDecl = parseConstDecl();
            return new Decl(constDecl);
        } else {
            auto varDecl = parseVarDecl();
            return new Decl(varDecl);
        }
    }

    ConstDecl *Parser::parseConstDecl() {
        lexer->next_assert(Token::TokenType::CONSTTK);
        auto bType = parseBType();
        std::vector<ConstDef *> constDefs;
        constDefs.push_back(parseConstDef());
        while (lexer->has_next() && lexer->cur_token()->is_type(Token::TokenType::COMMA)) {
            lexer->next();
            constDefs.push_back(parseConstDef());
        }
        lexer->next_assert(Token::TokenType::SEMICN);
        return new ConstDecl(bType, constDefs);
    }

    BType *Parser::parseBType() {
        if (lexer->has_next() && lexer->cur_token()->is_type(Token::TokenType::INTTK)) {
            auto cur = lexer->next();
            return new BType(cur);
        } else if (lexer->has_next() && lexer->cur_token()->is_type(Token::TokenType::CHARTK)) {
            auto cur = lexer->next();
            return new BType(cur);
        } else {
            throw std::runtime_error("expect int or char");
        }
    }

    ConstDef *Parser::parseConstDef() {
        auto identToken = lexer->next_assert(Token::TokenType::IDENFR);
        std::vector<ConstExp *> constExps;
        while (lexer->has_next() && !lexer->cur_token()->is_type(Token::TokenType::ASSIGN)) {
            lexer->next_assert(Token::TokenType::LBRACK);
            constExps.push_back(parseConstExp());
            lexer->next_assert(Token::TokenType::RBRACK);
        }
        lexer->next_assert(Token::TokenType::ASSIGN);
        auto constInitVal = parseConstInitVal();
        return new ConstDef(identToken, constExps, constInitVal);
    }

    ConstInitVal *Parser::parseConstInitVal() {
        if (lexer->has_next() && lexer->cur_token()->is_type(Token::TokenType::LBRACE)) {
            banOutput = true;
            std::vector<ConstInitVal *> constInitVals;
            lexer->next_assert(Token::TokenType::LBRACE);
            if (lexer->has_next() && !lexer->cur_token()->is_type(Token::TokenType::RBRACE)) {
                constInitVals.push_back(parseConstInitVal());
                while (lexer->has_next() && lexer->cur_token()->is_type(Token::TokenType::COMMA)) {
                    lexer->next();
                    constInitVals.push_back(parseConstInitVal());
                }
            }
            lexer->next_assert(Token::TokenType::RBRACE);
            banOutput = false;
            return new ConstInitVal(constInitVals);
        } else if (lexer->has_next() && lexer->cur_token()->is_type(Token::TokenType::STRCON)) {
            auto strToken = lexer->next();
            return new ConstInitVal(strToken);
        } else {
            auto constExp = parseConstExp();
            return new ConstInitVal(constExp);
        }
    }

    VarDecl *Parser::parseVarDecl() {
        auto bType = parseBType();
        std::vector<VarDef *> varDefs;
        varDefs.push_back(parseVarDef());
        while (lexer->has_next() && lexer->cur_token()->is_type(Token::TokenType::COMMA)) {
            lexer->next();
            varDefs.push_back(parseVarDef());
        }
        lexer->next_assert(Token::TokenType::SEMICN);
        return new VarDecl(bType, varDefs);
    }

    VarDef *Parser::parseVarDef() {
        auto identToken = lexer->next_assert(Token::TokenType::IDENFR);
        std::vector<ConstExp *> constExps;
        InitVal *initVal = nullptr;
        while (lexer->has_next() && lexer->cur_token()->is_type(Token::TokenType::LBRACK)) {
            lexer->next_assert(Token::TokenType::LBRACK);
            constExps.push_back(parseConstExp());
            lexer->next_assert(Token::TokenType::RBRACK);
        }
        if (lexer->has_next() && lexer->cur_token()->is_type(Token::TokenType::ASSIGN)) {
            lexer->next();
            initVal = parseInitVal();
            return new VarDef(identToken, constExps, initVal);
        } else {
            return new VarDef(identToken, constExps);
        }
    }

    InitVal *Parser::parseInitVal() {
        std::vector<InitVal *> initVals;
        if (lexer->has_next() && lexer->cur_token()->is_type(Token::TokenType::LBRACE)) {
            banOutput = true;
            lexer->next_assert(Token::TokenType::LBRACE);
            if (lexer->has_next() && !lexer->cur_token()->is_type(Token::TokenType::RBRACE)) {
                initVals.push_back(parseInitVal());
                while (lexer->has_next() && lexer->cur_token()->is_type(Token::TokenType::COMMA)) {
                    lexer->next();
                    initVals.push_back(parseInitVal());
                }
            }
            lexer->next_assert(Token::TokenType::RBRACE);
            banOutput = false;
            return new InitVal(initVals);
        } else if (lexer->has_next() && lexer->cur_token()->is_type(Token::TokenType::STRCON)) {
            auto strToken = lexer->next();
            return new InitVal(strToken);
        } else {
            auto exp = parseExp();
            return new InitVal(exp);
        }
    }

    FuncDef *Parser::parseFuncDef() {
        auto funcType = parseFuncType();
        auto identToken = lexer->next_assert(Token::TokenType::IDENFR);
        lexer->next_assert(Token::TokenType::LPARENT);
        FuncFParams *funcFParams = nullptr;

        if (lexer->has_next() && !lexer->cur_token()->is_type(Token::TokenType::RPARENT) && !lexer->cur_token()->is_type(Token::TokenType::LBRACE)) {
            funcFParams = parseFuncFParams();
        }
        lexer->next_assert(Token::TokenType::RPARENT);
        auto block = parseBlock();
        return new FuncDef(funcType, identToken, funcFParams, block);
    }

    MainFuncDef *Parser::parseMainFuncDef() {
        lexer->next_assert(Token::TokenType::INTTK);
        lexer->next_assert(Token::TokenType::MAINTK);
        lexer->next_assert(Token::TokenType::LPARENT);
        lexer->next_assert(Token::TokenType::RPARENT);
        auto block = parseBlock();
        return new MainFuncDef(block);
    }

    FuncType *Parser::parseFuncType() {
        if (!(lexer->cur_token()->is_type(Token::TokenType::VOIDTK) ||
              lexer->cur_token()->is_type(Token::TokenType::INTTK) ||
              lexer->cur_token()->is_type(Token::TokenType::CHARTK))) {
            throw std::runtime_error("expect void or int or char");
        }
        auto token = lexer->next();
        return new FuncType(token);
    }

    FuncFParams *Parser::parseFuncFParams() {
        std::vector<FuncFParam *> funcFParams;
        funcFParams.push_back(parseFuncFParam());
        while (lexer->has_next() && lexer->cur_token()->is_type(Token::TokenType::COMMA)) {
            lexer->next();
            funcFParams.push_back(parseFuncFParam());
        }
        return new FuncFParams(funcFParams);
    }

    FuncFParam *Parser::parseFuncFParam() {
        auto bType = parseBType();
        auto identToken = lexer->next_assert(Token::TokenType::IDENFR);
        Token *lbrack = nullptr;
        Token *rbrack = nullptr;
        std::vector<ConstExp *> constExps;
        if (lexer->has_next() && lexer->cur_token()->is_type(Token::TokenType::LBRACK)) {
            lbrack = lexer->next_assert(Token::TokenType::LBRACK);
            rbrack = lexer->next_assert(Token::TokenType::RBRACK);
            while (lexer->has_next() && lexer->cur_token()->is_type(Token::TokenType::LBRACK)) {
                lexer->next_assert(Token::TokenType::LBRACK);
                constExps.push_back(parseConstExp());
                lexer->next_assert(Token::TokenType::RBRACK);
            }
        }
        return new FuncFParam(bType, identToken, lbrack, rbrack, constExps);
    }

    Block *Parser::parseBlock() {
        lexer->next_assert(Token::TokenType::LBRACE);
        std::vector<BlockItem *> blockItems;
        while (lexer->has_next() && !lexer->cur_token()->is_type(Token::TokenType::RBRACE)) {
            blockItems.push_back(parseBlockItem());
        }
        lexer->next_assert(Token::TokenType::RBRACE);
        return new Block(blockItems);
    }

    BlockItem *Parser::parseBlockItem() {
        if (lexer->has_next() && (lexer->cur_token()->is_type(Token::TokenType::CONSTTK) ||
                                  lexer->cur_token()->is_type(Token::TokenType::INTTK) ||
                                  lexer->cur_token()->is_type(Token::TokenType::CHARTK))) {
            auto decl = parseDecl();
            return new BlockItem(decl);
        } else {
            auto stmt = parseStmt();
            return new BlockItem(stmt);
        }
    }

    Stmt *Parser::parseStmt() {
        auto type = getStmtType();
        switch (type) {
            case Stmt::StmtType::AssignStmt: {
                auto lVal = parseLVal();
                lexer->next_assert(Token::TokenType::ASSIGN);
                auto exp = parseExp();
                lexer->next_assert(Token::TokenType::SEMICN);
                return new Stmt(lVal, exp);
            }
            case Stmt::StmtType::ExpStmt: {
                Exp *exp = nullptr;
                if (lexer->has_next() && !lexer->cur_token()->is_type(Token::TokenType::SEMICN)) {
                    exp = parseExp();
                }
                lexer->next_assert(Token::TokenType::SEMICN);
                return new Stmt(exp);
            }
            case Stmt::StmtType::BlockStmt: {
                auto block = parseBlock();
                return new Stmt(block);
            }
            case Stmt::StmtType::ConditionStmt: {
                lexer->next_assert(Token::TokenType::IFTK);
                lexer->next_assert(Token::TokenType::LPARENT);
                auto cond = parseCond();
                lexer->next_assert(Token::TokenType::RPARENT);
                auto stmt1 = parseStmt();
                Stmt *stmt2 = nullptr;
                if (lexer->has_next() && lexer->cur_token()->is_type(Token::TokenType::ELSETK)) {
                    lexer->next_assert(Token::TokenType::ELSETK);
                    stmt2 = parseStmt();
                }
                return new Stmt(cond, stmt1, stmt2);
            }
            case Stmt::StmtType::ForStmt: {
                lexer->next_assert(Token::TokenType::FORTK);
                lexer->next_assert(Token::TokenType::LPARENT);
                ForStmt *init = nullptr;
                Cond *cond = nullptr;
                ForStmt *iter = nullptr;
                if (!lexer->cur_token()->is_type(Token::TokenType::SEMICN)) {
                    init = parseForStmt();
                }
                lexer->next_assert(Token::TokenType::SEMICN);
                if (!lexer->cur_token()->is_type(Token::TokenType::SEMICN)) {
                    cond = parseCond();
                }
                lexer->next_assert(Token::TokenType::SEMICN);
                if (lexer->has_next() && !lexer->cur_token()->is_type(Token::TokenType::RPARENT)) {
                    iter = parseForStmt();
                }
                lexer->next_assert(Token::TokenType::RPARENT);
                auto stmt = parseStmt();
                return new Stmt(init, cond, iter, stmt);
            }
            case Stmt::StmtType::ControlStmt: {
                if (lexer->cur_token()->is_type(Token::TokenType::CONTINUETK)) {
                    auto continueTK = lexer->next();
                    lexer->next_assert(Token::TokenType::SEMICN);
                    return new Stmt(type, continueTK);
                } else {
                    auto breakTK = lexer->next();
                    lexer->next_assert(Token::TokenType::SEMICN);
                    return new Stmt(type, breakTK);
                }
            }
            case Stmt::StmtType::ReturnStmt: {
                lexer->next_assert(Token::TokenType::RETURNTK);
                Exp *exp = nullptr;
                if (lexer->has_next() && !lexer->cur_token()->is_type(Token::TokenType::SEMICN)) {
                    exp = parseExp();
                }
                lexer->next_assert(Token::TokenType::SEMICN);
                return new Stmt(type, exp);
            }
            case Stmt::StmtType::PrintfStmt: {
                lexer->next_assert(Token::TokenType::PRINTFTK);
                lexer->next_assert(Token::TokenType::LPARENT);

                std::vector<Exp *> exps;
                auto formatStr = lexer->next_assert(Token::TokenType::STRCON);

                while (lexer->has_next() && lexer->cur_token()->is_type(Token::TokenType::COMMA)) {
                    lexer->next();
                    exps.push_back(parseExp());
                }

                lexer->next_assert(Token::TokenType::RPARENT);
                lexer->next_assert(Token::TokenType::SEMICN);
                return new Stmt(formatStr, exps);
            }
            case Stmt::StmtType::GetintStmt: {
                auto lVal = parseLVal();
                lexer->next_assert(Token::TokenType::ASSIGN);
                lexer->next_assert(Token::TokenType::GETINTTK);
                lexer->next_assert(Token::TokenType::LPARENT);
                lexer->next_assert(Token::TokenType::RPARENT);
                lexer->next_assert(Token::TokenType::SEMICN);
                return new Stmt(type, lVal);
            }
            case Stmt::StmtType::GetcharStmt: {
                auto lVal = parseLVal();
                lexer->next_assert(Token::TokenType::ASSIGN);
                lexer->next_assert(Token::TokenType::GETCHARTK);
                lexer->next_assert(Token::TokenType::LPARENT);
                lexer->next_assert(Token::TokenType::RPARENT);
                lexer->next_assert(Token::TokenType::SEMICN);
                return new Stmt(type, lVal);
            }
            default: {
                throw std::runtime_error("invalid stmt type");
            }
        }
    }

    ForStmt *Parser::parseForStmt() {
        auto lVal = parseLVal();
        lexer->next_assert(Token::TokenType::ASSIGN);
        auto exp = parseExp();
        return new ForStmt(lVal, exp);
    }

    Exp *Parser::parseExp() {
        auto addExp = parseAddExp();
        return new Exp(addExp);
    }

    Cond *Parser::parseCond() {
        auto lOrExp = parseLOrExp();
        return new Cond(lOrExp);
    }

    LVal *Parser::parseLVal() {
        auto identToken = lexer->next_assert(Token::TokenType::IDENFR);
        std::vector<Exp *> exps;
        while (lexer->has_next() && lexer->cur_token()->is_type(Token::TokenType::LBRACK)) {
            lexer->next_assert(Token::TokenType::LBRACK);
            exps.push_back(parseExp());
            lexer->next_assert(Token::TokenType::RBRACK);
        }
        return new LVal(identToken, exps);
    }

    PrimaryExp *Parser::parsePrimaryExp() {
        if (lexer->cur_token()->is_type(Token::TokenType::LPARENT)) {
            lexer->next_assert(Token::TokenType::LPARENT);
            auto exp = parseExp();
            lexer->next_assert(Token::TokenType::RPARENT);
            return new PrimaryExp(exp);
        } else if (lexer->cur_token()->is_type(Token::TokenType::IDENFR)) {
            auto lVal = parseLVal();
            return new PrimaryExp(lVal);
        } else if (lexer->cur_token()->is_type(Token::TokenType::INTCON)) {
            auto number = parseNumber();
            return new PrimaryExp(number);
        } else {
            auto character = parseCharacter();
            return new PrimaryExp(character);
        }
    }

    Number *Parser::parseNumber() {
        auto token = lexer->next();
        return new Number(token);
    }

    Character *Parser::parseCharacter() {
        auto token = lexer->next();
        return new Character(token);
    }

    UnaryExp *Parser::parseUnaryExp() {
        FuncRParams *funcRParams = nullptr;
        if (lexer->has_next() && lexer->cur_token()->is_type(Token::TokenType::IDENFR) && lexer->has_next(1) &&
            lexer->ahead_of(1)->is_type(Token::TokenType::LPARENT)) {
            auto identTK = lexer->next();
            lexer->next_assert(Token::TokenType::LPARENT);
            if (lexer->has_next() && !lexer->cur_token()->is_type(Token::TokenType::RPARENT)) {
                funcRParams = parseFuncRParams();
            }
            lexer->next_assert(Token::TokenType::RPARENT);
            return new UnaryExp(identTK, funcRParams);
        } else if (lexer->has_next() && (lexer->cur_token()->is_type(Token::TokenType::PLUS) ||
                                         lexer->cur_token()->is_type(Token::TokenType::MINU) ||
                                         lexer->cur_token()->is_type(Token::TokenType::NOT))) {
            auto unaryOp = parseUnaryOp();
            auto unaryExp = parseUnaryExp();
            return new UnaryExp(unaryOp, unaryExp);
        } else {
            auto primaryExp = parsePrimaryExp();
            return new UnaryExp(primaryExp);
        }
    }

    UnaryOp *Parser::parseUnaryOp() {
        auto op = lexer->next();
        return new UnaryOp(op);
    }

    FuncRParams *Parser::parseFuncRParams() {
        std::vector<Exp *> exps;
        exps.push_back(parseExp());
        while (lexer->has_next() && lexer->cur_token()->is_type(Token::TokenType::COMMA)) {
            lexer->next();
            exps.push_back(parseExp());
        }
        return new FuncRParams(exps);
    }

    MulExp *Parser::parseMulExp() {
        auto first = parseUnaryExp();
        auto mulExp = new MulExp(first);
        Token *mulExpTK = nullptr;
        while (lexer->has_next() && (lexer->cur_token()->is_type(Token::TokenType::MULT) ||
                                     lexer->cur_token()->is_type(Token::TokenType::DIV) ||
                                     lexer->cur_token()->is_type(Token::TokenType::MOD))) {
            mulExpTK = lexer->next();
            auto unaryExp = parseUnaryExp();
            mulExp = new MulExp(mulExp, mulExpTK, unaryExp);
        }
        return mulExp;
    }

    AddExp *Parser::parseAddExp() {
        auto first = parseMulExp();
        auto addExp = new AddExp(first);
        Token *addExpTK = nullptr;
        while (lexer->has_next() && (lexer->cur_token()->is_type(Token::TokenType::PLUS) ||
                                     lexer->cur_token()->is_type(Token::TokenType::MINU))) {
            addExpTK = lexer->next();
            auto mulExp = parseMulExp();
            addExp = new AddExp(mulExp, addExpTK, addExp);
        }
        return addExp;
    }

    RelExp *Parser::parseRelExp() {
        auto first = parseAddExp();
        auto relExp = new RelExp(first);
        Token *relExpTK = nullptr;
        while (lexer->has_next() && (lexer->cur_token()->is_type(Token::TokenType::LSS) ||
                                     lexer->cur_token()->is_type(Token::TokenType::LEQ) ||
                                     lexer->cur_token()->is_type(Token::TokenType::GRE) ||
                                     lexer->cur_token()->is_type(Token::TokenType::GEQ))) {
            relExpTK = lexer->next();
            auto addExp = parseAddExp();
            relExp = new RelExp(relExp, relExpTK, addExp);
        }
        return relExp;
    }

    EqExp *Parser::parseEqExp() {
        auto first = parseRelExp();
        auto eqExp = new EqExp(first);
        Token *eqExpTK = nullptr;
        while (lexer->has_next() && (lexer->cur_token()->is_type(Token::TokenType::EQL) ||
                                     lexer->cur_token()->is_type(Token::TokenType::NEQ))) {
            eqExpTK = lexer->next();
            auto relExp = parseRelExp();
            eqExp = new EqExp(eqExp, eqExpTK, relExp);
        }
        return eqExp;
    }

    LAndExp *Parser::parseLAndExp() {
        auto first = parseEqExp();
        auto lAndExp = new LAndExp(first);
        Token *lAndExpTK = nullptr;
        while (lexer->has_next() && lexer->cur_token()->is_type(Token::TokenType::AND)) {
            lAndExpTK = lexer->next();
            auto eqExp = parseEqExp();
            lAndExp = new LAndExp(lAndExp, lAndExpTK, eqExp);
        }
        return lAndExp;
    }

    LOrExp *Parser::parseLOrExp() {
        auto first = parseLAndExp();
        auto lOrExp = new LOrExp(first);
        Token *lOrExpTK = nullptr;
        while (lexer->has_next() && lexer->cur_token()->is_type(Token::TokenType::OR)) {
            lOrExpTK = lexer->next();
            auto lAndExp = parseLAndExp();
            lOrExp = new LOrExp(lOrExp, lOrExpTK, lAndExp);
        }
        return lOrExp;
    }

    ConstExp *Parser::parseConstExp() {
        auto addExp = parseAddExp();
        return new ConstExp(addExp);
    }

    Stmt::StmtType Parser::getStmtType() {
        Stmt::StmtType stmtType = Stmt::StmtType::None;
        if (lexer->cur_token()->is_type(Token::TokenType::LBRACE)) {
            stmtType = Stmt::StmtType::BlockStmt;
        } else if (lexer->cur_token()->is_type(Token::TokenType::IFTK)) {
            stmtType = Stmt::StmtType::ConditionStmt;
        } else if (lexer->cur_token()->is_type(Token::TokenType::FORTK)) {
            stmtType = Stmt::StmtType::ForStmt;
        } else if (lexer->cur_token()->is_type(Token::TokenType::BREAKTK) ||
                   lexer->cur_token()->is_type(Token::TokenType::CONTINUETK)) {
            stmtType = Stmt::StmtType::ControlStmt;
        } else if (lexer->cur_token()->is_type(Token::TokenType::RETURNTK)) {
            stmtType = Stmt::StmtType::ReturnStmt;
        } else if (lexer->cur_token()->is_type(Token::TokenType::PRINTFTK)) {
            stmtType = Stmt::StmtType::PrintfStmt;
        }
        if (stmtType != Stmt::StmtType::None) {
            return stmtType;
        }
        int offset = 0;
        bool flag = false;
        Token *token;
        while (lexer->has_next(offset) && !lexer->ahead_of(offset)->is_type(Token::TokenType::SEMICN)) {
            if (lexer->ahead_of(offset)->is_type(Token::TokenType::ASSIGN)) {
                flag = true;
                token = lexer->ahead_of(offset + 1);
                break;
            }
            offset++;
        }
        if (flag) {
            if (token->is_type(Token::TokenType::GETINTTK)) {
                stmtType = Stmt::StmtType::GetintStmt;
            } else if (token->is_type(Token::TokenType::GETCHARTK)) {
                stmtType = Stmt::StmtType::GetcharStmt;
            } else {
                stmtType = Stmt::StmtType::AssignStmt;
            }
        } else {
            stmtType = Stmt::StmtType::ExpStmt;
        }
        return stmtType;
    }

} // frontend