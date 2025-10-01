\# Simulación de Flujo de Pasajeros en Aeropuerto (C++)



Proyecto académico en \*\*C++\*\* que simula el flujo de pasajeros en un aeropuerto utilizando \*\*estructuras de datos\*\* clásicas. El objetivo es modelar cómo los pasajeros avanzan por diferentes etapas (llegadas, control, embarque) y medir el rendimiento del sistema.



\## ✨ Qué incluye

\- Simulación paso a paso del \*\*flujo de pasajeros\*\* por módulos del aeropuerto.

\- Uso explícito de \*\*colas\*\*, \*\*pilas\*\*, \*\*listas\*\* y \*\*árboles\*\* para gestionar estados y prioridades.

\- Métricas básicas: \*\*tiempos de espera\*\*, \*\*throughput\*\* (pasajeros procesados) y \*\*ocupación\*\* de recursos.

\- Diseño modular para poder \*\*cambiar la estructura\*\* y comparar rendimiento.



\## 🧰 Estructuras y ficheros (ejemplos)

\- `Cola.cpp`, `Pila.cpp`, `Lista.cpp`, `Arbol.cpp` → Implementaciones de E.D.

\- `Pasajero.cpp` → Modelo de entidad.

\- `Aeropuerto.cpp` → Orquestación de la simulación (lógica principal).

\- Otros: `Nodo\*.cpp`, `Box.cpp`, etc.



\## 🎯 Objetivos de aprendizaje

\- Practicar \*\*estructuras de datos y algoritmos\*\* aplicados a un caso realista.

\- Analizar \*\*complejidad\*\* y el impacto de elegir una u otra E.D.

\- Separación de responsabilidades y \*\*diseño modular\*\* del código.



\## ▶️ Cómo compilar y ejecutar



\### Windows (MinGW / g++)

Desde la raíz del proyecto:

```bash

g++ -std=c++17 -O2 -o aeropuerto.exe src/\*.cpp

.\\aeropuerto.exe

### macOS / Linux (g++)
```bash
g++ -std=c++17 -O2 -o aeropuerto src/*.cpp
./aeropuerto



