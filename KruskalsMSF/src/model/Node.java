package model;

public class Node implements Comparable<Node> {

    private final String nodeId;
    private Node head;
    private Node tail;
    private Node next;
    private int length;

    public Node(String nodeId) {
        this.nodeId = nodeId;
        head = this;
        tail = this;
        next = null;
        this.length = 1;
    }

    public String getNodeId() {
        return nodeId;
    }

    public Node getHead() {
        return head;
    }

    public Node getTail() {
        return tail;
    }

    public Node getNext() {
        return next;
    }

    public int getLength() {
        return length;
    }

    public void setHead(Node newHead) {
        head = newHead;
    }

    public void setTail(Node newTail) {
        tail = newTail;
    }

    public void setNext(Node newNext) {
        next = newNext;
    }

    public void setLength(int newLength) {
        length = newLength;
    }

    @Override
    public int compareTo(Node o) {
        return nodeId.compareTo(o.getNodeId());
    }


    @Override
    public boolean equals(Object o) {
        if(this == o) return true;
        Node oNode = (Node) o;
        return nodeId.equals(oNode.getNodeId());
    }

    @Override
    public int hashCode() {
        return nodeId.hashCode();
    }

}
