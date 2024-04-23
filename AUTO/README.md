# AUTOMATIZACIONES

Para que las automatizaciones funcionen correctamente, necesariamente se deben instalar las dependencias que están en el `requirements.txt`

## En Windows
Sin entorno virtual:
```cmd
py -m pip install -r requirements.txt
```

## En Linux
Con entorno virtual:
```bash
sudo apt install python3-virtualenv
cd <ruta_del_clone>/contest/AUTO
virtualenv -p python3 venv
source venv/bin/activate
pip install -r requirements.txt
deactivate
```
