# Arduino Sensor Reader

Este proyecto lee datos de sensores desde Arduino a través de comunicación serial por software (pines TX/RX) y los guarda en un archivo CSV.

## Conexiones

### Pines Serial
- RX: Pin Digital 2
- TX: Pin Digital 3

### Sensores
- Temperatura: Pin A0
- Humedad: Pin A1
- Luz: Pin A2

## Requisitos

- Python 3.x
- Arduino con sensores conectados
- Bibliotecas Python (instalar con `pip install -r requirements.txt`):
  - pyserial
  - pyyaml

## Configuración

1. Ajusta el archivo `config.yaml` según tus necesidades:
   - Modifica el puerto COM según tu sistema
   - Verifica que los pines RX (2) y TX (3) estén correctamente configurados
   - Ajusta los pines y tipos de sensores
   - Configura el intervalo de lectura

2. Conecta los componentes:
   - Conecta el pin digital 2 (RX) del Arduino al pin TX del dispositivo emisor
   - Conecta el pin digital 3 (TX) del Arduino al pin RX del dispositivo receptor
   - Conecta los sensores a sus pines analógicos correspondientes

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
