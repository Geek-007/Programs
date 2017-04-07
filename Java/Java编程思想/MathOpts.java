//: operators/MathOpts.java
// Demonstrates the mathematical operators
import java.util.*;

public class MathOpts{
	public static void main(String[] args){
		// Create a seeded random number generator:
		Random rand = new Random(47);
		int i, j, k;
		// Choose value from 1 to 100:
		j = rand.nextInt(100) + 1;
		System.out.println("j: " + j);
		k = rand.nextInt(100) + 1;
		System.out.println("k: " + k);
		i = j + k;
		System.out.println("j + k: " + i);
		i = j - k;
		System.out.println("j - k: " + i);
		i = k / j;
		System.out.println("j / k: " + i);
		i = k * j;
		System.out.println("j * k: " + i);
		i = k % j;
		System.out.println("j % k: " + i);
		j %= k;
		System.out.println("j %= k: " + j);
		// Floating-pont number tests:
		float u, v, w; // Applies to doubles, too
		v = rand.nextFloat();
		System.out.println("v: " + v);
		w = rand.nextFloat();
		System.out.println("w: " + w);
		u = v + w;
		System.out.println("v + w: " + u);
		u = v - w;
		System.out.println("v - w: " + u);
		u = v * w;
		System.out.println("v * w: " + u);
		u = v / w;
		System.out.println("v / w: " + u);
		// The following also works for char
		// byte, short, int, long and double
		u += v;
		System.out.println("u += v: " + u);
		u -= v;
		System.out.println("u -= v: " + u);
		u *= v;
		System.out.println("u *= v: " + u);
		u /= v;
		System.out.println("u /= v: " + u);
	}
}/* Output
j: 59
k: 56
j + k: 115
j - k: 3
j / k: 0
j * k: 3304
j % k: 56
j %= k: 3
v: 0.5309454
w: 0.0534122
v + w: 0.5843576
v - w: 0.47753322
v * w: 0.028358962
v / w: 9.940527
u += v: 10.471473
u -= v: 9.940527
u *= v: 5.2778773
u /= v: 9.940527
*///:~
