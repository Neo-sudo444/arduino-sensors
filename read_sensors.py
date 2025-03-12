import yaml
import serial
import csv
import time
from datetime import datetime

def load_config():
    with open('config.yaml', 'r') as file:
        return yaml.safe_load(file)

def setup_serial(config):
    serial_config = config['serial']
    return serial.Serial(
        port=serial_config['port'],
        baudrate=serial_config['baudrate'],
        timeout=serial_config['timeout']
    )

def read_sensors(ser):
    try:
        if ser.in_waiting:
            line = ser.readline().decode('utf-8').strip()
            return line.split(',')
    except Exception as e:
        print(f"Error leyendo sensores: {e}")
    return None

def main():
    config = load_config()
    ser = setup_serial(config)
    
    # Crear/abrir archivo CSV para guardar datos
    with open(config['reading']['log_file'], 'a', newline='') as csvfile:
        fieldnames = ['timestamp'] + [sensor['name'] for sensor in config['sensors']]
        writer = csv.DictWriter(csvfile, fieldnames=fieldnames)
        
        # Escribir cabecera si el archivo está vacío
        if csvfile.tell() == 0:
            writer.writeheader()
        
        print("Iniciando lectura de sensores...")
        try:
            while True:
                sensor_data = read_sensors(ser)
                if sensor_data:
                    # Crear diccionario con los datos
                    data = {
                        'timestamp': datetime.now().isoformat()
                    }
                    for i, sensor in enumerate(config['sensors']):
                        if i < len(sensor_data):
                            data[sensor['name']] = sensor_data[i]
                    
                    # Guardar datos en CSV
                    writer.writerow(data)
                    print(f"Datos guardados: {data}")
                
                time.sleep(config['reading']['interval'])
                
        except KeyboardInterrupt:
            print("\nLectura de sensores finalizada")
            ser.close()

if __name__ == "__main__":
    main()
