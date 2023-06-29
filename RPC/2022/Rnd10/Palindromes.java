import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Palindromes {

   public static void main(String[] args) {
      pc2Read();
   }

   public static void stringPalindrome(String morseCode) {
      StringBuilder strb = new StringBuilder(morseCode);
      String revertMorse = strb.reverse().toString();
      //System.out.printf("%s\n%s\n", morseCode, revertMorse);
      System.out.println((morseCode.equals(revertMorse)) ? "YES" : "NO");
   }

   public static void convertMorseCode(String word) {
      char[] character = word.toCharArray();
      String[] morseCodeLetters = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----." };
      String morseCode = "";

      for (int i = 0; i < character.length; i++) {
         char ch = character[i];
         String lt = String.valueOf(ch);

         if (ch >= 97) {
            if (lt.equals("a")) {
               morseCode += morseCodeLetters[0];
            } else if (lt.equals("b")) {
               morseCode += morseCodeLetters[1];
            } else if (lt.equals("c")) {
               morseCode += morseCodeLetters[2];
            } else if (lt.equals("d")) {
               morseCode += morseCodeLetters[3];
            } else if (lt.equals("e")) {
               morseCode += morseCodeLetters[4];
            } else if (lt.equals("f")) {
               morseCode += morseCodeLetters[5];
            } else if (lt.equals("g")) {
               morseCode += morseCodeLetters[6];
            } else if (lt.equals("h")) {
               morseCode += morseCodeLetters[7];
            } else if (lt.equals("i")) {
               morseCode += morseCodeLetters[8];
            } else if (lt.equals("j")) {
               morseCode += morseCodeLetters[9];
            } else if (lt.equals("k")) {
               morseCode += morseCodeLetters[10];
            } else if (lt.equals("l")) {
               morseCode += morseCodeLetters[11];
            } else if (lt.equals("m")) {
               morseCode += morseCodeLetters[12];
            } else if (lt.equals("n")) {
               morseCode += morseCodeLetters[13];
            } else if (lt.equals("o")) {
               morseCode += morseCodeLetters[14];
            } else if (lt.equals("p")) {
               morseCode += morseCodeLetters[15];
            } else if (lt.equals("q")) {
               morseCode += morseCodeLetters[16];
            } else if (lt.equals("r")) {
               morseCode += morseCodeLetters[17];
            } else if (lt.equals("s")) {
               morseCode += morseCodeLetters[18];
            } else if (lt.equals("t")) {
               morseCode += morseCodeLetters[19];
            } else if (lt.equals("u")) {
               morseCode += morseCodeLetters[20];
            } else if (lt.equals("v")) {
               morseCode += morseCodeLetters[21];
            } else if (lt.equals("w")) {
               morseCode += morseCodeLetters[22];
            } else if (lt.equals("x")) {
               morseCode += morseCodeLetters[23];
            } else if (lt.equals("y")) {
               morseCode += morseCodeLetters[24];
            } else if (lt.equals("z")) {
               morseCode += morseCodeLetters[25];
            }
         } else {
            if (lt.equals("0")) {
               morseCode += morseCodeLetters[26];
            } else if (lt.equals("1")) {
               morseCode += morseCodeLetters[27];
            } else if (lt.equals("2")) {
               morseCode += morseCodeLetters[28];
            } else if (lt.equals("3")) {
               morseCode += morseCodeLetters[29];
            } else if (lt.equals("4")) {
               morseCode += morseCodeLetters[30];
            } else if (lt.equals("5")) {
               morseCode += morseCodeLetters[31];
            } else if (lt.equals("6")) {
               morseCode += morseCodeLetters[32];
            } else if (lt.equals("7")) {
               morseCode += morseCodeLetters[33];
            } else if (lt.equals("8")) {
               morseCode += morseCodeLetters[34];
            } else if (lt.equals("9")) {
               morseCode += morseCodeLetters[35];
            }
         }
      }
      stringPalindrome(morseCode);
   }

   public static void pc2Read() {
      String vec[], line;

      BufferedReader buffer = new BufferedReader(new InputStreamReader(System.in));

      try {
         line = buffer.readLine();
         buffer.close();
         vec = line.toLowerCase().split("\\W");

         if (!line.isEmpty()) {
            line = "";
            for (int i = 0; i < vec.length; i++) {
               line += (!vec[i].equals(" ")) ? vec[i] : "";
            }
            convertMorseCode(line);
         } else {
            System.out.println("NO");
         }
      } catch (NullPointerException e) {
         e.printStackTrace();
      } catch (IOException e) {
         e.printStackTrace();
      }
   }
}