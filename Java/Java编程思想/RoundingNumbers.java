//: operators/RoundingNumbers.java
// What happens when you round a float
// or double to an integral value

public class RoundingNumbers{
	public static void main(String[] args){
		double above = 0.7, below = 0.4;
		float fabove = 0.7f, fbelow = 0.4f;
		System.out.println("round above: " + Math.round(above));
		System.out.println("round below: " + Math.round(below));
		System.out.println("round fabove: " + Math.round(fabove));
		System.out.println("round fbelow: " + Math.round(fbelow));
	}
}/* Output
(int) above: 1
(int) below: 0
(int) fabove: 1
(int) fbelow: 0
*///:~
