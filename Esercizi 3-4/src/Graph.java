import java.io.*;
import java.util.*;

public class Graph<T>{
    //creiamo un grafo usando map e tipi Disjoint ed un'altra mappa con il disjoint destinatario ed il peso
    private Map<Disjoint<T>, Map<Disjoint<T>, Double>> graph;
    protected UnionFind<T> unionFind=new UnionFind<>();
    boolean biDirectional = false;
    int totalVertices = 0;
    int i=0;
    
    //costruttore
    public Graph(){
    	this.graph = new HashMap<>();
    }
    
    //controlliamo se non è già presente (il controllo viene fatto sia sul mittente che sul destinatario
    //in tal caso lo aggiungiamo ed incrementiamo il numero di vertici
    public void addEdge(T source, T destination, Double km){
        Disjoint<T> dsource=new Disjoint<>(source,km);
        Disjoint<T> ddestination=new Disjoint<>(destination,km);
        
        if (!graph.containsKey(dsource)) { 
            addVertex(source);
            totalVertices+=1;
            unionFind.makeSet(source,km);
        }

        if (!graph.containsKey(ddestination)) { 
            addVertex(destination);
            totalVertices+=1;
            unionFind.makeSet(destination,km);
        }
        
        //prendiamo il nodo sorgente e ci aggiungiamo la destinazione, get e put sono metodi forniti da map 
        graph.get(dsource).put(ddestination, km);
        
     
    }
    //stampiamo il contenuto di union find
    public void print(){
        unionFind.scorri();
       
    }

     /*
     	Questo metodo verifica se il grafo è diretto
     */
     public boolean isDirect(){
    	return true;
     }
     
    /*
        cancella uno specifico nodo ritorna true o false passando un nodo Disjoint<T> 
        CONTROLLARE SE E' GIUSTO
     */
     public boolean DeleteNode(T node){
     	Disjoint<T> dnode=new Disjoint<>(node,0.0);
        if(dnode == null || dnode.getData() == null) return false;
        for (Map.Entry<Disjoint<T>, Map<Disjoint<T>, Double>> nodeg : graph.entrySet()) {
            if (nodeg.getKey().equals(dnode)){           
                continue;
            }
            nodeg.getValue().remove(dnode);
        }
        return graph.remove(dnode) != null;
     }
     /*
     	cancella l'arco utilizzando remove fornito da map, quindi scollegandolo dalla source
        
    */
     public boolean removeEdge(T source, T destination) {
        Disjoint<T> dsource=new Disjoint<>(source,0.0);
        Disjoint<T> ddestination=new Disjoint<>(destination,0.0);

        if(dsource == null || dsource.getData() == null) return false;
        if(ddestination == null || ddestination.getData() == null) return false;

        if (graph.containsKey(dsource)) return graph.get(dsource).remove(ddestination) != null;
         return false;

     }
  	
    /*
        questo metodo controlla se è presente il vertice passato per parametro
        containskey è fornito da map
    */

    public boolean hasVertex(T vertex) {
        if(graph.containsKey(vertex)) {
            return true;
        }
        return false;
        
    }

    /*
        questo metodo controlla se l'arco esiste
    */

    public boolean hasEdge(Disjoint<T> source, Disjoint<T> destination) {
        if(graph.get(source).containsValue(destination.getData())) {
            return true;            
        }
        return false;
    }

    /*
        aggiunge un vertice al graph con put
    */
    public void addVertex(T vertex) {
        Disjoint<T> dvertex= new Disjoint<>(vertex,0.0);
        graph.put(dvertex, new HashMap<Disjoint<T>, Double>());
    }
    /**
   * ritorna una lista di nodi
   *
   * @return
   */
   public List<Disjoint<T>> getNodes() {
    if (graph.size() == 0)
      return null;
    List<Disjoint<T>> nodes = new ArrayList<>(graph.keySet());
    return nodes;
   } 


   /**
   * ritorna una lista di archi
   * @return
   */
   public List<Edge<T>> getEdges() {
    if (graph.size() == 0)
      return null;
    
    //utilizziamo Treeset ed un Array
    Set<Edge<T>> EdgeS = new TreeSet<>();
    ArrayList<Edge<T>> EdgeSet = new ArrayList<>();

    //entrySet serve per ottenere un set di elementi(view) da graph, possiamo scorrerlo
    for (Map.Entry<Disjoint<T>, Map<Disjoint<T>, Double>> node : graph.entrySet()) {
      for (Map.Entry<Disjoint<T>, Double> edge : node.getValue().entrySet()) {
        //lo aggiungiamo in EdgeS, che è di tipo Set, che ci serve per poter sfruttare la TreeSet
        EdgeS.add(new Edge<>(node.getKey(), edge.getKey(), edge.getValue()));
      }
    }
    //dopo aver riempito EdgeS, usiamo addAll per riempire EdgeSet 
    EdgeSet.addAll(EdgeS);
    //quindi ritorniamo la lista EdgeSet
    return EdgeSet;
  }
    
    /* stampa il numero di vertici */
    public int countVertices(){
	   return totalVertices;   
    } 
    
    /* dimensione del grafo */
    public int size(){
        return graph.size();
    }
}
