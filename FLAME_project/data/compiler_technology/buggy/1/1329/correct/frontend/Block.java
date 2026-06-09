package frontend;
import java.util.ArrayList;

public class Block {
    // '{' { BlockItem } '}'
    private ArrayList<Word> words = new ArrayList<>();
    private ArrayList<BlockItem> blockItems = new ArrayList<>();

    public Block() {}

    public void addWord(Word word) {
        words.add(word);
    }

    public void addBlockItem(BlockItem blockItem) {
        blockItems.add(blockItem);
    }

    public String toString() {
        StringBuilder sb = new StringBuilder();
        int pos = 0;
        sb.append(words.get(pos).getLeiBie()).append(" ").append(words.get(pos++).getStr()).append("\n");
        for (BlockItem it : blockItems) {
            sb.append(it.toString());
        }
        sb.append(words.get(pos).getLeiBie()).append(" ").append(words.get(pos).getStr()).append("\n");
        sb.append("<Block>");
        sb.append("\n");
        return sb.toString();
    }
}
