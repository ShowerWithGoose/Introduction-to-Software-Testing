package IO;
import common.GComponent;
import common.Token;
import common.TokenType;
import frontend.ast.LNode;
import frontend.ast.NLNode;
import frontend.ast.Node;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Comparator;

/**
 * The type My writer.
 *
 * @author
 * @Description： 输出
 * @date
 */
public class MyWriter {
    private static MyWriter myWriter ;

    private String LexerLogPath;
    private FileWriter LexerLogWriter;
    private String ParserLogPath;
    private FileWriter ParserLogWriter;
    private String ErrorLogPath;
    private FileWriter ErrorLogWriter;
    private ArrayList<ErrorMessage> ErrorMessages;

    /**
     * 错误消息类型。
     */
    class ErrorMessage {
        /**
         * 行号。
         */
        Integer lineNum;
        /**
         * 消息。
         */
        String message;

        /**
         * 实例化一个新的错误消息。
         *
         * @param a       行号
         * @param message 消息
         */
        ErrorMessage(Integer a, String message) {
            this.lineNum = a;
            this.message = message;
        }
    }

    private MyWriter(){
        try{
            LexerLogPath = "lexer.txt";
            ParserLogPath = "parser.txt";
            ErrorLogPath = "error.txt";
            LexerLogWriter = new FileWriter(new File(LexerLogPath));
            ParserLogWriter = new FileWriter(new File(ParserLogPath));
            ErrorLogWriter = new FileWriter(new File(ErrorLogPath));
            ErrorMessages = new ArrayList<>();
        }catch(Exception e){}
    }

    /**
     * 获取写入器。
     *
     * @return 写入器实例
     */
    public static MyWriter getWriter() {
        if(myWriter==null){
            myWriter = new MyWriter();
        }
        return myWriter;
    }

    /**
     * 记录错误。
     *
     * @param string 错误消息字符串
     */
    public void callError(String string) {
        Integer lineNum = Integer.valueOf(string.split(" ")[0]);
        ErrorMessages.add(new ErrorMessage(lineNum, string));
    }

    /**
     * 打印错误。
     */
    public void printError(){
        ErrorMessages.sort(new Comparator<ErrorMessage>() {
            @Override
            public int compare(ErrorMessage e1, ErrorMessage e2) {
                if (e1.lineNum >= e2.lineNum) {
                    return 1;
                } else {
                    return -1;
                }
            }
        });
        ErrorMessage former = null;
        for (ErrorMessage message : ErrorMessages) {
            if (former != null) {
                if (former.lineNum == message.lineNum) {
                    continue;
                }
            }
            try {
                this.ErrorLogWriter.write(message.message + "\n");
                this.ErrorLogWriter.flush();
            } catch (Exception e) {
                e.printStackTrace();
            }
            former = message;
        }
    }

    /**
     * 打印词法分析结果。
     *
     * @param tokens 词法分析标记列表
     */
    public void printLexer(ArrayList<Token> tokens){
        for (Token token : tokens) {
            try {
                this.LexerLogWriter.write(token.getType()+" "+token.getStr() + "\n");
                this.LexerLogWriter.flush();
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }

    public void printAST(Node root) throws IOException {
        if (root instanceof NLNode) {
            ArrayList<Node> children = root.getChildren();
            for (Node node : children) {
                printAST(node);
            }

            GComponent type = ((NLNode) root).getValue();
            if (!type.equals(GComponent.BlockItem) && !type.equals(GComponent.BType) && !type.equals(GComponent.Decl)) {
                this.ParserLogWriter.write("<" + type + ">" + "\n");
                this.ParserLogWriter.flush();
            }
        } else if (root instanceof LNode) {
            this.ParserLogWriter.write(((LNode) root).getToken().getType().toString() + " " + ((LNode) root).getToken().getStr()+ "\n");
            this.ParserLogWriter.flush();
        }
    }


    /**
     * 是否有错误。
     *
     * @return 如果有错误返回true，否则返回false
     */
    public boolean hasError(){
        return !this.ErrorMessages.isEmpty();
    }
}
