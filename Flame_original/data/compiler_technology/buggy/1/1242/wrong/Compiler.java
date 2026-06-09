import frontend.Category.Token;
import frontend.Category.TokenList;
import frontend.Error.ErrorMap;
import frontend.Lexer.Lexer;
import frontend.Parser.Parser;
import frontend.symbol.SymbolTable;

import java.util.ArrayList;
import java.util.HashMap;

//TIP 要<b>运行</b>代码，请按 <shortcut actionId="Run"/> 或
// 点击装订区域中的 <icon src="AllIcons.Actions.Execute"/> 图标。
public class Compiler {
    public static void main(String[] args) {
        //System.out.println("当前工作目录: " + System.getProperty("user.dir"));
        Lexer.ReadFrom("testfile.txt", "lexer.txt");
        Parser.PrintTo("parser.txt");
        ErrorMap.Print();
        SymbolTable.Print();
    }
}