package frontend.expression.unaryexp;

import frontend.Token;
import frontend.TokenListIterator;
import frontend.TokenType;
import frontend.expression.primaryexp.PrimaryExpParser;

/**
 * 解析器: UnaryExp (一元表达式)
 * 对应文法: UnaryExp → PrimaryExp | Ident '(' [FuncRParams] ')' | UnaryOp UnaryExp
 *
 * 解析一元表达式 (UnaryExp)，处理三种情况：
 * 1. 基本表达式 (PrimaryExp)
 * 2. 函数调用 (Ident '(' [FuncRParams] ')')
 * 3. 一元操作符 (UnaryOp) 后接一元表达式
 */
public class UnaryExpParser {
    private final TokenListIterator iterator;
    private UnaryExpEle unaryExpEle = null;

    public UnaryExpParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    public UnaryExp parseUnaryExp() {
        Token first = iterator.readNextToken();
        Token second = iterator.readNextToken();

        // 函数调用的情况: Ident '(' [FuncRParams] ')'
        if (isIdentFirst(first, second)) {
            iterator.unReadToken(2);
            UnaryExpFuncParser unaryExpFuncParser = new UnaryExpFuncParser(iterator);
            unaryExpEle = unaryExpFuncParser.parseUnaryFuncExp();

            // 基本表达式的情况: PrimaryExp
        } else if (isPrimaryExpFirst(first)) {
            iterator.unReadToken(2);
            PrimaryExpParser primaryExpParser = new PrimaryExpParser(iterator);
            unaryExpEle = primaryExpParser.parsePrimaryExp();

            // 一元操作符的情况: UnaryOp UnaryExp
        } else if (isUnaryFirst(first)) {
            iterator.unReadToken(2);
            UnaryExpOpParser unaryExpOpParser = new UnaryExpOpParser(iterator);
            unaryExpEle = unaryExpOpParser.parseUnaryExpOp();
        }

        // 创建并返回 UnaryExp 对象
        return new UnaryExp(unaryExpEle);
    }

    // 判断是否为函数调用的第一部分: Ident '('
    private boolean isIdentFirst(Token first, Token second) {
        return first.getType().equals(TokenType.IDENFR) &&
                second.getType().equals(TokenType.LPARENT);
    }

    // 判断是否为基本表达式的第一部分: PrimaryExp
    private boolean isPrimaryExpFirst(Token first) {
        return first.getType().equals(TokenType.LPARENT) ||
                first.getType().equals(TokenType.IDENFR) ||
                first.getType().equals(TokenType.INTCON) ||
                first.getType().equals(TokenType.CHRCON);
    }

    // 判断是否为一元操作符的第一部分: UnaryOp
    private boolean isUnaryFirst(Token first) {
        return first.getType().equals(TokenType.PLUS) ||
                first.getType().equals(TokenType.MINU) ||
                first.getType().equals(TokenType.NOT);
    }
}
