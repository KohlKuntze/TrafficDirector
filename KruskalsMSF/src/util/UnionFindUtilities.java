package util;

import model.Node;
import model.UnionFind;

import java.util.List;

public class UnionFindUtilities {

    public static void addVertexToUnionFind(UnionFind unionFind, Node node) {
        List<Node> nodeList = unionFind.getNodeList();
        if(!nodeList.contains(node)) {
            nodeList.add(node);
        }
    }

    public static void makeSet(Node node) {
        node.setHead(node);
        node.setTail(node);
        node.setNext(null);
    }

    public static void weightedUnion(Node xNode, Node yNode) {
        Node xPrime = xNode.getHead();
        Node yPrime = yNode.getHead();

        if(xPrime.equals(yPrime)) return;

        if(xPrime.getLength() >= yPrime.getLength()) {
            xPrime.getTail().setNext(yPrime);
            Node wNode = yPrime;

            while(wNode != null) {
                wNode.setHead(xPrime);
                wNode = wNode.getNext();
            }

            int xPrimeLength = xPrime.getLength();
            int yPrimeLength = yPrime.getLength();

            xPrime.setLength(xPrimeLength + yPrimeLength);
            xPrime.setTail(yPrime.getTail());
        } else {
           weightedUnion(yNode, xNode);
        }
    }
}
