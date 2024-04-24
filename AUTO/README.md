# AUTOMATIZACIONES

Para que las automatizaciones funcionen correctamente, necesariamente se deben instalar los paquetes que están en el `requirements.txt`

## En Windows
Instalar los paquetes en el sistema y no en un entorno virtual:
```cmd
cd contest\AUTO
pip install -r requirements.txt
```

## En Linux
Instalar los paquetes en un entorno virtual:
```bash
sudo apt install python3-virtualenv
cd contest/AUTO
virtualenv -p python3 venv
source venv/bin/activate
pip install -r requirements.txt
deactivate
```
