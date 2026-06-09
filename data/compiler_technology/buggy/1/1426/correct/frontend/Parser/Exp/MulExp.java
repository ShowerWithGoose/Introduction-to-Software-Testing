package frontend.Parser.Exp;

import frontend.Token;

import java.util.ArrayList;

//乘除模表达式 MulExp → UnaryExp | MulExp ('*' | '/' | '%') UnaryExp
public class MulExp extends BinaryExp<UnaryExp> {

    public MulExp(UnaryExp first, ArrayList<Token> op, ArrayList<UnaryExp> others) {
        super("<MulExp>", first, op, others);
    }
}
