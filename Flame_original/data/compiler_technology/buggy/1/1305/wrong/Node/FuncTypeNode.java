package Node;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import Token.*;
import Utils.OutputUtils;
public class FuncTypeNode {
    public Token funcType;
    public FuncTypeNode(Token funcType){
        this.funcType = funcType;
    }
    public void print() throws IOException {
        OutputUtils.parserOutput(funcType.toString());
        OutputUtils.parserOutput("<FuncType>\n");
    }
}
