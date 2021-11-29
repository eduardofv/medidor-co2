# Un medidor de CO2 que puedes hacer tú mismo

Cómo hacer un medidor de CO2 mínimo en requerimientos y costos, con partes que se pueden conseguir en México.

**Este medidor no es un instrumento de medición regulado por lo que su uso es con fines educativos, no se puede garantizar que se adecúe a un uso o necesidad específica**

El objetivo de este proyecto es describir cómo hice un medidor de CO<sub>2</sub> para uso casero. Mi esperanza es que sea lo suficientemente sencillo como para que niños de secundaria con una clase de electricidad o electrónica lo puedan hacer, con el apoyo de un buen maestro:

- Los costos se han mantenido al mínimo, calculo que en Noviembre de 2021 el costo total del proyecto debe ser de unos $700
- Las partes se pueden conseguir en México fácilmente, con excepción del sensor de CO2 que se puede conseguir en Aliexpress con envío a México
- Las herramientas y materiales son lo que comunmente se tiene en un pequeño taller de electrónica

## La importancia de la medición de CO2 desde COVID-19

La evidencia actual nos muestra que COVID-19 y muchas otras enfermedades se pueden contagiar al respirar el aire que otras personas respiraron previamente (y que puede contener al virus u otros patógenos). En un ambiente cerrado, como interiores de casas, salones de clases, comercios, etc. la principal fuente de dióxido de carbono (CO2), si no existen otras fuentes como estufas encendidas o motores de combustión, es la respiración de las personas. Por eso es que medir el CO2 nos puede dar una indicación de la probabilidad de respitar el aire que otra persona ya ha respirado. 

La concentración de CO2 se mide en partículas por millón (ppm).
 
- En exteriores, al aire libre, se suelen medir 400 ppm o menos. 
- En interiores con poca gente y buena ventilación se miden entre 400 y 700 ppm y es el nivel recomendado. Si la medición es mayor a esto se recomienda mejorar la ventilación.
- La Organización Mundial de la Salud (OMS) recomienda que la concentración de CO2 en interiores se mantenga por debajo de las 1,000 ppm.

Aunque no es perfecto y hay muchos factores que influyen en el riesgo real, medir el nivel de CO2 en los espacios cerrados nos puede dar una indicación de cuándo es necesario ventilar, o si es preferible evitar un espacio en forma precautoria.

*[TODO: Referencias a estudios, comunicados y estándares]*

## El proyecto "Haz tu mismo tu medidor de CO2"

Primero una **advetencia**: si lo que se requiere es una medición mas exacta y confiable con el fin de disminuir riesgos **se recomienda usar medidores de CO2 comerciales confiables y homologados**. Existen en el mercado muchos modelos confiables en una diversidad de precios. 

*[TODO: referencias a productos y documentacion sobre medidores]*

Dicho esto el presente proyecto tiene la intención de enseñar la importancia de la ventilación y de construir un medidor básico de CO2 que pueda servir como un proyecto de ciencias y tecnología sencillo y con cierta utilidad práctica. Sin embargo, inisito en que no es un medidor homologado y no se debe confiar únicamente en el para tomar decisiones de seguridad.


### Modelo actual:



- *Microcontrolador*: NodeMCU v2
- *Sensor CO2*: Winsen MH-Z19
- 3 leds: verde, amarillo, rojo
- Plataforma: ESPHome

## Referencias

http://covidco2.exitcorp.net/documentacion/

https://www.hse.gov.uk/coronavirus/equipment-and-machinery/air-conditioning-and-ventilation/identifying-poorly-ventilated-areas.htm

https://ncceh.ca/sites/default/files/FINAL%20-%20Using%20Indoor%20CO2%20Sensors%20for%20COVID%20MAY%2017%202021.pdf


