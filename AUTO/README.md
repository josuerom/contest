# AUTOMATIZACIONES

Para que las automatizaciones funcionen correctamente, necesariamente se deben instalar las dependencias que están en `requirements.txt`

## En Windows
```cmd
cd contest
python -m venv venv
.\venv\Scripts\activate
py -m pip install -r requirements.txt
.\venv\Scripts\deactivate
```

## En Linux
```bash
sudo apt install python3-virtualenv
cd contest
virtualenv -p python3 venv
source venv/bin/activate
pip install -r requirements.txt
deactivate
```
