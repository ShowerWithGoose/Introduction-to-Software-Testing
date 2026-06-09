package Node;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import Token.*;
import Utils.OutputUtils;
public class BTypeNode {
    public Token BType;
    public BTypeNode(Token BType){
        this.BType = BType;
    }
    public void print() throws IOException {
        OutputUtils.parserOutput(BType.toString());
    }
}
