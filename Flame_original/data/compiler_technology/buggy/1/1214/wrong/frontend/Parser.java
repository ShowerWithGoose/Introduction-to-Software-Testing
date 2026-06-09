package frontend;

import java.io.BufferedWriter;
import java.util.ArrayList;
import java.util.Objects;

public class Parser {
    public ArrayList<Lexer.Token> tokens;
    public int index;
    public int tokenNum;
    public ArrayList<String> parserInfo = new ArrayList<>();
    public ArrayList<Lexer.Error> parserErrors = new ArrayList<>();

    public Parser(ArrayList<Lexer.Token> tokens) {
        this.tokens = tokens;
        this.index = 0;
        this.tokenNum = tokens.size();
    }

    public void writeType(String type) {
        parserInfo.add(type);
    }

    public void writeToken(int num) {
        for (int i = 0; i < num && index < tokenNum; i++) {
            parserInfo.add(tokens.get(index).tokenType.toString
                    () + " " + tokens.get(index).token);
            index++;
        }
    }

    public boolean isError() {
        return !parserErrors.isEmpty();
    }

    public AST getAST() {
        AST.CompUnit compUnit = parseCompUnit();
        return new AST(compUnit);
    }

    // CompUnit → {Decl} {FuncDef} MainFuncDef
    public AST.CompUnit parseCompUnit() {
        AST.CompUnit compUnit = new AST.CompUnit();
        while (index < tokenNum) {
            if (index + 1 < tokenNum && tokens.get(index).tokenType == TokenType.INTTK &&
                    tokens.get(index + 1).tokenType == TokenType.MAINTK) {
                compUnit.setMainFuncDef(parseMainFuncDef());
            } else if (index + 2 < tokenNum && (tokens.get(index).tokenType == TokenType.INTTK ||
                    tokens.get(index).tokenType == TokenType.VOIDTK || tokens.get(index).tokenType ==
                    TokenType.CHARTK) && tokens.get(index + 2).tokenType == TokenType.LBRACE) {
                compUnit.addFuncDef(parseFuncDef());
            } else {
                compUnit.addDecl(parseDecl());
            }
        }
        writeType(compUnit.getType());
        return compUnit;
    }

    // Decl → ConstDecl | VarDecl
    public AST.Decl parseDecl() {
        if (tokens.get(index).tokenType == TokenType.CONSTTK) {
            AST.Decl decl = new AST.Decl(parseConstDecl());
            return decl;
        } else {
            AST.Decl decl = new AST.Decl(parseVarDecl());
            return decl;
        }
    }

    // ConstDecl → 'const' BType ConstDef { ',' ConstDef } ';'
    public AST.ConstDecl parseConstDecl() {
        ArrayList<AST.ConstDef> constDefs = new ArrayList<>();
        writeToken(1);
        AST.BType bType = parseBType();
        int line = tokens.get(index).line;
        constDefs.add(parseConstDef());
        while (tokens.get(index).tokenType == TokenType.COMMA) {
            writeToken(1);
            line = tokens.get(index).line;
            constDefs.add(parseConstDef());
        }
        if (tokens.get(index).tokenType == TokenType.SEMICN) {
            writeToken(1);
        } else {
            parserErrors.add(new Lexer.Error(line, 'i'));
        }
        AST.ConstDecl constDecl = new AST.ConstDecl(bType, constDefs);
        writeType(constDecl.getType());
        return constDecl;
    }

    // BType → 'int' | 'char'
    public AST.BType parseBType() {
        if (tokens.get(index).tokenType == TokenType.INTTK) {
            writeToken(1);
            return new AST.BType("int");
        } else {
            writeToken(1);
            return new AST.BType("char");
        }
    }

    // ConstDef → Ident [ '[' ConstExp ']' ] '=' ConstInitVal
    public AST.ConstDef parseConstDef() {
        String ident = tokens.get(index).token;
        writeToken(1);
        if (tokens.get(index).tokenType == TokenType.LBRACK) {
            writeToken(1);
            int line = tokens.get(index).line;
            AST.ConstExp constExp = parseConstExp();
            if (tokens.get(index).tokenType == TokenType.RBRACK) {
                writeToken(1);
            } else {
                parserErrors.add(new Lexer.Error(line, 'k'));
            }
            writeToken(1); // '='
            AST.ConstInitVal constInitVal = parseConstInitVal();
            AST.ConstDef constDef = new AST.ConstDef(ident, constExp, constInitVal);
            writeType(constDef.getType());
            return constDef;
        } else {
            writeToken(1); // '='
            AST.ConstInitVal constInitVal = parseConstInitVal();
            AST.ConstDef constDef = new AST.ConstDef(ident, constInitVal);
            writeType(constDef.getType());
            return constDef;
        }
    }

    // ConstInitVal → ConstExp | '{' [ ConstExp { ',' ConstExp } ] '}' | StringConst
    public AST.ConstInitVal parseConstInitVal() {
        if (tokens.get(index).tokenType == TokenType.LBRACE) {
            writeToken(1);
            ArrayList<AST.ConstExp> constExps = new ArrayList<>();
            if (tokens.get(index).tokenType != TokenType.RBRACE) {
                constExps.add(parseConstExp());
                while (tokens.get(index).tokenType == TokenType.COMMA) {
                    writeToken(1);
                    constExps.add(parseConstExp());
                }
            }
            writeToken(1); // '}'
            AST.ConstInitVal constInitVal = new AST.ConstInitVal(constExps);
            writeType(constInitVal.getType());
            return constInitVal;
        } else if (tokens.get(index).tokenType == TokenType.STRCON) {
            AST.ConstInitVal constInitVal = new AST.ConstInitVal(tokens.get(index).token);
            writeToken(1);
            writeType(constInitVal.getType());
            return constInitVal;
        } else {
            AST.ConstExp constExp = parseConstExp();
            AST.ConstInitVal constInitVal = new AST.ConstInitVal(constExp);
            writeType(constInitVal.getType());
            return constInitVal;
        }
    }

    // VarDecl → BType VarDef { ',' VarDef } ';'
    public AST.VarDecl parseVarDecl() {
        AST.BType bType = parseBType();
        ArrayList<AST.VarDef> varDefs = new ArrayList<>();
        int line = tokens.get(index).line;
        varDefs.add(parseVarDef());
        while (tokens.get(index).tokenType == TokenType.COMMA) {
            writeToken(1);
            line = tokens.get(index).line;
            varDefs.add(parseVarDef());
        }
        if (tokens.get(index).tokenType == TokenType.SEMICN) {
            writeToken(1);
        } else {
            parserErrors.add(new Lexer.Error(line, 'i'));
        }
        AST.VarDecl varDecl = new AST.VarDecl(bType, varDefs);
        writeType(varDecl.getType());
        return varDecl;
    }

    // VarDef → Ident [ '[' ConstExp ']' ] | Ident [ '[' ConstExp ']' ] '=' InitVal
    public AST.VarDef parseVarDef() {
        String ident = tokens.get(index).token;
        writeToken(1);
        if (tokens.get(index).tokenType == TokenType.LBRACK) {
            writeToken(1);
            int line = tokens.get(index).line;
            AST.ConstExp constExp = parseConstExp();
            if (tokens.get(index).tokenType == TokenType.RBRACK) {
                writeToken(1);
            } else {
                parserErrors.add(new Lexer.Error(line, 'k'));
            }
            if (tokens.get(index).tokenType == TokenType.ASSIGN) {
                writeToken(1);
                AST.InitVal initVal = parseInitVal();
                AST.VarDef varDef = new AST.VarDef(ident, constExp, initVal);
                writeType(varDef.getType());
                return varDef;
            } else {
                AST.VarDef varDef = new AST.VarDef(ident, constExp);
                writeType(varDef.getType());
                return varDef;
            }
        } else {
            if (tokens.get(index).tokenType == TokenType.ASSIGN) {
                writeToken(1);
                AST.InitVal initVal = parseInitVal();
                AST.VarDef varDef = new AST.VarDef(ident, initVal);
                writeType(varDef.getType());
                return varDef;
            } else {
                return new AST.VarDef(ident);
            }
        }
    }

    // InitVal → Exp | '{' [ Exp { ',' Exp } ] '}' | StringConst
    public AST.InitVal parseInitVal() {
        if (tokens.get(index).tokenType == TokenType.LBRACE) {
            writeToken(1);
            ArrayList<AST.Exp> exps = new ArrayList<>();
            if (tokens.get(index).tokenType != TokenType.RBRACE) {
                exps.add(parseExp());
                while (tokens.get(index).tokenType == TokenType.COMMA) {
                    writeToken(1);
                    exps.add(parseExp());
                }
            }
            writeToken(1); // '}'
            AST.InitVal initVal = new AST.InitVal(exps);
            writeType(initVal.getType());
            return initVal;
        } else if (tokens.get(index).tokenType == TokenType.STRCON) {
            AST.InitVal initVal = new AST.InitVal(tokens.get(index).token);
            writeToken(1);
            writeType(initVal.getType());
            return initVal;
        } else {
            AST.Exp exp = parseExp();
            AST.InitVal initVal = new AST.InitVal(exp);
            writeType(initVal.getType());
            return initVal;
        }
    }

    // FuncDef → FuncType Ident '(' [FuncFParams] ')' Block
    public AST.FuncDef parseFuncDef() {
        int typeLine = tokens.get(index).line;
        AST.FuncType funcType = parseFuncType();
        String ident = tokens.get(index).token;
        writeToken(2); // Ident '('
        if (tokens.get(index).tokenType != TokenType.RPARENT &&
            tokens.get(index).tokenType != TokenType.LBRACE) {
            int line = tokens.get(index).line;
            AST.FuncFParams funcFParams = parseFuncFParams();
            if (tokens.get(index).tokenType == TokenType.RPARENT) {
                writeToken(1);
            } else {
                parserErrors.add(new Lexer.Error(line, 'j'));
            }
            AST.Block block = parseBlock();
            AST.FuncDef funcDef = new AST.FuncDef(funcType, ident, funcFParams, block);
            writeType(funcDef.getType());
            return funcDef;
        } else {
            if (tokens.get(index).tokenType == TokenType.RPARENT) {
                writeToken(1);
            } else {
                parserErrors.add(new Lexer.Error(typeLine, 'j'));
            }
            AST.Block block = parseBlock();
            AST.FuncDef funcDef = new AST.FuncDef(funcType, ident, block);
            writeType(funcDef.getType());
            return funcDef;
        }
    }

    // MainFuncDef → 'int' 'main' '(' ')' Block
    public AST.MainFuncDef parseMainFuncDef() {
        writeToken(3); // 'int' 'main' '('
        int line = tokens.get(index - 1).line; // '('
        if (tokens.get(index).tokenType == TokenType.RPARENT) {
            writeToken(1);
        } else {
            parserErrors.add(new Lexer.Error(line, 'j'));
        }
        AST.Block block = parseBlock();
        AST.MainFuncDef mainFuncDef = new AST.MainFuncDef(block);
        writeType(mainFuncDef.getType());
        return mainFuncDef;
    }

    // FuncType → 'void' | 'int' | 'char'
    public AST.FuncType parseFuncType() {
        if (tokens.get(index).tokenType == TokenType.VOIDTK) {
            writeToken(1);
            AST.FuncType funcType = new AST.FuncType("void");
            writeType(funcType.getType());
            return funcType;
        } else if (tokens.get(index).tokenType == TokenType.INTTK) {
            writeToken(1);
            AST.FuncType funcType = new AST.FuncType("int");
            writeType(funcType.getType());
            return funcType;
        } else {
            writeToken(1);
            AST.FuncType funcType = new AST.FuncType("char");
            writeType(funcType.getType());
            return funcType;
        }
    }

    // FuncFParams → FuncFParam { ',' FuncFParam }
    public AST.FuncFParams parseFuncFParams() {
        ArrayList<AST.FuncFParam> funcFParams = new ArrayList<>();
        funcFParams.add(parseFuncFParam());
        while (tokens.get(index).tokenType == TokenType.COMMA) {
            writeToken(1);
            funcFParams.add(parseFuncFParam());
        }
        AST.FuncFParams funcFParams1 = new AST.FuncFParams(funcFParams);
        writeType(funcFParams1.getType());
        return funcFParams1;
    }

    // FuncFParam → BType Ident ['[' ']']
    public AST.FuncFParam parseFuncFParam() {
        int line = tokens.get(index).line;
        AST.BType bType = parseBType();
        String ident = tokens.get(index).token;
        writeToken(1);
        if (tokens.get(index).tokenType == TokenType.LBRACK) {
            writeToken(1);
            if (tokens.get(index).tokenType == TokenType.RBRACK) {
                writeToken(1);
                AST.FuncFParam funcFParam = new AST.FuncFParam(bType, ident, true);
                writeType(funcFParam.getType());
                return funcFParam;
            } else {
                parserErrors.add(new Lexer.Error(line, 'k'));
                AST.FuncFParam funcFParam = new AST.FuncFParam(bType, ident, true);
                writeType(funcFParam.getType());
                return funcFParam;
            }
        } else {
            AST.FuncFParam funcFParam = new AST.FuncFParam(bType, ident, false);
            writeType(funcFParam.getType());
            return funcFParam;
        }
    }

    // Block → '{' { BlockItem } '}'
    public AST.Block parseBlock() {
        writeToken(1);
        ArrayList<AST.BlockItem> blockItems = new ArrayList<>();
        while (tokens.get(index).tokenType != TokenType.RBRACE) {
            blockItems.add(parseBlockItem());
        }
        writeToken(1);
        AST.Block block = new AST.Block(blockItems);
        writeType(block.getType());
        return block;
    }

    // BlockItem → Decl | Stmt
    public AST.BlockItem parseBlockItem() {
        if (tokens.get(index).tokenType == TokenType.CONSTTK || tokens.get(index).tokenType ==
                TokenType.INTTK || tokens.get(index).tokenType == TokenType.CHARTK) {
            AST.Decl decl = parseDecl();
            AST.BlockItem blockItem = new AST.BlockItem(decl);
            return blockItem;
        } else {
            AST.Stmt stmt = parseStmt();
            AST.BlockItem blockItem = new AST.BlockItem(stmt);
            return blockItem;
        }
    }

    // Stmt
    public AST.Stmt parseStmt() {
        if (tokens.get(index).tokenType == TokenType.LBRACE) { // Block
            AST.Block block = parseBlock();
            AST.Stmt stmt = new AST.Stmt(block);
            writeType(stmt.getType());
            return stmt;
        } else if (tokens.get(index).tokenType == TokenType.IFTK) {
            // 'if' '(' Cond ')' Stmt [ 'else' Stmt ]
            writeToken(2); // 'if' '('
            int line = tokens.get(index).line;
            AST.Cond cond = parseCond();
            if (tokens.get(index).tokenType == TokenType.RPARENT) {
                writeToken(1);
            } else {
                parserErrors.add(new Lexer.Error(line, 'j'));
            }
            AST.Stmt stmt1 = parseStmt();
            if (tokens.get(index).tokenType == TokenType.ELSETK) {
                writeToken(1); // 'else'
                AST.Stmt elseStmt = parseStmt();
                AST.Stmt stmt = new AST.Stmt(cond, stmt1, elseStmt);
                writeType(stmt.getType());
                return stmt;
            } else {
                AST.Stmt stmt = new AST.Stmt(cond, stmt1);
                writeType(stmt.getType());
                return stmt;
            }
        } else if (tokens.get(index).tokenType == TokenType.FORTK) {
            // 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
            AST.ForStmt forStmt1 = null;
            AST.Cond cond = null;
            AST.ForStmt forStmt2 = null;
            writeToken(2); // 'for' '('
            if (tokens.get(index).tokenType != TokenType.SEMICN) {
                forStmt1 = parseForStmt();
            }
            writeToken(1); // ';'
            if (tokens.get(index).tokenType != TokenType.SEMICN) {
                cond = parseCond();
            }
            writeToken(1); // ';'
            if (tokens.get(index).tokenType != TokenType.RPARENT) {
                forStmt2 = parseForStmt();
            }
            writeToken(1); // ')'
            AST.Stmt stmt1 = parseStmt();
            AST.Stmt stmt = new AST.Stmt(forStmt1, cond, forStmt2, stmt1);
            writeType(stmt.getType());
            return stmt;
        } else if (tokens.get(index).tokenType == TokenType.BREAKTK ||
                tokens.get(index).tokenType == TokenType.CONTINUETK) {
            // 'break' ';' | 'continue' ';'
            int line = tokens.get(index).line;
            String stop = tokens.get(index).token;
            writeToken(1);
            if (tokens.get(index).tokenType == TokenType.SEMICN) {
                writeToken(1);
            } else {
                parserErrors.add(new Lexer.Error(line, 'i'));
            }
            AST.Stmt stmt = new AST.Stmt(stop);
            writeType(stmt.getType());
            return stmt;
        } else if (tokens.get(index).tokenType == TokenType.RETURNTK) {
            // 'return' [Exp] ';'
            int line = tokens.get(index).line;
            writeToken(1); // 'return'
            AST.Exp exp = null;
            if (tokens.get(index).tokenType != TokenType.SEMICN) {
                line = tokens.get(index).line;
                exp = parseExp();
            }
            if (tokens.get(index).tokenType == TokenType.SEMICN) {
                writeToken(1);
            } else {
                parserErrors.add(new Lexer.Error(line, 'i'));
            }
            AST.Stmt stmt = new AST.Stmt(exp, "return");
            writeType(stmt.getType());
            return stmt;
        } else if (tokens.get(index).tokenType == TokenType.PRINTFTK) {
            // 'printf''('StringConst {','Exp}')'';'
            writeToken(2); // 'printf' '('
            int line = tokens.get(index).line;
            String stringConst = tokens.get(index).token;
            writeToken(1);
            ArrayList<AST.Exp> exps = new ArrayList<>();
            while (tokens.get(index).tokenType == TokenType.COMMA) {
                writeToken(1);
                line = tokens.get(index).line;
                exps.add(parseExp());
            }
            if (tokens.get(index).tokenType == TokenType.RPARENT) {
                writeToken(1);
            } else {
                parserErrors.add(new Lexer.Error(line, 'j'));
            }
            if (tokens.get(index).tokenType == TokenType.SEMICN) {
                writeToken(1);
            } else {
                parserErrors.add(new Lexer.Error(line, 'i'));
            }
            AST.Stmt stmt = new AST.Stmt(stringConst, exps);
            writeType(stmt.getType());
            return stmt;
        } else if (isLval()) {
            AST.LVal lVal = parseLVal();
            writeToken(1); // '='
            if (tokens.get(index).tokenType == TokenType.GETINTTK) {
                // LVal '=' 'getint' '(' ')'';'
                writeToken(2); // 'getint' '('
                int line = tokens.get(index - 1).line;
                if (tokens.get(index).tokenType == TokenType.RPARENT) {
                    writeToken(1);
                } else {
                    parserErrors.add(new Lexer.Error(line, 'j'));
                }
                if (tokens.get(index).tokenType == TokenType.SEMICN) {
                    writeToken(1);
                } else {
                    parserErrors.add(new Lexer.Error(line, 'i'));
                }
                AST.Stmt stmt = new AST.Stmt(lVal, "getint");
                writeType(stmt.getType());
                return stmt;
            } else if (tokens.get(index).tokenType == TokenType.GETCHARTK) {
                // LVal '=' 'getchar' '(' ')'';'
                writeToken(2); // 'getchar' '('
                int line = tokens.get(index - 1).line;
                if (tokens.get(index).tokenType == TokenType.RPARENT) {
                    writeToken(1);
                } else {
                    parserErrors.add(new Lexer.Error(line, 'j'));
                }
                if (tokens.get(index).tokenType == TokenType.SEMICN) {
                    writeToken(1);
                } else {
                    parserErrors.add(new Lexer.Error(line, 'i'));
                }
                AST.Stmt stmt = new AST.Stmt(lVal, "getchar");
                writeType(stmt.getType());
                return stmt;
            } else {
                int line = tokens.get(index).line;
                AST.Exp exp = parseExp();
                if (tokens.get(index).tokenType == TokenType.SEMICN) {
                    writeToken(1);
                } else {
                    parserErrors.add(new Lexer.Error(line, 'i'));
                }
                AST.Stmt stmt = new AST.Stmt(lVal, exp);
                writeType(stmt.getType());
                return stmt;
            }
        } else {
            // [Exp] ';'
            AST.Exp exp = null;
            int line = tokens.get(index).line;
            if (tokens.get(index).tokenType != TokenType.SEMICN) {
                line = tokens.get(index).line;
                exp = parseExp();
            }
            if (tokens.get(index).tokenType == TokenType.SEMICN) {
                writeToken(1);
            } else {
                parserErrors.add(new Lexer.Error(line, 'i'));
            }
            AST.Stmt stmt = new AST.Stmt(exp);
            writeType(stmt.getType());
            return stmt;
        }
    }

    public boolean isLval() {
        if (tokens.get(index).tokenType != TokenType.IDENFR) {
            return false;
        }
        for (int i = index; i < tokenNum &&
                tokens.get(i).tokenType != TokenType.SEMICN; i++) {
            if (tokens.get(i).tokenType == TokenType.ASSIGN) {
                return true;
            }
        }
        return false;
    }

    // ForStmt → LVal '=' Exp
    public AST.ForStmt parseForStmt() {
        AST.LVal lVal = parseLVal();
        writeToken(1); // '='
        AST.Exp exp = parseExp();
        AST.ForStmt forStmt = new AST.ForStmt(lVal, exp);
        writeType(forStmt.getType());
        return forStmt;
    }

    // Exp → AddExp
    public AST.Exp parseExp() {
        AST.AddExp addExp = parseAddExp();
        AST.Exp exp = new AST.Exp(addExp);
        writeType(exp.getType());
        return exp;
    }

    // Cond → LOrExp
    public AST.Cond parseCond() {
        AST.LOrExp lOrExp = parseLOrExp();
        AST.Cond cond = new AST.Cond(lOrExp);
        writeType(cond.getType());
        return cond;
    }

    // LVal → Ident ['[' Exp ']']
    public AST.LVal parseLVal() {
        String ident = tokens.get(index).token;
        writeToken(1);
        if (tokens.get(index).tokenType == TokenType.LBRACK) {
            writeToken(1);
            int line = tokens.get(index).line;
            AST.Exp exp = parseExp();
            if (tokens.get(index).tokenType == TokenType.RBRACK) {
                writeToken(1);
            } else {
                parserErrors.add(new Lexer.Error(line, 'k'));
            }
            AST.LVal lVal = new AST.LVal(ident, exp);
            writeType(lVal.getType());
            return lVal;
        } else {
            AST.LVal lVal = new AST.LVal(ident);
            writeType(lVal.getType());
            return lVal;
        }
    }

    // PrimaryExp → '(' Exp ')' | LVal | Number | Character
    public AST.PrimaryExp parsePrimaryExp() {
        if (tokens.get(index).tokenType == TokenType.LPARENT) {
            writeToken(1);
            int line = tokens.get(index).line;
            AST.Exp exp = parseExp();
            if (tokens.get(index).tokenType == TokenType.RPARENT) {
                writeToken(1);
            } else {
                parserErrors.add(new Lexer.Error(line, 'j'));
            }
            AST.PrimaryExp primaryExp = new AST.PrimaryExp(exp);
            writeType(primaryExp.getType());
            return primaryExp;
        } else if (tokens.get(index).tokenType == TokenType.IDENFR) {
            AST.LVal lVal = parseLVal();
            AST.PrimaryExp primaryExp = new AST.PrimaryExp(lVal);
            writeType(primaryExp.getType());
            return primaryExp;
        } else if (tokens.get(index).tokenType == TokenType.INTCON) {
            AST.Number number = parseNumber();
            AST.PrimaryExp primaryExp = new AST.PrimaryExp(number);
            writeType(primaryExp.getType());
            return primaryExp;
        } else {
            AST.Character character = parseCharacter();
            AST.PrimaryExp primaryExp = new AST.PrimaryExp(character);
            writeType(primaryExp.getType());
            return primaryExp;
        }
    }

    // Number → IntConst
    public AST.Number parseNumber() {
        AST.Number number = new AST.Number(tokens.get(index).token);
        writeToken(1);
        writeType(number.getType());
        return number;
    }

    // Character → CharConst
    public AST.Character parseCharacter() {
        AST.Character character = new AST.Character(tokens.get(index).token);
        writeToken(1);
        writeType(character.getType());
        return character;
    }

    // UnaryExp → PrimaryExp | Ident '(' [FuncRParams] ')' | UnaryOp UnaryExp
    public AST.UnaryExp parseUnaryExp() {
        if (tokens.get(index).tokenType == TokenType.IDENFR && tokens.get(index + 1).tokenType ==
                TokenType.LPARENT) {
            String ident = tokens.get(index).token;
            writeToken(2); // Ident '('
            if (tokens.get(index).tokenType != TokenType.RPARENT) {
                int line = tokens.get(index).line;
                AST.FuncRParams funcRParams = parseFuncRParams();
                if (tokens.get(index).tokenType == TokenType.RPARENT) {
                    writeToken(1);
                } else {
                    parserErrors.add(new Lexer.Error(line, 'j'));
                }
                AST.UnaryExp unaryExp = new AST.UnaryExp(ident, funcRParams);
                writeType(unaryExp.getType());
                return unaryExp;
            } else {
                writeToken(1); // ')'
                AST.UnaryExp unaryExp = new AST.UnaryExp(ident);
                writeType(unaryExp.getType());
                return unaryExp;
            }
        } else if (tokens.get(index).tokenType == TokenType.PLUS || tokens.get(index).tokenType ==
                TokenType.MINU || tokens.get(index).tokenType == TokenType.NOT) {
            AST.UnaryOp unaryOp = new AST.UnaryOp(tokens.get(index).token);
            writeToken(1);
            AST.UnaryExp unaryExp = new AST.UnaryExp(unaryOp, parseUnaryExp());
            writeType(unaryExp.getType());
            return unaryExp;
        } else {
            AST.PrimaryExp primaryExp = parsePrimaryExp();
            AST.UnaryExp unaryExp = new AST.UnaryExp(primaryExp);
            writeType(unaryExp.getType());
            return unaryExp;
        }
    }

    // UnaryOp → '+' | '−' | '!'
    public AST.UnaryOp parseUnaryOp() {
        if (tokens.get(index).tokenType == TokenType.PLUS) {
            writeToken(1);
            return new AST.UnaryOp("+");
        } else if (tokens.get(index).tokenType == TokenType.MINU) {
            writeToken(1);
            return new AST.UnaryOp("-");
        } else {
            writeToken(1);
            return new AST.UnaryOp("!");
        }
    }

    // FuncRParams → Exp { ',' Exp }
    public AST.FuncRParams parseFuncRParams() {
        ArrayList<AST.Exp> exps = new ArrayList<>();
        exps.add(parseExp());
        while (tokens.get(index).tokenType == TokenType.COMMA) {
            writeToken(1);
            exps.add(parseExp());
        }
        AST.FuncRParams funcRParams = new AST.FuncRParams(exps);
        writeType(funcRParams.getType());
        return funcRParams;
    }

    // MulExp → UnaryExp | MulExp ('*' | '/' | '%') UnaryExp
    public AST.MulExp parseMulExp() {
        ArrayList<AST.UnaryExp> unaryExps = new ArrayList<>();
        ArrayList<String> ops = new ArrayList<>();
        unaryExps.add(parseUnaryExp());
        writeType("<MulExp>");
        while (tokens.get(index).tokenType == TokenType.MULT || tokens.get(index).tokenType ==
                TokenType.DIV || tokens.get(index).tokenType == TokenType.MOD) {
            ops.add(tokens.get(index).token);
            writeToken(1);
            unaryExps.add(parseUnaryExp());
            writeType("<MulExp>");
        }
        AST.MulExp mulExp = new AST.MulExp(unaryExps, ops);
        return mulExp;
    }

    // AddExp → MulExp | AddExp ('+' | '−') MulExp
    public AST.AddExp parseAddExp() {
        ArrayList<AST.MulExp> mulExps = new ArrayList<>();
        ArrayList<String> ops = new ArrayList<>();
        mulExps.add(parseMulExp());
        writeType("<AddExp>");
        while (tokens.get(index).tokenType == TokenType.PLUS || tokens.get(index).tokenType ==
                TokenType.MINU) {
            ops.add(tokens.get(index).token);
            writeToken(1);
            mulExps.add(parseMulExp());
            writeType("<AddExp>");
        }
        AST.AddExp addExp = new AST.AddExp(mulExps, ops);
        return addExp;
    }

    // RelExp → AddExp | RelExp ('<' | '>' | '<=' | '>=') AddExp
    public AST.RelExp parseRelExp() {
        ArrayList<AST.AddExp> addExps = new ArrayList<>();
        ArrayList<String> ops = new ArrayList<>();
        addExps.add(parseAddExp());
        writeType("<RelExp>");
        while (tokens.get(index).tokenType == TokenType.LSS || tokens.get(index).tokenType ==
                TokenType.GRE || tokens.get(index).tokenType == TokenType.LEQ || tokens.get(index)
                .tokenType == TokenType.GEQ) {
            ops.add(tokens.get(index).token);
            writeToken(1);
            addExps.add(parseAddExp());
            writeType("<RelExp>");
        }
        AST.RelExp relExp = new AST.RelExp(addExps, ops);
        return relExp;
    }

    // EqExp → RelExp | EqExp ('==' | '!=') RelExp
    public AST.EqExp parseEqExp() {
        ArrayList<AST.RelExp> relExps = new ArrayList<>();
        ArrayList<String> ops = new ArrayList<>();
        relExps.add(parseRelExp());
        writeType("<EqExp>");
        while (tokens.get(index).tokenType == TokenType.EQL || tokens.get(index).tokenType ==
                TokenType.NEQ) {
            ops.add(tokens.get(index).token);
            writeToken(1);
            relExps.add(parseRelExp());
            writeType("<EqExp>");
        }
        AST.EqExp eqExp = new AST.EqExp(relExps, ops);
        return eqExp;
    }

    // LAndExp → EqExp | LAndExp '&&' EqExp
    public AST.LAndExp parseLAndExp() {
        ArrayList<AST.EqExp> eqExps = new ArrayList<>();
        eqExps.add(parseEqExp());
        writeType("<LAndExp>");
        while (tokens.get(index).tokenType == TokenType.AND ||
                Objects.equals(tokens.get(index).token, "&")) {
            if (Objects.equals(tokens.get(index).token, "&")) {
                parserErrors.add(new Lexer.Error(tokens.get(index).line, 'a'));
            }
            writeToken(1);
            eqExps.add(parseEqExp());
            writeType("<LAndExp>");
        }
        AST.LAndExp lAndExp = new AST.LAndExp(eqExps);
        return lAndExp;
    }

    // LOrExp → LAndExp | LOrExp '||' LAndExp
    public AST.LOrExp parseLOrExp() {
        ArrayList<AST.LAndExp> lAndExps = new ArrayList<>();
        lAndExps.add(parseLAndExp());
        writeType("<LOrExp>");
        while (tokens.get(index).tokenType == TokenType.OR ||
                Objects.equals(tokens.get(index).token, "|")) {
            if (Objects.equals(tokens.get(index).token, "|")) {
                parserErrors.add(new Lexer.Error(tokens.get(index).line, 'a'));
            }
            writeToken(1);
            lAndExps.add(parseLAndExp());
            writeType("<LOrExp>");
        }
        AST.LOrExp lOrExp = new AST.LOrExp(lAndExps);
        return lOrExp;
    }

    // ConstExp → AddExp
    public AST.ConstExp parseConstExp() {
        AST.AddExp addExp = parseAddExp();
        AST.ConstExp constExp = new AST.ConstExp(addExp);
        writeType(constExp.getType());
        return constExp;
    }
}
