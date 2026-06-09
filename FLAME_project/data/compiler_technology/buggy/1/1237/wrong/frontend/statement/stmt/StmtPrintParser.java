package frontend.statement.stmt;

import frontend.Token;
import frontend.TokenListIterator;
import frontend.TokenType;
import frontend.expression.Exp;
import frontend.expression.ExpParser;
import frontend.terminal.StringConst;
import error.Error;
import error.ErrorTable;
import error.ErrorType;

import java.util.ArrayList;

/**
 * 解析器: StmtPrint (printf 语句)
 * 对应文法: StmtPrint -> 'printf' '(' StringConst { ',' Exp } ')' ';'
 *
 * 解析 printf 语句，表示格式化输出，可以包含多个表达式。
 */
public class StmtPrintParser {
    private final TokenListIterator iterator;

    public StmtPrintParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    /**
     * 解析 printf 语句。
     * @return 解析后的 StmtPrint 对象
     */
    public StmtPrint parseStmtPrint() {
        // 解析 'printf' 关键字
        Token printf = this.iterator.readNextToken();
        if (printf.getType() != TokenType.PRINTFTK) {
            System.err.println("ERROR: Expected 'printf' keyword (PRINTFTK), but found: " + printf);
        }

        // 解析左括号 '('
        Token leftParent = this.iterator.readNextToken();
        if (leftParent.getType() != TokenType.LPARENT) {
            this.iterator.unReadToken(2);
            Error error = new Error(this.iterator.readNextToken().getLineIndex(), ErrorType.MISSING_R_PARENT);  // j 类错误
            ErrorTable.addError(error);
        }

        // 解析 FormatString
        StringConst formatString = new StringConst(this.iterator.readNextToken());

        // 解析可选的 ',' Exp 列表
        ArrayList<Token> commas = new ArrayList<>();
        ArrayList<Exp> exps = new ArrayList<>();
        Token token = this.iterator.readNextToken();
        while (token.getType() == TokenType.COMMA) {
            commas.add(token);
            ExpParser expParser = new ExpParser(this.iterator);
            exps.add(expParser.parseExp());
            token = this.iterator.readNextToken();
        }

        // 解析右括号 ')'
        Token rightParent = token;
        if (rightParent.getType() != TokenType.RPARENT) {
            this.iterator.unReadToken(2);
            Error error = new Error(this.iterator.readNextToken().getLineIndex(), ErrorType.MISSING_R_PARENT);  // j 类错误
            ErrorTable.addError(error);
        }

        // 解析分号 ';' 并处理 i 类错误
        Token semicn = this.iterator.readNextToken();
        if (semicn.getType() != TokenType.SEMICN) {
            this.iterator.unReadToken(2);
            Error error = new Error(this.iterator.readNextToken().getLineIndex(), ErrorType.MISSING_SEMICN);  // i 类错误
            ErrorTable.addError(error);
        }

        // 返回解析后的 StmtPrint 对象
        return new StmtPrint(printf, leftParent, formatString, commas, exps, rightParent, semicn);
    }
}
