import java.io.*;
import java.util.*;
public class Kruskal<T>{

	/*totalEdge è il counter per quanti archi abbiamo
	abbiamo una lista di nodi, di archi*/
	int totalEdge = 0;
	private List<Disjoint<T>> nodi;
	private List<Edge<T>> archi;
	private Set<Edge<T>> resarch;
	private List<Edge<T>> resultarchi;
	private UnionFind<T> unionFind; //UnionFind
	private double resultWeight; //peso finale di tutti gli archi connessi
	
	//costruttore
	public Kruskal(Graph<T> g){
		//chiamiamo il costruttore sottostante con i parametri
		this(g.getNodes(), g.getEdges());
		this.unionFind=g.unionFind;
		
		
	}
	//n è la lista di nodi, e è la lista di archi
	public Kruskal(List<Disjoint<T>> n, List<Edge<T>> e) {
    		this.nodi = n;
    		this.archi = e;
    		this.resarch = new HashSet<>();
    		this.resultarchi=new ArrayList<>(resarch);	
    		this.resultWeight = 0.0;
    		
    		

    } 
        
    /**
     * uniamo gli archi se non hanno lo stesso padre,incrementiamo gli edge e il peso finale
   	*/
	public void calcResults() {
			
            for (Edge<T> ed : archi) {
		       if (unionFind.find(ed.getSource()) != unionFind.find(ed.getDestination())) {
				
				 resultarchi.add(ed);
				 resultWeight += ed.getWeight();
			     totalEdge+=1;
				 unionFind.union(ed.getSource(), ed.getDestination(),ed.getWeight());
			   }
		    }
		    
		   
	 } // ritorna il numero di archi
	   public int countEdges(){
    	return totalEdge;
    }
	 /**
   	* 
   	* Stampa tutti gli archi di resultEges
   	* @return
   	*/
  	public List<Edge<T>> getResultEdges() {
    		return this.resultarchi;
  	} 
	 
	 /**
   	*Stampa il peso finale della foresta
   	*
   	* @return
   	*/
  	public double getResultWeight() {
    		return this.resultWeight;
  	} 
}
