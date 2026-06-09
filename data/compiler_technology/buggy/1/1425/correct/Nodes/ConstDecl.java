package Nodes;/**
 * @Description:
 * @author
 * @date 2024/9/28 18:57
 */
import java.util.*;
import Token.*;
import Utils.IO;
import frontend.*;
/**
 * @author:
 * TODO  
 * 2024/9/28 18:57
 */
public class ConstDecl {
//    ConstDecl â†’ 'const' BType ConstDef { ',' ConstDef } ';'
    private Token consttk;
    private BType bType;
    private List<ConstDef> constDefList;
    private List<Token> commaList;
    private Token semicn;

    public ConstDecl(Token consttk, BType bType, List<ConstDef> constDefList, List<Token> commaList, Token semicn) {
        this.consttk = consttk;
        this.bType = bType;
        this.constDefList = constDefList;
        this.commaList = commaList;
        this.semicn = semicn;
    }

    public void print(){
        IO.parser_output(consttk.toString());
        bType.print();
        constDefList.get(0).print();
        for(int i=1;i<constDefList.size();i++){
            IO.parser_output(commaList.get(i-1).toString());
            constDefList.get(i).print();
        }

        IO.parser_output(semicn.toString());
        IO.parser_output(Parser.nodeTypes.get(NodeType.ConstDecl));
    }

    public Token getConsttk() {
        return consttk;
    }

    public BType getbType() {
        return bType;
    }

    public List<ConstDef> getConstDefList() {
        return constDefList;
    }

    public List<Token> getCommaList() {
        return commaList;
    }

    public Token getSemicn() {
        return semicn;
    }
}
