package frontend.expression.multiexp;
import frontend.Token;
import java.util.List;

public class AddExp extends MultiExp<MulExp> {
    public AddExp(MulExp first, List<Token> tokens, List<MulExp> operands) {
        super(first, tokens, operands, "<AddExp>");
    }
}