package Node;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import Token.*;
import Utils.OutputUtils;
public class CharacterNode {
    public Token charConst;
    public CharacterNode(Token charConst){
        this.charConst = charConst;
    }
    public void print() throws IOException {
        OutputUtils.parserOutput(charConst.toString());
        OutputUtils.parserOutput("<Character>\n");
    }
}
