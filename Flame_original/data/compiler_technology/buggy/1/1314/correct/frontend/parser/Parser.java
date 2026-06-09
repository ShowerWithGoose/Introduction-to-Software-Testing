package frontend.parser;

import frontend.ErrorHandler.ErrorHandler;
import frontend.lexer.LexicalAnalyzer;
import frontend.lexer.Token;
import frontend.lexer.Word;
import frontend.ErrorHandler.Error;

import java.util.ArrayList;

public class Parser {
    private LexicalAnalyzer lexicalAnalyzer;
    private Token curToken;
    private int pos;
    private ArrayList<Token> tokens;
    //private ArrayList<Error> errors;

    public Parser(LexicalAnalyzer lexicalAnalyzer) {
        this.lexicalAnalyzer = lexicalAnalyzer;
        pos = -1;
        lexicalAnalyzer.parse();
        tokens = lexicalAnalyzer.getTokens();
        //errors=new ArrayList<>();
    }

    public void retract(int index) {
        pos -= index;
        if (pos >= 0) {
            curToken = tokens.get(pos);
        }
    }

    public boolean getToken(Word... words) {
        pos++;
        curToken = tokens.get(pos);
        if (words.length == 0) {
            return true;
        }
        for (Word word : words) {
            if (curToken.getWord().equals(word)) return true;
        }
        retract(1);
        return false;
    }

    public ParseUnit parseCompUnit() {
        ArrayList<ParseUnit> subUnits = new ArrayList<>();

        while (getToken(Word.CONSTTK, Word.CHARTK, Word.INTTK)) { //先预读一个，有可能是Decl、FuncDef、MainFuncDef

            if (curToken.isType(Word.CONSTTK)) {
                retract(1);
                subUnits.add(parseConstDecl());
            } else {
                //再预读一个
                if (!getToken(Word.IDENFR)) {
                    retract(1);
                    break;
                } else {
                    if (getToken(Word.LPARENT)) {
                        retract(3);
                        break;
                    } else {
                        retract(1);
                        subUnits.add(parseVarDecl());
                    }

                }
            }
        }

        while (getToken(Word.VOIDTK, Word.INTTK, Word.CHARTK)) { //可能是FuncDef、MainFuncDef
            if (!curToken.isType(Word.INTTK)) {
                retract(1);
                subUnits.add(parseFuncDef());
            } else {
                if (getToken(Word.MAINTK)) {
                    retract(2);
                    break;
                } else {
                    retract(1);
                    subUnits.add(parseFuncDef());
                }
            }
        }
        subUnits.add(parseMainFuncDef());
        return new ParseUnit("CompUnit", subUnits);
    }

    public ParseUnit parseConstDecl() {
        ArrayList<ParseUnit> subUnits = new ArrayList<>();
        getToken(Word.CONSTTK);
        subUnits.add(curToken);
        //subUnits.add(parseBType());
        getToken(Word.INTTK, Word.CHARTK);
        subUnits.add(curToken);
        subUnits.add(parseConstDef());
        while (getToken(Word.COMMA)) {
            subUnits.add(curToken);
            subUnits.add(parseConstDef());
        }
        if (getToken(Word.SEMICN)) {
            subUnits.add(curToken);
        } else {
            ErrorHandler.getInstance().addError(new Error('i', curToken.getLineNum()));
        }

        return new ParseUnit("ConstDecl", subUnits);
    }

    public ParseUnit parseBType() {
        ArrayList<ParseUnit> subUnits = new ArrayList<>();
        getToken(Word.INTTK, Word.CHARTK);
        subUnits.add(curToken);
        return new ParseUnit("BType", subUnits);

    }

    public ParseUnit parseConstDef() {
        ArrayList<ParseUnit> subUnits = new ArrayList<>();
        getToken(Word.IDENFR);
        subUnits.add(curToken);
        if (getToken(Word.LBRACK)) {
            subUnits.add(curToken);
            subUnits.add(parseConstExp());
            if (getToken(Word.RBRACK)) {
                subUnits.add(curToken);
            } else {
                ErrorHandler.getInstance().addError(new Error('k', curToken.getLineNum()));
            }

        }
        getToken(Word.ASSIGN);
        subUnits.add(curToken);
        subUnits.add(parseConstInitVal());
        return new ParseUnit("ConstDef", subUnits);
    }

    public ParseUnit parseConstInitVal() {
        ArrayList<ParseUnit> subUnits = new ArrayList<>();
        if (getToken(Word.STRCON)) {
            subUnits.add(curToken);
        } else if (!getToken(Word.LBRACE)) {
            subUnits.add(parseConstExp());
        } else {
            subUnits.add(curToken);
            if (!getToken(Word.RBRACE)) {
                subUnits.add(parseConstExp());
                while (getToken(Word.COMMA)) {
                    subUnits.add(curToken);
                    subUnits.add(parseConstExp());
                }
            }
            getToken(Word.RBRACE);
            subUnits.add(curToken);
        }
        return new ParseUnit("ConstInitVal", subUnits);
    }

    public ParseUnit parseVarDecl() {
        ArrayList<ParseUnit> subUnits = new ArrayList<>();
        getToken(Word.INTTK, Word.CHARTK);
        subUnits.add(curToken);
        subUnits.add(parseVarDef());
        while (getToken(Word.COMMA)) {
            subUnits.add(curToken);
            subUnits.add(parseVarDef());
        }
        if (getToken(Word.SEMICN)) {
            subUnits.add(curToken);
        } else {
            ErrorHandler.getInstance().addError(new Error('i', curToken.getLineNum()));
        }
        return new ParseUnit("VarDecl", subUnits);
    }

    public ParseUnit parseVarDef() {
        ArrayList<ParseUnit> subUnits = new ArrayList<>();
        getToken(Word.IDENFR);
        subUnits.add(curToken);
        if (getToken(Word.LBRACK)) {
            subUnits.add(curToken);
            subUnits.add(parseConstExp());
            if (getToken(Word.RBRACK)) {
                subUnits.add(curToken);
            } else {
                ErrorHandler.getInstance().addError(new Error('k', curToken.getLineNum()));
            }
        }
        if (getToken(Word.ASSIGN)) {
            subUnits.add(curToken);
            subUnits.add(parseInitVal());
        }
        return new ParseUnit("VarDef", subUnits);

    }

    public ParseUnit parseInitVal() {
        ArrayList<ParseUnit> subUnits = new ArrayList<>();
        if (getToken(Word.STRCON)) {
            subUnits.add(curToken);
        } else if (getToken(Word.LBRACE)) {
            subUnits.add(curToken);

            if (getToken(Word.LPARENT, Word.IDENFR, Word.PLUS, Word.MINU, Word.NOT, Word.INTCON, Word.CHRCON)) {
                retract(1);
                subUnits.add(parseExp());
                while (getToken(Word.COMMA)) {
                    subUnits.add(curToken);
                    subUnits.add(parseExp());
                }
            }
            getToken(Word.RBRACE);
            subUnits.add(curToken);
        } else {
            subUnits.add(parseExp());
        }
        return new ParseUnit("InitVal", subUnits);
    }

    public ParseUnit parseFuncDef() {
        ArrayList<ParseUnit> subUnits = new ArrayList<>();
        subUnits.add(parseFuncType());
        getToken(Word.IDENFR);
        subUnits.add(curToken);
        getToken(Word.LPARENT);
        subUnits.add(curToken);
        if (getToken(Word.INTTK, Word.CHARTK)) {
            retract(1);
            subUnits.add(parseFuncFParams());
        }
        if (getToken(Word.RPARENT)) {
            subUnits.add(curToken);
        } else {
            ErrorHandler.getInstance().addError(new Error('j', curToken.getLineNum()));
        }
        subUnits.add(parseBlock());
        return new ParseUnit("FuncDef", subUnits);
    }

    public ParseUnit parseMainFuncDef() {
        ArrayList<ParseUnit> subUnits = new ArrayList<>();
        getToken(Word.INTTK);
        subUnits.add(curToken);
        getToken(Word.MAINTK);
        subUnits.add(curToken);
        getToken(Word.LPARENT);
        subUnits.add(curToken);
        if (getToken(Word.RPARENT)) {
            subUnits.add(curToken);
        } else {
            ErrorHandler.getInstance().addError(new Error('j', curToken.getLineNum()));
        }
        subUnits.add(parseBlock());
        return new ParseUnit("MainFuncDef", subUnits);
    }

    public ParseUnit parseFuncType() {
        ArrayList<ParseUnit> subUnits = new ArrayList<>();
        getToken(Word.VOIDTK, Word.INTTK, Word.CHARTK);
        subUnits.add(curToken);
        return new ParseUnit("FuncType", subUnits);
    }

    public ParseUnit parseFuncFParams() {
        ArrayList<ParseUnit> subUnits = new ArrayList<>();
        subUnits.add(parseFuncFParam());
        while (getToken(Word.COMMA)) {
            subUnits.add(curToken);
            subUnits.add(parseFuncFParam());
        }
        return new ParseUnit("FuncFParams", subUnits);
    }

    public ParseUnit parseFuncFParam() {
        ArrayList<ParseUnit> subUnits = new ArrayList<>();
        getToken(Word.INTTK, Word.CHARTK);
        subUnits.add(curToken);
        getToken(Word.IDENFR);
        subUnits.add(curToken);
        if (getToken(Word.LBRACK)) {
            subUnits.add(curToken);
            if (getToken(Word.RBRACK)) {
                subUnits.add(curToken);
            } else {
                ErrorHandler.getInstance().addError(new Error('k', curToken.getLineNum()));
            }
        }
        return new ParseUnit("FuncFParam", subUnits);
    }

    public ParseUnit parseBlock() {
        ArrayList<ParseUnit> subUnits = new ArrayList<>();
        getToken(Word.LBRACE);
        subUnits.add(curToken);
        while (!getToken(Word.RBRACE)) {
            subUnits.add(parseBlockItem());
        }
        subUnits.add(curToken);
        return new ParseUnit("Block", subUnits);
    }

    public ParseUnit parseBlockItem() {
        //ArrayList<ParseUnit> subUnits=new ArrayList<>();
        if (getToken(Word.CONSTTK)) {
            retract(1);
            //subUnits.add(parseConstDecl());
            return parseConstDecl();
        } else if (getToken(Word.INTTK, Word.CHARTK)) {
            retract(1);
            //subUnits.add(parseVarDecl());
            return parseVarDecl();
        } else {
            //subUnits.add(parseStmt());
            return parseStmt();
        }
    }

    public ParseUnit parseStmt() {
        ArrayList<ParseUnit> subUnits = new ArrayList<>();
        if (getToken(Word.IFTK)) { //if
            subUnits.add(curToken);
            getToken(Word.LPARENT);
            subUnits.add(curToken);
            subUnits.add(parseCond());
            if (getToken(Word.RPARENT)) {
                subUnits.add(curToken);
            } else {
                ErrorHandler.getInstance().addError(new Error('j', curToken.getLineNum()));
            }
            subUnits.add(parseStmt());
            if (getToken(Word.ELSETK)) {
                subUnits.add(curToken);
                subUnits.add(parseStmt());
            }
        } else if (getToken(Word.FORTK)) { //for
            subUnits.add(curToken);
            getToken(Word.LPARENT);
            subUnits.add(curToken);
            if (getToken(Word.IDENFR)) {
                retract(1);
                subUnits.add(parseForStmt());
            }
            getToken(Word.SEMICN);
            subUnits.add(curToken);
            if (getToken(Word.LPARENT, Word.IDENFR, Word.INTCON, Word.CHRCON, Word.PLUS, Word.MINU, Word.NOT)) {
                retract(1);
                subUnits.add(parseCond());
            }
            getToken(Word.SEMICN);
            subUnits.add(curToken);
            if (getToken(Word.IDENFR)) {
                retract(1);
                subUnits.add(parseForStmt());
            }
            getToken(Word.RPARENT);
            subUnits.add(curToken);

            subUnits.add(parseStmt());
        } else if (getToken(Word.BREAKTK)) { //break
            subUnits.add(curToken);
            if (getToken(Word.SEMICN)) {
                subUnits.add(curToken);
            } else {
                ErrorHandler.getInstance().addError(new Error('i', curToken.getLineNum()));
            }
        } else if (getToken(Word.CONTINUETK)) { //continue
            subUnits.add(curToken);
            if (getToken(Word.SEMICN)) {
                subUnits.add(curToken);
            } else {
                ErrorHandler.getInstance().addError(new Error('i', curToken.getLineNum()));
            }
        } else if (getToken(Word.RETURNTK)) { //return
            subUnits.add(curToken);
            if (getToken(Word.LPARENT, Word.IDENFR, Word.PLUS, Word.MINU, Word.NOT, Word.INTCON, Word.CHRCON)) {
                retract(1);
                subUnits.add(parseExp());
            }
            if (getToken(Word.SEMICN)) {
                subUnits.add(curToken);
            } else {
                ErrorHandler.getInstance().addError(new Error('i', curToken.getLineNum()));
            }
        } else if (getToken(Word.PRINTFTK)) { //printf
            subUnits.add(curToken);
            getToken(Word.LPARENT);
            subUnits.add(curToken);
            getToken(Word.STRCON);
            subUnits.add(curToken);
            while (getToken(Word.COMMA)) {
                subUnits.add(curToken);
                subUnits.add(parseExp());
            }
            if (getToken(Word.RPARENT)) {
                subUnits.add(curToken);
            } else {
                ErrorHandler.getInstance().addError(new Error('j', curToken.getLineNum()));
            }
            if (getToken(Word.SEMICN)) {
                subUnits.add(curToken);
            } else {
                ErrorHandler.getInstance().addError(new Error('i', curToken.getLineNum()));
            }
        } else if (getToken(Word.LBRACE)) { //Block
            retract(1);
            subUnits.add(parseBlock());
        } else if (getToken(Word.IDENFR)) { //LVal
            if (getToken(Word.LPARENT)) {
                retract(2);
                subUnits.add(parseExp());
                if (getToken(Word.SEMICN)) {
                    subUnits.add(curToken);
                } else {
                    ErrorHandler.getInstance().addError(new Error('i', curToken.getLineNum()));
                }
            } else {
                retract(1);
                int tmpPos = pos;

                ParseUnit tmpUnits = parseLVal();
                //parseLVal();
                if (getToken(Word.ASSIGN)) {

                    subUnits.add(tmpUnits);

                    subUnits.add(curToken);
                    if (getToken(Word.GETINTTK)) { //getint
                        subUnits.add(curToken);
                        getToken(Word.LPARENT);
                        subUnits.add(curToken);
                        if (getToken(Word.RPARENT)) {
                            subUnits.add(curToken);
                        } else {
                            ErrorHandler.getInstance().addError(new Error('j', curToken.getLineNum()));
                        }
                        if (getToken(Word.SEMICN)) {
                            subUnits.add(curToken);
                        } else {
                            ErrorHandler.getInstance().addError(new Error('i', curToken.getLineNum()));
                        }
                    } else if (getToken(Word.GETCHARTK)) { //getchar
                        subUnits.add(curToken);
                        getToken(Word.LPARENT);
                        subUnits.add(curToken);
                        if (getToken(Word.RPARENT)) {
                            subUnits.add(curToken);
                        } else {
                            ErrorHandler.getInstance().addError(new Error('j', curToken.getLineNum()));
                        }
                        if (getToken(Word.SEMICN)) {
                            subUnits.add(curToken);
                        } else {
                            ErrorHandler.getInstance().addError(new Error('i', curToken.getLineNum()));
                        }
                    } else {


                        if(!getToken(Word.SEMICN)){
                            subUnits.add(parseExp());
                        }
                        if (getToken(Word.SEMICN)) {
                            subUnits.add(curToken);
                        } else {
                            ErrorHandler.getInstance().addError(new Error('i', curToken.getLineNum()));
                        }
                    }
                } else {
                    retract(pos - tmpPos);
                    if(!getToken(Word.SEMICN)){
                        subUnits.add(parseExp());
                    }
                    if (getToken(Word.SEMICN)) {
                        subUnits.add(curToken);
                    } else {
                        ErrorHandler.getInstance().addError(new Error('i', curToken.getLineNum()));
                    }
                }
            }


        } else { //Exp
            if (!getToken(Word.SEMICN)) {
                subUnits.add(parseExp());
            }else {
                retract(1);
            }

            if (getToken(Word.SEMICN)) {
                subUnits.add(curToken);
            } else {
                ErrorHandler.getInstance().addError(new Error('i', curToken.getLineNum()));
            }
        }
        return new ParseUnit("Stmt", subUnits);
    }

    public ParseUnit parseForStmt() {
        ArrayList<ParseUnit> subUnits = new ArrayList<>();
        subUnits.add(parseLVal());
        getToken(Word.ASSIGN);
        subUnits.add(curToken);
        subUnits.add(parseExp());
        return new ParseUnit("ForStmt", subUnits);
    }

    public ParseUnit parseExp() {
        ArrayList<ParseUnit> subUnits = new ArrayList<>();
        subUnits.add(parseAddExp());
        return new ParseUnit("Exp", subUnits);
    }

    public ParseUnit parseCond() {
        ArrayList<ParseUnit> subUnits = new ArrayList<>();
        subUnits.add(parseLOrExp());
        return new ParseUnit("Cond", subUnits);

    }

    public ParseUnit parseLVal() {
        ArrayList<ParseUnit> subUnits = new ArrayList<>();
        getToken(Word.IDENFR);
        subUnits.add(curToken);
        if (getToken(Word.LBRACK)) {
            subUnits.add(curToken);
            subUnits.add(parseExp());
            if (getToken(Word.RBRACK)) {
                subUnits.add(curToken);
            } else {
                ErrorHandler.getInstance().addError(new Error('k', curToken.getLineNum()));
            }
        }
        return new ParseUnit("LVal", subUnits);
    }

    public ParseUnit parsePrimaryExp() {
        ArrayList<ParseUnit> subUnits = new ArrayList<>();
        if (getToken(Word.LPARENT)) {
            subUnits.add(curToken);
            subUnits.add(parseExp());
            if (getToken(Word.RPARENT)) {
                subUnits.add(curToken);
            } else {
                ErrorHandler.getInstance().addError(new Error('j', curToken.getLineNum()));
            }
        } else if (getToken(Word.IDENFR)) {
            retract(1);
            subUnits.add(parseLVal());
        } else if (getToken(Word.INTCON)) {
            retract(1);
            subUnits.add(parseNumber());
        } else {
            subUnits.add(parseCharacter());
        }
        return new ParseUnit("PrimaryExp", subUnits);
    }

    public ParseUnit parseNumber() {
        ArrayList<ParseUnit> subUnits = new ArrayList<>();
        getToken(Word.INTCON);
        subUnits.add(curToken);
        return new ParseUnit("Number", subUnits);
    }

    public ParseUnit parseCharacter() {
        ArrayList<ParseUnit> subUnits = new ArrayList<>();
        getToken(Word.CHRCON);
        subUnits.add(curToken);
        return new ParseUnit("Character", subUnits);
    }

    public ParseUnit parseUnaryExp() {
        ArrayList<ParseUnit> subUnits = new ArrayList<>();
        if (getToken(Word.IDENFR)) {
            if (getToken(Word.LPARENT)) {
                retract(1);
                subUnits.add(curToken);
                getToken(Word.LPARENT);
                subUnits.add(curToken);
                if (getToken(Word.LPARENT, Word.IDENFR, Word.PLUS, Word.MINU, Word.NOT, Word.INTCON, Word.CHRCON)) { //FIRST(Exp) FuncRParams
                    retract(1);
                    subUnits.add(parseFuncRParams());

                }
                if (getToken(Word.RPARENT)) {
                    subUnits.add(curToken);
                } else {
                    ErrorHandler.getInstance().addError(new Error('j', curToken.getLineNum()));
                }
            } else {
                retract(1);
                subUnits.add(parsePrimaryExp());
            }
        } else if (getToken(Word.LPARENT, Word.INTCON, Word.CHRCON)) {
            retract(1);
            subUnits.add(parsePrimaryExp());
        } else {
            if (getToken(Word.PLUS, Word.MINU, Word.NOT)) {
                retract(1);
                subUnits.add(parseUnaryOp());
            }
//            getToken(Word.PLUS,Word.MINU,Word.NOT);
//            subUnits.add(curToken);
            subUnits.add(parseUnaryExp());
        }
        return new ParseUnit("UnaryExp", subUnits);
    }

    public ParseUnit parseUnaryOp() {
        ArrayList<ParseUnit> subUnits = new ArrayList<>();
        getToken(Word.PLUS, Word.MINU, Word.NOT);
        subUnits.add(curToken);
        return new ParseUnit("UnaryOp", subUnits);
    }

    public ParseUnit parseFuncRParams() {
        ArrayList<ParseUnit> subUnits = new ArrayList<>();
        subUnits.add(parseExp());
        while (getToken(Word.COMMA)) {

            subUnits.add(curToken);
            subUnits.add(parseExp());
        }
        return new ParseUnit("FuncRParams", subUnits);
    }

    public ParseUnit parseMulExp() {
        ArrayList<ParseUnit> subUnits = new ArrayList<>();
        subUnits.add(parseUnaryExp());
        while (getToken(Word.MULT, Word.DIV, Word.MOD)) {
            ArrayList<ParseUnit> newUnits = new ArrayList<>(subUnits);
            ParseUnit parseUnit = new ParseUnit("MulExp", newUnits);

            subUnits.clear();
            subUnits.add(parseUnit);
            subUnits.add(curToken);
            subUnits.add(parseUnaryExp());
        }
        return new ParseUnit("MulExp", subUnits);
    }

    public ParseUnit parseAddExp() {
        ArrayList<ParseUnit> subUnits = new ArrayList<>();
        subUnits.add(parseMulExp());
        while (getToken(Word.PLUS, Word.MINU)) {
            ArrayList<ParseUnit> newUnits = new ArrayList<>(subUnits);
            ParseUnit parseUnit = new ParseUnit("AddExp", newUnits);

            subUnits.clear();
            subUnits.add(parseUnit);
            subUnits.add(curToken);
            subUnits.add(parseMulExp());
        }
        return new ParseUnit("AddExp", subUnits);
    }

    public ParseUnit parseRelExp() {
        ArrayList<ParseUnit> subUnits = new ArrayList<>();
        subUnits.add(parseAddExp());
        while (getToken(Word.LSS, Word.GRE, Word.LEQ, Word.GEQ)) {
            ArrayList<ParseUnit> newUnits = new ArrayList<>(subUnits);
            ParseUnit parseUnit = new ParseUnit("RelExp", newUnits);

            subUnits.clear();
            subUnits.add(parseUnit);
            subUnits.add(curToken);
            subUnits.add(parseAddExp());
        }
        return new ParseUnit("RelExp", subUnits);
    }

    public ParseUnit parseEqExp() {
        ArrayList<ParseUnit> subUnits = new ArrayList<>();
        subUnits.add(parseRelExp());
        while (getToken(Word.EQL, Word.NEQ)) {
            ArrayList<ParseUnit> newUnits = new ArrayList<>(subUnits);
            ParseUnit parseUnit = new ParseUnit("EqExp", newUnits);

            subUnits.clear();
            subUnits.add(parseUnit);
            subUnits.add(curToken);
            subUnits.add(parseRelExp());
        }
        return new ParseUnit("EqExp", subUnits);
    }

    public ParseUnit parseLAndExp() {
        ArrayList<ParseUnit> subUnits = new ArrayList<>();
        subUnits.add(parseEqExp());
        while (getToken(Word.AND)) {
            ArrayList<ParseUnit> newUnits = new ArrayList<>(subUnits);
            ParseUnit parseUnit = new ParseUnit("LAndExp", newUnits);

            subUnits.clear();
            subUnits.add(parseUnit);
            subUnits.add(curToken);
            subUnits.add(parseEqExp());
        }
        return new ParseUnit("LAndExp", subUnits);
    }

    public ParseUnit parseLOrExp() {
        ArrayList<ParseUnit> subUnits = new ArrayList<>();
        subUnits.add(parseLAndExp());
        while (getToken(Word.OR)) {
            ArrayList<ParseUnit> newUnits = new ArrayList<>(subUnits);
            ParseUnit parseUnit = new ParseUnit("LOrExp", newUnits);

            subUnits.clear();
            subUnits.add(parseUnit);
            subUnits.add(curToken);
            subUnits.add(parseLAndExp());
        }
        return new ParseUnit("LOrExp", subUnits);
    }

    public ParseUnit parseConstExp() {
        ArrayList<ParseUnit> subUnits = new ArrayList<>();
        subUnits.add(parseAddExp());
        return new ParseUnit("ConstExp", subUnits);
    }
//    public ArrayList<Error> getErrors(){
//        return errors;
//    }
}
