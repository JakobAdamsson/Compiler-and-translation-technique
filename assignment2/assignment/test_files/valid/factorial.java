public class Factorial{
    public static void main(String[] a){
	System.out.println(new Fac().ComputeFac(5,5,2,1));
    }
}

class Fac {
    public int ComputeFac(int Walla, int x,int a, int b){
	int num_aux ;
	int hej;
	boolean hej2;
	num_aux = 23-5*10/(10-9);
	int sum;
	if (num < 1)
	{
		hej2 = 1+3;
		hej = false;
	    num_aux = 1 ;
	}
	else 
	    num_aux = Walla * this.ComputeFac(23-5*10/(10-9), num_aux,5,1);
	return num_aux ;
    }

}

