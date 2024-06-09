# Creación de directorios y archivos fuentes para Rounds de la RPC
# Autor: josuerom - Fecha: 27/06/23 15:34:40
import os
import re
import glob
import shutil
import subprocess


def buscar_archivo_pdf(dir_descargas):
   archivos_pdf = glob.glob(os.path.join(dir_descargas, "*.pdf"))
   for archivo in archivos_pdf:
      nombre_archivo = os.path.basename(archivo)
      if re.search(r"(problem|set|rpc|rnd)", nombre_archivo, re.IGNORECASE):
         return archivo
   return None


def crear_dirs():
   rnd, anio = input("Round/Year -> ").split("/")
   ruta_base_rpc = r"d:\workspace\contest\rpc"
   ruta_base_anio = os.path.join(ruta_base_rpc, anio)
   ruta_del_round = os.path.join(ruta_base_anio, f"Rnd{rnd}")

   if not os.path.exists(ruta_base_anio):
      os.makedirs(ruta_base_anio)

   if os.path.exists(ruta_del_round):
      print("\033[94mMijito/a ese round ya existe 😞.\033[0m")
      return
   
   ruta_descargas = f"c:\\users\\josuerom\\downloads"
   archivo_pdf = buscar_archivo_pdf(ruta_descargas)
   obtener_pdf, encontro_pdf = None, False

   if archivo_pdf:
      capturar_pdf = os.path.basename(archivo_pdf)
      obtener_pdf = os.path.join(ruta_descargas, capturar_pdf)
      encontro_pdf = True
   else:
      print("\033[91mMijito/a no pude encontrar el PDF.\033[0m")

   os.makedirs(ruta_del_round)
   if encontro_pdf:
      shutil.move(obtener_pdf, ruta_del_round)

   tem_cpp = f"d:\\workspace\\contest\\templates\\tem_2bits.cpp"
   tem_java = f"d:\\workspace\\contest\\templates\\template.java"
   tem_py = f"d:\\workspace\\contest\\templates\\template.py"
   
   lista_id = input("ID of the problems -> ").upper().split()

   template = input("Language -> ").lower()
   ext = None
   if template == "cpp":
      template, ext = tem_cpp, "cpp"
   elif template == "java":
      template, ext = tem_java, "java"
   elif template == "py":
      template, ext = tem_py, "py"

   for problemID in lista_id:
      ruta_rpc = os.path.join(ruta_del_round, problemID)
      os.makedirs(ruta_rpc, exist_ok=True)
      archivo_base = os.path.join(ruta_rpc, f"{problemID}.{ext}")
      shutil.copyfile(template, archivo_base)
      with open(archivo_base, 'r') as plantilla:
         lineas = plantilla.readlines()
      with open(archivo_base, 'w') as plantilla:
         for linea in lineas:
            if linea.strip().startswith("public class"):
               linea = "public class " + problemID + " {\n"
            elif linea.strip().startswith("class"):
               linea = "class RPCProblem" + problemID + " {\n"
            elif linea.strip().startswith("RPCProblem"):
               linea = "\tRPCProblem" + problemID + " me;\n"
            plantilla.write(linea)
      archivo_in = os.path.join(ruta_rpc, "in1")
      with open(archivo_in, 'x'):
         pass

   subprocess.run(f"code {ruta_del_round}", shell=True)
   subprocess.run("taskkill /f /im cmd.exe", shell=True)


if __name__ == '__main__':
   crear_dirs()
