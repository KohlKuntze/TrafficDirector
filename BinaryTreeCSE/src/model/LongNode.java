package model;

public class LongNode {

    private LongNode parent;
    private LongNode left;
    private LongNode right;
    private boolean isSumEven;
    private final long key;

    public Node(long nodeValue) {
        isSumEven = false;
        key = nodeValue;
    }

    public void setParent(LongNode parentNode) {
        parent = parentNode;
    }

    public void setLeft(LongNode leftNode) {
        left = leftNode;
    }

    public void setRight(LongNode rightNode) {
        right = rightNode;
    }

    public boolean changeIsSumEven() {
        isSumEven = !isSumEven;
    }

    public LongNode getParent() {
        return parent;
    }

    public LongNode getLeft() {
        return left;
    }

    public LongNode getRight() {
        return right;
    }

    public boolean getIsSumEven() {
        return isSumEven;
    }

    public long getKey() {
        return key;
    }

}
