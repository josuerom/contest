# author: josuerom - created: 22/04/24 16:11:25
import sys
import os
import subprocess
import requests
from termcolor import colored
from bs4 import BeautifulSoup


def main(programa):
    extension = programa.split(".")
    if programa.endswith(".py"):
        ejecutar_python(programa)
    elif programa.endswith(".cpp"):
        compilar_y_ejecutar_cpp(programa)
    elif programa.endswith(".java"):
        ejecutar_java(programa)
    else:
        print(f"No hay soporte para programas .{extension[1]}")
        return


def eliminar_archivos_de_entrada():
    ubicacion_programa = os.path.dirname(os.path.abspath(sys.argv[0]))
    archivos_txt = os.path.join(ubicacion_programa, "samples", "*.txt")
    subprocess.run(["del", archivos_txt], shell=True)


def obtener_input_output(id_contest, id_problema):
    eliminar_archivos_de_entrada()
    url = f"https://codeforces.com/contest/{id_contest}/problem/{id_problema}"
    response = requests.get(url)
    if response.status_code == 200:
        soup = BeautifulSoup(response.text, 'html.parser')
        input_divs = soup.find_all('div', class_='input')
        output_divs = soup.find_all('div', class_='output')

        for i, (input_div, output_div) in enumerate(zip(input_divs, output_divs), start=1):
            input_text = input_div.find('pre').get_text()
            output_text = output_div.find('pre').get_text()
            with open(f"samples\\in{i}.txt", "w") as input_file:
                input_file.write(input_text.strip())
            with open(f"samples\\ans{i}.txt", "w") as output_file:
                output_file.write(output_text.strip())
            print(colored(f"Test case {i} copied ✅", "yellow"))
    else:
        print(f"Acá hay un error: {url}")


def ejecutar_python(programa):
    for i in range(1, 100):
        entrada_estandar = f"samples\\in{i}.txt"
        respuesta_correcta = f"samples\\ans{i}.txt"
        if not os.path.exists(entrada_estandar):
            break
        with open(entrada_estandar, "r") as contenido_archivo_de_entrada:
            entrada_estandar_datos = contenido_archivo_de_entrada.read().strip()
        proceso = subprocess.Popen(["python", programa], stdin=subprocess.PIPE, stdout=subprocess.PIPE,
                                   stderr=subprocess.PIPE, text=True)
        salida_generada, _ = proceso.communicate(input=entrada_estandar_datos)
        with open(respuesta_correcta, "r") as contenido_archivo_de_entrada:
            salida_esperada = contenido_archivo_de_entrada.read().strip()
        if salida_generada.strip() == salida_esperada.strip():
            print(colored(f"Test case {i} passed ✅", "green"))
        else:
            print(colored(f"Wrong answer case {i} ❌", "red"))
            print(f"Output:\n{salida_generada}", end="\n")
            print(f"Answer:\n{salida_esperada}")


def compilar_y_ejecutar_cpp(programa):
    def ejecutar(programa):
        for i in range(1, 100):
            entrada_estandar = f"samples\\in{i}.txt"
            respuesta_correcta = f"samples\\ans{i}.txt"
            if not os.path.exists(entrada_estandar):
                break
            with open(entrada_estandar, "r") as contenido_archivo_de_entrada:
                entrada_estandar_datos = contenido_archivo_de_entrada.read().strip()
            proceso = subprocess.Popen([f".\\{programa}"], stdin=subprocess.PIPE, stdout=subprocess.PIPE,
                                       stderr=subprocess.PIPE, text=True)
            salida_generada, _ = proceso.communicate(input=entrada_estandar_datos)
            with open(respuesta_correcta, "r") as contenido_archivo_de_entrada:
                salida_esperada = contenido_archivo_de_entrada.read().strip()
            if salida_generada.strip() == salida_esperada.strip():
                print(colored(f"Test case {i} passed ✅", "green"))
            else:
                print(colored(f"Wrong answer case {i} ❌", "red"))
                print(f"Output:\n{salida_generada}", end="\n")
                print(f"Answer:\n{salida_esperada}")

    nombre_ejecutable = programa.replace(".cpp", "")
    proceso_compilacion = subprocess.Popen(["g++ -std=c++17 -O2 -DLOCAL", programa, "-o", nombre_ejecutable],
                                           stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
    _, errores_compilacion = proceso_compilacion.communicate()
    if proceso_compilacion.returncode == 0:
        ejecutar(nombre_ejecutable)
    else:
        print(colored("OJO: Error de compilación.", "red"))
        print(errores_compilacion)


def ejecutar_java(programa):
    for i in range(1, 100):
        entrada_estandar = f"samples\\in{i}.txt"
        respuesta_correcta = f"samples\\ans{i}.txt"
        if not os.path.exists(entrada_estandar):
            break
        with open(entrada_estandar, "r") as contenido_archivo_de_entrada:
            entrada_estandar_datos = contenido_archivo_de_entrada.read().strip()
        proceso = subprocess.Popen(["java", programa], stdin=subprocess.PIPE, stdout=subprocess.PIPE,
                                    stderr=subprocess.PIPE, text=True)
        salida_generada, _ = proceso.communicate(input=entrada_estandar_datos)
        with open(respuesta_correcta, "r") as contenido_archivo_de_entrada:
            salida_esperada = contenido_archivo_de_entrada.read().strip()
        if salida_generada.strip() == salida_esperada.strip():
            print(colored(f"Test case {i} passed ✅", "green"))
        else:
            print(colored(f"Wrong answer case {i} ❌", "red"))
            print(f"Output:\n{salida_generada}", end="\n")
            print(f"Answer:\n{salida_esperada}")


if __name__ == "__main__":
    """Para verificar todos los caso de prueba:
       python solution_tester.py -test <programa>
    
       Para obtener los casos de prueba junto con sus salidas
       python solution_tester.py -parse <id_contes>/<id_problema>
    """
    if len(sys.argv) == 3 and sys.argv[1] == "-test":
        main(sys.argv[1])
    elif len(sys.argv) == 3 and sys.argv[1] == "-parse":
      id_contest, id_problema = sys.argv[2].split("/")
      obtener_input_output(id_contest, id_problema)
   elif len(sys.argv) > 3 or sys.argv[1] != "-parse" and sys.argv[1] != "-test":
      print("Mijito/a la instrucción no es válida!")
