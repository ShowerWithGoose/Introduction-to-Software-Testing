import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class Block extends Father {
    private ArrayList<Father> list;

    public Block () {
        this.list = new ArrayList<>();
    }

    public int parser(int p,ArrayList<Token> tokens) {
        list.add(tokens.get(p));
        p++;
        BlockItem blockItem;
        while (!tokens.get(p).getCate().equals(Cate.RBRACE)) {
            //System.out.println(p); //28
            blockItem = new BlockItem();
            p = blockItem.parser(p,tokens);
            list.add(blockItem);
        }
        list.add(tokens.get(p));
        p++;
        return p;
    }

    public void Print() throws IOException {
        for (Father object : list) {
            if (object instanceof Token) {
                Token token = (Token) object;
                token.Print();
            } else if (object instanceof BlockItem) {
                BlockItem blockItem = (BlockItem) object;
                blockItem.Print();
            }
        }
        FileWriter fileWriter = new FileWriter("parser.txt", true);
        BufferedWriter bufferedWriter = new BufferedWriter(fileWriter);
        bufferedWriter.write('<' + "Block" + '>' + '\n');
        bufferedWriter.flush();
        bufferedWriter.close();
    }
}
