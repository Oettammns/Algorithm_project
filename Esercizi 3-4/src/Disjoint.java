import java.util.*;
 
class Disjoint<T>{

	T data;
	T parent;
	double weight;
	Disjoint next;
	//costruttore
	public Disjoint(T data){
		this.data = data;
		this.parent = data;
	}
	//costruttore
	public Disjoint(T data,double weight){
		this.data = data;
		this.weight=weight;

	}
	//stampa data
	public T getData(){
		return this.data;
	}
	//modifica data
	public void setData(T data){
		this.data=data;
	}
	//stampa peso
	public double getWeight(){
		return this.weight;
	}
	
	@Override
	 public int hashCode(){
	    return 50 * data.hashCode();
	}
	/**
   	* controlla se gli oggetti sono uguali
	   *
	   * @param o
	   * @return
	   */
	  @Override
	
	  public boolean equals(Object o) {
    	
        if (this == o) return true; 
        if (o == null || getClass() != o.getClass()) return false;
        Disjoint that = (Disjoint) o;
        
        return data.equals(that.data);
    	} //equals
	/*
		Metodo toString()
	*/
	
	@Override
  	public String toString(){
    		return "Node{Value: " + data.toString() +" weight "+ weight +"}";
  	} //toString
}
