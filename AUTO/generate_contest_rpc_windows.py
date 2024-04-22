# Creación de directorios y archivos fuentes para Rounds de la RPC
# Autor: josuerom - Fecha: 27/06/23 15:34:40
import os
import glob
import re
import shutil
import subprocess

def obtener_pdf(directorio_pdf, round):
    archivos_pdf = glob.glob(os.path.join(directorio_pdf, "*.pdf"))
    for archivo_pdf in archivos_pdf:
        if re.search(r"(rpc|set|problem|{round})", archivo_pdf, re.IGNORECASE):
            return archivo_pdf
    return None

def crear_dirs(round):
    ruta_base_rpc = r"d:\workspace\contest\rpc"
    ruta_base = os.path.join(ruta_base_rpc, "2024")

    if not os.path.exists(ruta_base):
        os.makedirs(ruta_base)

    nombre_dir = f"Rnd{round}"
    ruta_dir = os.path.join(ruta_base, nombre_dir)
    dir_pdf = r"c:\users\josuerom\downloads"

    if os.path.exists(ruta_dir):
        print(f"El round ya existe 😞.")
        return
    else:
        os.makedirs(ruta_dir)

    nombre_pdf = obtener_pdf(dir_pdf, round)

    if nombre_pdf:
        nombre_del_pdf = os.path.basename(nombre_pdf)
        get_pdf = os.path.join(dir_pdf, nombre_del_pdf)
        shutil.move(get_pdf, ruta_dir)
        print("Se han creado los archivos.")
    else:
        print("\nNo se encontró el archivo PDF en ~\Descargas o ~\Downloads.")
        option = int(input("Presione 1 para continuar o 2 para salir -> "))
        if option == 2:
            return

    template_2bits = r"d:\workspace\contest\templates\tem_2bits.cpp"
    lista_id = ["A", "B", "C", "D"]

    for problemID in lista_id:
        ruta_rpc = os.path.join(ruta_dir, problemID)
        os.makedirs(ruta_rpc)
        archivo_base = os.path.join(ruta_rpc, f"{problemID}.cpp")
        shutil.copyfile(template_2bits, archivo_base)
        archivo_base = os.path.join(ruta_rpc, "in1")
        with open(archivo_base, 'x'):
            pass

    print("\nSe iniciará VSCode 😁😁...")
    subprocess.run(f"code-insiders {ruta_dir}", shell=True)
    subprocess.run("taskkill /f /im cmd.exe", shell=True)

if __name__ == '__main__':
    s = input("Número del round -> ")
    crear_dirs(s)
