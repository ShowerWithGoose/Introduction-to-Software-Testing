package frontend.parser.block;

import frontend.lexer.Token;
import frontend.parser.SyntaxOutput;
import frontend.parser.expression.AddExp;
import frontend.parser.expression.Lval;

import java.util.LinkedList;

/**
 * 表示语句（Statement）类，实现了 SyntaxOutput 接口。
 */
public class Stmt implements SyntaxOutput {
    // 常量：语法节点名称
    private static final String NODE_NAME = "<Stmt>";

    // 成员变量，根据语句类型不同而使用不同的变量
    private Lval leftValue = null;
    private Token assignToken = null;
    private AddExp expression = null;
    private Token semicolonToken = null;

    private Token getIntToken = null;
    private Token leftParenGetInt = null;
    private Token rightParenGetInt = null;

    private Token getCharToken = null;
    private Token leftParenGetChar = null;
    private Token rightParenGetChar = null;

    private Token ifToken = null;
    private Token leftParenToken = null;
    private LOrExp logicOrExp = null;
    private Token rightParenToken = null;
    private Stmt ifStatement = null;
    private Token elseToken = null;
    private Stmt elseStatement = null;

    private Token breakToken = null;
    private Token continueToken = null;

    private Token forToken = null;
    private Token leftParenFor = null;
    private ForStmt firstForStmt = null;
    private Token firstSemicolonFor = null;
    private LOrExp forLogicOrExp = null;
    private Token secondSemicolonFor = null;
    private ForStmt secondForStmt = null;
    private Token rightParenFor = null;
    private Stmt forBodyStmt = null;

    private Token returnToken = null;
    private AddExp returnExpression = null;

    private Token printfToken = null;
    private Token leftParenPrintf = null;
    private Token stringConstToken = null;
    private LinkedList<Token> commaTokenList = null;
    private LinkedList<AddExp> printfExpressions = null;
    private Token rightParenPrintf = null;

    private Block codeBlock = null;

    /**
     * 构造函数，用于初始化赋值语句或输入语句。
     *
     * @param leftValue       左值（变量）
     * @param assignToken     赋值号 Token
     * @param expression      表达式
     * @param semicolonToken  分号 Token
     * @param getIntToken     读取整数的 Token（可选）
     * @param leftParenGetInt 左括号 Token（可选）
     * @param rightParenGetInt 右括号 Token（可选）
     * @param getCharToken    读取字符的 Token（可选）
     * @param leftParenGetChar 左括号 Token（可选）
     * @param rightParenGetChar 右括号 Token（可选）
     */
    public Stmt(Lval leftValue, Token assignToken, AddExp expression, Token semicolonToken,
                Token getIntToken, Token leftParenGetInt, Token rightParenGetInt,
                Token getCharToken, Token leftParenGetChar, Token rightParenGetChar) {
        this.leftValue = leftValue;
        this.assignToken = assignToken;
        this.expression = expression;
        this.semicolonToken = semicolonToken;
        this.getIntToken = getIntToken;
        this.leftParenGetInt = leftParenGetInt;
        this.rightParenGetInt = rightParenGetInt;
        this.getCharToken = getCharToken;
        this.leftParenGetChar = leftParenGetChar;
        this.rightParenGetChar = rightParenGetChar;
    }

    /**
     * 构造函数，用于初始化表达式语句或空语句。
     *
     * @param expression     表达式（可选）
     * @param semicolonToken 分号 Token
     */
    public Stmt(AddExp expression, Token semicolonToken) {
        this.expression = expression;
        this.semicolonToken = semicolonToken;
    }

    /**
     * 构造函数，用于初始化代码块语句。
     *
     * @param codeBlock 代码块对象
     */
    public Stmt(Block codeBlock) {
        this.codeBlock = codeBlock;
    }

    /**
     * 构造函数，用于初始化条件语句。
     *
     * @param ifToken        if 关键字 Token
     * @param leftParenToken 左括号 Token
     * @param logicOrExp     逻辑或表达式
     * @param rightParenToken 右括号 Token
     * @param ifStatement    if 分支的语句
     * @param elseToken      else 关键字 Token（可选）
     * @param elseStatement  else 分支的语句（可选）
     */
    public Stmt(Token ifToken, Token leftParenToken, LOrExp logicOrExp, Token rightParenToken,
                Stmt ifStatement, Token elseToken, Stmt elseStatement) {
        this.ifToken = ifToken;
        this.leftParenToken = leftParenToken;
        this.logicOrExp = logicOrExp;
        this.rightParenToken = rightParenToken;
        this.ifStatement = ifStatement;
        this.elseToken = elseToken;
        this.elseStatement = elseStatement;
    }

    /**
     * 构造函数，用于初始化 break 或 continue 语句。
     *
     * @param breakToken     break 关键字 Token（可选）
     * @param continueToken  continue 关键字 Token（可选）
     * @param semicolonToken 分号 Token
     */
    public Stmt(Token breakToken, Token continueToken, Token semicolonToken) {
        this.breakToken = breakToken;
        this.continueToken = continueToken;
        this.semicolonToken = semicolonToken;
    }

    /**
     * 构造函数，用于初始化 for 循环语句。
     *
     * @param forToken          for 关键字 Token
     * @param leftParenFor      左括号 Token
     * @param firstForStmt      第一个 ForStmt（初始化部分）
     * @param firstSemicolonFor 第一个分号 Token
     * @param forLogicOrExp     逻辑或表达式（循环条件）
     * @param secondSemicolonFor 第二个分号 Token
     * @param secondForStmt     第二个 ForStmt（迭代部分）
     * @param rightParenFor     右括号 Token
     * @param forBodyStmt       循环体语句
     */
    public Stmt(Token forToken, Token leftParenFor, ForStmt firstForStmt, Token firstSemicolonFor,
                LOrExp forLogicOrExp, Token secondSemicolonFor, ForStmt secondForStmt,
                Token rightParenFor, Stmt forBodyStmt) {
        this.forToken = forToken;
        this.leftParenFor = leftParenFor;
        this.firstForStmt = firstForStmt;
        this.firstSemicolonFor = firstSemicolonFor;
        this.forLogicOrExp = forLogicOrExp;
        this.secondSemicolonFor = secondSemicolonFor;
        this.secondForStmt = secondForStmt;
        this.rightParenFor = rightParenFor;
        this.forBodyStmt = forBodyStmt;
    }

    /**
     * 构造函数，用于初始化返回语句。
     *
     * @param returnToken     return 关键字 Token
     * @param returnExpression 返回的表达式（可选）
     * @param semicolonToken  分号 Token
     */
    public Stmt(Token returnToken, AddExp returnExpression, Token semicolonToken) {
        this.returnToken = returnToken;
        this.returnExpression = returnExpression;
        this.semicolonToken = semicolonToken;
    }

    /**
     * 构造函数，用于初始化 printf 语句。
     *
     * @param printfToken       printf 关键字 Token
     * @param leftParenPrintf   左括号 Token
     * @param stringConstToken  字符串常量 Token
     * @param commaTokenList    逗号 Token 列表（可选）
     * @param printfExpressions 表达式列表（可选）
     * @param rightParenPrintf  右括号 Token
     * @param semicolonToken    分号 Token
     */
    public Stmt(Token printfToken, Token leftParenPrintf, Token stringConstToken,
                LinkedList<Token> commaTokenList, LinkedList<AddExp> printfExpressions,
                Token rightParenPrintf, Token semicolonToken) {
        this.printfToken = printfToken;
        this.leftParenPrintf = leftParenPrintf;
        this.stringConstToken = stringConstToken;
        this.commaTokenList = commaTokenList;
        this.printfExpressions = printfExpressions;
        this.rightParenPrintf = rightParenPrintf;
        this.semicolonToken = semicolonToken;
    }

    /**
     * 构造函数，用于初始化空语句（仅有分号）。
     *
     * @param semicolonToken 分号 Token
     */
    public Stmt(Token semicolonToken) {
        this.semicolonToken = semicolonToken;
    }

    /**
     * 生成语句的语法字符串表示。
     *
     * @return 语法字符串
     */
    @Override
    public String toSyntaxString() {
        StringBuilder syntaxBuilder = new StringBuilder();

        // 标记是否已处理
        boolean handled = false;

        // 处理赋值语句或输入语句
        if (leftValue != null) {
            syntaxBuilder.append(leftValue.toSyntaxString());
            syntaxBuilder.append(assignToken.toSyntaxString());
            if (expression != null) {
                syntaxBuilder.append(expression.toSyntaxString());
                syntaxBuilder.append("<Exp>\n");
            } else if (getCharToken != null) {
                syntaxBuilder.append(getCharToken.toSyntaxString());
                syntaxBuilder.append(leftParenGetChar.toSyntaxString());
                syntaxBuilder.append(rightParenGetChar.toSyntaxString());
            } else if (getIntToken != null) {
                syntaxBuilder.append(getIntToken.toSyntaxString());
                syntaxBuilder.append(leftParenGetInt.toSyntaxString());
                syntaxBuilder.append(rightParenGetInt.toSyntaxString());
            }
            if (semicolonToken != null) {
                syntaxBuilder.append(semicolonToken.toSyntaxString());
            }
            handled = true;
        }

        // 处理表达式语句
        else if (expression != null) {
            syntaxBuilder.append(expression.toSyntaxString());
            syntaxBuilder.append("<Exp>\n");
            if (semicolonToken != null) {
                syntaxBuilder.append(semicolonToken.toSyntaxString());
            }
            handled = true;
        }

        // 处理代码块语句
        else if (codeBlock != null) {
            syntaxBuilder.append(codeBlock.toSyntaxString());
            handled = true;
        }

        // 处理条件语句
        else if (ifToken != null) {
            syntaxBuilder.append(ifToken.toSyntaxString());
            syntaxBuilder.append(leftParenToken.toSyntaxString());
            syntaxBuilder.append(logicOrExp.toSyntaxString());
            syntaxBuilder.append(rightParenToken.toSyntaxString());
            syntaxBuilder.append(ifStatement.toSyntaxString());
            if (elseToken != null) {
                syntaxBuilder.append(elseToken.toSyntaxString());
                syntaxBuilder.append(elseStatement.toSyntaxString());
            }
            handled = true;
        }

        // 处理 break 或 continue 语句
        else if (breakToken != null || continueToken != null) {
            if (breakToken != null) {
                syntaxBuilder.append(breakToken.toSyntaxString());
            } else if (continueToken != null) {
                syntaxBuilder.append(continueToken.toSyntaxString());
            }
            if (semicolonToken != null) {
                syntaxBuilder.append(semicolonToken.toSyntaxString());
            }
            handled = true;
        }

        // 处理 for 循环语句
        else if (forToken != null) {
            syntaxBuilder.append(forToken.toSyntaxString());
            syntaxBuilder.append(leftParenFor.toSyntaxString());
            if (firstForStmt != null) {
                syntaxBuilder.append(firstForStmt.toSyntaxString());
            }
            syntaxBuilder.append(firstSemicolonFor.toSyntaxString());
            if (forLogicOrExp != null) {
                syntaxBuilder.append(forLogicOrExp.toSyntaxString());
            }
            syntaxBuilder.append(secondSemicolonFor.toSyntaxString());
            if (secondForStmt != null) {
                syntaxBuilder.append(secondForStmt.toSyntaxString());
            }
            syntaxBuilder.append(rightParenFor.toSyntaxString());
            syntaxBuilder.append(forBodyStmt.toSyntaxString());
            handled = true;
        }

        // 处理 return 语句
        else if (returnToken != null) {
            syntaxBuilder.append(returnToken.toSyntaxString());
            if (returnExpression != null) {
                syntaxBuilder.append(returnExpression.toSyntaxString());
                syntaxBuilder.append("<Exp>\n");
            }
            if (semicolonToken != null) {
                syntaxBuilder.append(semicolonToken.toSyntaxString());
            }
            handled = true;
        }

        // 处理 printf 语句
        else if (printfToken != null) {
            syntaxBuilder.append(printfToken.toSyntaxString());
            syntaxBuilder.append(leftParenPrintf.toSyntaxString());
            syntaxBuilder.append(stringConstToken.toSyntaxString());
            if (printfExpressions != null && !printfExpressions.isEmpty()) {
                int exprCount = printfExpressions.size();
                for (int index = 0; index < exprCount; index++) {
                    syntaxBuilder.append(commaTokenList.get(index).toSyntaxString());
                    syntaxBuilder.append(printfExpressions.get(index).toSyntaxString());
                    syntaxBuilder.append("<Exp>\n");
                }
            }
            syntaxBuilder.append(rightParenPrintf.toSyntaxString());
            if (semicolonToken != null) {
                syntaxBuilder.append(semicolonToken.toSyntaxString());
            }
            handled = true;
        }

        // 处理空语句（仅有分号）
        else if (semicolonToken != null) {
            syntaxBuilder.append(semicolonToken.toSyntaxString());
            handled = true;
        }

        syntaxBuilder.append(NODE_NAME).append("\n");
        return syntaxBuilder.toString();
    }
}
