package frontend;

import common.Error;
import common.ParseTree;
import common.SyntaxElem;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.function.Supplier;


public class Parser {
    private final ArrayList<Token> tokens;
    private int cursor;
    private final ArrayList<Error> errorList;

    private int getCursor() {
        return cursor;
    }

    private int getErrorLine() {
        assert cursor > 0;
        return tokens.get(cursor - 1).line;
    }

    private Token getNextToken() {
        return tokens.get(cursor);
    }

    private Token getNextNextToken() {
        return tokens.get(cursor + 1);
    }

    /**
     *
     * @param num: 下几个（num=1: 下一个 <=> getNextToken）
     * @return token
     */
    private Token getTokenOfNextNum(int num) {
        return tokens.get(cursor + num - 1);
    }

    private void moveCursor() {
        cursor++;
    }

    private void rollBack(int tokensCursor, int errorsCursor) {
        this.cursor = tokensCursor;
        if (errorsCursor < errorList.size()) {
            errorList.subList(errorsCursor, errorList.size()).clear();
        }
    }

    private boolean tryAndTest(Supplier<ParseTree> func, TokenType nxtType) {
        int rollBackPoint = cursor;
        int errorListTail = errorList.size();
        boolean res = func.get() != null && getNextToken().type == nxtType;
        rollBack(rollBackPoint, errorListTail);
        return res;
    }

    private boolean tryAndTest(Supplier<ParseTree> func) {
        int rollBackPoint = cursor;
        int errorListTail = errorList.size();
        boolean res = func.get() != null;
        rollBack(rollBackPoint, errorListTail);
        return res;
    }

    private Parser(ArrayList<Token> tokens, ArrayList<Error> handlerOfErrList) {
        this.tokens = tokens;
        this.errorList = handlerOfErrList;
    }

    public static ParseTree parse(ArrayList<Token> tokens, ArrayList<Error> handlerOfErrList) {
        tokens.add(new Token(TokenType.End, "", 0));
        Parser parser = new Parser(tokens, handlerOfErrList);
        ParseTree res = parser.parseCompUnit();
        assert parser.getNextToken().type == TokenType.End;
        tokens.remove(parser.cursor);
        return res;
    }

    public static ArrayList<String> traversalParseTree(ParseTree tree) {
        HashSet<SyntaxElem> ignoredElem = new HashSet<>();
        ignoredElem.add(SyntaxElem.BlockItem);
        ignoredElem.add(SyntaxElem.Decl);
        ignoredElem.add(SyntaxElem.BType);
        List<ParseTree> nodes = tree.preOrderTraversal();
        ArrayList<String> strings = new ArrayList<>();
        for (ParseTree node: nodes) {
            if (ignoredElem.contains(node.syntaxElem)) {
                continue;
            }
            strings.add(node.printNode());
        }
        return strings;
    }

    /*
     * 以下内容使用脚本生成：utils/grammar.py
     * 不许直接在Java代码中修改
     */

    /*------------------------------------自定义形式，总共3个-------------------------------------*/

    private ParseTree parseCompUnit() {
        //set roll-back point
        int rollBackPoint = cursor;
        int errorListTail = errorList.size();
        ParseTree topNode = new ParseTree(SyntaxElem.CompUnit);
        ParseTree nxtNode;

        while (
                (!(tryAndTest(this::parseFuncType) &&
                        getTokenOfNextNum(2).type == TokenType.IDENFR &&
                        getTokenOfNextNum(3).type == TokenType.LPARENT))
                        &&
                        ((nxtNode = parseDecl()) != null)
        ) {
            topNode.addChild(nxtNode);
        }
        while ((nxtNode = parseFuncDef()) != null) {
            topNode.addChild(nxtNode);
        }

        nxtNode = parseMainFuncDef();
        if (nxtNode == null) {
            rollBack(rollBackPoint, errorListTail);
            return null;
        }
        topNode.addChild(nxtNode);

        return topNode;
    }


    private ParseTree parseStmt() {
        //set roll-back point
        int rollBackPoint = cursor;
        int errorListTail = errorList.size();
        ParseTree topNode = new ParseTree(SyntaxElem.Stmt);
        ParseTree nxtNode;

        if (getNextToken().type == TokenType.LBRACE) {

            nxtNode = parseBlock();
            if (nxtNode == null) {
                rollBack(rollBackPoint, errorListTail);
                return null;
            }
            topNode.addChild(nxtNode);

        } else if (getNextToken().type == TokenType.IFTK) {

            if (getNextToken().type != TokenType.IFTK) {
                rollBack(rollBackPoint, errorListTail);
                return null;
            }
            topNode.addChild(new ParseTree(SyntaxElem.Terminal, getNextToken()));
            moveCursor();

            if (getNextToken().type != TokenType.LPARENT) {
                rollBack(rollBackPoint, errorListTail);
                return null;
            }
            topNode.addChild(new ParseTree(SyntaxElem.Terminal, getNextToken()));
            moveCursor();

            nxtNode = parseCond();
            if (nxtNode == null) {
                rollBack(rollBackPoint, errorListTail);
                return null;
            }
            topNode.addChild(nxtNode);

            // 错误处理：MISSING_RIGHT_PAREN
            if (getNextToken().type != TokenType.RPARENT) {
                errorList.add(new Error(getErrorLine(), Error.MISSING_RIGHT_PAREN));
            } else {
                // 若无错，加入语法树并移动
                topNode.addChild(new ParseTree(SyntaxElem.Terminal, getNextToken()));
                moveCursor();
            }
            nxtNode = parseStmt();
            if (nxtNode == null) {
                rollBack(rollBackPoint, errorListTail);
                return null;
            }
            topNode.addChild(nxtNode);

            //可选项开始：[ELSETK...]
            if (getNextToken().type == TokenType.ELSETK) {
                topNode.addChild(new ParseTree(SyntaxElem.Terminal, getNextToken()));
                moveCursor();

                nxtNode = parseStmt();
                if (nxtNode == null) {
                    rollBack(rollBackPoint, errorListTail);
                    return null;
                }
                topNode.addChild(nxtNode);

            }
            //可选项结束

        } else if (getNextToken().type == TokenType.FORTK) {

            if (getNextToken().type != TokenType.FORTK) {
                rollBack(rollBackPoint, errorListTail);
                return null;
            }
            topNode.addChild(new ParseTree(SyntaxElem.Terminal, getNextToken()));
            moveCursor();

            if (getNextToken().type != TokenType.LPARENT) {
                rollBack(rollBackPoint, errorListTail);
                return null;
            }
            topNode.addChild(new ParseTree(SyntaxElem.Terminal, getNextToken()));
            moveCursor();

            //可选项开始：
            nxtNode = parseForStmt();
            if (nxtNode != null) {
                topNode.addChild(nxtNode);

            }
            //可选项结束：

            // 错误处理：MISSING_SEMICOLON
            if (getNextToken().type != TokenType.SEMICN) {
                errorList.add(new Error(getErrorLine(), Error.MISSING_SEMICOLON));
            } else {
                // 若无错，加入语法树并移动
                topNode.addChild(new ParseTree(SyntaxElem.Terminal, getNextToken()));
                moveCursor();
            }
            //可选项开始：
            nxtNode = parseCond();
            if (nxtNode != null) {
                topNode.addChild(nxtNode);

            }
            //可选项结束：

            // 错误处理：MISSING_SEMICOLON
            if (getNextToken().type != TokenType.SEMICN) {
                errorList.add(new Error(getErrorLine(), Error.MISSING_SEMICOLON));
            } else {
                // 若无错，加入语法树并移动
                topNode.addChild(new ParseTree(SyntaxElem.Terminal, getNextToken()));
                moveCursor();
            }
            //可选项开始：
            nxtNode = parseForStmt();
            if (nxtNode != null) {
                topNode.addChild(nxtNode);

            }
            //可选项结束：

            // 错误处理：MISSING_RIGHT_PAREN
            if (getNextToken().type != TokenType.RPARENT) {
                errorList.add(new Error(getErrorLine(), Error.MISSING_RIGHT_PAREN));
            } else {
                // 若无错，加入语法树并移动
                topNode.addChild(new ParseTree(SyntaxElem.Terminal, getNextToken()));
                moveCursor();
            }
            nxtNode = parseStmt();
            if (nxtNode == null) {
                rollBack(rollBackPoint, errorListTail);
                return null;
            }
            topNode.addChild(nxtNode);

        } else if (getNextToken().type == TokenType.BREAKTK) {

            if (getNextToken().type != TokenType.BREAKTK) {
                rollBack(rollBackPoint, errorListTail);
                return null;
            }
            topNode.addChild(new ParseTree(SyntaxElem.Terminal, getNextToken()));
            moveCursor();

            // 错误处理：MISSING_SEMICOLON
            if (getNextToken().type != TokenType.SEMICN) {
                errorList.add(new Error(getErrorLine(), Error.MISSING_SEMICOLON));
            } else {
                // 若无错，加入语法树并移动
                topNode.addChild(new ParseTree(SyntaxElem.Terminal, getNextToken()));
                moveCursor();
            }
        } else if (getNextToken().type == TokenType.CONTINUETK) {

            if (getNextToken().type != TokenType.CONTINUETK) {
                rollBack(rollBackPoint, errorListTail);
                return null;
            }
            topNode.addChild(new ParseTree(SyntaxElem.Terminal, getNextToken()));
            moveCursor();

            // 错误处理：MISSING_SEMICOLON
            if (getNextToken().type != TokenType.SEMICN) {
                errorList.add(new Error(getErrorLine(), Error.MISSING_SEMICOLON));
            } else {
                // 若无错，加入语法树并移动
                topNode.addChild(new ParseTree(SyntaxElem.Terminal, getNextToken()));
                moveCursor();
            }
        } else if (getNextToken().type == TokenType.RETURNTK) {

            if (getNextToken().type != TokenType.RETURNTK) {
                rollBack(rollBackPoint, errorListTail);
                return null;
            }
            topNode.addChild(new ParseTree(SyntaxElem.Terminal, getNextToken()));
            moveCursor();

            //可选项开始：
            nxtNode = parseExp();
            if (nxtNode != null) {
                topNode.addChild(nxtNode);

            }
            //可选项结束：

            // 错误处理：MISSING_SEMICOLON
            if (getNextToken().type != TokenType.SEMICN) {
                errorList.add(new Error(getErrorLine(), Error.MISSING_SEMICOLON));
            } else {
                // 若无错，加入语法树并移动
                topNode.addChild(new ParseTree(SyntaxElem.Terminal, getNextToken()));
                moveCursor();
            }
        } else if (getNextToken().type == TokenType.PRINTFTK) {

            if (getNextToken().type != TokenType.PRINTFTK) {
                rollBack(rollBackPoint, errorListTail);
                return null;
            }
            topNode.addChild(new ParseTree(SyntaxElem.Terminal, getNextToken()));
            moveCursor();

            if (getNextToken().type != TokenType.LPARENT) {
                rollBack(rollBackPoint, errorListTail);
                return null;
            }
            topNode.addChild(new ParseTree(SyntaxElem.Terminal, getNextToken()));
            moveCursor();

            if (getNextToken().type != TokenType.STRCON) {
                rollBack(rollBackPoint, errorListTail);
                return null;
            }
            topNode.addChild(new ParseTree(SyntaxElem.Terminal, getNextToken()));
            moveCursor();

            //可选项开始：[COMMA...]
            while (getNextToken().type == TokenType.COMMA) {
                topNode.addChild(new ParseTree(SyntaxElem.Terminal, getNextToken()));
                moveCursor();

                nxtNode = parseExp();
                if (nxtNode == null) {
                    rollBack(rollBackPoint, errorListTail);
                    return null;
                }
                topNode.addChild(nxtNode);

            }
            //可选项结束

            // 错误处理：MISSING_RIGHT_PAREN
            if (getNextToken().type != TokenType.RPARENT) {
                errorList.add(new Error(getErrorLine(), Error.MISSING_RIGHT_PAREN));
            } else {
                // 若无错，加入语法树并移动
                topNode.addChild(new ParseTree(SyntaxElem.Terminal, getNextToken()));
                moveCursor();
            }
            // 错误处理：MISSING_SEMICOLON
            if (getNextToken().type != TokenType.SEMICN) {
                errorList.add(new Error(getErrorLine(), Error.MISSING_SEMICOLON));
            } else {
                // 若无错，加入语法树并移动
                topNode.addChild(new ParseTree(SyntaxElem.Terminal, getNextToken()));
                moveCursor();
            }
        } else if (tryAndTest(this::parseLVal, TokenType.ASSIGN)) {

            nxtNode = parseLVal();
            if (nxtNode == null) {
                rollBack(rollBackPoint, errorListTail);
                return null;
            }
            topNode.addChild(nxtNode);

            if (getNextToken().type != TokenType.ASSIGN) {
                rollBack(rollBackPoint, errorListTail);
                return null;
            }
            topNode.addChild(new ParseTree(SyntaxElem.Terminal, getNextToken()));
            moveCursor();
            if (getNextToken().type == TokenType.GETINTTK) {

                if (getNextToken().type != TokenType.GETINTTK) {
                    rollBack(rollBackPoint, errorListTail);
                    return null;
                }
                topNode.addChild(new ParseTree(SyntaxElem.Terminal, getNextToken()));
                moveCursor();

                if (getNextToken().type != TokenType.LPARENT) {
                    rollBack(rollBackPoint, errorListTail);
                    return null;
                }
                topNode.addChild(new ParseTree(SyntaxElem.Terminal, getNextToken()));
                moveCursor();

                // 错误处理：MISSING_RIGHT_PAREN
                if (getNextToken().type != TokenType.RPARENT) {
                    errorList.add(new Error(getErrorLine(), Error.MISSING_RIGHT_PAREN));
                } else {
                    // 若无错，加入语法树并移动
                    topNode.addChild(new ParseTree(SyntaxElem.Terminal, getNextToken()));
                    moveCursor();
                }
                // 错误处理：MISSING_SEMICOLON
                if (getNextToken().type != TokenType.SEMICN) {
                    errorList.add(new Error(getErrorLine(), Error.MISSING_SEMICOLON));
                } else {
                    // 若无错，加入语法树并移动
                    topNode.addChild(new ParseTree(SyntaxElem.Terminal, getNextToken()));
                    moveCursor();
                }
            } else if (getNextToken().type == TokenType.GETCHARTK) {

                if (getNextToken().type != TokenType.GETCHARTK) {
                    rollBack(rollBackPoint, errorListTail);
                    return null;
                }
                topNode.addChild(new ParseTree(SyntaxElem.Terminal, getNextToken()));
                moveCursor();

                if (getNextToken().type != TokenType.LPARENT) {
                    rollBack(rollBackPoint, errorListTail);
                    return null;
                }
                topNode.addChild(new ParseTree(SyntaxElem.Terminal, getNextToken()));
                moveCursor();

                // 错误处理：MISSING_RIGHT_PAREN
                if (getNextToken().type != TokenType.RPARENT) {
                    errorList.add(new Error(getErrorLine(), Error.MISSING_RIGHT_PAREN));
                } else {
                    // 若无错，加入语法树并移动
                    topNode.addChild(new ParseTree(SyntaxElem.Terminal, getNextToken()));
                    moveCursor();
                }
                // 错误处理：MISSING_SEMICOLON
                if (getNextToken().type != TokenType.SEMICN) {
                    errorList.add(new Error(getErrorLine(), Error.MISSING_SEMICOLON));
                } else {
                    // 若无错，加入语法树并移动
                    topNode.addChild(new ParseTree(SyntaxElem.Terminal, getNextToken()));
                    moveCursor();
                }
            } else {

                nxtNode = parseExp();
                if (nxtNode == null) {
                    rollBack(rollBackPoint, errorListTail);
                    return null;
                }
                topNode.addChild(nxtNode);

                // 错误处理：MISSING_SEMICOLON
                if (getNextToken().type != TokenType.SEMICN) {
                    errorList.add(new Error(getErrorLine(), Error.MISSING_SEMICOLON));
                } else {
                    // 若无错，加入语法树并移动
                    topNode.addChild(new ParseTree(SyntaxElem.Terminal, getNextToken()));
                    moveCursor();
                }
            }

        } else {
            //[Exp] ;

            //可选项开始：
            nxtNode = parseExp();
            if (nxtNode != null) {
                topNode.addChild(nxtNode);

            }
            //可选项结束：

            // 错误处理：MISSING_SEMICOLON
            if (getNextToken().type != TokenType.SEMICN) {
                errorList.add(new Error(getErrorLine(), Error.MISSING_SEMICOLON));
            } else {
                // 若无错，加入语法树并移动
                topNode.addChild(new ParseTree(SyntaxElem.Terminal, getNextToken()));
                moveCursor();
            }
        }
        return topNode;
    }


    private ParseTree parseUnaryExp() {
        //set roll-back point
        int rollBackPoint = cursor;
        int errorListTail = errorList.size();
        ParseTree topNode = new ParseTree(SyntaxElem.UnaryExp);
        ParseTree nxtNode;

        if ((nxtNode = parseUnaryOp()) != null) {
            //UnaryOp UnaryExp
            topNode.addChild(nxtNode);

            nxtNode = parseUnaryExp();
            if (nxtNode == null) {
                rollBack(rollBackPoint, errorListTail);
                return null;
            }
            topNode.addChild(nxtNode);

        } else if (getNextToken().type == TokenType.IDENFR && getNextNextToken().type == TokenType.LPARENT) {
            // Ident '(' [FuncRParams] ')'

            if (getNextToken().type != TokenType.IDENFR) {
                rollBack(rollBackPoint, errorListTail);
                return null;
            }
            topNode.addChild(new ParseTree(SyntaxElem.Terminal, getNextToken()));
            moveCursor();

            if (getNextToken().type != TokenType.LPARENT) {
                rollBack(rollBackPoint, errorListTail);
                return null;
            }
            topNode.addChild(new ParseTree(SyntaxElem.Terminal, getNextToken()));
            moveCursor();

            //可选项开始：
            nxtNode = parseFuncRParams();
            if (nxtNode != null) {
                topNode.addChild(nxtNode);

            }
            //可选项结束：

            // 错误处理：MISSING_RIGHT_PAREN
            if (getNextToken().type != TokenType.RPARENT) {
                errorList.add(new Error(getErrorLine(), Error.MISSING_RIGHT_PAREN));
            } else {
                // 若无错，加入语法树并移动
                topNode.addChild(new ParseTree(SyntaxElem.Terminal, getNextToken()));
                moveCursor();
            }
        } else {
            //PrimaryExp

            nxtNode = parsePrimaryExp();
            if (nxtNode == null) {
                rollBack(rollBackPoint, errorListTail);
                return null;
            }
            topNode.addChild(nxtNode);

        }

        return topNode;
    }

    /*------------------------------------一般形式，总共20个-------------------------------------*/

    private ParseTree parseDecl() {
        //set roll-back point
        int rollBackPoint = cursor;
        int errorListTail = errorList.size();
        ParseTree topNode = new ParseTree(SyntaxElem.Decl);
        ParseTree nxtNode;
        if (getNextToken().type == TokenType.CONSTTK) {

            nxtNode = parseConstDecl();
            if (nxtNode == null) {
                rollBack(rollBackPoint, errorListTail);
                return null;
            }
            topNode.addChild(nxtNode);

        } else {

            nxtNode = parseVarDecl();
            if (nxtNode == null) {
                rollBack(rollBackPoint, errorListTail);
                return null;
            }
            topNode.addChild(nxtNode);

        }

        return topNode;
    }


    private ParseTree parseConstDecl() {
        //set roll-back point
        int rollBackPoint = cursor;
        int errorListTail = errorList.size();
        ParseTree topNode = new ParseTree(SyntaxElem.ConstDecl);
        ParseTree nxtNode;

        if (getNextToken().type != TokenType.CONSTTK) {
            rollBack(rollBackPoint, errorListTail);
            return null;
        }
        topNode.addChild(new ParseTree(SyntaxElem.Terminal, getNextToken()));
        moveCursor();

        nxtNode = parseBType();
        if (nxtNode == null) {
            rollBack(rollBackPoint, errorListTail);
            return null;
        }
        topNode.addChild(nxtNode);

        nxtNode = parseConstDef();
        if (nxtNode == null) {
            rollBack(rollBackPoint, errorListTail);
            return null;
        }
        topNode.addChild(nxtNode);

        //可选项开始：[COMMA...]
        while (getNextToken().type == TokenType.COMMA) {
            topNode.addChild(new ParseTree(SyntaxElem.Terminal, getNextToken()));
            moveCursor();

            nxtNode = parseConstDef();
            if (nxtNode == null) {
                rollBack(rollBackPoint, errorListTail);
                return null;
            }
            topNode.addChild(nxtNode);

        }
        //可选项结束

        // 错误处理：MISSING_SEMICOLON
        if (getNextToken().type != TokenType.SEMICN) {
            errorList.add(new Error(getErrorLine(), Error.MISSING_SEMICOLON));
        } else {
            // 若无错，加入语法树并移动
            topNode.addChild(new ParseTree(SyntaxElem.Terminal, getNextToken()));
            moveCursor();
        }
        return topNode;
    }


    private ParseTree parseConstDef() {
        //set roll-back point
        int rollBackPoint = cursor;
        int errorListTail = errorList.size();
        ParseTree topNode = new ParseTree(SyntaxElem.ConstDef);
        ParseTree nxtNode;

        if (getNextToken().type != TokenType.IDENFR) {
            rollBack(rollBackPoint, errorListTail);
            return null;
        }
        topNode.addChild(new ParseTree(SyntaxElem.Terminal, getNextToken()));
        moveCursor();

        //可选项开始：[LBRACK...]
        if (getNextToken().type == TokenType.LBRACK) {
            topNode.addChild(new ParseTree(SyntaxElem.Terminal, getNextToken()));
            moveCursor();

            nxtNode = parseConstExp();
            if (nxtNode == null) {
                rollBack(rollBackPoint, errorListTail);
                return null;
            }
            topNode.addChild(nxtNode);

            // 错误处理：MISSING_RIGHT_BRACKET
            if (getNextToken().type != TokenType.RBRACK) {
                errorList.add(new Error(getErrorLine(), Error.MISSING_RIGHT_BRACKET));
            } else {
                // 若无错，加入语法树并移动
                topNode.addChild(new ParseTree(SyntaxElem.Terminal, getNextToken()));
                moveCursor();
            }
        }
        //可选项结束

        if (getNextToken().type != TokenType.ASSIGN) {
            rollBack(rollBackPoint, errorListTail);
            return null;
        }
        topNode.addChild(new ParseTree(SyntaxElem.Terminal, getNextToken()));
        moveCursor();

        nxtNode = parseConstInitVal();
        if (nxtNode == null) {
            rollBack(rollBackPoint, errorListTail);
            return null;
        }
        topNode.addChild(nxtNode);

        return topNode;
    }


    private ParseTree parseConstInitVal() {
        //set roll-back point
        int rollBackPoint = cursor;
        int errorListTail = errorList.size();
        ParseTree topNode = new ParseTree(SyntaxElem.ConstInitVal);
        ParseTree nxtNode;
        if (getNextToken().type == TokenType.STRCON) {

            if (getNextToken().type != TokenType.STRCON) {
                rollBack(rollBackPoint, errorListTail);
                return null;
            }
            topNode.addChild(new ParseTree(SyntaxElem.Terminal, getNextToken()));
            moveCursor();

        } else if (getNextToken().type == TokenType.LBRACE) {

            if (getNextToken().type != TokenType.LBRACE) {
                rollBack(rollBackPoint, errorListTail);
                return null;
            }
            topNode.addChild(new ParseTree(SyntaxElem.Terminal, getNextToken()));
            moveCursor();

            //可选项开始：
            nxtNode = parseConstExp();
            if (nxtNode != null) {
                topNode.addChild(nxtNode);

                //可选项开始：[COMMA...]
                while (getNextToken().type == TokenType.COMMA) {
                    topNode.addChild(new ParseTree(SyntaxElem.Terminal, getNextToken()));
                    moveCursor();

                    nxtNode = parseConstExp();
                    if (nxtNode == null) {
                        rollBack(rollBackPoint, errorListTail);
                        return null;
                    }
                    topNode.addChild(nxtNode);

                }
                //可选项结束

            }
            //可选项结束：

            if (getNextToken().type != TokenType.RBRACE) {
                rollBack(rollBackPoint, errorListTail);
                return null;
            }
            topNode.addChild(new ParseTree(SyntaxElem.Terminal, getNextToken()));
            moveCursor();

        } else {

            nxtNode = parseConstExp();
            if (nxtNode == null) {
                rollBack(rollBackPoint, errorListTail);
                return null;
            }
            topNode.addChild(nxtNode);

        }

        return topNode;
    }


    private ParseTree parseVarDecl() {
        //set roll-back point
        int rollBackPoint = cursor;
        int errorListTail = errorList.size();
        ParseTree topNode = new ParseTree(SyntaxElem.VarDecl);
        ParseTree nxtNode;

        nxtNode = parseBType();
        if (nxtNode == null) {
            rollBack(rollBackPoint, errorListTail);
            return null;
        }
        topNode.addChild(nxtNode);

        nxtNode = parseVarDef();
        if (nxtNode == null) {
            rollBack(rollBackPoint, errorListTail);
            return null;
        }
        topNode.addChild(nxtNode);

        //可选项开始：[COMMA...]
        while (getNextToken().type == TokenType.COMMA) {
            topNode.addChild(new ParseTree(SyntaxElem.Terminal, getNextToken()));
            moveCursor();

            nxtNode = parseVarDef();
            if (nxtNode == null) {
                rollBack(rollBackPoint, errorListTail);
                return null;
            }
            topNode.addChild(nxtNode);

        }
        //可选项结束

        // 错误处理：MISSING_SEMICOLON
        if (getNextToken().type != TokenType.SEMICN) {
            errorList.add(new Error(getErrorLine(), Error.MISSING_SEMICOLON));
        } else {
            // 若无错，加入语法树并移动
            topNode.addChild(new ParseTree(SyntaxElem.Terminal, getNextToken()));
            moveCursor();
        }
        return topNode;
    }


    private ParseTree parseVarDef() {
        //set roll-back point
        int rollBackPoint = cursor;
        int errorListTail = errorList.size();
        ParseTree topNode = new ParseTree(SyntaxElem.VarDef);
        ParseTree nxtNode;

        if (getNextToken().type != TokenType.IDENFR) {
            rollBack(rollBackPoint, errorListTail);
            return null;
        }
        topNode.addChild(new ParseTree(SyntaxElem.Terminal, getNextToken()));
        moveCursor();

        //可选项开始：[LBRACK...]
        if (getNextToken().type == TokenType.LBRACK) {
            topNode.addChild(new ParseTree(SyntaxElem.Terminal, getNextToken()));
            moveCursor();

            nxtNode = parseConstExp();
            if (nxtNode == null) {
                rollBack(rollBackPoint, errorListTail);
                return null;
            }
            topNode.addChild(nxtNode);

            // 错误处理：MISSING_RIGHT_BRACKET
            if (getNextToken().type != TokenType.RBRACK) {
                errorList.add(new Error(getErrorLine(), Error.MISSING_RIGHT_BRACKET));
            } else {
                // 若无错，加入语法树并移动
                topNode.addChild(new ParseTree(SyntaxElem.Terminal, getNextToken()));
                moveCursor();
            }
        }
        //可选项结束

        //可选项开始：[ASSIGN...]
        if (getNextToken().type == TokenType.ASSIGN) {
            topNode.addChild(new ParseTree(SyntaxElem.Terminal, getNextToken()));
            moveCursor();

            nxtNode = parseInitVal();
            if (nxtNode == null) {
                rollBack(rollBackPoint, errorListTail);
                return null;
            }
            topNode.addChild(nxtNode);

        }
        //可选项结束

        return topNode;
    }


    private ParseTree parseInitVal() {
        //set roll-back point
        int rollBackPoint = cursor;
        int errorListTail = errorList.size();
        ParseTree topNode = new ParseTree(SyntaxElem.InitVal);
        ParseTree nxtNode;
        if (getNextToken().type == TokenType.STRCON) {

            if (getNextToken().type != TokenType.STRCON) {
                rollBack(rollBackPoint, errorListTail);
                return null;
            }
            topNode.addChild(new ParseTree(SyntaxElem.Terminal, getNextToken()));
            moveCursor();

        } else if (getNextToken().type == TokenType.LBRACE) {

            if (getNextToken().type != TokenType.LBRACE) {
                rollBack(rollBackPoint, errorListTail);
                return null;
            }
            topNode.addChild(new ParseTree(SyntaxElem.Terminal, getNextToken()));
            moveCursor();

            //可选项开始：
            nxtNode = parseExp();
            if (nxtNode != null) {
                topNode.addChild(nxtNode);

                //可选项开始：[COMMA...]
                while (getNextToken().type == TokenType.COMMA) {
                    topNode.addChild(new ParseTree(SyntaxElem.Terminal, getNextToken()));
                    moveCursor();

                    nxtNode = parseExp();
                    if (nxtNode == null) {
                        rollBack(rollBackPoint, errorListTail);
                        return null;
                    }
                    topNode.addChild(nxtNode);

                }
                //可选项结束

            }
            //可选项结束：

            if (getNextToken().type != TokenType.RBRACE) {
                rollBack(rollBackPoint, errorListTail);
                return null;
            }
            topNode.addChild(new ParseTree(SyntaxElem.Terminal, getNextToken()));
            moveCursor();

        } else {

            nxtNode = parseExp();
            if (nxtNode == null) {
                rollBack(rollBackPoint, errorListTail);
                return null;
            }
            topNode.addChild(nxtNode);

        }

        return topNode;
    }


    private ParseTree parseFuncDef() {
        //set roll-back point
        int rollBackPoint = cursor;
        int errorListTail = errorList.size();
        ParseTree topNode = new ParseTree(SyntaxElem.FuncDef);
        ParseTree nxtNode;

        nxtNode = parseFuncType();
        if (nxtNode == null) {
            rollBack(rollBackPoint, errorListTail);
            return null;
        }
        topNode.addChild(nxtNode);

        if (getNextToken().type != TokenType.IDENFR) {
            rollBack(rollBackPoint, errorListTail);
            return null;
        }
        topNode.addChild(new ParseTree(SyntaxElem.Terminal, getNextToken()));
        moveCursor();

        if (getNextToken().type != TokenType.LPARENT) {
            rollBack(rollBackPoint, errorListTail);
            return null;
        }
        topNode.addChild(new ParseTree(SyntaxElem.Terminal, getNextToken()));
        moveCursor();

        //可选项开始：
        nxtNode = parseFuncFParams();
        if (nxtNode != null) {
            topNode.addChild(nxtNode);

        }
        //可选项结束：

        // 错误处理：MISSING_RIGHT_PAREN
        if (getNextToken().type != TokenType.RPARENT) {
            errorList.add(new Error(getErrorLine(), Error.MISSING_RIGHT_PAREN));
        } else {
            // 若无错，加入语法树并移动
            topNode.addChild(new ParseTree(SyntaxElem.Terminal, getNextToken()));
            moveCursor();
        }
        nxtNode = parseBlock();
        if (nxtNode == null) {
            rollBack(rollBackPoint, errorListTail);
            return null;
        }
        topNode.addChild(nxtNode);

        return topNode;
    }


    private ParseTree parseMainFuncDef() {
        //set roll-back point
        int rollBackPoint = cursor;
        int errorListTail = errorList.size();
        ParseTree topNode = new ParseTree(SyntaxElem.MainFuncDef);
        ParseTree nxtNode;

        if (getNextToken().type != TokenType.INTTK) {
            rollBack(rollBackPoint, errorListTail);
            return null;
        }
        topNode.addChild(new ParseTree(SyntaxElem.Terminal, getNextToken()));
        moveCursor();

        if (getNextToken().type != TokenType.MAINTK) {
            rollBack(rollBackPoint, errorListTail);
            return null;
        }
        topNode.addChild(new ParseTree(SyntaxElem.Terminal, getNextToken()));
        moveCursor();

        if (getNextToken().type != TokenType.LPARENT) {
            rollBack(rollBackPoint, errorListTail);
            return null;
        }
        topNode.addChild(new ParseTree(SyntaxElem.Terminal, getNextToken()));
        moveCursor();

        // 错误处理：MISSING_RIGHT_PAREN
        if (getNextToken().type != TokenType.RPARENT) {
            errorList.add(new Error(getErrorLine(), Error.MISSING_RIGHT_PAREN));
        } else {
            // 若无错，加入语法树并移动
            topNode.addChild(new ParseTree(SyntaxElem.Terminal, getNextToken()));
            moveCursor();
        }
        nxtNode = parseBlock();
        if (nxtNode == null) {
            rollBack(rollBackPoint, errorListTail);
            return null;
        }
        topNode.addChild(nxtNode);

        return topNode;
    }


    private ParseTree parseFuncFParams() {
        //set roll-back point
        int rollBackPoint = cursor;
        int errorListTail = errorList.size();
        ParseTree topNode = new ParseTree(SyntaxElem.FuncFParams);
        ParseTree nxtNode;

        nxtNode = parseFuncFParam();
        if (nxtNode == null) {
            rollBack(rollBackPoint, errorListTail);
            return null;
        }
        topNode.addChild(nxtNode);

        //可选项开始：[COMMA...]
        while (getNextToken().type == TokenType.COMMA) {
            topNode.addChild(new ParseTree(SyntaxElem.Terminal, getNextToken()));
            moveCursor();

            nxtNode = parseFuncFParam();
            if (nxtNode == null) {
                rollBack(rollBackPoint, errorListTail);
                return null;
            }
            topNode.addChild(nxtNode);

        }
        //可选项结束

        return topNode;
    }


    private ParseTree parseFuncFParam() {
        //set roll-back point
        int rollBackPoint = cursor;
        int errorListTail = errorList.size();
        ParseTree topNode = new ParseTree(SyntaxElem.FuncFParam);
        ParseTree nxtNode;

        nxtNode = parseBType();
        if (nxtNode == null) {
            rollBack(rollBackPoint, errorListTail);
            return null;
        }
        topNode.addChild(nxtNode);

        if (getNextToken().type != TokenType.IDENFR) {
            rollBack(rollBackPoint, errorListTail);
            return null;
        }
        topNode.addChild(new ParseTree(SyntaxElem.Terminal, getNextToken()));
        moveCursor();

        //可选项开始：[LBRACK...]
        if (getNextToken().type == TokenType.LBRACK) {
            topNode.addChild(new ParseTree(SyntaxElem.Terminal, getNextToken()));
            moveCursor();

            // 错误处理：MISSING_RIGHT_BRACKET
            if (getNextToken().type != TokenType.RBRACK) {
                errorList.add(new Error(getErrorLine(), Error.MISSING_RIGHT_BRACKET));
            } else {
                // 若无错，加入语法树并移动
                topNode.addChild(new ParseTree(SyntaxElem.Terminal, getNextToken()));
                moveCursor();
            }
        }
        //可选项结束

        return topNode;
    }


    private ParseTree parseBlock() {
        //set roll-back point
        int rollBackPoint = cursor;
        int errorListTail = errorList.size();
        ParseTree topNode = new ParseTree(SyntaxElem.Block);
        ParseTree nxtNode;

        if (getNextToken().type != TokenType.LBRACE) {
            rollBack(rollBackPoint, errorListTail);
            return null;
        }
        topNode.addChild(new ParseTree(SyntaxElem.Terminal, getNextToken()));
        moveCursor();

        //可选项开始：[...]
        while (getNextToken().type != TokenType.RBRACE) {

            nxtNode = parseBlockItem();
            if (nxtNode == null) {
                rollBack(rollBackPoint, errorListTail);
                return null;
            }
            topNode.addChild(nxtNode);

        }
        //可选项结束

        if (getNextToken().type != TokenType.RBRACE) {
            rollBack(rollBackPoint, errorListTail);
            return null;
        }
        topNode.addChild(new ParseTree(SyntaxElem.Terminal, getNextToken()));
        moveCursor();

        return topNode;
    }


    private ParseTree parseBlockItem() {
        //set roll-back point
        int rollBackPoint = cursor;
        int errorListTail = errorList.size();
        ParseTree topNode = new ParseTree(SyntaxElem.BlockItem);
        ParseTree nxtNode;
        if (getNextToken().type == TokenType.CONSTTK || getNextToken().type == TokenType.INTTK || getNextToken().type == TokenType.CHARTK) {

            nxtNode = parseDecl();
            if (nxtNode == null) {
                rollBack(rollBackPoint, errorListTail);
                return null;
            }
            topNode.addChild(nxtNode);

        } else {

            nxtNode = parseStmt();
            if (nxtNode == null) {
                rollBack(rollBackPoint, errorListTail);
                return null;
            }
            topNode.addChild(nxtNode);

        }

        return topNode;
    }


    private ParseTree parseForStmt() {
        //set roll-back point
        int rollBackPoint = cursor;
        int errorListTail = errorList.size();
        ParseTree topNode = new ParseTree(SyntaxElem.ForStmt);
        ParseTree nxtNode;

        nxtNode = parseLVal();
        if (nxtNode == null) {
            rollBack(rollBackPoint, errorListTail);
            return null;
        }
        topNode.addChild(nxtNode);

        if (getNextToken().type != TokenType.ASSIGN) {
            rollBack(rollBackPoint, errorListTail);
            return null;
        }
        topNode.addChild(new ParseTree(SyntaxElem.Terminal, getNextToken()));
        moveCursor();

        nxtNode = parseExp();
        if (nxtNode == null) {
            rollBack(rollBackPoint, errorListTail);
            return null;
        }
        topNode.addChild(nxtNode);

        return topNode;
    }


    private ParseTree parseExp() {
        //set roll-back point
        int rollBackPoint = cursor;
        int errorListTail = errorList.size();
        ParseTree topNode = new ParseTree(SyntaxElem.Exp);
        ParseTree nxtNode;

        nxtNode = parseAddExp();
        if (nxtNode == null) {
            rollBack(rollBackPoint, errorListTail);
            return null;
        }
        topNode.addChild(nxtNode);

        return topNode;
    }


    private ParseTree parseCond() {
        //set roll-back point
        int rollBackPoint = cursor;
        int errorListTail = errorList.size();
        ParseTree topNode = new ParseTree(SyntaxElem.Cond);
        ParseTree nxtNode;

        nxtNode = parseLOrExp();
        if (nxtNode == null) {
            rollBack(rollBackPoint, errorListTail);
            return null;
        }
        topNode.addChild(nxtNode);

        return topNode;
    }


    private ParseTree parseLVal() {
        //set roll-back point
        int rollBackPoint = cursor;
        int errorListTail = errorList.size();
        ParseTree topNode = new ParseTree(SyntaxElem.LVal);
        ParseTree nxtNode;

        if (getNextToken().type != TokenType.IDENFR) {
            rollBack(rollBackPoint, errorListTail);
            return null;
        }
        topNode.addChild(new ParseTree(SyntaxElem.Terminal, getNextToken()));
        moveCursor();

        //可选项开始：[LBRACK...]
        if (getNextToken().type == TokenType.LBRACK) {
            topNode.addChild(new ParseTree(SyntaxElem.Terminal, getNextToken()));
            moveCursor();

            nxtNode = parseExp();
            if (nxtNode == null) {
                rollBack(rollBackPoint, errorListTail);
                return null;
            }
            topNode.addChild(nxtNode);

            // 错误处理：MISSING_RIGHT_BRACKET
            if (getNextToken().type != TokenType.RBRACK) {
                errorList.add(new Error(getErrorLine(), Error.MISSING_RIGHT_BRACKET));
            } else {
                // 若无错，加入语法树并移动
                topNode.addChild(new ParseTree(SyntaxElem.Terminal, getNextToken()));
                moveCursor();
            }
        }
        //可选项结束

        return topNode;
    }


    private ParseTree parsePrimaryExp() {
        //set roll-back point
        int rollBackPoint = cursor;
        int errorListTail = errorList.size();
        ParseTree topNode = new ParseTree(SyntaxElem.PrimaryExp);
        ParseTree nxtNode;
        if (getNextToken().type == TokenType.LPARENT) {

            if (getNextToken().type != TokenType.LPARENT) {
                rollBack(rollBackPoint, errorListTail);
                return null;
            }
            topNode.addChild(new ParseTree(SyntaxElem.Terminal, getNextToken()));
            moveCursor();

            nxtNode = parseExp();
            if (nxtNode == null) {
                rollBack(rollBackPoint, errorListTail);
                return null;
            }
            topNode.addChild(nxtNode);

            // 错误处理：MISSING_RIGHT_PAREN
            if (getNextToken().type != TokenType.RPARENT) {
                errorList.add(new Error(getErrorLine(), Error.MISSING_RIGHT_PAREN));
            } else {
                // 若无错，加入语法树并移动
                topNode.addChild(new ParseTree(SyntaxElem.Terminal, getNextToken()));
                moveCursor();
            }
        } else if (getNextToken().type == TokenType.IDENFR) {

            nxtNode = parseLVal();
            if (nxtNode == null) {
                rollBack(rollBackPoint, errorListTail);
                return null;
            }
            topNode.addChild(nxtNode);

        } else if (getNextToken().type == TokenType.INTCON) {

            nxtNode = parseNumber();
            if (nxtNode == null) {
                rollBack(rollBackPoint, errorListTail);
                return null;
            }
            topNode.addChild(nxtNode);

        } else if (getNextToken().type == TokenType.CHRCON) {

            nxtNode = parseCharacter();
            if (nxtNode == null) {
                rollBack(rollBackPoint, errorListTail);
                return null;
            }
            topNode.addChild(nxtNode);

        }  else {
            //match none
            rollBack(rollBackPoint, errorListTail);
            return null;
        }

        return topNode;
    }


    private ParseTree parseFuncRParams() {
        //set roll-back point
        int rollBackPoint = cursor;
        int errorListTail = errorList.size();
        ParseTree topNode = new ParseTree(SyntaxElem.FuncRParams);
        ParseTree nxtNode;

        nxtNode = parseExp();
        if (nxtNode == null) {
            rollBack(rollBackPoint, errorListTail);
            return null;
        }
        topNode.addChild(nxtNode);

        //可选项开始：[COMMA...]
        while (getNextToken().type == TokenType.COMMA) {
            topNode.addChild(new ParseTree(SyntaxElem.Terminal, getNextToken()));
            moveCursor();

            nxtNode = parseExp();
            if (nxtNode == null) {
                rollBack(rollBackPoint, errorListTail);
                return null;
            }
            topNode.addChild(nxtNode);

        }
        //可选项结束

        return topNode;
    }


    private ParseTree parseConstExp() {
        //set roll-back point
        int rollBackPoint = cursor;
        int errorListTail = errorList.size();
        ParseTree topNode = new ParseTree(SyntaxElem.ConstExp);
        ParseTree nxtNode;

        nxtNode = parseAddExp();
        if (nxtNode == null) {
            rollBack(rollBackPoint, errorListTail);
            return null;
        }
        topNode.addChild(nxtNode);

        return topNode;
    }

    /*---------------------------------左递归形式，总共6个----------------------------------*/


    private ParseTree parseLOrExp() {
        //set roll-back point
        int rollBackPoint = cursor;
        int errorListTail = errorList.size();
        //generate set of conj
        HashSet<TokenType> conjSet = new HashSet<>();
        conjSet.add(TokenType.OR);

        ParseTree tmpNode = parseLAndExp();
        if (tmpNode == null) {
            rollBack(rollBackPoint, errorListTail);
            return null;
        }
        ParseTree topNode = new ParseTree(SyntaxElem.LOrExp);
        topNode.addChild(tmpNode);
        while(conjSet.contains(getNextToken().type)) {
            ParseTree newTopNode = new ParseTree(SyntaxElem.LOrExp);
            newTopNode.addChild(topNode);
            newTopNode.addChild(new ParseTree(SyntaxElem.Terminal, getNextToken()));
            moveCursor();
            tmpNode = parseLAndExp();
            if (tmpNode == null) {
                rollBack(rollBackPoint, errorListTail);
                return null;
            }
            newTopNode.addChild(tmpNode);
            topNode = newTopNode;
        }
        return topNode;
    }



    private ParseTree parseLAndExp() {
        //set roll-back point
        int rollBackPoint = cursor;
        int errorListTail = errorList.size();
        //generate set of conj
        HashSet<TokenType> conjSet = new HashSet<>();
        conjSet.add(TokenType.AND);

        ParseTree tmpNode = parseEqExp();
        if (tmpNode == null) {
            rollBack(rollBackPoint, errorListTail);
            return null;
        }
        ParseTree topNode = new ParseTree(SyntaxElem.LAndExp);
        topNode.addChild(tmpNode);
        while(conjSet.contains(getNextToken().type)) {
            ParseTree newTopNode = new ParseTree(SyntaxElem.LAndExp);
            newTopNode.addChild(topNode);
            newTopNode.addChild(new ParseTree(SyntaxElem.Terminal, getNextToken()));
            moveCursor();
            tmpNode = parseEqExp();
            if (tmpNode == null) {
                rollBack(rollBackPoint, errorListTail);
                return null;
            }
            newTopNode.addChild(tmpNode);
            topNode = newTopNode;
        }
        return topNode;
    }



    private ParseTree parseEqExp() {
        //set roll-back point
        int rollBackPoint = cursor;
        int errorListTail = errorList.size();
        //generate set of conj
        HashSet<TokenType> conjSet = new HashSet<>();
        conjSet.add(TokenType.NEQ);
        conjSet.add(TokenType.EQL);

        ParseTree tmpNode = parseRelExp();
        if (tmpNode == null) {
            rollBack(rollBackPoint, errorListTail);
            return null;
        }
        ParseTree topNode = new ParseTree(SyntaxElem.EqExp);
        topNode.addChild(tmpNode);
        while(conjSet.contains(getNextToken().type)) {
            ParseTree newTopNode = new ParseTree(SyntaxElem.EqExp);
            newTopNode.addChild(topNode);
            newTopNode.addChild(new ParseTree(SyntaxElem.Terminal, getNextToken()));
            moveCursor();
            tmpNode = parseRelExp();
            if (tmpNode == null) {
                rollBack(rollBackPoint, errorListTail);
                return null;
            }
            newTopNode.addChild(tmpNode);
            topNode = newTopNode;
        }
        return topNode;
    }



    private ParseTree parseRelExp() {
        //set roll-back point
        int rollBackPoint = cursor;
        int errorListTail = errorList.size();
        //generate set of conj
        HashSet<TokenType> conjSet = new HashSet<>();
        conjSet.add(TokenType.LEQ);
        conjSet.add(TokenType.GRE);
        conjSet.add(TokenType.GEQ);
        conjSet.add(TokenType.LSS);

        ParseTree tmpNode = parseAddExp();
        if (tmpNode == null) {
            rollBack(rollBackPoint, errorListTail);
            return null;
        }
        ParseTree topNode = new ParseTree(SyntaxElem.RelExp);
        topNode.addChild(tmpNode);
        while(conjSet.contains(getNextToken().type)) {
            ParseTree newTopNode = new ParseTree(SyntaxElem.RelExp);
            newTopNode.addChild(topNode);
            newTopNode.addChild(new ParseTree(SyntaxElem.Terminal, getNextToken()));
            moveCursor();
            tmpNode = parseAddExp();
            if (tmpNode == null) {
                rollBack(rollBackPoint, errorListTail);
                return null;
            }
            newTopNode.addChild(tmpNode);
            topNode = newTopNode;
        }
        return topNode;
    }



    private ParseTree parseAddExp() {
        //set roll-back point
        int rollBackPoint = cursor;
        int errorListTail = errorList.size();
        //generate set of conj
        HashSet<TokenType> conjSet = new HashSet<>();
        conjSet.add(TokenType.MINU);
        conjSet.add(TokenType.PLUS);

        ParseTree tmpNode = parseMulExp();
        if (tmpNode == null) {
            rollBack(rollBackPoint, errorListTail);
            return null;
        }
        ParseTree topNode = new ParseTree(SyntaxElem.AddExp);
        topNode.addChild(tmpNode);
        while(conjSet.contains(getNextToken().type)) {
            ParseTree newTopNode = new ParseTree(SyntaxElem.AddExp);
            newTopNode.addChild(topNode);
            newTopNode.addChild(new ParseTree(SyntaxElem.Terminal, getNextToken()));
            moveCursor();
            tmpNode = parseMulExp();
            if (tmpNode == null) {
                rollBack(rollBackPoint, errorListTail);
                return null;
            }
            newTopNode.addChild(tmpNode);
            topNode = newTopNode;
        }
        return topNode;
    }



    private ParseTree parseMulExp() {
        //set roll-back point
        int rollBackPoint = cursor;
        int errorListTail = errorList.size();
        //generate set of conj
        HashSet<TokenType> conjSet = new HashSet<>();
        conjSet.add(TokenType.DIV);
        conjSet.add(TokenType.MULT);
        conjSet.add(TokenType.MOD);

        ParseTree tmpNode = parseUnaryExp();
        if (tmpNode == null) {
            rollBack(rollBackPoint, errorListTail);
            return null;
        }
        ParseTree topNode = new ParseTree(SyntaxElem.MulExp);
        topNode.addChild(tmpNode);
        while(conjSet.contains(getNextToken().type)) {
            ParseTree newTopNode = new ParseTree(SyntaxElem.MulExp);
            newTopNode.addChild(topNode);
            newTopNode.addChild(new ParseTree(SyntaxElem.Terminal, getNextToken()));
            moveCursor();
            tmpNode = parseUnaryExp();
            if (tmpNode == null) {
                rollBack(rollBackPoint, errorListTail);
                return null;
            }
            newTopNode.addChild(tmpNode);
            topNode = newTopNode;
        }
        return topNode;
    }

    /*---------------------------------仅终结符形式，总共5个----------------------------------*/

    private ParseTree parseBType() {
        //set roll-back point
        int rollBackPoint = cursor;
        int errorListTail = errorList.size();
        //generate set of sym
        HashSet<TokenType> symSet = new HashSet<>();
        symSet.add(TokenType.INTTK);
        symSet.add(TokenType.CHARTK);

        if (symSet.contains(getNextToken().type)) {
            ParseTree topNode = new ParseTree(SyntaxElem.BType);
            topNode.addChild(new ParseTree(SyntaxElem.Terminal, getNextToken()));
            moveCursor();
            return topNode;
        } else {
            rollBack(rollBackPoint, errorListTail);
            return null;
        }
    }


    private ParseTree parseFuncType() {
        //set roll-back point
        int rollBackPoint = cursor;
        int errorListTail = errorList.size();
        //generate set of sym
        HashSet<TokenType> symSet = new HashSet<>();
        symSet.add(TokenType.VOIDTK);
        symSet.add(TokenType.INTTK);
        symSet.add(TokenType.CHARTK);

        if (symSet.contains(getNextToken().type)) {
            ParseTree topNode = new ParseTree(SyntaxElem.FuncType);
            topNode.addChild(new ParseTree(SyntaxElem.Terminal, getNextToken()));
            moveCursor();
            return topNode;
        } else {
            rollBack(rollBackPoint, errorListTail);
            return null;
        }
    }


    private ParseTree parseUnaryOp() {
        //set roll-back point
        int rollBackPoint = cursor;
        int errorListTail = errorList.size();
        //generate set of sym
        HashSet<TokenType> symSet = new HashSet<>();
        symSet.add(TokenType.MINU);
        symSet.add(TokenType.NOT);
        symSet.add(TokenType.PLUS);

        if (symSet.contains(getNextToken().type)) {
            ParseTree topNode = new ParseTree(SyntaxElem.UnaryOp);
            topNode.addChild(new ParseTree(SyntaxElem.Terminal, getNextToken()));
            moveCursor();
            return topNode;
        } else {
            rollBack(rollBackPoint, errorListTail);
            return null;
        }
    }


    private ParseTree parseNumber() {
        //set roll-back point
        int rollBackPoint = cursor;
        int errorListTail = errorList.size();
        //generate set of sym
        HashSet<TokenType> symSet = new HashSet<>();
        symSet.add(TokenType.INTCON);

        if (symSet.contains(getNextToken().type)) {
            ParseTree topNode = new ParseTree(SyntaxElem.Number);
            topNode.addChild(new ParseTree(SyntaxElem.Terminal, getNextToken()));
            moveCursor();
            return topNode;
        } else {
            rollBack(rollBackPoint, errorListTail);
            return null;
        }
    }


    private ParseTree parseCharacter() {
        //set roll-back point
        int rollBackPoint = cursor;
        int errorListTail = errorList.size();
        //generate set of sym
        HashSet<TokenType> symSet = new HashSet<>();
        symSet.add(TokenType.CHRCON);

        if (symSet.contains(getNextToken().type)) {
            ParseTree topNode = new ParseTree(SyntaxElem.Character);
            topNode.addChild(new ParseTree(SyntaxElem.Terminal, getNextToken()));
            moveCursor();
            return topNode;
        } else {
            rollBack(rollBackPoint, errorListTail);
            return null;
        }
    }

    /*---------------------------------共34个----------------------------------*/

}