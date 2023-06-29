import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Building {

   public static void main(String[] args) {
      pc2Read();
   }

   public static void isPalindrome(String morseCode) {
      StringBuilder strb = new StringBuilder(morseCode);
      String revertMorseCode = strb.reverse().toString();
      System.out.println((morseCode.equals(revertMorseCode)) ? "YES" : "NO");
      //System.out.printf("Código Morse Original: %s\nCódigo Morse Invertido: %s\n", morseCode, revertMorseCode);
   }

   public static void convertMorseCode(String word) {
      char[] character = word.toCharArray();
      String[] charMorseCode = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..",
              "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..",
              "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----." };
      String morseCode = "";

      for (int i = 0; i < character.length; i++) {
         char ch = character[i];
         String lt = String.valueOf(ch);

         if (ch >= 97) {
            if (lt.equals("a")) {
               morseCode += charMorseCode[0];
            } else if (lt.equals("b")) {
               morseCode += charMorseCode[1];
            } else if (lt.equals("c")) {
               morseCode += charMorseCode[2];
            } else if (lt.equals("d")) {
               morseCode += charMorseCode[3];
            } else if (lt.equals("e")) {
               morseCode += charMorseCode[4];
            } else if (lt.equals("f")) {
               morseCode += charMorseCode[5];
            } else if (lt.equals("g")) {
               morseCode += charMorseCode[6];
            } else if (lt.equals("h")) {
               morseCode += charMorseCode[7];
            } else if (lt.equals("i")) {
               morseCode += charMorseCode[8];
            } else if (lt.equals("j")) {
               morseCode += charMorseCode[9];
            } else if (lt.equals("k")) {
               morseCode += charMorseCode[10];
            } else if (lt.equals("l")) {
               morseCode += charMorseCode[11];
            } else if (lt.equals("m")) {
               morseCode += charMorseCode[12];
            } else if (lt.equals("n")) {
               morseCode += charMorseCode[13];
            } else if (lt.equals("o")) {
               morseCode += charMorseCode[14];
            } else if (lt.equals("p")) {
               morseCode += charMorseCode[15];
            } else if (lt.equals("q")) {
               morseCode += charMorseCode[16];
            } else if (lt.equals("r")) {
               morseCode += charMorseCode[17];
            } else if (lt.equals("s")) {
               morseCode += charMorseCode[18];
            } else if (lt.equals("t")) {
               morseCode += charMorseCode[19];
            } else if (lt.equals("u")) {
               morseCode += charMorseCode[20];
            } else if (lt.equals("v")) {
               morseCode += charMorseCode[21];
            } else if (lt.equals("w")) {
               morseCode += charMorseCode[22];
            } else if (lt.equals("x")) {
               morseCode += charMorseCode[23];
            } else if (lt.equals("y")) {
               morseCode += charMorseCode[24];
            } else if (lt.equals("z")) {
               morseCode += charMorseCode[25];
            }
         } else {
            if (lt.equals("0")) {
               morseCode += charMorseCode[26];
            } else if (lt.equals("1")) {
               morseCode += charMorseCode[27];
            } else if (lt.equals("2")) {
               morseCode += charMorseCode[28];
            } else if (lt.equals("3")) {
               morseCode += charMorseCode[29];
            } else if (lt.equals("4")) {
               morseCode += charMorseCode[30];
            } else if (lt.equals("5")) {
               morseCode += charMorseCode[31];
            } else if (lt.equals("6")) {
               morseCode += charMorseCode[32];
            } else if (lt.equals("7")) {
               morseCode += charMorseCode[33];
            } else if (lt.equals("8")) {
               morseCode += charMorseCode[34];
            } else if (lt.equals("9")) {
               morseCode += charMorseCode[35];
            }
         }
      }
      isPalindrome(morseCode);
   }

   public static void pc2Read() {
      String vec[], line;

      BufferedReader buffer = new BufferedReader(new InputStreamReader(System.in));

      try {
         line = buffer.readLine();
         buffer.close();
         vec = line.toLowerCase().split("\\W");

         if (!line.isEmpty() && line.length() <= 80) {
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