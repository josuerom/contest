#  author: josuerom - created: 21/04/24 20:00:03
import os
import subprocess
from termcolor import colored


def tipo_de_programa():
   programa = input("Nombre del programa: ").strip()
   extension = programa.split(".")
   if programa.endswith(".py"):
      ejecutar_python(programa)
   elif programa.endswith(".cpp"):
      compilar_y_ejecutar_cpp(programa)
   elif programa.endswith(".java"):
      ejecutar_java(programa)
   else:
      print(f"No hay soporte de compilación para archivos .{extension[1]}")


def ejecutar_python(programa):
   for i in range(1, 100):
      entrada_estandar = f"samples/in{i}.txt"
      respuesta_correcta = f"samples/ans{i}.txt"
      if not os.path.exists(entrada_estandar):
         break
      with open(entrada_estandar, "r") as contenido_archivo_de_entrada:
         entrada_estandar_datos = contenido_archivo_de_entrada.read().strip()
      proceso = subprocess.Popen(["python3", programa], stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
      salida_generada, _ = proceso.communicate(input=entrada_estandar_datos)
      with open(respuesta_correcta, "r") as contenido_archivo_de_entrada:
         salida_esperada = contenido_archivo_de_entrada.read().strip()
      if salida_generada.strip() == salida_esperada.strip():
         print(colored(f"Test case {i} passed ✅", "green"))
      else:
         print(colored("Wrong answer case {i} ❌", "red"))
         print(f"Output:\n{salida_generada}", end="\n")
         print(f"Answer:\n{salida_esperada}")


def compilar_y_ejecutar_cpp(programa):
   def ejecutar(programa):
      for i in range(1, 100):
         entrada_estandar = f"samples/in{i}.txt"
         respuesta_correcta = f"samples/ans{i}.txt"
         if not os.path.exists(entrada_estandar):
            break
         with open(entrada_estandar, "r") as contenido_archivo_de_entrada:
            entrada_estandar_datos = contenido_archivo_de_entrada.read().strip()
         proceso = subprocess.Popen(["./" + programa], stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
         salida_generada, _ = proceso.communicate(input=entrada_estandar_datos)
         with open(respuesta_correcta, "r") as contenido_archivo_de_entrada:
            salida_esperada = contenido_archivo_de_entrada.read().strip()
         if salida_generada.strip() == salida_esperada.strip():
            print(colored(f"Test case {i} passed ✅", "green"))
         else:
            print(colored("Wrong answer case {i} ❌", "red"))
            print(f"Output:\n{salida_generada}", end="\n")
            print(f"Answer:\n{salida_esperada}")

   nombre_ejecutable = programa.replace(".cpp", "")
   proceso_compilacion = subprocess.Popen(["g++ -std=c++17 -O2 -DLOCAL", programa, "-o", nombre_ejecutable], stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
   _, errores_compilacion = proceso_compilacion.communicate()
   if proceso_compilacion.returncode == 0:
      ejecutar(nombre_ejecutable)
   else:
      print(colored("OJO: Error de compilación.", "red"))
      print(errores_compilacion)


def ejecutar_java(programa):
   for i in range(1, 100):
      entrada_estandar = f"samples/in{i}.txt"
      respuesta_correcta = f"samples/ans{i}.txt"
      if not os.path.exists(entrada_estandar):
         break
      with open(entrada_estandar, "r") as contenido_archivo_de_entrada:
         entrada_estandar_datos = contenido_archivo_de_entrada.read().strip()
      proceso = subprocess.Popen(["java", programa], stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
      salida_generada, _ = proceso.communicate(input=entrada_estandar_datos)
      with open(respuesta_correcta, "r") as contenido_archivo_de_entrada:
         salida_esperada = contenido_archivo_de_entrada.read().strip()
      if salida_generada.strip() == salida_esperada.strip():
         print(colored(f"Test case {i} passed ✅", "green"))
      else:
         print(colored("Wrong answer case {i} ❌", "red"))
         print(f"Output:\n{salida_generada}", end="\n")
         print(f"Answer:\n{salida_esperada}")


if __name__ == "__main__":
   tipo_de_programa()
