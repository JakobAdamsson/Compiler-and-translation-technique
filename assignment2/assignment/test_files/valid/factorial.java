public class Factorial{
    public static void main(String[] a){
	System.out.println(new Fac().ComputeFac(10));
    }
}

class Fac {
	int y;
    public int ComputeFac(int num){
	int num_aux ;
	int x;
	if (num < 1)
	{
		hej = 10;
	    num_aux = 1 ;
		x = 5;
		
	}
	else 
	    num_aux = num * (this.ComputeFac(num-1)) ;
	return num_aux ;
    }

}
