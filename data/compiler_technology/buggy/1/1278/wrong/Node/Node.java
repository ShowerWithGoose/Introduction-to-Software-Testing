package Node;
import java.util.ArrayList;
import Tools.Token;
import Tools.WriteFile;
public class Node {
    int lineno;
    ArrayList<Token> tokens = new ArrayList<>();
    public Node(int lineno) {
        this.lineno = lineno;
    }
    public int getLineno() {
        return lineno;
    }
    public void checkOut() {}
    public void addTokens(ArrayList<Token> tokens) {
        this.tokens = tokens;
    }
}























