package Nodes;/**
 * @Description:
 * @author
 * @date 2024/9/28 19:00
 */
import java.util.*;
import Token.Token;
import Utils.IO;
import frontend.*;
/**
 * @author:
 * TODO  
 * 2024/9/28 19:00
 */
public class Character {
    private Token chacon;

    public Character(Token chacon) {
        this.chacon = chacon;
    }

    public void print(){
        IO.parser_output(chacon.toString());
        IO.parser_output(Parser.nodeTypes.get(NodeType.Character));
    }

    public Token getChacon() {
        return chacon;
    }
}
