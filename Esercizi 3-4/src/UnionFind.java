import java.util.*;

class UnionFind<T> {
  
  int archi[] = null;
  List<T> array = new ArrayList<>();
  Disjoint<T> first= new Disjoint<T>(null,0.0);
  Disjoint<T> second= new Disjoint<T>(null,0.0);
  /**
   * 
   *
   * @param source Source SET for the class
   * @return
   * 
   * 
   * aggiungiamo source nell'array dei vertici 
   */
  public void makeSet(T value, double km){
    /*Disjoint<T> dis*/
    //first = new Disjoint<>(value,km);
    array.add(value);
    archi = new int[array.size()];
    //creiamo un array che rappresentano le città in ordine sfruttando gli interi per definire 
    //nel makeset che prima di ogni union le città sono parent di se stesse
    for(int i=0; i < array.size(); i++){
        archi[i] = i;
    }
    
  }
  //semplice stampa delle città dell'array
  public void scorri(){
    //scorro l'ArrayList
    for(int i=0; i<array.size(); i++){
      System.out.println("nodo : "+array.get(i));
    }
  }
  
  /**
   * ritorna true se la union è andata a buon fine
   * 
   *
   * @param src
   * @param dest
   * @param km
   */
  public boolean union(T src, T dest,double km) {

    if (src == null)
      return false;
    if (dest == null)
      return false;

    int srcIndex=0;
    int destIndex=0;

    srcIndex = array.indexOf(find(src));
    destIndex = array.indexOf(find(dest));
    // se sono già uniti non fa niente
    if(srcIndex == destIndex){
        return false;
    }
    //altrimenti aggiorniamo l'indice del destinatario mettendo il padre
    archi[destIndex] = archi[srcIndex];

    return true;
  } 
  /**
   * ritorna l'indirizzo di value usando la path compression
   *
   * @param value
   * @return
   */
  public T find(T value) {
    int pos=0;
     
      if (value == null){
        return null;
      }
      //memorizziamo la posizione di value all'interno dell'array di vertici
      pos=array.indexOf(value);
    //facciamo la path compression, dove l'altezza dell'albero se è maggiore di 1
    //i figli vengono messi tutti allo stesso livello
     while (pos != archi[pos]) {
      archi[pos] = archi[archi[pos]]; 
      pos = archi[pos];
    }
      return array.get(pos);
    }

  /**
   * Stampa
   */
  public void printSet() {
    int vertexSize = array.size();
    for (int x = 0; x < vertexSize; x++) {
      System.out.println(array.get(x).toString() + " ---> " + array.get(archi[x]).toString());
    }
  } // printSet
} // class
