# AutomatizaciónRPC.py: Creación de directorios y archivos fuente para Rounds RPC
# autor: josuerom fecha: 27/06/23 15:34:40
import os
import glob
import shutil
import time
import subprocess

def obtenerPDF(ubicacion_archivo, round_number):
    archivo_pdf = glob.glob(os.path.join(ubicacion_archivo, f"*RPC{round_number}*.pdf"))
    if len(archivo_pdf) > 0:
        return archivo_pdf[0]
    else:
        return None

def crear_dirs(round, n):
    ruta_base = r"d:\workspace\contests\rpc\2023"
    nom_dir = f"Rnd{round}"
    ruta_dir = os.path.join(ruta_base, nom_dir)
    ruta_del_archivo = r"c:\users\jr3\downloads"

    if not os.path.exists(ruta_dir) and n != 0:
        os.makedirs(ruta_dir)

        archivo_pdf = obtenerPDF(ruta_del_archivo, round)

        if archivo_pdf is not None:
            nombre_real = os.path.basename(archivo_pdf)
            ruta_archivo_pdf = os.path.join(ruta_del_archivo, nombre_real)
            ruta_de_destino = os.path.join(ruta_dir, nombre_real)
            shutil.move(ruta_archivo_pdf, ruta_de_destino)
            print(f"Se han creado los archivos.")
        else:
            print(f"\nNo se encontró el archivo PDF en {ruta_del_archivo}\\")

        ruta_archivo_debug = os.path.join(ruta_dir, "debug.h")
        shutil.copyfile(r"d:\workspace\templates\debug.h", ruta_archivo_debug)

        ruta_archivo_input = os.path.join(ruta_dir, "input")
        open(ruta_archivo_input, 'x')

        template_cpp = r"d:\workspace\templates\tem_petr.cpp"
        template_java = r"d:\workspace\templates\tem.java"

        lista_id = ["A", "B", "C"]

        for i in range(0, n):
            ruta_archivo_destino = os.path.join(ruta_dir, f"{lista_id[i]}.java")
            # shutil.copyfile(template_java, ruta_archivo_destino)
            open(ruta_archivo_destino, 'x')

            ruta_archivo_destino = os.path.join(ruta_dir, f"{lista_id[i]}.cpp")
            shutil.copyfile(template_cpp, ruta_archivo_destino)
            # open(ruta_archivo_destino, 'x')

        print(f"Iniciando VSCode", end='')
        time.sleep(0.25)
        stop = 4
        for i in range(0, stop):
            time.sleep(0.6)
            if i != stop - 1:
                print(f".", end='', flush=True)
            else:
                print(f"😁", flush=True)

        comando = f"code-insiders {ruta_dir}"
        subprocess.run(comando, shell=True)
    else:
        print(f"El dir Rnd{round} ya existe 😞.")

if __name__ == '__main__':
    s = input("-> ").split(" ")
    crear_dirs(s[0], int(s[1]))