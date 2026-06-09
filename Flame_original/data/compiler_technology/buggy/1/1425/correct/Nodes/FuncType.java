package Nodes;/**
 * @Description:
 * @author
 * @date 2024/9/28 18:58
 */
import Token.*;
import Utils.IO;
import frontend.Parser;

/**
 * @author:
 * TODO  
 * 2024/9/28 18:58
 */
public class FuncType {
//    FuncType â†’ 'void' | 'int' | 'char'
    private Token voidtk;
    private Token inttk;
    private Token chartk;

    public FuncType(Token voidtk, Token inttk, Token chartk) {
        this.voidtk = voidtk;
        this.inttk = inttk;
        this.chartk = chartk;
    }

    public void print(){
        if(voidtk!=null){
            IO.parser_output(voidtk.toString());
        }
        else if(inttk!=null){
            IO.parser_output(inttk.toString());
        }
        else if(chartk!=null){
            IO.parser_output(chartk.toString());
        }
        IO.parser_output(Parser.nodeTypes.get(NodeType.FuncType));
    }

    public Token getVoidtk() {
        return voidtk;
    }

    public Token getInttk() {
        return inttk;
    }

    public Token getChartk() {
        return chartk;
    }
}
