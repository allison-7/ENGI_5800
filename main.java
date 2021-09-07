import java.io.*;
//import java.util.Arrays;

public class main {
	public static void processData(String data) {
		String[] dataValues = data.split(",");//Parse the string
		//Convert from string
		double power = Double.parseDouble(dataValues[0]);
		int light = Integer.parseInt(dataValues[1]);
		uploadData(power,light);
	}
	public static void uploadData(double power, int light) {
		ApiClient api = new ApiClient("A1E-cbef9c616018117d306c6ca8f4d7370e116d"); //Initialize client
		//Initialize variables
		Variable powerVariable = api.getVariable("5aabba8fc03f9773096de022");
		Variable lightVariable = api.getVariable("5ab42326c03f971bde5c4ce6");
		powerVariable.saveValue(power);
		lightVariable.saveValue(light);
	}
	public static void main(String[] args) {
		BufferedReader br = null;
		FileReader fr = null;
		String FILENAME="dataFile.txt";
		try {
			fr = new FileReader(FILENAME);
			br = new BufferedReader(fr);
		    String line = null;
		    //while ((line = br.readLine()) != null) {
		    line = br.readLine();    
		    processData(line);
		    //}
		} catch (IOException x) {
		    System.err.format("IOException: %s%n", x);
		} finally {

		try {

			if (br != null)
				br.close();

			if (fr != null)
				fr.close();

		} catch (IOException ex) {

			ex.printStackTrace();

		}
	}

	}
}
