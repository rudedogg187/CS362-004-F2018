
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

		// Test only valid input
		
		UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		assertTrue(urlVal.isValid("http://www.amazon.co.uk/"));
		assertTrue(urlVal.isValid("https://www.bbc.com"));											// FAILS
		assertTrue(urlVal.isValid("http://developer.mozilla.org"));
		assertTrue(urlVal.isValid("http://devast.io/"));
		assertTrue(urlVal.isValid("http://foo.com/blah_blah/"));
		assertTrue(urlVal.isValid("http://foo.com/blah_blah_(wikipedia)"));
		assertTrue(urlVal.isValid("http://foo.com/PICTUREINALLCAPS.jpeg"));
		assertTrue(urlVal.isValid("http://www.example.com/wpstyle/?p=364"));
		assertTrue(urlVal.isValid("http://www.example.com/wpstyle/?p=364$_'*"));
		assertTrue(urlVal.isValid("http://142.42.1.1/"));
		assertTrue(urlVal.isValid("http://142.42.1.1:8080/"));
		assertTrue(urlVal.isValid("http://code.google.com/events/#&product=browser"));
		assertTrue(urlVal.isValid("https://foo_bar.example.com/"));	      
		assertTrue(urlVal.isValid("file:///D:/CS362/Week02/Lesson6Coverage.pdf")); 
	}

	public void testYourSecondPartition() {
	// You can use this function to implement your Second Partition testing

		// Test only invalid input

		UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		assertFalse(urlVal.isValid("http://"));
		assertFalse(urlVal.isValid("www.amazon.co.uk/"));
		assertFalse(urlVal.isValid("http:\\www.amazon.co.uk"));
		assertFalse(urlVal.isValid("http://foo.bar?q=Spaces should be encoded"));
		assertFalse(urlVal.isValid("http://foo.bar?q=[]"));
		assertFalse(urlVal.isValid("http:// shouldfail.com"));	   
		assertFalse(urlVal.isValid("http://.www.foo.bar/"));
		assertFalse(urlVal.isValid("http://1.1.254"));	   
		assertFalse(urlVal.isValid("http://0.0.0.0/"));
		assertFalse(urlVal.isValid("http://300.500.300.500"));
		assertFalse(urlVal.isValid("file///D:/CS362/Week02/Lesson6Coverage.pdf")); 
		assertFalse(urlVal.isValid("D:/CS362/Week02/Lesson6Coverage.pdf"));

	}
	// You need to create more test cases for your Partitions if you need to

	public void testIsValid() {
		// You can use this function for programming based testing

	}

}
