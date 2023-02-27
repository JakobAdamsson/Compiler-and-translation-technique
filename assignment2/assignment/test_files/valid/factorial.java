public class Factorial{
    public static void main(String[] a){
	System.out.println(new Fac().ComputeFac(10,5));
    }
}

class Fac {
	int x;
    public int ComputeFac(int num,int hej){
	int num_aux ;
	if (num < 1) 
	{
	    num_aux = 1 ;
		if (num_aux == 1)
		{
			num_aux = 2;
			hej = 5;
		}
	}
	else 
	    num_aux = num * (this.ComputeFac(num-1,2)) ;
	return num_aux ;
    }

}
