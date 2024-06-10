"""
   Generador de rondas automático para la Red de programación Colombiana (RPC) para sistemas Unix
   Autor: josuerom
   Fecha: 10/06/24
"""
import os
import re
import glob
import shutil
import subprocess


def buscarDocumentoPDF(dir_descargas):
   archivos_pdf = glob.glob(os.path.join(dir_descargas, "*.pdf"))
   for archivo in archivos_pdf:
      nombre_archivo = os.path.basename(archivo)
      if re.search(r"(problem|set|rpc|rnd)", nombre_archivo, re.IGNORECASE):
         return archivo
   return None


def generadorConcursoRPCUnix():
   ronda, año = re.split(r'[ \-/]+', input("\033[93mRonda y año ->\033[0m "))
   ruta_base_rpc = f"/home/josuerom/Workspace/contest/RPC"
   ruta_base_año = os.path.join(ruta_base_rpc, año)
   ruta_ronda = os.path.join(ruta_base_año, f"Rnd{ronda}")

   if not os.path.exists(ruta_base_año):
      os.makedirs(ruta_base_año)

   if os.path.exists(ruta_ronda):
      print("\033[91mMijito/a ese round ya existe 😞.\033[0m")
      return
   
   ruta_descargas = r"/home/josuerom/Descargas"
   archivo_pdf = buscarDocumentoPDF(ruta_descargas)
   obtener_pdf, encontro_pdf = None, False

   if archivo_pdf:
      capturar_pdf = os.path.basename(archivo_pdf)
      obtener_pdf = os.path.join(ruta_descargas, capturar_pdf)
      encontro_pdf = True
   else:
      print("\033[91mMijito/a no encontré el problemSet.\033[0m")

   os.makedirs(ruta_ronda)

   if encontro_pdf:
      shutil.move(obtener_pdf, ruta_ronda)

   tem_cpp = f"/home/josuerom/Workspace/contest/TEMPLATES/tem_2bits.cpp"
   tem_java = f"/home/josuerom/Workspace/contest/TEMPLATES/template.java"
   tem_py = f"/home/josuerom/Workspace/contest/TEMPLATES/template.py"

   lista_id = input("\033[93mQué problemas intentará resolver ->\033[0m ").upper().split()
   
   while True:
      template = int(input("\033[93mSeleccione el lenguaje:\n1. cpp\n2. java\n3. python\n->\033[0m "))
      ext = None
      if template == 1:
         template, ext = tem_cpp, "cpp"
      elif template == 2:
         template, ext = tem_java, "java"
      elif template == 3:
         template, ext = tem_py, "py"
      else:
         print("\033[91mMijito/a opción inválida. Intente de nuevo.\033[0m")
         continue
      break

   for problemID in lista_id:
      ruta_rpc = os.path.join(ruta_ronda, problemID)
      os.makedirs(ruta_rpc, exist_ok=True)
      archivo_base = os.path.join(ruta_rpc, f"{problemID}.{ext}")
      shutil.copyfile(template, archivo_base)
      with open(archivo_base, 'r') as plantilla:
         lineas = plantilla.readlines()
      with open(archivo_base, 'w') as plantilla:
         for linea in lineas:
            if linea.strip().startswith("public class"):
               linea = "public class " + problemID + " {\n"
            if linea.strip().startswith("class"):
               linea = "class RPCProblem" + problemID + " {\n"
            if linea.strip().startswith("RPCProblem"):
               linea = "\tRPCProblem" + problemID + " me;\n"
            plantilla.write(linea)
      archivo_in = os.path.join(ruta_rpc, "in1")
      with open(archivo_in, 'x'):
         pass

   print("\033[94mIniciando la ronda con VSCode...\033[0m")

   subprocess.run(f"code {ruta_ronda}", shell=True)
   subprocess.run("pkill -f bash", shell=True)


if __name__ == '__main__':
   generadorConcursoRPCUnix()
