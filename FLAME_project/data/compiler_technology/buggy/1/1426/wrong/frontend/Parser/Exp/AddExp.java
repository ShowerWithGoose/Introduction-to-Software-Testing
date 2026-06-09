package frontend.Parser.Exp;

import frontend.Token;

import java.util.ArrayList;
//加减表达式 AddExp → MulExp | AddExp ('+' | '−') MulExp
public class AddExp extends BinaryExp<MulExp> {
    public AddExp(MulExp first, ArrayList<Token> op, ArrayList<MulExp> others) {
                super("<AddExp>", first, op, others);
    }
}
