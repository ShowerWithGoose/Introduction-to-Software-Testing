package frontend.declaration.variable.initval;

import frontend.Token;
import frontend.TokenListIterator;
import frontend.TokenType;
import frontend.expression.Exp;
import frontend.expression.ExpParser;
import frontend.terminal.StringConst;
import java.util.ArrayList;

/**
 * 解析器: InitVal (变量初值)
 * 对应文法: InitVal → Exp | '{' [ Exp { ',' Exp } ] '}' | StringConst
 *
 * 解析过程：
 * 1. 解析表达式初值 (Exp)。
 * 2. 解析数组初值 ('{' [Exp { ',' Exp }] '}')。
 * 3. 解析字符串常量初值 (StringConst)。
 */
public class InitValParser {
    private final TokenListIterator iterator;

    public InitValParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    /**
     * 解析 InitVal，处理三种可能的初值类型：Exp, 数组初值, 字符串常量初值。
     */
    public InitVal parseInitVal() {
        // 读取下一个 token，检查是否为 '{'，以处理数组初值的情况
        Token token = this.iterator.readNextToken();

        if (token.getType().equals(TokenType.LBRACE)) {
            // 处理数组初值：'{ [Exp { ',' Exp }] }'
            Token leftBrace = token; // 保存左花括号 '{'
            Exp firstExp = null;
            ArrayList<Exp> exps = new ArrayList<>();
            ArrayList<Token> commas = new ArrayList<>();

            // 解析第一个表达式
            token = this.iterator.readNextToken();
            if (!token.getType().equals(TokenType.RBRACE)) {
                this.iterator.unReadToken(1); // 回退以重新读取表达式
                ExpParser expParser = new ExpParser(this.iterator);
                firstExp = expParser.parseExp(); // 第一个元素
                token = this.iterator.readNextToken();

                // 解析后续的 ',' Exp 列表
                while (token.getType().equals(TokenType.COMMA)) {
                    commas.add(token);
                    exps.add(expParser.parseExp()); // 后续元素
                    token = this.iterator.readNextToken();
                }
            }

            // 检查是否为 '}'，以正确闭合数组初值
            if (!token.getType().equals(TokenType.RBRACE)) {
                System.err.println("ERROR: EXPECTING '}'");
            }

            // 构造并返回 InitVal（数组初值）
            InitVals initVals = new InitVals(leftBrace, firstExp, commas, exps, token); // token 是右花括号 '}'
            return new InitVal(initVals);

        } else {
            // 处理非数组初值的情况，回退 token 以检查其他类型的初值
            this.iterator.unReadToken(1);

            // 检查是字符串常量还是普通表达式
            token = this.iterator.readNextToken();
            if (token.getType().equals(TokenType.STRCON)) {
                // 解析字符串常量
                StringConst stringConst = new StringConst(token);
                return new InitVal(stringConst); // 返回字符串常量的 InitVal
            } else {
                // 解析表达式初值
                this.iterator.unReadToken(1);
                ExpParser expParser = new ExpParser(this.iterator);
                Exp exp = expParser.parseExp();
                return new InitVal(exp); // 返回表达式的 InitVal
            }
        }
    }
}
