package frontend.Parser;

import frontend.Lexer.Token;
import frontend.Lexer.TokenType;

public class Nonterminal implements GrammarWord
{
    protected NonterminalType type;

    public Nonterminal(NonterminalType type){
        this.type = type;
    }
    public NonterminalType getType() {
        return type;
    }

    @Override
    public String toString() {
        return type.toString();
    }
}
