package frontend.statement.stmt;
import frontend.Token;
import frontend.TokenListIterator;
import frontend.TokenType;
import frontend.expression.Exp;
import frontend.expression.ExpParser;
import frontend.expression.primaryexp.LVal;
import frontend.expression.primaryexp.LValParser;
import frontend.statement.stmt.ForStmt;

public class ForStmtParser {
    private TokenListIterator iterator;

    public ForStmtParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    public ForStmt parseForStmt() {
        // 使用 LValParser 解析 LVal
        LValParser lvalParser = new LValParser(this.iterator);
        LVal lval = lvalParser.parseLVal();

        // 解析 '='
        Token assign = this.iterator.readNextToken();
        if (assign.getType() != TokenType.ASSIGN) {
            System.out.println("EXPECT '=' IN FORSTMTPARSER");
        }

        // 使用 ExpParser 解析 Exp
        ExpParser expParser = new ExpParser(this.iterator);
        Exp exp = expParser.parseExp();

        // 返回解析后的 ForStmt 对象
        return new ForStmt(lval, assign, exp);
    }
}