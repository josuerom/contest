# AutomatizaciónRPC.py: Creación de directorios y archivos fuentes para Rounds de la RPC
# autor: josuerom  -  fecha: 27/06/23 15:34:40
import os
import glob
import shutil
import time
import subprocess


def obtenerPDF(directorio_pdf, round):
    nombre_pdf = glob.glob(os.path.join(
        directorio_pdf, f"*RPC{round}*.pdf"))
    if len(nombre_pdf) > 0:
        return nombre_pdf[0]
    else:
        return None


def crear_dirs(round):
    ruta_base_rpc = r"/home/josuerom/workspace/contest/RPC/"

    ruta_base = os.path.join(ruta_base_rpc, "2024")
    if not os.path.exists(ruta_base):
        os.makedirs(ruta_base)

    nombre_dir = f"Rnd{round}"
    ruta_dir = os.path.join(ruta_base, nombre_dir)
    dir_pdf = r"/home/josuerom/Descargas"
    #dir_pdf = r"/home/josuerom/Downloads"

    if os.path.exists(ruta_dir):
        print(f"El directorio {ruta_dir} ya existe 😞.")
        return
    else:
        os.makedirs(ruta_dir)

    nombre_pdf = obtenerPDF(dir_pdf, round)

    if nombre_pdf is not None:
        nombre_del_pdf = os.path.basename(nombre_pdf)
        get_pdf = os.path.join(dir_pdf, nombre_del_pdf)
        shutil.move(get_pdf, ruta_dir)
        print(f"Se han creado los archivos.")
    else:
        print(
            f"\nNo se encontró el archivo PDF en el directorio ~/Descargas o ~/Downloads.")
        option = int(input("Presione 1 para continuar o 2 para salir -> "))
        if option == 2:
            return

    ruta_archivo_debug = os.path.join(ruta_dir, "debug.h")
    shutil.copyfile(
        r"/home/josuerom/workspace/contest/TEMPLATES/debug.h", ruta_archivo_debug)
    template_2bits = r"/home/josuerom/workspace/contest/TEMPLATES/tem_2bits.cpp"

    lista_id = ["A", "B", "C", "D", "E"]

    for problemID in lista_id:
        ruta_rpc = os.path.join(ruta_dir, problemID)
        os.makedirs(ruta_rpc)
        archivo_base = os.path.join(ruta_rpc, f"{problemID}.cpp")
        shutil.copyfile(template_2bits, archivo_base)
        archivo_base = os.path.join(ruta_rpc, "in1")
        with open(archivo_base, 'x'):
            pass

    print("\nSe iniciará VSCode 😁😁", end='\n')

    comando = f"code {ruta_dir}"
    # comando = f"code-insiders {ruta_dir}"
    subprocess.run(comando, shell=True)


if __name__ == '__main__':
    s = input("Round ID -> ")
    crear_dirs(s)
