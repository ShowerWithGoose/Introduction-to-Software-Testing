package Node;

import Token.Token;
import frontend.Parser;

public class CharacterNode {
    // Character â†’ CharConst
    private Token charCon;
    public CharacterNode(Token charCon){
        this.charCon = charCon;
    }

    public void print(){
        Parser.getInstance().output(charCon);
        Parser.getInstance().output(NodeType.Character);
    }
}
