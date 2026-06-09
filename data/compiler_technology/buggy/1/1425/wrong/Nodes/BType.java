package Nodes;/**
 * @Description:
 * @author
 * @date 2024/9/28 18:58
 */
import java.io.IOError;
import java.util.*;
import Token.*;
import Utils.IO;
import frontend.*;
/**
 * @author:
 * TODO  
 * 2024/9/28 18:58
 */
public class BType {
//    BType â†’ 'int' | 'char'
    private Token inttk;
    private Token chartk;

    public BType(Token inttk, Token chartk) {
        this.inttk = inttk;
        this.chartk = chartk;
    }

    public void print(){
        if(inttk!=null)
            IO.parser_output(inttk.toString());
        else if(chartk!=null)
            IO.parser_output(chartk.toString());
    }

    public Token getInttk() {
        return inttk;
    }

    public Token getChartk() {
        return chartk;
    }
}
