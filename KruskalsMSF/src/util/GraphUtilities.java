package util;

import model.Edge;
import model.Graph;
import model.Node;

import java.util.*;

public class GraphUtilities {

    public static void addEdge(Graph graph, Edge edge) {
        Map<Node, Set<Edge>> edgeMap = graph.getEdgeMap();

        Node sourceVertex = edge.getSourceVertex();
        Node destinationVertex = edge.getDestinationVertex();

        if(!edgeMap.keySet().contains(sourceVertex)) {
            edgeMap.put(sourceVertex, new HashSet<Edge>());
        }

        if(!edgeMap.keySet().contains(destinationVertex)) {
            edgeMap.put(destinationVertex, new HashSet<Edge>());
        }

        edgeMap.get(sourceVertex).add(edge);
    }

    public static Set<Node> getVertices(Graph graph) {
        return graph.getEdgeMap().keySet();
    }

    public static PriorityQueue<Edge> getEdgePriorityQueue(Graph graph) {
        PriorityQueue<Edge> edgePriorityQueue = new PriorityQueue<>();

        Map<Node, Set<Edge>> edgeMap = graph.getEdgeMap();

        Set<Node> graphNodes = edgeMap.keySet();

        for(Node node : graphNodes) {
            Set<Edge> edgeSet = edgeMap.get(node);

            for(Edge edge : edgeSet) {
                edgePriorityQueue.offer(edge);
            }
        }

        return edgePriorityQueue;
    }
}
