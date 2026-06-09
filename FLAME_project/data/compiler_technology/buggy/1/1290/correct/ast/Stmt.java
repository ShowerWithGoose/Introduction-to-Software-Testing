package ast;

import error.ParserError;
import error.SemanticError;
import lexical.LexerMark;
import lexical.TokenType;
import semantic.*;

public class Stmt extends Symbol {

    private boolean returned = false;

    public static Symbol of(String dir, SymbolTable table, FuncInfo info, Boolean loop) {
        Symbol symbol;
        Stmt stmt = new Stmt();

        LexerMark mark = lexer.mark();

         /*
            LVal 开头三种
            1. LVal = Exp;
            2. LVal = getint();
            3. LVal = getchar();
         */
        if ((symbol = LVal.of(table)) != null) {

            Info info1 = table.getInfo(((LVal) symbol).getIdent());
            if (info1 instanceof ConstInfo) {
                logger.log(new SemanticError(((LVal) symbol).getIdentLine(), "h"));
            }

            // =
            if (token.getType().equals(TokenType.ASSIGN)) {
                stmt.add(symbol);
                stmt.add(token);
                token = lexer.nextToken();

                // getint
                if (token.getType().equals(TokenType.GETINTTK)) {
                    stmt.add(token);
                    token = lexer.nextToken();

                    // (
                    if (!token.getType().equals(TokenType.LPARENT)) {
                        return null;
                    }
                    stmt.add(token);
                    token = lexer.nextToken();

                    // )
                    if (!token.getType().equals(TokenType.RPARENT)) {
                        logger.log(new ParserError(symbol.getLine(), "j"));
                    } else {
                        stmt.add(token);
                        token = lexer.nextToken();
                    }

                    // ;
                    if (!token.getType().equals(TokenType.SEMICN)) {
                        logger.log(new ParserError(symbol.getLine(), "i"));
                        return stmt;
                    }
                    stmt.add(token);
                    token = lexer.nextToken();
                    return stmt;

                    // getchar
                } else if (token.getType().equals(TokenType.GETCHARTK)) {
                    stmt.add(token);
                    token = lexer.nextToken();

                    // (
                    if (!token.getType().equals(TokenType.LPARENT)) {
                        return null;
                    }
                    stmt.add(token);
                    token = lexer.nextToken();

                    // )
                    if (!token.getType().equals(TokenType.RPARENT)) {
                        logger.log(new ParserError(symbol.getLine(), "j"));
                    } else {
                        stmt.add(token);
                        token = lexer.nextToken();
                    }

                    // ;
                    if (!token.getType().equals(TokenType.SEMICN)) {
                        logger.log(new ParserError(symbol.getLine(), "i"));
                        return stmt;
                    }
                    stmt.add(token);
                    token = lexer.nextToken();
                    return stmt;

                    // Exp
                } else if ((symbol = Exp.of(table)) != null) {
                    stmt.add(symbol);

                    // ;
                    if (!token.getType().equals(TokenType.SEMICN)) {
                        logger.log(new ParserError(symbol.getLine(), "i"));
                        return stmt;
                    }
                    stmt.add(token);
                    token = lexer.nextToken();
                    return stmt;
                }
            }
        }

        lexer.back(mark);
        token = lexer.getToken();

        /*
            Exp;
         */
        if ((symbol = Exp.of(table)) != null) {
            // ;
            if (token.getType().equals(TokenType.SEMICN)) {
                stmt.add(symbol);
                stmt.add(token);
                token = lexer.nextToken();
                return stmt;
            } else {
                stmt.add(symbol);
                logger.log(new ParserError(symbol.getLine(), "i"));
                return stmt;
            }
        }

        /*
            ;
         */
        if (token.getType().equals(TokenType.SEMICN)) {
            stmt.add(token);
            token = lexer.nextToken();
            return stmt;
        }

        /*
            Block
         */
        if ((symbol = Block.of(dir, info, loop)) != null) {
            stmt.add(symbol);
            return stmt;
        }

        /*
            if(Cond) Stmt [else Stmt]
         */
        if (token.getType().equals(TokenType.IFTK)) {
            stmt.add(token);
            token = lexer.nextToken();

            // (
            if (!token.getType().equals(TokenType.LPARENT)) {
                return null;
            }
            stmt.add(token);
            token = lexer.nextToken();

            // Cond
            if ((symbol = Cond.of(table)) == null) {
                return null;
            }
            stmt.add(symbol);

            // )
            if (!token.getType().equals(TokenType.RPARENT)) {
                logger.log(new ParserError(symbol.getLine(), "j"));
            } else {
                stmt.add(token);
                token = lexer.nextToken();
            }

            // Stmt
            if ((symbol = Stmt.of(dir, table, info, loop)) == null) {
                return null;
            }
            stmt.add(symbol);

            // else
            if (token.getType().equals(TokenType.ELSETK)) {
                stmt.add(token);
                token = lexer.nextToken();

                // Stmt
                if ((symbol = Stmt.of(dir, table, info, loop)) == null) {
                    return null;
                }
                stmt.add(symbol);
            }
            return stmt;
        }

        /*
            for(ForStmt; Cond; ForStmt) Stmt
         */
        if (token.getType().equals(TokenType.FORTK)) {
            stmt.add(token);
            token = lexer.nextToken();

            // (
            if (!token.getType().equals(TokenType.LPARENT)) {
                return null;
            }
            stmt.add(token);
            token = lexer.nextToken();

            // ForStmt
            if ((symbol = ForStmt.of(table)) != null) {
                stmt.add(symbol);
            }

            // ;
            if (!token.getType().equals(TokenType.SEMICN)) {
                return null;
            }
            stmt.add(token);
            token = lexer.nextToken();

            // Cond
            if ((symbol = Cond.of(table)) != null) {
                stmt.add(symbol);
            }

            // ;
            if (!token.getType().equals(TokenType.SEMICN)) {
                return null;
            }
            stmt.add(token);
            token = lexer.nextToken();

            // ForStmt
            if ((symbol = ForStmt.of(table)) != null) {
                stmt.add(symbol);
            }

            // )
            if (!token.getType().equals(TokenType.RPARENT)) {
                return null;
            }
            stmt.add(token);
            token = lexer.nextToken();

            // Stmt
            if ((symbol = Stmt.of(dir, table, info, true)) == null) {
                return null;
            }
            stmt.add(symbol);
            return stmt;
        }

        /*
            break;
         */
        if (token.getType().equals(TokenType.BREAKTK)) {
            if (!loop) {
                logger.log(new SemanticError(token.getLine(), "m"));
            }
            int line = token.getLine();
            stmt.add(token);
            token = lexer.nextToken();

            // ;
            if (!token.getType().equals(TokenType.SEMICN)) {
                // TODO
                logger.log(new ParserError(line, "i"));
                return stmt;
            }
            stmt.add(token);
            token = lexer.nextToken();
            return stmt;
        }

        /*
            continue;
         */
        if (token.getType().equals(TokenType.CONTINUETK)) {
            if (!loop) {
                logger.log(new SemanticError(token.getLine(), "m"));
            }
            int line = token.getLine();
            stmt.add(token);
            token = lexer.nextToken();

            // ;
            if (!token.getType().equals(TokenType.SEMICN)) {
                // TODO
                logger.log(new ParserError(line, "i"));
                return stmt;
            }
            stmt.add(token);
            token = lexer.nextToken();
            return stmt;
        }

        /*
            return [Exp];
         */
        if (token.getType().equals(TokenType.RETURNTK)) {
            stmt.add(token);
            int returnLine = token.getLine();
            token = lexer.nextToken();
            stmt.returned = true;
            // Exp
            if ((symbol = Exp.of(table)) != null) {
                stmt.add(symbol);
                if (info instanceof VoidFuncInfo) {
                    logger.log(new SemanticError(returnLine, "f"));
                }
            }

            // ;
            if (!token.getType().equals(TokenType.SEMICN)) {
                if (symbol == null) {
                    logger.log(new ParserError(returnLine, "i"));
                } else {
                    logger.log(new ParserError(symbol.getLine(), "i"));
                }
                return stmt;
            }
            stmt.add(token);
            token = lexer.nextToken();
            return stmt;
        }

        /*
            print(StringConst {, Exp});
         */
        if (token.getType().equals(TokenType.PRINTFTK)) {
            int printfLine = token.getLine();

            stmt.add(token);
            token = lexer.nextToken();

            // (
            if (!token.getType().equals(TokenType.LPARENT)) {
                return null;
            }
            stmt.add(token);
            token = lexer.nextToken();

            // StringConst
            if ((symbol = StringConst.of()) == null) {
                return null;
            }
            String pattern = ((StringConst) symbol).getValue();
            stmt.add(symbol);
            int num = getNum(pattern);
            int stmtNum = 0;
            // ,
            while (token.getType().equals(TokenType.COMMA)) {
                stmt.add(token);
                token = lexer.nextToken();
                stmtNum++;
                // Stmt
                if ((symbol = Exp.of(table)) == null) {
                    return null;
                }
                stmt.add(symbol);
            }

            if (stmtNum != num) {
                logger.log(new SemanticError(printfLine, "l"));
            }
            // )
            if (!token.getType().equals(TokenType.RPARENT)) {
                logger.log(new ParserError(symbol.getLine(), "j"));
            } else {
                stmt.add(token);
                token = lexer.nextToken();
            }

            // ;
            if (!(token.getType().equals(TokenType.SEMICN))) {
                logger.log(new ParserError(symbol.getLine(), "i"));
                return stmt;
            }
            stmt.add(token);
            token = lexer.nextToken();
            return stmt;
        }
        return null;
    }

    public boolean getReturned() {
        return returned;
    }

    private static int getNum(String pattern) {
        String replaced = pattern.replaceAll("%d|%c", " ");
        return pattern.length() - replaced.length();
    }

}
