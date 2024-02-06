package assignment1;

import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;

public class MathsTest {
	
	Maths math;
	
	@Before
	public void setUp() throws Exception {
		math = new Maths();
	}

	@Test
	public void testAdd() {
		Assert.assertEquals("Addition failed,", 2.0, math.add(1.0, 1.0), 0.0);
		Assert.assertEquals("Addition failed,", 0.0, math.add(-1.0, 1.0), 0.0);
		Assert.assertEquals("Addition failed,", 1.0, math.add(-2.0, 3.0), 0.0);
		Assert.assertEquals("Addition failed,", -11.0, math.add(-5.0, -6.0), 0.0);
		Assert.assertEquals("Addition failed,", 7.5, math.add(4.0, 3.5), 0.0);
		
		Assert.assertNotEquals("Addition failed", 1.0, math.add(1.0, 1.0), 0.0);
		Assert.assertNotEquals("Addition failed", 2.0, math.add(-1.0, 1.0), 0.0);
		Assert.assertNotEquals("Addition failed", 5.0, math.add(-2.0, 3.0), 0.0);
		Assert.assertNotEquals("Addition failed", 11.0, math.add(-5.0, -6.0), 0.0);
		Assert.assertNotEquals("Addition failed", 7.0, math.add(4.0, 3.5), 0.0);
	}
	
	@Test
	public void testSubtract() {
		Assert.assertEquals("Subtraction failed,", 0.0, math.subtract(1.0, 1.0), 0.0);
		Assert.assertEquals("Subtraction failed,", -2.0, math.subtract(-1.0, 1.0), 0.0);
		Assert.assertEquals("Subtraction failed,", -5.0, math.subtract(-2.0, 3.0), 0.0);
		Assert.assertEquals("Subtraction failed,", 1.0, math.subtract(-5.0, -6.0), 0.0);
		Assert.assertEquals("Subtraction failed,", 0.5, math.subtract(4.0, 3.5), 0.0);
		
		Assert.assertNotEquals("Subtraction failed", 1.0, math.subtract(1.0, 1.0), 0.0);
		Assert.assertNotEquals("Subtraction failed", 0.0, math.subtract(-1.0, 1.0), 0.0);
		Assert.assertNotEquals("Subtraction failed", -1.0, math.subtract(-2.0, 3.0), 0.0);
		Assert.assertNotEquals("Subtraction failed", -1.0, math.subtract(-5.0, -6.0), 0.0);
		Assert.assertNotEquals("Subtraction failed", 1.0, math.subtract(4.0, 3.5), 0.0);
	}
	
	@Test
	public void testMultiply() {
		Assert.assertEquals("Multiplication failed,", 1.0, math.multiply(1.0, 1.0), 0.0);
		Assert.assertEquals("Multiplication failed,", -1.0, math.multiply(-1.0, 1.0), 0.0);
		Assert.assertEquals("Multiplication failed,", -6.0, math.multiply(-2.0, 3.0), 0.0);
		Assert.assertEquals("Multiplication failed,", 30.0, math.multiply(-5.0, -6.0), 0.0);
		Assert.assertEquals("Multiplication failed,", 14.0, math.multiply(4.0, 3.5), 0.0);
		
		Assert.assertNotEquals("Multiplication failed", 0.0, math.multiply(1.0, 1.0), 0.0);
		Assert.assertNotEquals("Multiplication failed", 1.0, math.multiply(-1.0, 1.0), 0.0);
		Assert.assertNotEquals("Multiplication failed", 6.0, math.multiply(-2.0, 3.0), 0.0);
		Assert.assertNotEquals("Multiplication failed", -30.0, math.multiply(-5.0, -6.0), 0.0);
		Assert.assertNotEquals("Multiplication failed", 12.0, math.multiply(4.0, 3.5), 0.0);
	}
	
	@Test
	public void testDivide() {
		Assert.assertEquals("Division failed,", 1.0, math.divide(1.0, 1.0), 0.0);
		Assert.assertEquals("Division failed,", -1.0, math.divide(-1.0, 1.0), 0.0);
		Assert.assertEquals("Division failed,", -2.0, math.divide(-4.0, 2.0), 0.0);
		Assert.assertEquals("Division failed,", 0.2, math.divide(5.0, 25.0), 0.0);
		Assert.assertEquals("Division failed,", 0.0, math.divide(0.0, 3.5), 0.0);
		
		Assert.assertNotEquals("Division failed", -1.0, math.divide(1.0, 1.0), 0.0);
		Assert.assertNotEquals("Division failed", 1.0, math.divide(-1.0, 1.0), 0.0);
		Assert.assertNotEquals("Division failed", 2.0, math.divide(-4.0, 2.0), 0.0);
		Assert.assertNotEquals("Division failed", 0.2, math.divide(-5.0, 25.0), 0.0);
		Assert.assertNotEquals("Division failed", -5.0, math.divide(15.0, 3.0), 0.0);
	}
	
	@Test
	public void testPower() {
		Assert.assertEquals("Exponentiation failed,", 1.0, math.power(1.0, 1.0), 0.0);
		Assert.assertEquals("Exponentiation failed,", -1.0, math.power(-1.0, 1.0), 0.0);
		Assert.assertEquals("Exponentiation failed,", 16.0, math.power(4.0, 2.0), 0.0);
		Assert.assertEquals("Exponentiation failed,", -3125.0, math.power(-5.0, 5.0), 0.0);
		Assert.assertEquals("Exponentiation failed,", 10.0, math.power(10.0, 1.0), 0.0);
		
		Assert.assertNotEquals("Exponentiation failed", 0.0, math.power(1.0, 1.0), 0.0);
		Assert.assertNotEquals("Exponentiation failed", 1.0, math.power(-1.0, 1.0), 0.0);
		Assert.assertNotEquals("Exponentiation failed", 8.0, math.power(4.0, 2.0), 0.0);
		Assert.assertNotEquals("Exponentiation failed", 3125.0, math.power(-5.0, 5.0), 0.0);
		Assert.assertNotEquals("Exponentiation failed", 1.0, math.power(10.0, 1.0), 0.0);
	}

}
