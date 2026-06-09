import Symbol.symbolHandler;
import node.CompUnitNode;
import node.TokenList;
import node.tokenError;

import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Iterator;
import java.util.List;

public class Compiler {
    public static void main(String[] args) {


        String filePath = "testfile.txt"; // 替换为你的文件路径
        StringBuilder content = new StringBuilder();
        try (BufferedReader br = new BufferedReader(new FileReader(filePath))) {
            String line;
            while ((line = br.readLine()) != null) {
                //System.out.println(line);
                content.append(line);
                content.append('\n');
            }
        } catch (IOException e) {
            e.printStackTrace();
        }

        Lexer lexer = new Lexer();
        lexer.tokenize(content.toString());
        //lexer.printAns();

        TokenList tokens = lexer.getTokens();
        ArrayList<tokenError> errors = lexer.getTokenErrors();

        Parser parser = new Parser(tokens,errors);

        CompUnitNode compUnitNode = (CompUnitNode) parser.parseCompUnit();


        List<tokenError> tokenErrors = parser.getTokenErrors();

        //symbolHandler symbolHandler = new symbolHandler(compUnitNode,parser.getTokenErrors());
        //symbolHandler.compHandler();
        //List<tokenError> tokenErrors = symbolHandler.getErrors();
        if (tokenErrors.isEmpty()) {
            try {
                FileOutputStream fos = new FileOutputStream("parser.txt");
                PrintStream ps = new PrintStream(fos);
                System.setOut(ps);
                //FileWriter writer = new FileWriter("lexer.txt");
                //symbolHandler.getSignal().print();
                compUnitNode.print();
                //System.out.println("Data written to file successfully.");
            } catch (IOException e) {
                System.out.println("An error occurred.");
                e.printStackTrace();
            }
        } else {
            try {
                FileOutputStream fos = new FileOutputStream("error.txt");
                PrintStream ps = new PrintStream(fos);
                System.setOut(ps);
                //FileWriter writer = new FileWriter("lexer.txt");

                Iterator<tokenError> iterator = tokenErrors.iterator();
                tokenError last = null;
                while (iterator.hasNext()) {
                    tokenError t = iterator.next();
                    if (last == null) {
                        last = t;
                    } else {
                        if (last.getLineNum() == t.getLineNum()) {
                            iterator.remove();
                        }
                    }


                }

                Collections.sort(tokenErrors);
                for (tokenError t : tokenErrors) {
                    System.out.println(t);
                }
                //System.out.println("Data written to file successfully.");
            } catch (IOException e) {
                System.out.println("An error occurred.");
                e.printStackTrace();
            }
        }



    }
}