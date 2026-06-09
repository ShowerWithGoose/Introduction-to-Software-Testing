package frontend.parser.block;

import frontend.SyntaxError.ErrorType;
import frontend.SyntaxError.SyntaxErrorHandler;
import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.lexer.TokenType;
import frontend.parser.expression.AddExp;
import frontend.parser.expression.AddExpParser;
import frontend.parser.expression.Lval;
import frontend.parser.expression.LvalParser;

import java.util.LinkedList;

/**
 * 语句解析器类，用于解析不同类型的语句。
 */
public class StmtParser {
    // Token 列表迭代器，用于遍历 Token 流
    private TokenListIterator tokenIterator;

    /**
     * 构造函数，初始化 Token 迭代器。
     *
     * @param tokenIterator TokenListIterator 对象
     */
    public StmtParser(TokenListIterator tokenIterator) {
        this.tokenIterator = tokenIterator;
    }

    /**
     * 解析语句，根据不同的 Token 类型解析对应的语句。
     *
     * @return 解析得到的 Stmt 对象
     */
    public Stmt parseStmt() {
        // 初始化解析所需的变量
        Lval leftValue = null;
        Token assignToken = null;
        AddExp expression = null;
        Token semicolonToken = null;

        Token getIntToken = null;
        Token leftParenGetInt = null;
        Token rightParenGetInt = null;

        Token getCharToken = null;
        Token leftParenGetChar = null;
        Token rightParenGetChar = null;

        Block codeBlock = null;

        Token ifToken = null;
        Token leftParenToken = null;
        LOrExp logicOrExp = null;
        Token rightParenToken = null;
        Stmt ifStmt = null;
        Token elseToken = null;
        Stmt elseStmt = null;

        Token breakToken = null;
        Token continueToken = null;

        Token forToken = null;
        Token leftParenFor = null;
        ForStmt firstForStmt = null;
        Token firstSemicolonFor = null;
        LOrExp forLogicOrExp = null;
        Token secondSemicolonFor = null;
        ForStmt secondForStmt = null;
        Token rightParenFor = null;
        Stmt forBodyStmt = null;

        Token returnToken = null;
        AddExp returnExpression = null;

        Token printfToken = null;
        Token leftParenPrintf = null;
        Token stringConstToken = null;
        LinkedList<Token> commaTokenList = new LinkedList<>();
        LinkedList<AddExp> printfExpressions = new LinkedList<>();
        Token rightParenPrintf = null;

        // 初始化子解析器
        LOrExpParser logicOrExpParser = new LOrExpParser(tokenIterator);
        AddExpParser addExpParser = new AddExpParser(tokenIterator);
        ForStmtParser forStmtParser = new ForStmtParser(tokenIterator);
        BlockParser blockParser = new BlockParser(tokenIterator);
        LvalParser lvalParser = new LvalParser(tokenIterator);

        // 读取下一个 Token
        Token currentToken = tokenIterator.readNextToken();

        // 根据当前 Token 的类型选择解析逻辑
        switch (currentToken.getType()) {
            case IFTK:
                // 解析 if 语句
                ifToken = currentToken;
                leftParenToken = tokenIterator.readNextToken();
                logicOrExp = logicOrExpParser.parseLOrExp();
                rightParenToken = tokenIterator.readNextToken();
                if (rightParenToken.getType() != TokenType.RPARENT) {
                    tokenIterator.unReadTokens(1);
                    rightParenToken = new Token(TokenType.RPARENT, ")", ifToken.getLine());
                    SyntaxErrorHandler.getInstance().WriteSyntaxError(ErrorType.j, leftParenToken.getLine());
                }
                ifStmt = parseStmt();
                Token nextTokenIf = tokenIterator.readNextToken();
                if (nextTokenIf.getType() == TokenType.ELSETK) {
                    elseToken = nextTokenIf;
                    elseStmt = parseStmt();
                } else {
                    tokenIterator.unReadTokens(1);
                }
                return new Stmt(ifToken, leftParenToken, logicOrExp, rightParenToken, ifStmt, elseToken, elseStmt);

            case FORTK:
                // 解析 for 循环语句
                forToken = currentToken;
                leftParenFor = tokenIterator.readNextToken();
                Token tempToken = tokenIterator.readNextToken();
                if (tempToken.getType() != TokenType.SEMICN) {
                    tokenIterator.unReadTokens(1);
                    firstForStmt = forStmtParser.parseForStmt();
                } else {
                    tokenIterator.unReadTokens(1);
                }
                firstSemicolonFor = tokenIterator.readNextToken();
                tempToken = tokenIterator.readNextToken();
                if (tempToken.getType() != TokenType.SEMICN) {
                    tokenIterator.unReadTokens(1);
                    forLogicOrExp = logicOrExpParser.parseLOrExp();
                } else {
                    tokenIterator.unReadTokens(1);
                }
                secondSemicolonFor = tokenIterator.readNextToken();
                tempToken = tokenIterator.readNextToken();
                if (tempToken.getType() != TokenType.RPARENT) {
                    tokenIterator.unReadTokens(1);
                    secondForStmt = forStmtParser.parseForStmt();
                } else {
                    tokenIterator.unReadTokens(1);
                }
                rightParenFor = tokenIterator.readNextToken();
                forBodyStmt = parseStmt();
                return new Stmt(forToken, leftParenFor, firstForStmt, firstSemicolonFor, forLogicOrExp,
                        secondSemicolonFor, secondForStmt, rightParenFor, forBodyStmt);

            case RETURNTK:
                // 解析 return 语句
                returnToken = currentToken;
                Token nextTokenReturn = tokenIterator.readNextToken();
                if (nextTokenReturn.getType() != TokenType.SEMICN) {
                    tokenIterator.unReadTokens(1);
                    returnExpression = addExpParser.parseAddExp();
                } else {
                    tokenIterator.unReadTokens(1);
                }
                Token semicolonReturn = tokenIterator.readNextToken();
                if (semicolonReturn.getType() == TokenType.SEMICN) {
                    semicolonToken = semicolonReturn;
                } else {
                    tokenIterator.unReadTokens(1);
                    semicolonToken = new Token(TokenType.SEMICN, ";", returnToken.getLine());
                    SyntaxErrorHandler.getInstance().WriteSyntaxError(ErrorType.i, returnToken.getLine());
                }
                return new Stmt(returnToken, returnExpression, semicolonToken);

            case BREAKTK:
                // 解析 break 语句
                breakToken = currentToken;
                Token semicolonBreak = tokenIterator.readNextToken();
                if (semicolonBreak.getType() == TokenType.SEMICN) {
                    semicolonToken = semicolonBreak;
                } else {
                    tokenIterator.unReadTokens(1);
                    semicolonToken = new Token(TokenType.SEMICN, ";", breakToken.getLine());
                    SyntaxErrorHandler.getInstance().WriteSyntaxError(ErrorType.i, breakToken.getLine());
                }
                // 显式指定 null 类型为 Token，以匹配正确的构造函数
                return new Stmt(breakToken, (Token) null, semicolonToken);

            case CONTINUETK:
                // 解析 continue 语句
                continueToken = currentToken;
                Token semicolonContinue = tokenIterator.readNextToken();
                if (semicolonContinue.getType() == TokenType.SEMICN) {
                    semicolonToken = semicolonContinue;
                } else {
                    tokenIterator.unReadTokens(1);
                    semicolonToken = new Token(TokenType.SEMICN, ";", continueToken.getLine());
                    SyntaxErrorHandler.getInstance().WriteSyntaxError(ErrorType.i, continueToken.getLine());
                }
                // 显式指定 null 类型为 Token，以匹配正确的构造函数
                return new Stmt((Token) null, continueToken, semicolonToken);

            case PRINTFTK:
                // 解析 printf 语句
                printfToken = currentToken;
                leftParenPrintf = tokenIterator.readNextToken();
                stringConstToken = tokenIterator.readNextToken();
                Token nextTokenPrintf = tokenIterator.readNextToken();
                while (nextTokenPrintf.getType() == TokenType.COMMA) {
                    commaTokenList.add(nextTokenPrintf);
                    AddExp printfExp = addExpParser.parseAddExp();
                    printfExpressions.add(printfExp);
                    nextTokenPrintf = tokenIterator.readNextToken();
                }
                tokenIterator.unReadTokens(1);
                Token rightParenTokenPrintf = tokenIterator.readNextToken();
                if (rightParenTokenPrintf.getType() != TokenType.RPARENT) {
                    tokenIterator.unReadTokens(1);
                    rightParenPrintf = new Token(TokenType.RPARENT, ")", printfToken.getLine());
                    SyntaxErrorHandler.getInstance().WriteSyntaxError(ErrorType.j, leftParenPrintf.getLine());
                } else {
                    rightParenPrintf = rightParenTokenPrintf;
                }
                Token semicolonPrintf = tokenIterator.readNextToken();
                if (semicolonPrintf.getType() != TokenType.SEMICN) {
                    tokenIterator.unReadTokens(1);
                    semicolonToken = new Token(TokenType.SEMICN, ";", printfToken.getLine());
                    SyntaxErrorHandler.getInstance().WriteSyntaxError(ErrorType.i, leftParenPrintf.getLine());
                } else {
                    semicolonToken = semicolonPrintf;
                }
                return new Stmt(printfToken, leftParenPrintf, stringConstToken, commaTokenList,
                        printfExpressions, rightParenPrintf, semicolonToken);

            case LBRACE:
                // 解析代码块
                tokenIterator.unReadTokens(1);
                codeBlock = blockParser.parseBlock();
                return new Stmt(codeBlock);

            case SEMICN:
                // 空语句，仅有分号
                return new Stmt(currentToken);

            default:
                // 尝试解析 Lval 或表达式语句
                tokenIterator.unReadTokens(1);
                int startIndex = tokenIterator.getCurrentIndex();
                lvalParser.tryParseLval();
                Token nextToken = tokenIterator.readNextToken();
                int endIndex = tokenIterator.getCurrentIndex();
                int tokensRead = endIndex - startIndex;
                if (nextToken.getType() == TokenType.ASSIGN) {
                    // 解析赋值语句
                    tokenIterator.unReadTokens(tokensRead);
                    leftValue = lvalParser.parseLval();
                    assignToken = tokenIterator.readNextToken();
                    Token assignNextToken = tokenIterator.readNextToken();
                    switch (assignNextToken.getType()) {
                        case GETINTTK:
                            // 解析 getint() 输入
                            getIntToken = assignNextToken;
                            leftParenGetInt = tokenIterator.readNextToken();
                            rightParenGetInt = tokenIterator.readNextToken();
                            if (rightParenGetInt.getType() != TokenType.RPARENT) {
                                tokenIterator.unReadTokens(1);
                                rightParenGetInt = new Token(TokenType.RPARENT, ")", getIntToken.getLine());
                                SyntaxErrorHandler.getInstance().WriteSyntaxError(ErrorType.j, leftParenGetInt.getLine());
                            }
                            break;
                        case GETCHARTK:
                            // 解析 getchar() 输入
                            getCharToken = assignNextToken;
                            leftParenGetChar = tokenIterator.readNextToken();
                            rightParenGetChar = tokenIterator.readNextToken();
                            if (rightParenGetChar.getType() != TokenType.RPARENT) {
                                tokenIterator.unReadTokens(1);
                                rightParenGetChar = new Token(TokenType.RPARENT, ")", getCharToken.getLine());
                                SyntaxErrorHandler.getInstance().WriteSyntaxError(ErrorType.j, leftParenGetChar.getLine());
                            }
                            break;
                        default:
                            // 解析一般的表达式
                            tokenIterator.unReadTokens(1);
                            expression = addExpParser.parseAddExp();
                            break;
                    }
                    Token semicolonAssign = tokenIterator.readNextToken();
                    if (semicolonAssign.getType() != TokenType.SEMICN) {
                        tokenIterator.unReadTokens(1);
                        semicolonToken = new Token(TokenType.SEMICN, ";", assignToken.getLine());
                        SyntaxErrorHandler.getInstance().WriteSyntaxError(ErrorType.i, assignToken.getLine());
                    } else {
                        semicolonToken = semicolonAssign;
                    }
                    return new Stmt(leftValue, assignToken, expression, semicolonToken,
                            getIntToken, leftParenGetInt, rightParenGetInt,
                            getCharToken, leftParenGetChar, rightParenGetChar);
                } else {
                    // 解析表达式语句
                    tokenIterator.unReadTokens(tokensRead);
                    expression = addExpParser.parseAddExp();
                    Token semicolonExp = tokenIterator.readNextToken();
                    if (semicolonExp.getType() != TokenType.SEMICN) {
                        tokenIterator.unReadTokens(1);
                        semicolonToken = new Token(TokenType.SEMICN, ";", semicolonExp.getLine() - 1);
                        SyntaxErrorHandler.getInstance().WriteSyntaxError(ErrorType.i, semicolonExp.getLine() - 1);
                    } else {
                        semicolonToken = semicolonExp;
                    }
                    return new Stmt(expression, semicolonToken);
                }
        }
    }
}
