package Node;
import IOcontrol.IO;
import Token.*;
public class BTypeNode {
    //基本类型 BType → 'int' | 'char'
    private Token token;
    public BTypeNode(Token token) {
        this.token = token;
    }

    public void print() {
        IO.ParserOutput(token);
    }

}
