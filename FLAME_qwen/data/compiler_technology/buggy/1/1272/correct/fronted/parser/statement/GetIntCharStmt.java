package fronted.parser.statement;

import fronted.ErrorList;
import fronted.lexer.Token;
import fronted.lexer.TokenList;
import fronted.lexer.TokenType;
import fronted.parser.expression.LVal;
import fronted.parser.others.Block;

public class GetIntCharStmt {
    //自定义
    //LVal '=' ('getchar'| 'getint')'('')'';' // i j

    private LVal lVal;

    private static final Token assign = new Token(TokenType.Type.ASSIGN,"=",1);

    private Token Get;

    private static final Token leftParent = new Token(TokenType.Type.LPARENT,"(",1);

    private static final Token rightParent = new Token(TokenType.Type.RPARENT,")",1);

    private static final Token semicn = new Token(TokenType.Type.SEMICN,";",1);

    public GetIntCharStmt(LVal lVal,Token get) {
        this.lVal = lVal;
        this.Get = get;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(lVal.toString());
        sb.append(assign);
        sb.append(Get.toString());
        sb.append(leftParent);
        sb.append(rightParent);
        sb.append(semicn);
        return sb.toString();
    }

    public static GetIntCharStmt parse(TokenList list) {
        LVal lVal = LVal.parse(list);
        list.next();//=
        Token token = list.now();//getint || getchar
        list.next();
        list.next();//(
        if (list.now().getType().equals(TokenType.Type.RPARENT)) {
            list.next();
        } else {
            ErrorList.addError(list.before().getLine(),'j');
        }
        if (list.now().getType().equals(TokenType.Type.SEMICN)) {
            list.next();
        } else {
            ErrorList.addError(list.before().getLine(),'i');
        }
        return new GetIntCharStmt(lVal,token);
    }//不做其他错误考虑
}
