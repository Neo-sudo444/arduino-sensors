# Arduino Sensor Reader

Este proyecto lee datos de sensores desde Arduino a través del puerto serie y los guarda en un archivo CSV.

## Requisitos

- Python 3.x
- Arduino con sensores conectados
- Bibliotecas Python (instalar con `pip install -r requirements.txt`):
  - pyserial
  - pyyaml

## Configuración

1. Ajusta el archivo `config.yaml` según tus necesidades:
   - Modifica el puerto COM según tu sistema
   - Ajusta los pines y tipos de sensores
   - Configura el intervalo de lectura

2. Asegúrate que tu Arduino esté enviando los datos en formato CSV por el puerto serie.

## Uso

1. Instala las dependencias:
   ```
   pip install -r requirements.txt
   ```

2. Ejecuta el script:
   ```
   python read_sensors.py
   ```

Los datos se guardarán en `sensor_data.csv` en el directorio del proyecto.
