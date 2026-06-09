import java.io.*;
import java.lang.Character;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

import Lexer.Token;
import Grammar.Grammar;
import Nonterminal.*;
import Error.Error;
import Symbol.Symbol;
import Error.Errortype;
/**
 *
 * <p>Project: Compiler - Compiler
 * <p>Powered by berry On 2024-09-20 
 *
 * @author
 * @version 1.0
 */
import Lexer.Lexer;
import Nonterminal.CompUnit;
import Symbol.Symboltable;

public class Compiler {
    public enum Stage{
        Lexer,
        Grammar,
        Error
    }
    public static Stage stage=Stage.Grammar;
    public static List<Token> tokens = new ArrayList<>();//保存所有Token
    public static Map<Integer, Character> errors=new HashMap<Integer, Character>();
    public static void main(String[] args) {
        //System.out.println(stage);
        try {
            BufferedWriter writer = new BufferedWriter(new FileWriter("./lexer.txt", false)); // 设置为false以清空文件
            writer.close(); // 关闭流，这将清空文件
        } catch (IOException e) {
            e.printStackTrace();
        }
        try {
            BufferedWriter writer = new BufferedWriter(new FileWriter("./error.txt", false)); // 设置为false以清空文件
            writer.close(); // 关闭流，这将清空文件
        } catch (IOException e) {
            e.printStackTrace();
        }
        //Error.getError().errors.clear();
        //语法分析
        Lexer lexer = Lexer.getLexer();
        lexer.tokens.clear();//之后可以保存
        lexer.isError = false;
        lexer.errorLine.clear();
        //System.out.println(new Token(Token.Type.NONE,"",0).type);
        try {
            BufferedReader reader = new BufferedReader(new FileReader("./testfile.txt"));
            String line;
            while ((line = reader.readLine()) != null) {
                lexer.line = line;
                lexer.token = "";
                lexer.curPos = 0;
                lexer.isEnd = false;
                lexer.lineNum++;
                lexer.analyseLine();
                //System.out.println(lexer.lineNum);
            }
            reader.close();
        } catch (IOException e) {
            System.out.print("input test.txt Exception");
        }
        //存储所有Token
        tokens = lexer.tokens;


        if(lexer.isError){
            errors.putAll(lexer.errorLine);
        }
        //System.out.println(errors);
        //语法分析
        Grammar grammar=Grammar.getGrammar();
        grammar.errorLine.clear();
        grammar.isError=false;
        grammar.isEnd=false;
        grammar.curPos=0;
        grammar.now=tokens.get(0);
        grammar.setTokens(tokens);
        Grammar.nodeOutput.clear();
        grammar.createMap();
        grammar.analyse();
        if(grammar.isError){
            errors.putAll(grammar.errorLine);
        }
        Error error=Error.getError();
        error.scope=0;
        error.loop=0;
        error.compUnitError(grammar.compUnit);
        error.removeSymbolTable();
        for(Errortype e:error.errors){
            System.out.println(e.lineno+" "+e.type);
        }
        //输出
        //词法分析输出部分
        if(stage==Stage.Lexer) {
            if (!lexer.isError) {
                lexer.output();
            } else {
                try {
                    BufferedWriter writer = new BufferedWriter(new FileWriter("./error.txt", false));
                    //Error.getError().outputErrors(writer);
                    writer.close(); // 关闭流，这将清空文件
                } catch (IOException e) {
                    e.printStackTrace();
                }
                //System.out.println(lexer.errorLine+" "+"a");
            }
        }
        //语法分析输出部分
        else if(stage==Stage.Grammar){
            //System.out.println(grammar.tokens.size());
            if(!grammar.isError&&!lexer.isError){
                try {
                    BufferedWriter writer = new BufferedWriter(new FileWriter("./parser.txt", false));
                    grammar.compUnit.output(writer);
                    writer.close();
                }catch (IOException e) {
                    e.printStackTrace();
                }
            }
            //错误处理
            else{
                try {
                    BufferedWriter writer = new BufferedWriter(new FileWriter("./error.txt", false));
                    Error.getError().outputErrors(writer);
                    writer.close(); // 关闭流，这将清空文件
                }catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }
        else if(stage==Stage.Error){
            if(error.errors.size()==0){
                //System.out.println("1");
                try {
                    BufferedWriter writer = new BufferedWriter(new FileWriter("./symbol.txt", false));
                    for (Integer i : error.SymboltableSave.keySet()) {
                        for(Symbol s:error.SymboltableSave.get(i).symbolMap){
                            //System.out.println(i+" "+s.name+" "+s.type.toString()+"\n");
                            writer.write(i+" "+s.name+" "+s.type.toString()+"\n");
                        }
                    }
                    writer.close();
                }catch (IOException e) {
                    e.printStackTrace();
                }
            }else{
                try {
                    BufferedWriter writer = new BufferedWriter(new FileWriter("./error.txt", false));
                    Error.getError().outputErrors(writer);
                    writer.close(); // 关闭流，这将清空文件
                }catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }

    }
}
