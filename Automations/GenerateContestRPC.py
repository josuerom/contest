# AutomatizaciónRPC.py: Creación de directorios y archivos fuentes para Rounds de la RPC
# autor: josuerom fecha: 27/06/23 15:34:40
import os
import glob
import shutil
import time
import subprocess


def obtenerPDF(ubicacion_archivo, round_number):
    archivo_pdf = glob.glob(os.path.join(
        ubicacion_archivo, f"*RPC{round_number}*.pdf"))
    if len(archivo_pdf) > 0:
        return archivo_pdf[0]
    else:
        return None


def crear_dirs(round, n):
    ruta_base = r"d:\workspace\contests\rpc\2023"
    nom_dir = f"Rnd{round}"
    ruta_dir = os.path.join(ruta_base, nom_dir)
    ruta_del_archivo = r"c:\users\jr3\downloads"
    # ruta_del_archivo = r"c:\users\$HOME$\downloads"

    if not os.path.exists(ruta_dir) and n != 0:
        archivo_pdf = obtenerPDF(ruta_del_archivo, round)

        if archivo_pdf is not None:
            nombre_real = os.path.basename(archivo_pdf)
            ruta_archivo_pdf = os.path.join(ruta_del_archivo, nombre_real)
            ruta_de_destino = os.path.join(ruta_dir, nombre_real)
            shutil.move(ruta_archivo_pdf, ruta_de_destino)
            print(f"Se han creado los archivos.")
        else:
            print(
                f"\nNo se encontró el archivo PDF en el directorio ~\Descargas o ~\Downloads.")
            option = int(input("Presione 1 para continuar o 2 para salir -> "))
            if option == 2:
                return

        os.makedirs(ruta_dir)

        ruta_archivo_debug = os.path.join(ruta_dir, "debug.h")
        shutil.copyfile(r"d:\workspace\templates\debug.h", ruta_archivo_debug)

        lista_id = ["A", "B", "C", "D"]
        # template_java = "d:\workspace\templates\tem.java"

        for i in range(0, n):
            ruta_arc = os.path.join(ruta_dir, lista_id[i])
            os.makedirs(ruta_arc)
            ruta_archivo_destino = os.path.join(
                ruta_arc, f"{lista_id[i]}.java")
            open(ruta_archivo_destino, 'x')
            # shutil.copyfile(template_java, ruta_archivo_destino)

            ruta_archivo_destino = os.path.join(ruta_arc, f"{lista_id[i]}.cpp")
            open(ruta_archivo_destino, 'x')

        print(f"\nSe iniciará VSCode", end='')
        time.sleep(0.15)
        stop = 4
        for i in range(0, stop):
            time.sleep(0.45)
            if i != stop - 1:
                print(f".", end='', flush=True)
            else:
                print(f"😁", flush=True)

        # comando = f"code {ruta_dir}"
        comando = f"code-insiders {ruta_dir}"
        subprocess.run(comando, shell=True)
    else:
        print(f"El dir Rnd{round} ya existe 😞.")


if __name__ == '__main__':
    s = input("Round number -> ")
    n = int(input("How many problems -> "))
    crear_dirs(s, n)
