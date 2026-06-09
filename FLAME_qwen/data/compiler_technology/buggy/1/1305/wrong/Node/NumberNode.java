package Node;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import Token.*;
import Utils.OutputUtils;
public class NumberNode {
    public Token intConst;
    public NumberNode(Token intConst){
        this.intConst = intConst;
    }
    public void print() throws IOException {
        OutputUtils.parserOutput(intConst.toString());
        OutputUtils.parserOutput("<Number>\n");
    }
}
