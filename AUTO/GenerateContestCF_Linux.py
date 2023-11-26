# Creación de directorios y archivos fuentes para Rounds de Codeforces
# Autor: josuerom  -  Fecha: 27/06/23 06:17:05
import os
import shutil
import subprocess
import re
import time
import json
import urllib.request


def obtenerNombreProblemas(contestId):
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


def crear_dirs(contestId):
    ruta_principal = r"/home/josuerom/workspace/contests/cf"
    ruta_contest = os.path.join(ruta_principal, contestId)

    if os.path.exists(ruta_contest):
        print(f"Ese contests ya existe 😞.")
    else:
        n = int(input("How many problems -> "))
        nombreP = obtenerNombreProblemas(contestId)
        os.makedirs(ruta_contest)

        print("Se crearon estos archivos:\n-----------------------------")

        ruta_archivo_destino = os.path.join(ruta_contest, "debug.h")
        shutil.copyfile(r"/home/josuerom/workspace/templates/debug.h",
                        ruta_archivo_destino)
        open(f"{ruta_contest}\\in1", 'w')

        for i in range(0, n):
            invalid_chars = r'_<>:"/\|?*'
            sanitized_title = ''.join(
                c if c not in invalid_chars else '_' for c in nombreP[i])
            file_path = os.path.join(ruta_contest, f"{sanitized_title}.cpp")
            with open(file_path, 'w'):
                pass
            print(f"{sanitized_title}.cpp")

        print("in1\ndebug.h\n--------------------------")
        print(f"Iniciando tu VSCode...\n", end='')

        comando = f"code {ruta_contest}"
        subprocess.run(comando, shell=True)


if __name__ == '__main__':
    s = input("ID Contest -> ")
    crear_dirs(s)
