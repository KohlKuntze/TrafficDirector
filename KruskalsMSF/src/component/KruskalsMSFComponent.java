package component;

import model.Edge;
import model.Graph;
import model.Node;
import model.UnionFind;
import util.GraphUtilities;
import util.UnionFindUtilities;

import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Set;

public class KruskalsMSFComponent {

    private final Graph graph;
    private final List<Node> unionFind;

    public KruskalsMSFComponent(Graph graph) {
        this.graph = graph;
        this.unionFind = new ArrayList<>();
    }

    public void findKruskalsMSF() {
        Set<Node> nodeSet = GraphUtilities.getVertices(graph);

        for(Node node : nodeSet) {
            //UnionFindUtilities.makeSet(node);
            unionFind.add(node);
        }

        PriorityQueue<Edge> edgePriorityQueue = GraphUtilities.getEdgePriorityQueue(graph);

        while(edgePriorityQueue.size() > 0 && unionFind.size() > 1) {
            Edge currentEdge = edgePriorityQueue.poll();
            Node source = null;
            Node destination = null;

            for(Node node : unionFind) {
                if(node.equals(currentEdge.getSourceVertex())) {
                    source = node;
                } else if(node.equals(currentEdge.getDestinationVertex())) {
                    destination = node;
                }
            }

            if(!source.getHead().equals(destination.getHead())) {
                System.out.println(currentEdge.getSourceVertex().getNodeId() + ", "
                        + currentEdge.getDestinationVertex().getNodeId() + ":"
                        + currentEdge.getWeight());

                UnionFindUtilities.weightedUnion(source, destination);
            }
        }
    }
}
