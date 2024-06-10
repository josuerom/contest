"""
   Generador de concursos automáticos de codeforces, enfocado en sistemas Windows
   Autor: josuerom
   Fecha: 09/06/24
"""
import os
import subprocess
import re
import json
import urllib.request


def consultarNombreProblema(contest_id):
   url = f"https://codeforces.com/api/contest.standings?contestId={contest_id}&from=1&count=1&showUnofficial=true"
   problem_set = []
   try:
      headers = {
         'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/58.0.3029.110 Safari/537.3'
      }
      req = urllib.request.Request(url, headers=headers)
      response = urllib.request.urlopen(req)
      data = json.loads(response.read().decode('utf-8'))
      s = str(data)
      s = re.sub(r"[.:,{}()\[\]]", "", s)
      s = re.sub(r"' '", " ", s)
      s = re.sub(r"'", "", s).split(" ")
      ind = title = ""
      for i in range(0, len(s)):
         if s[i] == 'index':
               ind = s[i + 1]
               i += 2
         elif s[i] == 'name':
               i += 1
               while s[i] != 'type':
                  if s[i + 1] != 'type':
                     title += s[i] + " "
                  else:
                     title += s[i]
                  i += 1
               i += 4
               ans = re.sub(r"[.!'\-,:;=+&%/\\]", "", f"{ind} {title}")
               problem_set.append(ans.replace(" ", "_"))
         title = ""
      problem_set.remove(problem_set[0])
      return problem_set
   except urllib.error.URLError as e:
      print(f"Error {e}")


def generadorConcursoCFWindows():
   contest_id = input("\033[93mContestID ->\033[0m ")
   root = f"d:\\workspace\\contest\\cf"
   contest_route = os.path.join(root, contest_id)

   if os.path.exists(contest_route):
      print(f"\033[91mThe contest already exists 😞.\033[0m")
      return

   n = int(input("\033[93mHow many problems ->\033[0m "))
   nameProblem = consultarNombreProblema(contest_id)

   while True:
      option = int(input("\033[93mSelect the language:\n1. cpp\n2. java\n3. python\n->\033[0m "))
      extension = None
      if option == 1:
         extension = "cpp"
      elif option == 2:
         extension = "java"
      elif option == 3:
         extension = "py"
      else:
         print("\033[91mInvalid option. Try again.\033[0m")
         continue
      break

   os.makedirs(contest_route)

   print("\033[94mThese files were created:\n-----------------------------\033[0m")
   open(f"{contest_route}\\in1", 'w')

   for i in range(0, n):
      invalid_chars = r'_<>:"/\|?*'
      file_title = ''.join(
         c if c not in invalid_chars else '_' for c in nameProblem[i])
      with open(f"{contest_route}\\{file_title}.{extension}", 'w'):
         pass
      print(f"{file_title}.{extension}")

   print("in1\n\033[94m-----------------------------\033[0m")
   print(f"\033[94mStarting contest with VSCode 😁😁...\033[0m", end='\n')

   subprocess.run(f"code {contest_route}", shell=True)
   subprocess.run("taskkill /f /im cmd.exe", shell=True)


if __name__ == '__main__':
   generadorConcursoCFWindows()
