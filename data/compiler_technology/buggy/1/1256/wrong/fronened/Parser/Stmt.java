package fronened.Parser;

import fronened.Lexer.Error;
import fronened.Lexer.ErrorList;
import fronened.Lexer.Token;
import fronened.Lexer.TokenIterator;

import java.util.ArrayList;

public class Stmt {
    private LVal lVal1;
    private Token assign1;
    private Exp exp1;
    private Token semicn1;
    private Exp exp2;
    private Token semicn2;
    private Block block;
    private Token If;
    private Stmt stmt1;
    private Token Else;
    private Stmt stmt2;
    private Token lParent1;
    private Cond cond1;
    private Token rParent1;
    private Token For;
    private Token lParent2;
    private Token rParent2;
    private ForStmt forStmt1;
    private Token semicn1_for;
    private Cond cond2;
    private Token semicn2_for;
    private ForStmt forStmt2;
    private Stmt stmt_for;
    private Token Break;
    private Token semicn_break;
    private Token Continue;
    private Token semicn_continue;
    private Token Return;
    private Exp exp3;
    private Token semicn_return;
    private LVal lVal2;
    private Token assign2;
    private Token getint;
    private Token lParent3;
    private Token rParent3;
    private Token semicn_getint;
    private LVal lVal3;
    private Token assign3;
    private Token getchar;
    private Token lParent4;
    private Token rParent4;
    private Token semicn_getchar;
    private Token printf;
    private Token lParent5;
    private Token rParent5;
    private Token stringConst;
    private ArrayList<Token> commas;
    private ArrayList<Exp> exps;
    private Token semicn_printf;
    private Integer op;

    public Stmt(LVal lVal1, Token assign1, Exp exp1, Token semicn1) {
        this.lVal1 = lVal1;
        this.assign1 = assign1;
        this.exp1 = exp1;
        this.semicn1 = semicn1;
        this.op = 0;
    }

    public Stmt(Exp exp2, Token semicn2) {
        this.exp2 = exp2;
        this.semicn2 = semicn2;
        this.op = 1;
    }

    public Stmt(Block block) {
        this.block = block;
        this.op = 2;
    }

    public Stmt(Token anIf, Stmt stmt1, Token anElse, Stmt stmt2, Token lParent1, Cond cond1, Token rParent1) {
        If = anIf;
        this.stmt1 = stmt1;
        Else = anElse;
        this.stmt2 = stmt2;
        this.lParent1 = lParent1;
        this.cond1 = cond1;
        this.rParent1 = rParent1;
        this.op = 3;
    }

    public Stmt(Token aFor, Token lParent2, Token rParent2, ForStmt forStmt1, Token semicn1_for, Cond cond2, Token semicn2_for, ForStmt forStmt2, Stmt stmt_for) {
        For = aFor;
        this.lParent2 = lParent2;
        this.rParent2 = rParent2;
        this.forStmt1 = forStmt1;
        this.semicn1_for = semicn1_for;
        this.cond2 = cond2;
        this.semicn2_for = semicn2_for;
        this.forStmt2 = forStmt2;
        this.stmt_for = stmt_for;
        this.op = 4;
    }

    public Stmt(Token aBreak, Token semicn_break) {
        if (aBreak.getType().equals(Token.Type.BREAKTK)) {
            this.Break = aBreak;
            this.semicn_break = semicn_break;
            this.op = 5;
        }
        else {
            this.Continue = aBreak;
            this.semicn_continue = semicn_break;
            this.op = 6;
        }
    }

    public Stmt(Token aReturn, Exp exp3, Token semicn_return) {
        Return = aReturn;
        this.exp3 = exp3;
        this.semicn_return = semicn_return;
        this.op = 7;
    }

    public Stmt(LVal lVal2, Token assign2, Token getint, Token lParent3, Token rParent3, Token semicn_getint) {
        if (getint.getType().equals(Token.Type.GETINTTK)) {
            this.lVal2 = lVal2;
            this.assign2 = assign2;
            this.getint = getint;
            this.lParent3 = lParent3;
            this.rParent3 = rParent3;
            this.semicn_getint = semicn_getint;
            this.op = 8;
        }
        else {
            this.lVal3 = lVal2;
            this.assign3 = assign2;
            this.getchar = getint;
            this.lParent4 = lParent3;
            this.rParent4 = rParent3;
            this.semicn_getchar = semicn_getint;
            this.op = 9;
        }
    }

    public Stmt(Token printf, Token lParent5, Token rParent5, Token stringConst, ArrayList<Token> commas, ArrayList<Exp> exps, Token semicn_printf) {
        this.printf = printf;
        this.lParent5 = lParent5;
        this.rParent5 = rParent5;
        this.stringConst = stringConst;
        this.commas = commas;
        this.exps = exps;
        this.semicn_printf = semicn_printf;
        this.op = 10;
    }

    public String print() {
        StringBuilder sb = new StringBuilder();
        if (op == 0) {
            sb.append(lVal1.print());
            sb.append(assign1.print());
            sb.append(exp1.print());
            if (semicn1 != null) {
                sb.append(semicn1.print());
            }
        }
        else if (op == 1) {
            if (exp2 != null) {
                sb.append(exp2.print());
            }
            if (semicn2 != null) {
                sb.append(semicn2.print());
            }
        }
        else if (op == 2) {
            sb.append(block.print());
        }
        else if (op == 3) {
            sb.append(If.print());
            sb.append(lParent1.print());
            sb.append(cond1.print());
            if (rParent1 != null) {
                sb.append(rParent1.print());
            }
            sb.append(stmt1.print());
            if (Else != null) {
                sb.append(Else.print());
            }
            if (stmt2 != null) {
                sb.append(stmt2.print());
            }
        }
        else if (op == 4) {
            sb.append(For.print());
            sb.append(lParent2.print());
            if (forStmt1 != null) {
                sb.append(forStmt1.print());
            }
            sb.append(semicn1_for.print());
            if (cond2 != null) {
                sb.append(cond2.print());
            }
            sb.append(semicn2_for.print());
            if (forStmt2 != null) {
                sb.append(forStmt2.print());
            }
            sb.append(rParent2.print());
            sb.append(stmt_for.print());
        }
        else if (op == 5) {
            sb.append(Break.print());
            if (semicn_break != null) {
                sb.append(semicn_break.print());
            }
        }
        else if (op == 6) {
            sb.append(Continue.print());
            if (semicn_continue != null) {
                sb.append(semicn_continue.print());
            }
        }
        else if (op == 7) {
            sb.append(Return.print());
            if (exp3 != null){
                sb.append(exp3.print());
            }
            if (semicn_return != null) {
                sb.append(semicn_return.print());
            }
        }
        else if (op == 8) {
            sb.append(lVal2.print());
            sb.append(assign2.print());
            sb.append(getint.print());
            sb.append(lParent3.print());
            if (rParent3 != null) {
                sb.append(rParent3.print());
            }
            if (semicn_getint != null) {
                sb.append(semicn_getint.print());
            }
        }
        else if (op == 9) {
            sb.append(lVal3.print());
            sb.append(assign3.print());
            sb.append(getchar.print());
            sb.append(lParent4.print());
            if (rParent4 != null) {
                sb.append(rParent4.print());
            }
            if (semicn_getchar != null) {
                sb.append(semicn_getchar.print());
            }
        }
        else {
            sb.append(printf.print());
            sb.append(lParent5.print());
            sb.append(stringConst.print());
            if (!commas.isEmpty()) {
                for (int i = 0; i < commas.size(); i++) {
                    sb.append(commas.get(i).print());
                    sb.append(exps.get(i).print());
                }
            }
            if (rParent5 != null) {
                sb.append(rParent5.print());
            }
            if (semicn_printf != null) {
                sb.append(semicn_printf.print());
            }

        }
        sb.append("<Stmt>\n");
        return sb.toString();
    }

    public static Stmt parse(TokenIterator iterator) {
        Token token = iterator.next();
        if (token.getType().equals(Token.Type.RETURNTK)) {
            Token Return = token;
            Token first = iterator.next();
            Exp exp = null;
            Token semicn = null;
            if (first.getType().equals(Token.Type.IDENFR) || first.getType().equals(Token.Type.LPARENT) || first.getType().equals(Token.Type.INTCON) || first.getType().equals(Token.Type.CHRCON)
            || first.getType().equals(Token.Type.PLUS) || first.getType().equals(Token.Type.MINU) || first.getType().equals(Token.Type.NOT)) {
                iterator.back();
                exp = Exp.parse(iterator);
            }
            else {
                iterator.back();
            }
            token = iterator.next();
            if (token.getType().equals(Token.Type.SEMICN)) {
                semicn = token;
            } else {
                iterator.back();
                Error error = new Error(iterator.now_line(), 'i');
                ErrorList.addError(error);
            }
            return new Stmt(Return,exp,semicn);


        }
        else if (token.getType().equals(Token.Type.IFTK)) {
            Token If = token;
            Token lParent1 = iterator.next();
            Cond cond1 = Cond.parse(iterator);
            Token rParent1 = null;
            token = iterator.next();
            if (token.getType().equals(Token.Type.RPARENT)) {
                rParent1 = token;
            } else {
                iterator.back();
                Error error = new Error(iterator.now_line(), 'j');
                ErrorList.addError(error);
            }
            Stmt stmt1 = Stmt.parse(iterator);
            Token Else = null;
            Stmt stmt2 = null;
            token = iterator.next();
            if (token.getType().equals(Token.Type.ELSETK)) {
                Else = token;
                stmt2 = Stmt.parse(iterator);
            } else {
                iterator.back();
            }
            return new Stmt(If, stmt1, Else, stmt2, lParent1, cond1, rParent1);
        } else if (token.getType().equals(Token.Type.LBRACE)) {
            iterator.back();
            Block block = Block.parse(iterator);
            return new Stmt(block);
        } else if (token.getType().equals(Token.Type.FORTK)) {
            Token For = token;
            Token lParent = iterator.next();
            ForStmt forStmt = null;
            token = iterator.next();
            if (!token.getType().equals(Token.Type.SEMICN)) {
                iterator.back();
                forStmt = ForStmt.parse(iterator);
                token = iterator.next();
            }
            Token semicn1 = token;
            Cond cond = null;
            token = iterator.next();
            if (!token.getType().equals(Token.Type.SEMICN)) {
                iterator.back();
                cond = Cond.parse(iterator);
                token = iterator.next();
            }
            Token semicn2 = token;
            ForStmt forStmt2 = null;
            token = iterator.next();
            if (!token.getType().equals(Token.Type.RPARENT)) {
                iterator.back();
                forStmt2 = ForStmt.parse(iterator);
                token = iterator.next();
            }
            Token rParent = token;
            Stmt stmt = Stmt.parse(iterator);
            return new Stmt(For, lParent, rParent, forStmt, semicn1, cond, semicn2, forStmt2, stmt);
        } else if (token.getType().equals(Token.Type.BREAKTK)) {
            Token Break = token;
            Token semicn = null;
            token = iterator.next();
            if (token.getType().equals(Token.Type.SEMICN)) {
                semicn = token;
            } else {
                iterator.back();
                Error error = new Error(iterator.now_line(), 'i');
                ErrorList.addError(error);
            }
            return new Stmt(Break, semicn);
        } else if (token.getType().equals(Token.Type.CONTINUETK)) {
            Token Continue = token;
            Token semicn = null;
            token = iterator.next();
            if (token.getType().equals(Token.Type.SEMICN)) {
                semicn = token;
            } else {
                iterator.back();
                Error error = new Error(iterator.now_line(), 'i');
                ErrorList.addError(error);
            }
            return new Stmt(Continue, semicn);
        } else if (token.getType().equals(Token.Type.PRINTFTK)) {
            Token Printf = token;
            Token lParent = iterator.next();
            Token stringConst = iterator.next();
            ArrayList<Token> commas = new ArrayList<>();
            ArrayList<Exp> exps = new ArrayList<>();
            Token rParent = null;
            Token semicn_printf = null;
            token = iterator.next();
            while (token.getType().equals(Token.Type.COMMA)) {
                commas.add(token);
                exps.add(Exp.parse(iterator));
                token = iterator.next();
            }
            if (token.getType().equals(Token.Type.RPARENT)) {
                rParent = token;
            } else {
                iterator.back();
                Error error = new Error(iterator.now_line(), 'j');
                ErrorList.addError(error);
            }
            token = iterator.next();
            if (token.getType().equals(Token.Type.SEMICN)) {
                semicn_printf = token;
            } else {
                iterator.back();
                Error error = new Error(iterator.now_line(), 'i');
                ErrorList.addError(error);
            }
            return new Stmt(Printf, lParent, rParent, stringConst, commas, exps, semicn_printf);
        } else if (token.getType().equals(Token.Type.IDENFR)) {
            token = iterator.next();
            if (!token.getType().equals(Token.Type.LBRACK) && !token.getType().equals(Token.Type.ASSIGN)) {
                iterator.back(2);
                Exp exp = Exp.parse(iterator);
                Token semicn_exp = null;
                token = iterator.next();
                if (token.getType().equals(Token.Type.SEMICN)) {
                    semicn_exp = token;
                } else {
                    iterator.back();
                    Error error = new Error(iterator.now_line(), 'i');
                    ErrorList.addError(error);
                }
                return new Stmt(exp, semicn_exp);
            } else {
                if (token.getType().equals(Token.Type.LBRACK)) {
                    iterator.back(2);
                    int start = iterator.getCurrentToken();
                    LVal lVal = LVal.parse(iterator);
                    token = iterator.next();
                    if (token.getType().equals(Token.Type.ASSIGN)) {
                        Token assign = token;
                        token = iterator.next();
                        if (token.getType().equals(Token.Type.GETINTTK)) {
                            Token getint = token;
                            Token lParent = iterator.next();
                            Token rParent = null;
                            Token semicn_getint = null;
                            token = iterator.next();
                            if (token.getType().equals(Token.Type.RPARENT)) {
                                rParent = token;
                            } else {
                                iterator.back();
                                Error error = new Error(iterator.now_line(), 'j');
                                ErrorList.addError(error);
                            }
                            token = iterator.next();
                            if (token.getType().equals(Token.Type.SEMICN)) {
                                semicn_getint = token;
                            } else {
                                iterator.back();
                                Error error = new Error(iterator.now_line(), 'i');
                                ErrorList.addError(error);
                            }
                            return new Stmt(lVal, assign, getint, lParent, rParent, semicn_getint);
                        } else if (token.getType().equals(Token.Type.GETCHARTK)) {
                            Token getchar = token;
                            Token lParent = iterator.next();
                            Token rParent = null;
                            Token semicn_getchar = null;
                            token = iterator.next();
                            if (token.getType().equals(Token.Type.RPARENT)) {
                                rParent = token;
                            } else {
                                iterator.back();
                                Error error = new Error(iterator.now_line(), 'j');
                                ErrorList.addError(error);
                            }
                            token = iterator.next();
                            if (token.getType().equals(Token.Type.SEMICN)) {
                                semicn_getchar = token;
                            } else {
                                iterator.back();
                                Error error = new Error(iterator.now_line(), 'i');
                                ErrorList.addError(error);
                            }
                            return new Stmt(lVal, assign, getchar, lParent, rParent, semicn_getchar);
                        } else {
                            iterator.back();
                            Exp exp = Exp.parse(iterator);
                            Token semicn_exp = null;
                            token = iterator.next();
                            if (token.getType().equals(Token.Type.SEMICN)) {
                                semicn_exp = token;
                            } else {
                                iterator.back();
                                Error error = new Error(iterator.now_line(), 'i');
                                ErrorList.addError(error);
                            }
                            return new Stmt(lVal, assign, exp, semicn_exp);
                        }
                    } else {
                        iterator.setCurrentToken(start);
                        Exp exp = Exp.parse(iterator);
                        Token semicn_exp = null;
                        token = iterator.next();
                        if (token.getType().equals(Token.Type.SEMICN)) {
                            semicn_exp = token;
                        } else {
                            iterator.back();
                            Error error = new Error(iterator.now_line(), 'i');
                            ErrorList.addError(error);
                        }
                        return new Stmt(exp, semicn_exp);
                    }
                } else {
                    iterator.back(2);
                    LVal lVal = LVal.parse(iterator);
                    Token assign = iterator.next();
                    token = iterator.next();
                    if (token.getType().equals(Token.Type.GETINTTK)) {
                        Token getint = token;
                        Token lParent = iterator.next();
                        Token rParent = null;
                        Token semicn_getint = null;
                        token = iterator.next();
                        if (token.getType().equals(Token.Type.RPARENT)) {
                            rParent = token;
                        } else {
                            iterator.back();
                            Error error = new Error(iterator.now_line(), 'j');
                            ErrorList.addError(error);
                        }
                        token = iterator.next();
                        if (token.getType().equals(Token.Type.SEMICN)) {
                            semicn_getint = token;
                        } else {
                            iterator.back();
                            Error error = new Error(iterator.now_line(), 'i');
                            ErrorList.addError(error);
                        }
                        return new Stmt(lVal, assign, getint, lParent, rParent, semicn_getint);
                    } else if (token.getType().equals(Token.Type.GETCHARTK)) {
                        Token getchar = token;
                        Token lParent = iterator.next();
                        Token rParent = null;
                        Token semicn_getchar = null;
                        token = iterator.next();
                        if (token.getType().equals(Token.Type.RPARENT)) {
                            rParent = token;
                        } else {
                            iterator.back();
                            Error error = new Error(iterator.now_line(), 'j');
                            ErrorList.addError(error);
                        }
                        token = iterator.next();
                        if (token.getType().equals(Token.Type.SEMICN)) {
                            semicn_getchar = token;
                        } else {
                            iterator.back();
                            Error error = new Error(iterator.now_line(), 'i');
                            ErrorList.addError(error);
                        }
                        return new Stmt(lVal, assign, getchar, lParent, rParent, semicn_getchar);
                    } else {
                        iterator.back();
                        Exp exp = Exp.parse(iterator);
                        Token semicn_exp = null;
                        token = iterator.next();
                        if (token.getType().equals(Token.Type.SEMICN)) {
                            semicn_exp = token;
                        } else {
                            iterator.back();
                            Error error = new Error(iterator.now_line(), 'i');
                            ErrorList.addError(error);
                        }
                        return new Stmt(lVal, assign, exp, semicn_exp);
                    }
                }
            }
        }
        else {
            if (token.getType().equals(Token.Type.SEMICN)) {
                Exp exp = null;
                Token semicn_exp = token;
                return new Stmt(exp,semicn_exp);
            }
            else {
                iterator.back();
                Exp exp = Exp.parse(iterator);
                Token semicn_exp = null;
                token = iterator.next();
                if (token.getType().equals(Token.Type.SEMICN)) {
                    semicn_exp = token;
                } else {
                    iterator.back();
                    Error error = new Error(iterator.now_line(), 'i');
                    ErrorList.addError(error);
                }
                return new Stmt(exp,semicn_exp);
            }
        }
    }


}
