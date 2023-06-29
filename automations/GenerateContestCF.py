# AutomatizaciónCodeforces.py: Creación de directorios y archivos fuente para RoundsCF
# autor: josuerom fecha: 27/06/23 06:17:05
import os
import shutil
import subprocess
import re
import time
import json
import urllib.request

def obtenerIndexNombreProblemas(contestId):
   url = f"https://codeforces.com/api/contest.standings?contestId={contestId}&from=1&count=1&showUnofficial=true"
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

def crear_dirs(contestId, n):
   ruta_principal = r"d:\workspace\contests\codeforces"
   ruta_contest = os.path.join(ruta_principal, contestId)

   if not os.path.exists(ruta_contest):
      nombreP = obtenerIndexNombreProblemas(contestId)
      os.makedirs(ruta_contest)
      print("Se han creado estos archivos:\n-----------------------------")

      ruta_archivo_destino = os.path.join(ruta_contest, "debug.h")
      shutil.copyfile(r"d:\workspace\templates\debug.h", ruta_archivo_destino)

      ruta_archivo_destino = os.path.join(ruta_contest, "input")
      open(ruta_archivo_destino, 'x')

      for i in range(0, n):
         open(f"{ruta_contest}\\{nombreP[i]}.java", 'x')
         open(f"{ruta_contest}\\{nombreP[i]}.cpp", 'x')
         print(f"{nombreP[i]}.cpp\n{nombreP[i]}.java")

      print("debug.h\ninput\n-----------------------------")
      t = float(f"{(n / 2 * 0.35):.2f}")
      time.sleep(t)

      print(f"Iniciando VSCode", end='')
      stop = 4
      for i in range(0, stop):
         time.sleep(0.6)
         if i != stop - 1:
            print(f".", end='', flush=True)
         else:
            print("😁", end='', flush=True)

      comando = f"code-insiders {ruta_contest}"
      subprocess.run(comando, shell=True)
   else:
      print(f"El contest {contestId} ya existe 😞.")

if __name__ == '__main__':
   s = input("-> ").split(" ")
   crear_dirs(s[0], int(s[1]))