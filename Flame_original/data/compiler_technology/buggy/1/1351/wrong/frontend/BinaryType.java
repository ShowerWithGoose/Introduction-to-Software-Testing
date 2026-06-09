package frontend;

import frontend.lexer.TokenType;

import java.util.Arrays;
import java.util.List;

public enum BinaryType {
    LOR(TokenType.OR),
    LAND(TokenType.AND),
    EQ(TokenType.EQL, TokenType.NEQ),
    REL(TokenType.GRE, TokenType.LSS, TokenType.GEQ, TokenType.LEQ),
    ADD(TokenType.PLUS, TokenType.MINU),
    MUL(TokenType.MULT, TokenType.DIV, TokenType.MOD),
    ;

    private final List<TokenType> types;

    BinaryType(TokenType... types) {
        this.types = Arrays.asList(types);
    }

    public boolean contains(TokenType type) {
        return types.contains(type);
    }
    public String print() {
        switch (this) {
            case LOR:  {
                return "<LOrExp>\n";
            }
            case LAND: {
                return "<LAndExp>\n";
            }
            case EQ :  {
                return "<EqExp>\n";
            }
            case REL : {
                return  "<RelExp>\n";
            }
            case ADD : {
                return  "<AddExp>\n";
            }
            case MUL : {
                return  "<MulExp>\n";
            }
            default: {
                return "no sign\n";
            }
        }
    }
}
