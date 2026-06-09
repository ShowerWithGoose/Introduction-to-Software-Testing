package frontend.parser.specificUnit;

import frontend.ErrorHandler.Error;
import frontend.ErrorHandler.ErrorHandler;
import frontend.lexer.Token;
import frontend.parser.ParseUnit;

import java.util.ArrayList;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class PrintfStmt extends Stmt {
    private Token printfTK;
    private Token stringConst;
    private ArrayList<Exp> args;

    public PrintfStmt(String name, ArrayList<ParseUnit> subUnits,
                      Token stringConst, ArrayList<Exp> args, Token printfTK) {
        super(name, subUnits);
        this.printfTK = printfTK;
        this.stringConst = stringConst;
        this.args = args;

    }

    public void checkL() {
        String regex = "%[a-zA-Z]";

        // 编译正则表达式
        Pattern pattern = Pattern.compile(regex);

        // 使用正则表达式查找匹配项
        Matcher matcher = pattern.matcher(stringConst.getContext());
        int matchCount = 0;

        // 遍历所有匹配项并计数
        while (matcher.find()) {
            matchCount++;
        }
        if (matchCount != args.size()) {
            ErrorHandler.getInstance().addError(new Error('l', printfTK.getLineNum()));
        }
    }
}
