
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

   //****** PROGRAMMING BASED TESTING START ******
   public void testUrlPart(String urlPart, String status, boolean loudTest, boolean assertTest) { 
	   //url validation object
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   //string to hold url to test
	   String url;
	   //string array to hold multiple urls
	   String[] urls;
	   //bool to catch url result;
	   boolean isValid;
	   //string to hold success message used in loud tests
	   String successMessage;
	   //string to hold fail message used in loud tests
	   String failMessage;
	   
	   //string array to hold valid url schemes to test
	   String[] validScheme = {
		"http://", 
		"https://",
		"ftp://", 
		"h3t://"
	   };
	   //string array to hold invalid url schemes to test
	   String[] invalidScheme = {
			   "3ht://",
               "http:/",
               "http:",
               "http/",
               "://",
               ""  
	   };
	   //string array to hold valid url auths to test
	   String[] validAuthority = {
		"www.google.com",
		"test.org",
		"test.net",
               	"oregonstate.edu",
               	"test.au",
               	"0.0.0.0",
               	"255.255.255.255",
               	"nsa.gov"
	   };
	   //string array to hold invalid url auths to test
	   String[] invalidAuthority = {
		"256.256.256.256",
              	"1.2.3.4.5", 
             	"1.2.3.4.", 
              	"1.2.3",
              	".1.2.3.4",
              	"oregon.a",
              	"state.os",
              	"osu.osu1",
              	"osu.",
              	".osu",
              	"osu",
              	"" 
	   };
	   //string array to hold valid url port numbers to test
	   String[] validPort = {
		":80",
              	":65535",
              	":0",
              	":8000",
              	""
	   };
	   //string array to hold invalid url port numbers to test
	   String[] invalidPort = {
		":65636",
              	":ac",
               	":-80"
	   };
	   //string array to hold valid url paths to test
	   String[] validPath = {
		"/unittest", 
               	"/unittest2", 
               	"/unittest3$", 
               	"/unittest4/", 
               	"", 
               	"/unit/test",
	   };
	   //string array to hold invalid url paths to test
	   String[] invalidPath = {
		"/..",
         	"/../",    
         	"/..//file",
         	"/test1//file"
	   };
	   //string array to hold valid query strings to test
	   String[] validQuery = {
		"?course=cs362",
               	"?school=osu&state=41",
               	"" 
	   };
	   //string array to hold invalid query strings to test
	   String[] invalidQuery = {
		//"!course-cs362",
               	//"!school=osu&state=41",
		"//////////"
			   
	   };
	   
	   //call buildUrls() to obtain all valid urls
	   urls = buildUrls(validScheme, validAuthority, validPort, validPath, validQuery);
	   //if function parameter status indicates to test an invalid url part, enter this switch statement
	   if(status == "invalid") {
		   //test which url part is to be set with invalid data
		   switch(urlPart) {
		   		case "scheme":
		   			//call buildUrls() to obtain urls with invalid scheme
		   			urls = buildUrls(invalidScheme, validAuthority, validPort, validPath, validQuery);
		   			break;
		   		case "authority":
		   			//call buildUrls() to obtain urls with invalid authority
		   			urls = buildUrls(validScheme, invalidAuthority, validPort, validPath, validQuery);
		   			break;
		   		case "port":
		   			//call buildUrls() to obtain urls with invalid port number
		   			urls = buildUrls(validScheme, validAuthority, invalidPort, validPath, validQuery);
		   			break;
		   		case "path":
		   			//call buildUrls() to obtain urls with invalid path
		   			urls = buildUrls(validScheme, validAuthority, validPort, invalidPath, validQuery);	
		   			break;
		   		case "query":
		   			//call buildUrls() to obtain urls with invalid query string
		   			urls = buildUrls(validScheme, validAuthority, validPort, validPath, invalidQuery);
		   			break;
		   		case "all":
		   			//call buildUrls() to obtain urls with all parts invalid
		   			urls = buildUrls(invalidScheme, invalidAuthority, invalidPort, invalidPath, invalidQuery);
		   			break;
		   }
	   } 
	   //loop through array of test urls
	   for(int i = 0; i < urls.length; i++) {
		   //save url at current index to string variable
		   url = urls[i];
		   //save result of url validation test to bool var
		   isValid = urlVal.isValid(url);
		   
		   successMessage = new StringBuilder(14)
				.append(urlPart)
				.append(" Success\n URL Tested: ")
				.append(url)
				.append("\n Validator returned: ")
				.append(isValid)
				.append(" \n Expected Result: ")
				.append(isValid)
				.append("\n") 
				.toString();
		   
		   failMessage = new StringBuilder(14)
				.append(urlPart)
				.append(" Failure\n URL Tested: ")
				.append(url)
				.append("\n Validator returned: ")
				.append(isValid)
				.append(" \n Expected Result: ")
				.append(!isValid)
				.append("\n") 
				.toString();
		   
		   //if loudTest flag is set, print validator result to console
		   if(loudTest) {
			   //if result and expected resutl do not match
			   if((status == "invalid" && isValid) || (status != "invalid" && !(isValid))) {
				   //print fail message
				   System.out.println(failMessage);
			   } 
			   //if result and expected result match
			   else {
				   //print success message
				   //System.out.println(successMessage);
			   }
			   
		   }
		   
		   // if assertTest flag is set, use assert to test validator result
		   if(assertTest) {
			   //if function parameter status indicates to test an invalid url
			   if(status == "invalid") {
				   //assert the the url validator will return false	   
				   assertFalse(isValid);
			   } else {
				   //otherwise, assert the url validator will return true
				   assertTrue(isValid);
			   }
		   }
	   }
   }
   
   public String[] buildUrls(String[] schemes, String[] auths, String[] ports, String[] paths, String[] queries) {
	   //var to hold size of url array - this is size of all combinations of url part arrays
	   int size = schemes.length * auths.length * ports.length * paths.length * queries.length;
	   
	   int i = 0;
	   //string array to hold all combinations of url parts
	   String[] urls = new String[size];
	   //string to hold scheme for each iteration of nested loop
	   String scheme;
	   //string to hold authority for each iteration of nested loop
	   String auth;
	   //string to hold port number for each iteration of nested loop
	   String port;
	   //string to hold path for each iteration of nested loop
	   String path;
	   //string to hold query string for each iteration of nested loop
	   String query;
	   //string to hold url for each iteration of nested loop
	   String url;
	
	   
	   //iterate through all schemes in scheme array
	   for(int a = 0; a < schemes.length; a++) {
		   	//save scheme at current index to a var
	   		scheme = schemes[a];
	   		
	   		//iterate through all authorities in the authority array
	   		for(int b = 0; b < auths.length; b++) {
	   			//save authority at current index to a var
	   			auth = auths[b];
	   			
	   			//iterate through all port numbers in the port number array
	   			for(int c = 0; c < ports.length; c++) {
	   				//save port number at current index to a var
	   				port = ports[c];
	   				//port = "";
	   				
	   				//iterate through all paths in path array
	   				for(int d = 0; d < paths.length; d++) {
	   					//save path at current index to a var
	   					path = paths[d];
	   					//path = "";
	   					
	   					//iterate through all query strings in query string array
	   					for(int e = 0; e < queries.length; e++) {
	   						//save query string at current index to a var
	   						query = queries[e];
	   						
	   						//build the url with all the url parts of current iteration, save to var
				   			url = new StringBuilder(14)
				   				.append(scheme)
				   				.append(auth)
				   				.append(port)
				   				.append(path)
				   				.append(query)
				   				.toString();
				   			
				   			//insert url int url array
				   			urls[i++] = url;
	   					}
	   				}
	   			}	
	   		}
	   }	
	   
	   //return url array
	   return urls;
   }
   
   public void testIsValid()
   {
	   //You can use this function for programming based testing
	   System.out.println("** testIsValid() **");
	      
	   //bool flag to print test results to console
	   boolean loudTest = true;
	   //bool flag to use assert to test results - when true, if assert dosen't pass, program will stop
	   boolean assertTest = true;
	   
	   //test urls with all parts invalid
	   testUrlPart("all", "invalid", loudTest, assertTest);
	   
	   //test urls with all parts valid
	   testUrlPart("all", "valid", loudTest, assertTest);
	   
	   //test urls with an invalid scheme and with all other parts valid
	   testUrlPart("scheme", "invalid", loudTest, assertTest);
	   
	   //test urls with an invalid authority and with all other parts valid
	   testUrlPart("authority", "invalid", loudTest, assertTest);
	   
	   //test urls with an invalid port number and with all other parts valid
	   testUrlPart("port", "invalid", loudTest, assertTest);
	   
	   //test urls with an invalid path and with all other parts valid
	   testUrlPart("path", "invalid", loudTest, assertTest);
	   
	   //test urls with an invalid query string and with all other parts valid
	   testUrlPart("query", "invalid", loudTest, assertTest);
   }

   //****** PROGRAMMING BASED TESTING END ******

}
