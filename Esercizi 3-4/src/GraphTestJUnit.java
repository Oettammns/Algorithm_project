import java.util.*;
import static org.junit.Assert.*;
import org.junit.*;

public class GraphTestJUnit{

  Graph<Integer> grafo;
  Kruskal<Integer> kruskal;

  @Before
  public void initializeClass() {
    grafo = new Graph<>();
    grafo.biDirectional = true;
    grafo.addVertex(21);
    grafo.addVertex(7);
    grafo.addVertex(34);
    grafo.addVertex(55);
    grafo.addVertex(8);
    

    grafo.addEdge(21, 7, 5.0);
    grafo.addEdge(8, 55, 6.0);
    grafo.addEdge(21, 8, 2.0);
    grafo.addEdge(34, 55, 5.0);
    grafo.addEdge(55, 21, 1.0);
    
  }

  @Test
  public void IsDirect() {
    assertTrue(grafo.isDirect());
  }
  
  @Test
  public void RemoveNode() {
    assertTrue(grafo.DeleteNode(7));
  }
  
  @Test
  public void RemoveEdge() {
    assertTrue(grafo.removeEdge(34, 55));
  }
  public void HasVertex(){
    assertTrue(grafo.hasVertex(7));
  }
  
  @Test
  public void Kruskal() {
    kruskal = new Kruskal<>(grafo.getNodes(), grafo.getEdges());
    kruskal.calcResults();
    
    assertEquals(8.0, kruskal.getResultWeight(), 0.0);
  }

}
