/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		// your code goes here
		String str = "Saksham";
		char[] characters = str.toCharArray();
		int i = 0;
		int j = characters.length - 1;
		while(i < j) {
		    char temp = characters[i];
		    characters[i] = characters[j];
		    characters[j] = temp;
		    i++; j--;
		}
		for(int k=0; k<characters.length; k++) {
		    System.out.print(characters[k]);
		}
	}
}
