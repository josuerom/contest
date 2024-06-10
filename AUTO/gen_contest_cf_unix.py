"""
   Generador de concursos automáticos de codeforces, enfocado en sistemas Unix
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


def generadorConcursoCFUnix():
   contest_id = input("ContestID -> ")
   root = f"/home/josuerom/Workspace/contest/CF"
   contest_route = os.path.join(root, contest_id)

   if os.path.exists(contest_route):
      print(f"The contest already exists 😞.")
      return

   n = int(input("How many problems -> "))
   nameProblem = consultarNombreProblema(contest_id)
   
   while True:
      option = int(input("Select the language:\n1. cpp\n2. java\n3. python\n-> "))
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

   print("These files were created:\n-----------------------------")
   open(f"{contest_route}\\in1", 'w')

   for i in range(0, n):
      invalid_chars = r'_<>:"/\|?*'
      file_title = ''.join(
         c if c not in invalid_chars else '_' for c in nameProblem[i])
      file_path = os.path.join(contest_route, f"{file_title}.{extension}")
      with open(file_path, 'w'):
         pass
      print(f"{file_title}.{extension}")

   print("in1\n-----------------------------")
   print(f"Starting contest with VSCode 😁😁...", end='\n')

   subprocess.run(f"code {contest_route}", shell=True)
   subprocess.run("pkill -f bash", shell=True)


if __name__ == '__main__':
   generadorConcursoCFUnix()
