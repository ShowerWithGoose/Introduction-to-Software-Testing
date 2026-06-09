package frontend.trees;


import java.io.PrintStream;
import java.util.function.Consumer;

public class PrimaryExpTreeForCharacter extends PrimaryExpTree {
    public CharacterTree character;

    @Override
    public void walk(PrintStream printStream) {
        character.walk(printStream);

        printStream.println("<PrimaryExp>");
    }
}
