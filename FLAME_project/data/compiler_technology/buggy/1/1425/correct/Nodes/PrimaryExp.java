package Nodes;/**
 * @Description:
 * @author
 * @date 2024/9/28 19:00
 */
import java.util.*;
import Token.*;
import Utils.IO;
import frontend.*;
/**
 * @author:
 * TODO  
 * 2024/9/28 19:00
 */
public class PrimaryExp {
//     PrimaryExp â†’ '(' Exp ')' | LVal | Number | Character
    private Token lparent;
    private Exp exp;
    private Token rparent;
    private LVal lVal;
    private Number number;
    private Character character;

    public PrimaryExp(Token lparent, Exp exp, Token rparent, LVal lVal, Number number, Character character) {
        this.lparent = lparent;
        this.exp = exp;
        this.rparent = rparent;
        this.lVal = lVal;
        this.number = number;
        this.character = character;
    }

    public void print(){
        if(lparent!=null){
            IO.parser_output(lparent.toString());
            exp.print();
            IO.parser_output(rparent.toString());
        }
        else if(lVal!=null){
            lVal.print();
        }
        else if(number!=null){
            number.print();
        }
        else if(character!=null){
            character.print();
        }
        IO.parser_output(Parser.nodeTypes.get(NodeType.PrimaryExp));
    }

    public Token getLparent() {
        return lparent;
    }

    public Exp getExp() {
        return exp;
    }

    public Token getRparent() {
        return rparent;
    }

    public LVal getlVal() {
        return lVal;
    }

    public Number getNumber() {
        return number;
    }

    public Character getCharacter() {
        return character;
    }
}
