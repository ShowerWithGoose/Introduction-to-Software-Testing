package frontend.Parser.SyntaxNode.PrimaryExp;
import frontend.Parser.SyntaxNode.Char;

public class PrimaryExpChar extends PrimaryExp{
    private Char character;

    public PrimaryExpChar(Char character) {
        this.character = character;
    }

    @Override
    public String toString() {
        return character.toString() + name + "\n";
    }
}
