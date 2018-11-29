
import junit.framework.TestCase;

//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!

public class UrlValidatorTest extends TestCase {

	public UrlValidatorTest(String testName) {
		super(testName);
	}

	public void testManualTest() {
//You can use this function to implement your manual testing	   
		UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		assertTrue(urlVal.isValid("http://www.google.com"));
		assertTrue(urlVal.isValid("https://www.google.com/"));
		assertFalse(urlVal.isValid("http://www.google.com../"));
		assertTrue(urlVal.isValid("http://209.191.122.70/"));
		assertFalse(urlVal.isValid("http://256.191.122.70/"));
//		assertTrue(urlVal.isValid("https://stackoverflow.com/questions/1547899/which-characters-make-a-url-invalid"));
	}

	public void testYourFirstPartition() {
		// You can use this function to implement your First Partition testing

	}

	public void testYourSecondPartition() {
		// You can use this function to implement your Second Partition testing

	}
	// You need to create more test cases for your Partitions if you need to

	public void testIsValid() {
		// You can use this function for programming based testing

	}

}
