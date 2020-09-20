# OTA

Clase rapida y simple implementacion del sistema de grabación OTA con interfaz serial opcional

## Instalación

Utilizando la consola de tu preferencia, dirigete a la ruta de las librerias de arduino de tu instalacion. Por ejemplo:

``` bash
cd P:\Arduino\libraries
```

Una vez dentro del directorio solo basta con clonar el proyecto de la libreria en la versión que gustes.

``` bash
git clone git@gitlab.com:arduinolibraries/OTA.git .
```

Esto creara el directorio OTA de la libreria junto con los archivos de documentación y los ejemplos.

## Seleccion de versión

Por defecto, luego de instalar desde el repositorio, la versión seleccionada es la última vigente en master. Si quiere puede seleccionar otra version en cualquier momento utilizando los comandos git checkout y haciendo referencia a la versión que desee.

``` bash
git checkout tag/<versión>
```

Puede ver un listado de las versiones disponibles por medio del siguiente comando

``` bash
git fetch --tags
```

## Actualización

Para actualizar a la última versión solo es necesario ejecutar un simple pull

``` bash
git pull
```

Luego podra seleccionar la última versión siguiendo los pasos de Selección de versión

## Uso

La libreria incluye una instancia de Wireless ya declarada. No es necesario realizar ninguna instancia nueva. Pero puede ser util aprovechar los constructores para configurar rapidamente el comportamiento de Wireless.

``` c++
OTA = OTAClass( <hostname>, <password>, <port> );
```

De otra forma se pueden utilizar los metodos setters correspondientes para cargar los valores.

OTAClass, no ofrece metodos callbacks. Simplemente estan definidos para lanzar mensajes por el puerto Serie. 

Por defecto, la salida de mensajes esta desactivada. Debe usar ``` setDebug(true); ``` para ver el estado OTA durante el proceso de actualizacion.

Estas configuraciones se deben realizar antes de iniciar el servicio OTA.
Para iniciar el ciclo de ejecucion de OTAClass se debe realizar una llamada al metodo Begin()

``` c++
OTA.setHostname(hostname);
OTA.setDebug(true);
OTA.Begin();
```

Es obligatorio que se realice una llamada al metodo **Loop()** dentro del bucle infinito del procesador para que OTAClass sea capaz de capturar la solicitud de actualización dle firmware e inice el proceso de grabación.

``` c++
void loop(){
    OTA.Loop();
}
```

## Links

- [Cambios de version](CHANGELOG.md)
- [Repositorio](https://gitlab.com/arduinolibraries/OTA/-/tree/master)