import java.io.IOException;
import java.util.ArrayList;

public class BlockItem extends Father {
    private ArrayList<Father> list;

    public BlockItem() {
        list = new ArrayList<>();
    }

    public int parser(int p,ArrayList<Token> tokens) {
        if (tokens.get(p).getCate().equals(Cate.CONSTTK)
                || tokens.get(p).getCate().equals(Cate.INTTK)
                || tokens.get(p).getCate().equals(Cate.CHARTK)) {
            Decl decl = new Decl();
            p = decl.parser(p,tokens);
            list.add(decl);
        } else {
            Stmt stmt = new Stmt();
            p = stmt.parser(p,tokens);
            list.add(stmt);
        }
        return p;
    }

    public void Print() throws IOException {
        for (Father object : list) {
            if (object instanceof Token) {
                Token token = (Token) object;
                token.Print();
            } else if (object instanceof Decl) {
                Decl decl = (Decl) object;
                decl.Print();
            } else if (object instanceof Stmt) {
                Stmt stmt = (Stmt) object;
                stmt.Print();
            }
        }
        /*FileWriter fileWriter = new FileWriter("parser.txt", true);
        BufferedWriter bufferedWriter = new BufferedWriter(fileWriter);
        bufferedWriter.write('<' + "BlockItem" + '>' + '\n');
        bufferedWriter.flush();
        bufferedWriter.close();*/
    }
}
