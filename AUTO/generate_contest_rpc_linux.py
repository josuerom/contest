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


def crear_dirs(round):
    ruta_base_rpc = f"/home/josuerom/Workspace/contest/RPC"
    ruta_base_anio = os.path.join(ruta_base_rpc, "2024")
    ruta_del_round = os.path.join(ruta_base_anio, f"Rnd{round}")

    if not os.path.exists(ruta_base_anio):
        os.makedirs(ruta_base_anio)

    if os.path.exists(ruta_del_round):
        print("\033[94mMijito/a ese round ya existe 😞.\033[0m")
        return
    
    ruta_descargas = r"/home/josuerom/Descargas"
    archivo_pdf = buscar_archivo_pdf(ruta_descargas)
    obtener_pdf, encontro_pdf = None, False

    if archivo_pdf:
        capturar_pdf = os.path.basename(archivo_pdf)
        obtener_pdf = os.path.join(ruta_descargas, capturar_pdf)
        encontro_pdf = True
    else:
        print("\033[91mMijito/a no pude encontrar el PDF.\033[0m")
        option = int(input("\033[93mPresione 1 para continuar o 2 para salir -> \033[0m"))
        if option == 2:
            return

    os.makedirs(ruta_del_round)
    if encontro_pdf:
        shutil.move(obtener_pdf, ruta_del_round)

    template = f"/home/josuerom/Workspace/contest/TEMPLATES/tem_2bits.cpp"
    lista_id = input("ID of the problems -> ").upper().split()

    for problemID in lista_id:
        ruta_rpc = os.path.join(ruta_del_round, problemID)
        os.makedirs(ruta_rpc, exist_ok=True)
        archivo_base = os.path.join(ruta_rpc, f"{problemID}.cpp")
        shutil.copyfile(template, archivo_base)
        with open(archivo_base, 'r') as plantilla:
           lineas = plantilla.readlines()
        with open(archivo_base, 'w') as plantilla:
           for linea in lineas:
              if linea.strip().startswith("class"):
                 linea = "class RPCProblem" + problemID + " {\n"
              if linea.strip().startswith("RPCProblem"):
                 linea = "RPCProblem" + problemID + " me;\n"
              plantilla.write(linea)
        archivo_in = os.path.join(ruta_rpc, "in1")
        with open(archivo_in, 'x'):
            pass

    subprocess.run(f"code {ruta_del_round}", shell=True)
    subprocess.run("pkill -f bash", shell=True)


if __name__ == '__main__':
    s = input("RoundID -> ")
    crear_dirs(s)
