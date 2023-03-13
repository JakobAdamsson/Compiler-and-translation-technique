public class Factorial{
    public static void main(String[] a){
	System.out.println(new Fac().Insert(1));
    }
}

class Fac {
public boolean Insert(int v_key){
		Tree new_node ;
		new_node = new Tree();

		boolean ntb ;
		ntb = new_node.Init(v_key) ;

		boolean cont ;
		cont = true ;

		int key_aux ;
		Tree current_node ;
		current_node = this ;
		
		while (cont){
			key_aux = current_node.GetKey();
			if (v_key < key_aux){
				if (current_node.GetHas_Left())
					current_node = current_node.GetLeft() ;
				else {
					cont = false ;
					ntb = current_node.SetHas_Left(true);
					ntb = current_node.SetLeft(new_node);
				}
			}
			else{
				if (current_node.GetHas_Right())
					current_node = current_node.GetRight() ;
				else {
					cont = false ;
					ntb = current_node.SetHas_Right(true);
					ntb = current_node.SetRight(new_node);
				}
			}
		}
		return true ;
    }


}


